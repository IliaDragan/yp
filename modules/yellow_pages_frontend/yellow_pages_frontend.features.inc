<?php
/**
 * @file
 * yellow_pages_frontend.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function yellow_pages_frontend_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function yellow_pages_frontend_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function yellow_pages_frontend_image_default_styles() {
  $styles = array();

  // Exported image style: node_list_image.
  $styles['node_list_image'] = array(
    'label' => 'Node list image (150x200)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 150,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: og_medium.
  $styles['og_medium'] = array(
    'label' => 'OpenGraph Medium',
    'effects' => array(
      4 => array(
        'name' => 'yellow_pages_frontend_image_background',
        'data' => array(
          'width' => 220,
          'height' => 220,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
