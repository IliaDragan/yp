<?php
/**
 * @file
 * yellow_pages_company_ct.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function yellow_pages_company_ct_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function yellow_pages_company_ct_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function yellow_pages_company_ct_image_default_styles() {
  $styles = array();

  // Exported image style: company_gallery.
  $styles['company_gallery'] = array(
    'label' => 'Company gallery (185x185)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 185,
          'height' => 185,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
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
      'title_label' => t('Company name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
