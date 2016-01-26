<?php
/**
 * @file
 * Code for the Yellow Pages statistics Google Analytics functionality.
 */

/**
 * Form function that returns google analytics page content.
 */
function yellow_pages_statistics_ga($form, &$form_state) {
  $metrics_options = array(
    'ga:entrances' => t('Entrances'),
    'ga:users'     => t('Users'),
  );
  $default_metric = empty($form_state['storage']['metrics']) ? 'ga:entrances' : $form_state['storage']['metrics'];
  $form['metrics'] = array(
    '#type' => 'select',
    '#title' => t('Select Metrics'),
    '#options' => $metrics_options,
    '#default_value' => $default_metric,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Show'),
  );
  $form['chart'] = array(
    '#markup' => yellow_pages_statistics_ga_chart($default_metric, $metrics_options),
  );

  return $form;
}

/**
 * Submit function for google analytics page content form.
 */
function yellow_pages_statistics_ga_submit (&$form, &$form_state) {
  $form_state['storage']['metrics'] = $form_state['values']['metrics'];
  $form_state['rebuild'] = TRUE;
}

/**
 * This function creates google analytics chart for given metrics for last year.
 *
 * @param $metric
 *   Selected metric.
 * @param $metrics
 *   Array of all metrics.
 *
 * @return string
 *   Html of chart content.
 */
function yellow_pages_statistics_ga_chart($metric, $metrics) {
  $analytics = yellow_pages_statistics_get_google_analytics_service();
  $profile_id = yellow_pages_statistics_get_first_google_user_profile_id($analytics);

  $start_date = date('Y-m-d', strtotime('-1 year'));

  $results = $analytics->data_ga->get(
    'ga:' . $profile_id,
    $start_date,
    'today',
    $metric,
    array(
      'dimensions' => 'ga:year,ga:month'
    )
  );
  $rows = $results->getRows();

  $data = '';
  if (count($rows) > 0) {
    $profile_name = $results->getProfileInfo()->getProfileName();

    $chart_data = array();
    foreach ($rows as $row) {
      $chart_data[] = array(
        date("F Y", mktime(null, null, null, $row[1], 1, $row[0])),
        intval($row[2])
      );
    }

    $module_path = drupal_get_path('module', 'yellow_pages_statistics');
    $js_data = array(
      'analyticsChart' => array(
        'chartData' => $chart_data,
        'chartTitle' => t('Google Analytics for @profile', array('@profile' => $profile_name)),
        'chartColumns' => array(
          array('string', t('Months')),
          array('number', t($metrics[$metric])),
        ),
      ),
    );
    drupal_add_js($js_data, 'setting');
    drupal_add_js('http://www.google.com/jsapi', 'external');
    drupal_add_js($module_path . '/js/yellow_pages_statistics.chart.js');

    $data .= '<div id="chart"></div>';
  }
  else {
    $data .= t('No results found.');
  }
  return $data;
}

/**
 * Creates and returns the Analytics service object.
 *
 * @return Google_Service_Analytics
 */
function yellow_pages_statistics_get_google_analytics_service() {
  // Load the Google API PHP Client Library.
  require_once 'google_api_php_client/src/Google/autoload.php';

  // Create and configure a new client object.
  $email = variable_get('google_service_account_email', '');

  $client = new Google_Client();
  $client->setApplicationName("HelloAnalytics");
  $analytics = new Google_Service_Analytics($client);

  // Read the generated client_secrets.p12 key.
  $key = variable_get('google_service_account_keys', '');
  $cred = new Google_Auth_AssertionCredentials(
    $email,
    array(Google_Service_Analytics::ANALYTICS_READONLY),
    $key
  );
  $client->setAssertionCredentials($cred);
  if ($client->getAuth()->isAccessTokenExpired()) {
    $client->getAuth()->refreshTokenWithAssertion($cred);
  }

  return $analytics;
}

/**
 * Get the user's first view (profile) ID.
 *
 * @param Google_Service_Analytics $analytics
 *   the Analytics service object.
 *
 * @return
 *   user profile ID.
 */
function yellow_pages_statistics_get_first_google_user_profile_id(&$analytics) {
  // Get the list of accounts for the authorized user.
  $accounts = $analytics->management_accounts->listManagementAccounts();

  if (count($accounts->getItems()) > 0) {
    $items = $accounts->getItems();
    $first_ccount_id = $items[0]->getId();

    // Get the list of properties for the authorized user.
    $properties = $analytics->management_webproperties
      ->listManagementWebproperties($first_ccount_id);

    if (count($properties->getItems()) > 0) {
      $items = $properties->getItems();
      $first_property_id = $items[0]->getId();

      // Get the list of views (profiles) for the authorized user.
      $profiles = $analytics->management_profiles
        ->listManagementProfiles($first_ccount_id, $first_property_id);

      if (count($profiles->getItems()) > 0) {
        $items = $profiles->getItems();

        // Return the first view (profile) ID.
        return $items[0]->getId();

      }
      else {
        throw new Exception(t('No views (profiles) found for this user.'));
      }
    }
    else {
      throw new Exception(t('No properties found for this user.'));
    }
  }
  else {
    throw new Exception(t('No accounts found for this user.'));
  }
}
