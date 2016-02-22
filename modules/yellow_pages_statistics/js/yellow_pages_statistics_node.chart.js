// Load the Google Visualization API and the chart.
google.load('visualization', '1', {'packages': ['corechart']});
// Set callback.
google.setOnLoadCallback(createChart);

function createChart() {
  var ns = Drupal.settings.nodeStatistics;

  // Create data table object.
  var data = JSON.parse(ns['chartData']);
  var dataTable = new google.visualization.arrayToDataTable(data);

  // Instantiate our chart object.
  var element = document.getElementById('chart');
  if (element) {
    var chart = new google.visualization.AreaChart(element);

    // Define options for visualization.
    var options = {
      height: 400,
      legend: {position: 'bottom'},
      lineWidth: 2,
      pointSize: 4
    };

    // Draw our chart.
    chart.draw(dataTable, options);
  }
}
