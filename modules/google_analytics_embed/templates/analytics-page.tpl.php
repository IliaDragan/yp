<div id="ga-visits"></div>

<div class="row">
  <div class="col-md-6">
    <h5>Popular sections</h5>
    <div id="ga-pages-pie"></div>
    <h5>Browsers</h5>
    <div id="ga-browsers-pie"></div>
  </div>
  <div class="col-md-6">
    <div id="ga-pages-list"></div>
  </div>
</div>



<script>

gapi.analytics.ready(function() {

  /**
   * Authorize the user with an access token obtained server side.
   */
  gapi.analytics.auth.authorize({
    'serverAuth': {
      'access_token': Drupal.settings.google_analytics_embed.token
    }
  });

  var ids = Drupal.settings.google_analytics_embed.view_id;


  /**
   * Creates a new DataChart instance showing sessions over the past 30 days.
   * It will be rendered inside an element with the id "chart-1-container".
   */
  new gapi.analytics.googleCharts.DataChart({
    query: {
      'ids': ids, // The Demos & Tools website view.
      'start-date': '30daysAgo',
      'end-date': 'yesterday',
      'metrics': 'ga:sessions,ga:users',
      'dimensions': 'ga:date'
    },
    chart: {
      'container': 'ga-visits',
      'type': 'LINE',
      'options': {
        'width': '100%'
      }
    }
  }).execute();


  /**
   * Creates a new DataChart instance showing top 5 most popular demos/tools
   * amongst returning users only.
   * It will be rendered inside an element with the id "chart-3-container".
   */
  new gapi.analytics.googleCharts.DataChart({
    query: {
      'ids': ids, // The Demos & Tools website view.
      'start-date': '30daysAgo',
      'end-date': 'yesterday',
      'metrics': 'ga:pageviews',
      'dimensions': 'ga:pagePathLevel1',
      'sort': '-ga:pageviews',
      'filters': 'ga:pagePathLevel1!=/',
      'max-results': 7
    },
    chart: {
      'container': 'ga-pages-pie',
      type: 'PIE',
      'options': {
        'width': '100%',
        'pieHole': 4/9
      }
    }
  }).execute();

  /**
   * Creates a new DataChart instance showing top 5 most popular demos/tools
   * amongst returning users only.
   * It will be rendered inside an element with the id "chart-3-container".
   */
  new gapi.analytics.googleCharts.DataChart({
    query: {
      'ids': ids, // The Demos & Tools website view.
      'start-date': '30daysAgo',
      'end-date': 'yesterday',
      'metrics': 'ga:pageviews',
      'dimensions': 'ga:pagePath',
      'sort': '-ga:pageviews',
      //'filters': 'ga:pagePathLevel1!=/',
      'max-results': 10
    },
    chart: {
      'container': 'ga-pages-list',
      type: 'TABLE',
      'options': {
        'width': '100%'
      }
    }
  }).execute();


  /**
   * Creates a new DataChart instance showing top 5 most popular demos/tools
   * amongst returning users only.
   * It will be rendered inside an element with the id "chart-3-container".
   */
  new gapi.analytics.googleCharts.DataChart({
    query: {
      'ids': ids, // The Demos & Tools website view.
      'start-date': '30daysAgo',
      'end-date': 'yesterday',
      'metrics': 'ga:sessions',
      'dimensions': 'ga:browser',
      'max-results': 7
    },
    chart: {
      'container': 'ga-browsers-pie',
      type: 'PIE',
      'options': {
        'width': '100%',
        'pieHole': 4/9
      }
    }
  }).execute();

});
</script>