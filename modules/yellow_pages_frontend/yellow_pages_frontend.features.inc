<?php
/**
 * @file
 * yellow_pages_frontend.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function yellow_pages_frontend_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function yellow_pages_frontend_image_default_styles() {
  $styles = array();

  // Exported image style: node_list_image.
  $styles['node_list_image'] = array(
    'name' => 'node_list_image',
    'label' => 'Node list image (150x200)',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
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
    'name' => 'og_medium',
    'label' => 'OpenGraph Medium',
    'effects' => array(
      4 => array(
        'label' => 'Фон',
        'help' => 'Background will make images an exact set of dimensions, placing scaled image in the center of bacground.',
        'effect callback' => 'yellow_pages_frontend_image_background_effect',
        'dimensions callback' => 'yellow_pages_frontend_image_background_dimensions',
        'form callback' => 'yellow_pages_frontend_image_background_form',
        'summary theme' => 'yellow_pages_frontend_image_background_summary',
        'module' => 'yellow_pages_frontend',
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
