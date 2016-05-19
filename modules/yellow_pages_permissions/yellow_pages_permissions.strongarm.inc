<?php
/**
 * @file
 * yellow_pages_permissions.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function yellow_pages_permissions_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'date_format_user_features';
  $strongarm->value = 'l, d F Y, H:i:s';
  $export['date_format_user_features'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_pictures';
  $strongarm->value = 0;
  $export['user_pictures'] = $strongarm;

  return $export;
}
