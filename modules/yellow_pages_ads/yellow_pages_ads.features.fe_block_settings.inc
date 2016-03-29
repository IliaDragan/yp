<?php
/**
 * @file
 * yellow_pages_ads.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function yellow_pages_ads_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-adsense_company_300_250'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'adsense_company_300_250',
    'module' => 'block',
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

  $export['block-adsense_front_468_60_left'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'adsense_front_468_60_left',
    'module' => 'block',
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

  $export['block-adsense_front_468_60_right'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'adsense_front_468_60_right',
    'module' => 'block',
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

  $export['block-adsense_news_728_90_first'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'adsense_news_728_90_first',
    'module' => 'block',
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

  $export['block-adsense_news_728_90_second'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'adsense_news_728_90_second',
    'module' => 'block',
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

  $export['block-adsense_search_300_250'] = array(
    'cache' => -1,
    'custom' => 0,
    'machine_name' => 'adsense_search_300_250',
    'module' => 'block',
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
