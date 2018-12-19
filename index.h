const char PAGE_humidity[] PROGMEM = R"=====(
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
   table.text  {
    width:  100%; /* Ширина таблицы */
    border-spacing: 0; /* Расстояние между ячейками */
   }
   table.text td {
    width: 50%; /* Ширина ячеек */
    vertical-align: top; /* Выравнивание по верхнему краю */
   }
   td.rightcol { /* Правая ячейка */ 
    text-align: right; /* Выравнивание по правому краю */
   }
</style>
<table class="text">
   <tr>
    <td><a href="/pressure.html">--- Pressure</a></td>
    <td class="rightcol"><a href="/temperature.html">Temperature ---</a></td>
   </tr>
</table>


</body>
</html>
)=====";

const char PAGE_pressure[] PROGMEM = R"=====(
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
   table.text  {
    width:  100%; /* Ширина таблицы */
    border-spacing: 0; /* Расстояние между ячейками */
   }
   table.text td {
    width: 50%; /* Ширина ячеек */
    vertical-align: top; /* Выравнивание по верхнему краю */
   }
   td.rightcol { /* Правая ячейка */ 
    text-align: right; /* Выравнивание по правому краю */
   }
</style>
<table class="text">
   <tr>
    <td><a href="/temperature.html">--- Temperature</a></td>
    <td class="rightcol"><a href="/humidity.html">Humidity ---</a></td>
   </tr>
</table>
</body>
</html>
)=====";

const char PAGE_temperature[] PROGMEM = R"=====(
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
            valueSuffix: 'C'
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
   table.text  {
    width:  100%; /* Ширина таблицы */
    border-spacing: 0; /* Расстояние между ячейками */
   }
   table.text td {
    width: 50%; /* Ширина ячеек */
    vertical-align: top; /* Выравнивание по верхнему краю */
   }
   td.rightcol { /* Правая ячейка */ 
    text-align: right; /* Выравнивание по правому краю */
   }
</style>
<table class="text">
   <tr>
    <td><a href="/humidity.html">--- Humidity</a></td>
    <td class="rightcol"><a href="/pressure.html">Pressure ---</a></td>
   </tr>
</table>
</body>
</html>
)=====";
