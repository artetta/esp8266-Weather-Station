const char PAGE_humidity[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
   <head>
      <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
      <title>Weather Station</title>
      <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js" type="text/javascript"></script>
      <script type='text/javascript'>//<![CDATA[
         $(document).ready(function() {
             var options = {
                 chart: {
                     renderTo: 'container',
                     type: 'spline'
                 },
                 title: {
                     text: 'Humidity Data'
                 },
                 xAxis: {
                     type: 'datetime'
                 },
                 yAxis: {
                   title: {
                     text: 'Humidity (%)'
                         }
                 },
                 plotOptions: {
                     line: {
                         dataLabels: {
                             enabled: true
                         },
                         enableMouseTracking: true
                     }
                 },
                     series: [{
                     type: 'spline',
                     name: 'Humidity sensor data',
                     tooltip: {
                     valueDecimals: 0,
                     valueSuffix: '%'
                     }
                 }]
             };
             $.getJSON('humidity.json', function(data) {
                 options.series[0].data = data;
                 var chart = new Highcharts.Chart(options);
             });
         });
         //]]>
      </script>
   </head>
   <body>
      <script src="https://code.highcharts.com/stock/highstock.js" type="text/javascript"></script>
      <script src="https://code.highcharts.com/stock/modules/exporting.js" type="text/javascript"></script>
      <div id="container" style="height: 400px; min-width: 310px"></div>
      <style>
         .t {
         text-align: justify;
         padding: 10px;
         }
         .t:after {
         content: '';
         width: 100%;
         display: inline-block;
         }
         .i {
         display: inline-block;
         padding: 10px;
         }
      </style>
      <div class="t">
         <div class="i">
            <form action="/pressure.html">
               <input type="image" src="http://claws.msk.ru/src/pressure.png" alt="Pressure" width="48" height="48">
            </form>
         </div>
         <div class="i">
            <form action="/temperature.html">
               <input type="image" src="http://claws.msk.ru/src/temperature.png" alt="Temperature" width="48" height="48">
            </form>
         </div>
      </div>
      <div style="position: absolute; bottom: 0; right: 0;">
         <form action="/">
            <input type="image" src="http://claws.msk.ru/src/home.png" alt="Home" width="48" height="48">
         </form>
      </div>
   </body>
</html>
)=====";

const char PAGE_pressure[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
   <head>
      <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
      <title>Weather Station</title>
      <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js" type="text/javascript"></script>
      <script type='text/javascript'>//<![CDATA[
         $(document).ready(function() {
             var options = {
                 chart: {
                     renderTo: 'container',
                     type: 'spline'
                 },
                 title: {
                     text: 'Pressure Data'
                 },
                 xAxis: {
                     type: 'datetime'
                 },
                 yAxis: {
                   title: {
                     text: 'Pressure (hPa)'
                         }
                 },
                 plotOptions: {
                     line: {
                         dataLabels: {
                             enabled: true
                         },
                         enableMouseTracking: true
                     }
                 },
                     series: [{
                     type: 'spline',
                     name: 'Pressure sensor data',
                     tooltip: {
                     valueDecimals: 0,
                     valueSuffix: 'hPa'
                     }
                 }]
             };
             $.getJSON('pressure.json', function(data) {
                 options.series[0].data = data;
                 var chart = new Highcharts.Chart(options);
             });
         });
         //]]>
      </script>
   </head>
   <body>
      <script src="https://code.highcharts.com/stock/highstock.js" type="text/javascript"></script>
      <script src="https://code.highcharts.com/stock/modules/exporting.js" type="text/javascript"></script>
      <div id="container" style="height: 400px; min-width: 310px"></div>
      <style>
         .t {
         text-align: justify;
         padding: 10px;
         }
         .t:after {
         content: '';
         width: 100%;
         display: inline-block;
         }
         .i {
         display: inline-block;
         padding: 10px;
         }
      </style>
      <div class="t">
         <div class="i">
            <form action="/temperature.html">
               <input type="image" src="http://claws.msk.ru/src/temperature.png" alt="Pressure" width="48" height="48">
            </form>
         </div>
         <div class="i">
            <form action="/humidity.html">
               <input type="image" src="http://claws.msk.ru/src/humidity.png" alt="Temperature" width="48" height="48">
            </form>
         </div>
      </div>
      <div style="position: absolute; bottom: 0; right: 0;">
         <form action="/">
            <input type="image" src="http://claws.msk.ru/src/home.png" alt="Home" width="48" height="48">
         </form>
      </div>
   </body>
</html>
)=====";

const char PAGE_temperature[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
   <head>
      <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
      <title>Weather Station</title>
      <script src="http://ajax.googleapis.com/ajax/libs/jquery/1.7.1/jquery.min.js" type="text/javascript"></script>
      <script type='text/javascript'>//<![CDATA[
         $(document).ready(function() {
             var options = {
                 chart: {
                     renderTo: 'container',
                     type: 'spline'
                 },
                 title: {
                     text: 'Temperature Data'
                 },
                 xAxis: {
                     type: 'datetime'
                 },
                 yAxis: {
                   title: {
                     text: 'Temperature (C)'
                         }
                 },
                 plotOptions: {
                     line: {
                         dataLabels: {
                             enabled: true
                         },
                         enableMouseTracking: true
                     }
                 },
                     series: [{
                     type: 'spline',
                     name: 'Temperature sensor data',
                     tooltip: {
                     valueDecimals: 0,
                     valueSuffix: ' C'
                     }
                 }]
             };
             $.getJSON('temperature.json', function(data) {
                 options.series[0].data = data;
                 var chart = new Highcharts.Chart(options);
             });
         });
         //]]>
      </script>
   </head>
   <body>
      <script src="https://code.highcharts.com/stock/highstock.js" type="text/javascript"></script>
      <script src="https://code.highcharts.com/stock/modules/exporting.js" type="text/javascript"></script>
      <div id="container" style="height: 400px; min-width: 310px"></div>
      <style>
         .t {
         text-align: justify;
         padding: 10px;
         }
         .t:after {
         content: '';
         width: 100%;
         display: inline-block;
         }
         .i {
         display: inline-block;
         padding: 10px;
         }
      </style>
      <div class="t">
         <div class="i">
            <form action="/humidity.html">
               <input type="image" src="http://claws.msk.ru/src/humidity.png" alt="Humidity" width="48" height="48">
            </form>
         </div>
         <div class="i">
            <form action="/pressure.html">
               <input type="image" src="http://claws.msk.ru/src/pressure.png" alt="Pressure" width="48" height="48">
            </form>
         </div>
      </div>
      <div style="position: absolute; bottom: 0; right: 0;">
         <form action="/">
            <input type="image" src="http://claws.msk.ru/src/home.png" alt="Home" width="48" height="48">
         </form>
      </div>
   </body>
</html>
)=====";

const char head [] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
   <head>
      <meta charset="utf-8">
      <title>Weather Station</title>
      <style>
         body{
         background-color: #6495ed;
         text-align:  center;
         }
      </style>
      <font color="#FFF">
      <div>
      <table width="100%" height="100%" align="center" valign="center">
      <tr>
         <td>
)=====";

const char tail [] PROGMEM = R"=====(
</td></tr>
</table>
</div>
</font>
</head>
<body>
   <div style="position: absolute; bottom: 0; right: 0;">
      <form action="/temperature.html">
         <input type="image" src="http://claws.msk.ru/src/graph_icon.png" alt="Graph" width="48" height="48">
      </form>
   </div>
</body>
</html>
)=====";
