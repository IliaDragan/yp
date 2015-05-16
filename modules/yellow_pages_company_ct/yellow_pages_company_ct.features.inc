<?php
/**
 * @file
 * yellow_pages_company_ct.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function yellow_pages_company_ct_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function yellow_pages_company_ct_node_info() {
  $items = array(
    'company' => array(
      'name' => t('Company'),
      'base' => 'node_content',
      'description' => t('CT contain company entity fields.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
