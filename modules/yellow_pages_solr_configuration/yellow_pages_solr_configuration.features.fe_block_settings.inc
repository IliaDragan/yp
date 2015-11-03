<?php
/**
 * @file
 * yellow_pages_solr_configuration.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function yellow_pages_solr_configuration_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['simpleads-ad_groups_2'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'ad_groups_2',
    'module' => 'simpleads',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'yellow_pages' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'yellow_pages',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
