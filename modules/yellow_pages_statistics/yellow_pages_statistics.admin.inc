<?php
/**
 * @file
 * Module administration and settings forms.
 */

/**
 * Yellow Pages Google Analytics settings form.
 */
function yellow_pages_statistics_ga_client_settings_form($form, &$form_state) {
  $form['email'] = array(
    '#title' => t('E-mail'),
    '#description' => t('Service account email address'),
    '#type' => 'textfield',
    '#default_value' => variable_get('google_service_account_email', ''),
    '#required' => TRUE,
  );

  $form['key_file'] = array(
    '#title' => t('Key file'),
    '#description' => t('File with service account keys (p12 format).'),
    '#type' => 'file',
    '#default_value' => NULL,
  );

  $form['documentation_wrapper'] = array(
    '#title' => t('How to create service account'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['documentation_wrapper']['documentation'] = array(
    '#markup' => get_google_documentation(),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save settings'),
  );

  return $form;
}

/**
 * Yellow Pages Google Analytics settings form validate.
 */
function yellow_pages_statistics_ga_client_settings_form_validate(&$form, &$form_state) {
  $values = $form_state['values'];
  if (!valid_email_address($values['email'])) {
    form_set_error('email', t('The value of field email is not a valid email address'));
  }

  $validators = array('file_validate_extensions' => array('p12'));
  $file = file_save_upload('key_file', $validators);
  if (!empty($file)) {
    $form_state['storage']['key_file'] = $file;
  }
  else {
    form_set_error('key_file', t('The key file could not be uploaded.'));
  }
}

/**
 * Yellow Pages Google Analytics settings form submit.
 */
function yellow_pages_statistics_ga_client_settings_form_submit(&$form, &$form_state) {
  $values = $form_state['values'];
  variable_set('google_service_account_email', $values['email']);

  $file = $form_state['storage']['key_file'];
  $contents = file_get_contents($file->uri);
  variable_set('google_service_account_keys', $contents);
  file_delete($file, TRUE);

  drupal_set_message(t('For security reason the content of your key file was saved in the database and the file was deleted.'));
}

/**
 * Callback function with Client ID creation documentation.
 *
 * @return string
 *   Html code of documentation.
 */
function get_google_documentation() {
  $doc = '<h3>Create a client ID</h3>';
  $doc .= '<ol>';
  $doc .= '<li>Open the <a href="https://console.developers.google.com/projectselector/permissions/serviceaccounts">Service accounts section</a> of the Developers Console\'s <b>Permissions</b> page.</li>';
  $doc .= '<li>Click <b>Create service account</b>.</li>';
  $doc .= '<li>In the <b>Create service account</b> window, type a name for the service account and select <b>Furnish a new private key</b>. When prompted for the Key type select <b>P12</b>. If you want to <a href="https://developers.google.com/identity/protocols/OAuth2ServiceAccount#delegatingauthority">grant Google Apps domain-wide authority</a> to the service account, also select <b>Enable Google Apps Domain-wide Delegation</b>. Then, click <b>Create</b>.</li>';
  $doc .= '</ol>';
  $doc .= '<p>Your new public/private key pair is generated and downloaded to your machine; it serves as the only copy of this key. You are responsible for storing it securely.</p>';
  $doc .= '<h3>Add service account to Google Analytics account</h3>';
  $doc .= '<p>The newly created service account will have an email address, <code>&lt;projectId&gt;-&lt;uniqueId&gt;@developer.gserviceaccount.com</code>; Use this email address to <a href="https://support.google.com/analytics/answer/1009702">add a user</a> to the Google analytics account you want to access via the API. Only <a href="https://support.google.com/analytics/answer/2884495">Read &amp; Analyze</a> permissions are needed.</p>';

  return $doc;
}
