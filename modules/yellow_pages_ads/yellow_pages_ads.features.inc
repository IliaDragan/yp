<?php
/**
 * @file
 * yellow_pages_ads.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function yellow_pages_ads_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function yellow_pages_ads_node_info() {
  $items = array(
    'advertisement' => array(
      'name' => t('Advertisement'),
      'base' => 'node_content',
      'description' => t('Use this to create advertisement campaigns.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
