<?php
/**
 * @file
 * yellow_pages_statistics.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function yellow_pages_statistics_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'zend_path';
  $strongarm->value = 'profiles/yp/libraries/zend/library/Zend';
  $export['zend_path'] = $strongarm;

  return $export;
}
