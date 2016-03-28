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
      'label' => t('Popup map'),
      'field types' => array('addressfield'),
    )
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function yellow_pages_core_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  $field_view = field_view_field($entity_type, $entity, $field['field_name'], array('label' => $display['label']));
  if (!empty($field_view)) {
    $element = $field_view;

    $element[0]['#prefix'] = '<div class="addressfield-popup-map" data-nid="' . $entity->nid . '">';
    $element[0]['#suffix'] = '</div>';
    $element[0]['#attached']['js'][] = drupal_get_path('module', 'yellow_pages_core') . '/js/yellow_pages_core-geomap.js';
  }

  return $element;
}
