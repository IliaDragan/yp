<?php
/**
 * @file
 */

/**
 * Implements hook_field_formatter_info().
 */
function yellow_pages_core_field_formatter_info() {
  return array(
    'field_address_popup_map' => array(
      'label' => t('Google map'),
      'field types' => array('addressfield'),
    ),
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function yellow_pages_core_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  $field_view = field_view_field($entity_type, $entity, 'field_address');
  $geo_items = field_get_items($entity_type, $entity, 'field_geocode');

  if ($geo_items) {
    $geo_position = $geo_items[0]['lat'] . ',' . $geo_items[0]['lon'];
    $field_view['#prefix'] = '<div class="address-coordinates" data-coordinates="' . $geo_position . '">';
    $field_view['#suffix'] = '</div>';
    $field_view['#attached']['js'][] = drupal_get_path('module', 'yellow_pages_core') . '/js/yellow_pages_core-geomap.js';
  }

  return $field_view;
}
