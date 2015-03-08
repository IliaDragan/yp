<?php
/**
 * @file
 * yellow_pages_campaign.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function yellow_pages_campaign_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function yellow_pages_campaign_node_info() {
  $items = array(
    'advertisement' => array(
      'name' => t('Advertisement'),
      'base' => 'node_content',
      'description' => t('Create ad\'s in a simple banner or campaign behavior.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
