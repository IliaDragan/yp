<?php
/**
 * @file
 * yellow_page_nodeviewcount.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function yellow_page_nodeviewcount_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeviewcount_flush_log_timer';
  $strongarm->value = '0';
  $export['nodeviewcount_flush_log_timer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeviewcount_node_types';
  $strongarm->value = array(
    'company' => 'company',
    'news' => 0,
  );
  $export['nodeviewcount_node_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeviewcount_node_view_modes';
  $strongarm->value = array(
    'full' => 0,
    'teaser' => 0,
    'rss' => 0,
    'search_index' => 0,
    'search_result' => 0,
  );
  $export['nodeviewcount_node_view_modes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeviewcount_user_roles';
  $strongarm->value = array(
    1 => '1',
    2 => '2',
    4 => '4',
    5 => '5',
    3 => 0,
  );
  $export['nodeviewcount_user_roles'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'nodeviewcount_way_counting';
  $strongarm->value = '0';
  $export['nodeviewcount_way_counting'] = $strongarm;

  return $export;
}
