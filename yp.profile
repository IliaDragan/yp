<?php
/**
 * @file
 * Enables modules and site configuration for a standard site installation.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function yp_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = 'Yellow pages';
  $form['server_settings']['site_default_country']['#default_value'] = 'MD';
  $form['server_settings']['date_default_timezone']['#default_value'] = 'Europe/Chisinau';
}
