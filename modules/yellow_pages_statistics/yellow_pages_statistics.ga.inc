<?php
/**
 * @file
 * Code for the Yellow Pages statistics Google Analytics functionality.
 */

/**
 * Callback function that return google analytics page content.
 */
function yellow_pages_statistics_ga_page() {
  $analytics = yellow_pages_statistics_get_google_analytics_service();
  $profile_id = yellow_pages_statistics_get_first_google_user_profile_id($analytics);

  // Calls the Core Reporting API and queries for the number of sessions for the last seven days.
  $results = $analytics->data_ga->get('ga:' . $profile_id, '7daysAgo', 'today', 'ga:sessions');

  $data = '';
  // Parses the response from the Core Reporting API and prints
  // the profile name and total sessions.
  if (count($results->getRows()) > 0) {
    // Get the profile name.
    $profile_name = $results->getProfileInfo()->getProfileName();

    // Get the entry for the first entry in the first row.
    $rows = $results->getRows();
    $sessions = $rows[0][0];

    // Print the results.
    $data .= "First view (profile) found: $profile_name\n";
    $data .= "Total sessions: $sessions\n";
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
