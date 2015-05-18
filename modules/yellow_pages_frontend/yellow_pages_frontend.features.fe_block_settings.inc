<?php
/**
 * @file
 * yellow_pages_frontend.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function yellow_pages_frontend_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['locale-language'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'language',
    'module' => 'locale',
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
        'region' => 'header',
        'status' => 1,
        'theme' => 'yellow_pages',
        'weight' => -14,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['search-form'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'form',
    'module' => 'search',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'yellow_pages' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'yellow_pages',
        'weight' => -15,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-main'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'main',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'yellow_pages' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'yellow_pages',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['system-user-menu'] = array(
    'cache' => -1,
    'custom' => 0,
    'delta' => 'user-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'yellow_pages' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'yellow_pages',
        'weight' => -13,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  $export['yellow_pages_contacts-yp_contacts'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'yp_contacts',
    'module' => 'yellow_pages_contacts',
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
        'region' => 'aside_a',
        'status' => 1,
        'theme' => 'yellow_pages',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['yellow_pages_rates-yp_rates'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'yp_rates',
    'module' => 'yellow_pages_rates',
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
        'region' => 'aside_b',
        'status' => 1,
        'theme' => 'yellow_pages',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['yellow_pages_weather-yp_weather'] = array(
    'cache' => 8,
    'custom' => 0,
    'delta' => 'yp_weather',
    'module' => 'yellow_pages_weather',
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
        'region' => 'aside_c',
        'status' => 1,
        'theme' => 'yellow_pages',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
