<?php
/**
 * @file
 * Enables modules and site configuration for a standard site installation.
 */

/**
 * Implements hook_profile_details().
 */
// function yp_profile_details() {
//   $details['language'] = "ru";

//   return $details;
// }

/**
 * Implements hook_form_FORM_ID_alter().
 */
function yp_form_install_configure_form_alter(&$form, $form_state) {
  $t = get_t();
  // Pre-populate the site name with the server name, default country and timezone.
  $form['site_information']['site_name']['#default_value'] = $t('YELLOW PAGES OF MOLDOVA');

  $form['site_information']['site_slogan'] = array(
    '#type' => 'textfield',
    '#title' => $t('Site slogan'),
    '#default_value' => $t('All <span class="yellow">Moldova</span> facilities at your demand'),
  );

  $form['site_information']['site_description'] = array(
    '#type' => 'textfield',
    '#title' => $t('Site description'),
    '#default_value' => $t('Search companies by name, activity, take your own pick or make a tour through links'),
  );

  $form['site_information']['site_mail']['#weight'] = '99';

  $form['server_settings']['site_default_country']['#default_value'] = 'MD';
  $form['server_settings']['date_default_timezone']['#default_value'] = 'Europe/Chisinau';

  $form['#submit'][] = '_yp_configure_form_submit';
}

function _yp_configure_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  variable_set('site_slogan', $values['site_slogan']);
  variable_set('site_description', $values['site_description']);
}

/**
 * Implements hook_install_tasks().
 */
function yp_install_tasks($install_state) {
  $task = array();

  $task['yp_enable_modules'] = array(
    'display_name' => st('Enable yellow pages modules'),
    'display' => FALSE,
    'type' => 'normal',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    'function' => '_yp_enable_modules',
  );

  return $task;
}

/**
 * Callback for enable modules install task.
 */
function _yp_enable_modules() {
  $modules = array(
    'yellow_pages_admin',
    'yellow_pages_ads',
    'yellow_pages_article_ct',
    'yellow_pages_company_ct',
    'yellow_pages_contacts',
    'yellow_pages_feedback',
    'yellow_pages_frontend',
    'yellow_pages_lists',
    'yellow_pages_news_ct',
    'yellow_pages_permissions',
    'yellow_pages_print',
    'yellow_pages_rates',
    'yellow_pages_rules_configuration',
    'yellow_pages_solr_configuration',
    'yellow_pages_sync',
    'yellow_pages_taxonomy',
    'yellow_pages_weather',
    'yellow_pages_nodeviewcount',
  );

  module_enable($modules);
}
