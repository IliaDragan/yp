// Load the Google Visualization API and the chart.
google.load('visualization', '1', {'packages': ['corechart']});
// Set callback.
google.setOnLoadCallback(createNodeChart);

function createNodeChart() {
  var ns = Drupal.settings.nodeStatistics;
  if (ns['companyViewsChartData']) {
    constructChart('company-views-chart', ns['companyViewsChartData']);
  }
  if (ns['companyClicksChartData']) {
    constructChart('company-clicks-chart', ns['companyClicksChartData']);
  }
  if (ns['advertisementViewsChartData']) {
    constructChart('advertisement-views-chart', ns['advertisementViewsChartData']);
  }
  if (ns['advertisementClicksChartData']) {
    constructChart('advertisement-clicks-chart', ns['advertisementClicksChartData']);
  }
}

function constructChart(chartId, chartData) {

  // Create data table object.
  var data = JSON.parse(chartData.values);
  var dataTable = new google.visualization.arrayToDataTable(data);

  // Instantiate our chart object.
  var element = document.getElementById(chartId);
  if (element) {
    var chart = new google.visualization.LineChart(element);

    // Define options for visualization.
    var options = {
      height: 400,
      title: chartData.title,
      legend: {position: 'none'},
      colors: ['#333333'],
      lineWidth: 3,
      pointSize: 6,
      pointShape: 'diamond',
      vAxis: {
        minValue: 0,
        baseline: 0,
        viewWindow: {min: 0}
      }
    }

    google.visualization.events.addListener(chart, 'ready', function () {
      // Add chart copy as png image for print version.
      var img = '<img class="graph-as-png ' + chartId + '-print" src="' + chart.getImageURI() + '">';
      jQuery(element).after(img);
    });

    // Draw our chart.
    chart.draw(dataTable, options);

  }
}
