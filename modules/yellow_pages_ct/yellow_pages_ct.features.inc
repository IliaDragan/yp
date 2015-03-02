<?php
/**
 * @file
 * yellow_pages_ct.features.inc
 */

/**
 * Implements hook_node_info().
 */
function yellow_pages_ct_node_info() {
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
