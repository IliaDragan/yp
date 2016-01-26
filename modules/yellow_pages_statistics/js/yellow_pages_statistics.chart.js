// Load the Google Visualization API and the chart.
google.load('visualization', '1', {'packages': ['corechart']});
// Set callback.
google.setOnLoadCallback(createChart);

function createChart() {
  var ga = Drupal.settings.analyticsChart;

  // Create data table object.
  var dataTable = new google.visualization.DataTable();

  // Define columns.
  var cols = ga['chartColumns'];
  dataTable.addColumn(cols[0][0],cols[0][1]);
  dataTable.addColumn(cols[1][0],cols[1][1]);

  // Define rows of data.
  dataTable.addRows(ga['chartData']);

  // Instantiate our chart object.
  var chart = new google.visualization.AreaChart(document.getElementById('chart'));

  // Define options for visualization.
  var options = {
    height: 400,
    title: ga['chartTitle'],
    legend: {position: 'none'},
    lineWidth: 4,
    pointSize: 7
  };

  // Draw our chart.
  chart.draw(dataTable, options);
}
