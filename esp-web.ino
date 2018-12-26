#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Wire.h>
#include <Adafruit_BME280.h>
#include <time.h>
#include "index.h"

#define CHART_SIZE 144
#define BME280_ADDRESS 0x76
Adafruit_BME280 bme;
 
ESP8266WebServer server(80);

bool PointExist = false;
long co2t[CHART_SIZE];

int timezone = 3;
int dst = 0;
time_t now;

int cur_pos = -2;

uint32_t Date[CHART_SIZE];
int Temperature[CHART_SIZE];
int Humidity[CHART_SIZE];
int Pressure[CHART_SIZE];
 
//SSID and Password of your WiFi router
const char* ssid = "ssid";
const char* password = "password";

void processCSV(int *data)
{      
    String str = "[\n";
    for (int i=0; i<=cur_pos; i++) {
      if ((i>0)&&(String(co2t[i])!="0")) str +=",\n";
      if (String(co2t[i])!="0") str += "["+String(co2t[i])+"000,"+String(data[i])+"]";}
      str +="\n]";
    server.send ( 200, "application/json", str);  
}
 
void ServerInit() {
  server.on ( "/", []() { server.send ( 200, "text/html", PAGE_temperature ); });
  server.on ( "/temperature.html", []() { server.send ( 200, "text/html", PAGE_temperature ); });
  server.on ( "/pressure.html", []() { server.send ( 200, "text/html", PAGE_pressure ); });
  server.on ( "/humidity.html", []() { server.send ( 200, "text/html", PAGE_humidity ); });
  server.on ( "/temperature.json", []() { processCSV(Temperature); });
  server.on ( "/pressure.json", []() { processCSV(Pressure); });
  server.on ( "/humidity.json", []() { processCSV(Humidity); });
     server.onNotFound ( []() { server.send ( 400, "text/html", "Page not Found" );   }  );
    server.begin();
}
 
void bme280Init() {
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  delay(10);
   Wire.begin(0, 2);
  Wire.setClock(100000);
  if (!bme.begin(0x76)) {
    while (1);
  }
}

void DataRead(int pos) {
  now = time(nullptr);
  Date[pos] = now;
  Temperature[pos] = bme.readTemperature();
  Pressure[pos] = bme.readPressure() / 100.0F;
  Humidity[pos] = bme.readHumidity();
  for (int i=0; i<=cur_pos; i++) {co2t[i]=Date[i];}
} 

void setup(void){
  WiFi.begin(ssid, password);     //Connect to your WiFi router
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  
  configTime(timezone * 3600, 0, "pool.ntp.org", "time.nist.gov");
 
  bme280Init();
  
  delay(60000);
  DataRead(++cur_pos);
  delay(60000);
  now = time(nullptr);
  DataRead(++cur_pos);
  
  ServerInit();
}

void loop(void){  
  now = time(nullptr);
  
  if (now / 60 % 60 == 0)
  {
    if (PointExist == false)
    {
      cur_pos++;
      if (cur_pos >= CHART_SIZE)
      {
        cur_pos--;
        for (int i(0); i < (CHART_SIZE - 1); i++)
        {
          Date[i] = Date[i+1];
          Temperature[i] = Temperature[i+1];
          Humidity[i] = Humidity[i+1];
          Pressure[i] = Pressure[i+1];
        }
      }
    DataRead(cur_pos);
    PointExist = true;
   }    
  }
  else
    PointExist = false;
  
  server.handleClient();          //Handle client requests
  yield();
}
