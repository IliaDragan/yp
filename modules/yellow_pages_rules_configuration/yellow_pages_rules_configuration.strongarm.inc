<?php
/**
 * @file
 * yellow_pages_rules_configuration.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function yellow_pages_rules_configuration_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_expire_company';
  $strongarm->value = '';
  $export['node_expire_company'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_expire_date_entry_elements';
  $strongarm->value = '1';
  $export['node_expire_date_entry_elements'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_expire_enabled_company';
  $strongarm->value = 1;
  $export['node_expire_enabled_company'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_expire_handle_content_expiry';
  $strongarm->value = '1';
  $export['node_expire_handle_content_expiry'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_expire_max_company';
  $strongarm->value = '';
  $export['node_expire_max_company'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_expire_ntypes';
  $strongarm->value = array(
    'company' => array(
      'enabled' => 1,
      'default' => '',
      'max' => '',
      'required' => 0,
    ),
  );
  $export['node_expire_ntypes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_expire_past_date_allowed';
  $strongarm->value = 1;
  $export['node_expire_past_date_allowed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_expire_required_company';
  $strongarm->value = 0;
  $export['node_expire_required_company'] = $strongarm;

  return $export;
}
