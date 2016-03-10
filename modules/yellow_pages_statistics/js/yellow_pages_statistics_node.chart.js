// Load the Google Visualization API and the chart.
google.load('visualization', '1', {'packages': ['corechart']});
// Set callback.
google.setOnLoadCallback(createNodeChart);

function createNodeChart() {
  var ns = Drupal.settings.nodeStatistics;
  if (ns['companyChartData']) {
    constructChart('companyChart', ns['companyChartData']);
  }
  if (ns['advertisementChartData']) {
    constructChart('advertisementChart', ns['advertisementChartData']);
  }
}

function constructChart(chartId, dataJSON) {

  // Create data table object.
  var data = JSON.parse(dataJSON);
  var dataTable = new google.visualization.arrayToDataTable(data);

  // Instantiate our chart object.
  var element = document.getElementById(chartId);
  if (element) {
    var chart = new google.visualization.LineChart(element);

    // Define options for visualization.
    var options = {
      height: 400,
      legend: {position: 'bottom'},
      lineWidth: 2,
      pointSize: 4,
      vAxis: {
        minValue: 0,
        baseline: 0,
        viewWindow: {min: 0}
      },
      series: {
        0: {
          pointShape: 'diamond',
          pointSize: 10
        }
      }
    }

    // Draw our chart.
    chart.draw(dataTable, options);

  }
}
