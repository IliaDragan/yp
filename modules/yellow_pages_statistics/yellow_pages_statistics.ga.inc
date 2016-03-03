<?php
/**
 * @file
 * Code for the Yellow Pages statistics Google Analytics functionality.
 */

/**
 * Form function that returns google analytics page content.
 */
function yellow_pages_statistics_ga($form, &$form_state) {
  $analytics = yellow_pages_statistics_get_google_analytics_service();

  $form['filter'] = array(
    '#type' => 'fieldset',
  );

  // Metrics.
  $metrics_options = array(
    'ga:entrances' => t('Entrances'),
    'ga:users'     => t('Users'),
    'ga:sessions'  => t('Sessions'),
    'ga:pageviews' => t('Pageviews'),
    'ga:avgSessionDuration' => t('Session duration average')
  );
  $default_metric = empty($form_state['storage']['metric']) ? 'ga:entrances' : $form_state['storage']['metric'];
  $form['filter']['metric'] = array(
    '#type' => 'select',
    '#title' => t('Select Metric'),
    '#options' => $metrics_options,
    '#default_value' => $default_metric,
  );

  // Profiles.
  if (empty($form_state['storage']['profile'])) {
    $profiles_options = yellow_pages_statistics_get_google_user_profiles_ids($analytics);
    reset($profiles_options);
    $default_profile = key($profiles_options);
  }
  else {
    $default_profile = $form_state['storage']['profile'];

  }

  $form['filter']['profile'] = array(
    '#type' => 'value',
    '#value' => $default_profile,
  );

  // Periods.
  $periods_options = array(
    'year' => t('Last year'),
    'month' => t('Last month'),
    'week' => t('Last week')
  );
  $default_period = empty($form_state['storage']['period']) ? 'year' : $form_state['storage']['period'];
  $form['filter']['period'] = array(
    '#type' => 'select',
    '#title' => t('Select Period'),
    '#options' => $periods_options,
    '#default_value' => $default_period,
  );

  $form['filter']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Show'),
  );

  $form['chart'] = array(
    '#markup' => yellow_pages_statistics_ga_chart($analytics, $default_profile, $default_metric, $metrics_options, $default_period),
  );

  return $form;
}

/**
 * Submit function for google analytics page content form.
 */
function yellow_pages_statistics_ga_submit(&$form, &$form_state) {
  $form_state['storage']['metric'] = $form_state['values']['metric'];
  $form_state['storage']['profile'] = $form_state['values']['profile'];
  $form_state['storage']['period'] = $form_state['values']['period'];
  $form_state['rebuild'] = TRUE;
}

/**
 * This function creates google analytics chart for given metrics for last year.
 *
 * @param $analytics
 *   Google_Service_Analytics object.
 * @param $profile_id
 *   Service user ID.
 * @param $metric
 *   Selected metric.
 * @param $metrics
 *   Array of all metrics.
 *
 * @return string
 *   Html of chart content.
 */
function yellow_pages_statistics_ga_chart($analytics, $profile_id, $metric, $metrics, $period) {
  $period_vars = yellow_pages_statistics_ga_get_period_variables($period);

  $results = $analytics->data_ga->get(
    'ga:' . $profile_id,
    $period_vars['start_date'],
    'today',
    $metric,
    array(
      'dimensions' => $period_vars['dimensions'],
    )
  );
  $rows = $results->getRows();

  $data = '';
  if (count($rows) > 0) {
    $profile_name = $results->getProfileInfo()->getProfileName();

    $chart_data = array();
    foreach ($rows as $row) {
      $chart_data[] = array(
        format_date(mktime(NULL, NULL, NULL, $row[1], ($period_vars['with_day'] ? $row[2] : 1), $row[0]), 'custom', $period_vars['format']),
        intval(($period_vars['with_day'] ? $row[3] : $row[2]))
      );
    }

    $module_path = drupal_get_path('module', 'yellow_pages_statistics');
    $js_data = array(
      'analyticsChart' => array(
        'chartData' => json_encode($chart_data),
        'chartTitle' => t('@metric on @profile', array('@metric' => $metrics[$metric], '@profile' => $profile_name)),
        'chartColumns' => array(
          'col1' => array(
            'type' => 'string',
            'title' => t('Months')
          ),
          'col2' => array(
            'type' => 'number',
            'title' => $metrics[$metric]
          ),
        ),
      ),
    );

    if ($metric == 'ga:avgSessionDuration') {
      $js_data['analyticsChart']['chartColumns']['col2']['format'] = '# ' . t('sec');
    }

    drupal_add_js($js_data, 'setting');
    drupal_add_js('http://www.google.com/jsapi', array('type' => 'external', 'group' => JS_LIBRARY));
    drupal_add_js($module_path . '/js/yellow_pages_statistics_ga.chart.js');

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
 * Get the user's views (profiles) IDs.
 *
 * @param Google_Service_Analytics $analytics
 *   the Analytics service object.
 *
 * @return
 *   available user profile IDs list.
 */
function yellow_pages_statistics_get_google_user_profiles_ids(&$analytics) {
  // Get the list of accounts for the authorized user.
  $accounts = $analytics->management_accounts->listManagementAccounts();

  $profiles_ids = array();
  $account_items = $accounts->getItems();
  foreach ($account_items as $account_item) {
    $account_id = $account_item->getId();

    // Get the list of properties for the authorized user.
    $properties = $analytics->management_webproperties
      ->listManagementWebproperties($account_id);

    $property_items = $properties->getItems();
    foreach ($property_items as $property_item) {
      $property_id = $property_item->getId();

      // Get the list of views (profiles) for the authorized user.
      $profiles = $analytics->management_profiles
        ->listManagementProfiles($account_id, $property_id);

      $profiles_items = $profiles->getItems();
      foreach ($profiles_items as $profiles_item) {
        $profiles_ids[$profiles_item->getId()] = $profiles_item->getName();
      }
    }
  }
  if (count($profiles_ids)) {
    return $profiles_ids;
  }
  else {
    throw new Exception(t('No views (profiles) found for this user.'));
  }
}

/**
 * Gets specific for period type variables values.
 *
 * @param $period
 *   The selected period type.
 *
 * @return array
 *   List of variables values.
 */
function yellow_pages_statistics_ga_get_period_variables($period) {
  switch ($period) {
    case 'week':
      $variables = array(
        'with_day' => TRUE,
        'dimensions' => 'ga:year,ga:month,ga:day',
        'start_date' => '7daysAgo',
        'format' => 'd M',
      );
      break;

    case 'month':
      $variables = array(
        'with_day' => TRUE,
        'dimensions' => 'ga:year,ga:month,ga:day',
        'start_date' => date('Y-m-d', strtotime('-1 month')),
        'format' => 'd M',
      );
      break;

    case 'year':
    default:
      $variables = array(
        'with_day' => FALSE,
        'dimensions' => 'ga:year,ga:month',
        'start_date' => date('Y-m-d', strtotime('-1 year')),
        'format' => 'M Y',
      );
  }
  return $variables;
}
