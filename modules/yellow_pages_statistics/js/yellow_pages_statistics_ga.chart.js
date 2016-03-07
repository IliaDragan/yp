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
  dataTable.addColumn(cols['col1']['type'],cols['col1']['title']);
  dataTable.addColumn(cols['col2']['type'],cols['col2']['title']);

  // Define rows of data.
  var data = JSON.parse(ga['chartData']);
  dataTable.addRows(data);

  // Instantiate our chart object.
  var element = document.getElementById('chart');
  if (element) {
    var chart = new google.visualization.AreaChart(element);

    // Define options for visualization.
    var options = {
      height: 400,
      title: ga['chartTitle'],
      legend: {position: 'none'},
      lineWidth: 4,
      pointSize: 7
    };

    // Add vAxis format if is set.
    if (cols['col2']['format']) {
      options.vAxis = {format: cols['col2']['format']};
    }

    // Draw our chart.
    chart.draw(dataTable, options);
  }
}
