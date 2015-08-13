<?php
/**
 * @file
 * Custom fields implementations.
 */

/**
 * Implements hook_field_info().
 */
function yellow_pages_company_ct_field_info() {
  return array(
    'yp_product' => array(
      'label' => t('Products'),
      'description' => t('Products related to this company.'),
      'default_widget' => 'yp_product_field',
      'default_formatter' => 'yp_product_default',
    ),
  );
}

/**
 * Implements hook_field_widget_info().
 */
function yellow_pages_company_ct_field_widget_info() {
  return array(
    'yp_product_field' => array(
      'label' => t('Products field'),
      'field types' => array('yp_product'),
    ),
  );
}

/**
 * Implements hook_field_settings_form().
 */
function yellow_pages_company_ct_field_settings_form($field, $instance, $has_data) {
  $settings = $field['settings'];

  $form = array();
  return $form;
}

/**
 * Implements hook_field_instance_settings_form().
 */
function yellow_pages_company_ct_field_instance_settings_form($field, $instance) {
  $settings = $instance['settings'];

  $form = array();
  return $form;
}

/**
 * Implements hook_field_widget_form().
 */
function yellow_pages_company_ct_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  switch ($instance['widget']['type']) {
    case 'yp_product_field':

      $element['product_source'] = array(
        '#type' => 'select',
        '#title' => t('Activity'),
        '#default_value' => isset($items[$delta]['product_source']) ? $items[$delta]['product_source'] : '',
        '#options' => array(
          YP_PRODUCT_SELL => t('We sell'),
          YP_PRODUCT_BUY => t('We buy'),
          YP_PRODUCT_MANUFACTURE => t('Manufacture'),
          YP_PRODUCT_SERVICES => t('Service'),
        ),
        '#required' => $element['#required'],
      );

      $term = isset($items[$delta]['product']) ? taxonomy_term_load($items[$delta]['product']) : NULL;
      $element['product'] = array(
        '#type' => 'textfield',
        '#autocomplete_path' => 'yp/autocomplete/product',
        '#title' => t('Product'),
        '#default_value' => !empty($term) ? $term->name . ' [tid:' . $term->tid . ']' : '',
        '#required' => $element['#required'],
        '#size' => 32,
        '#attributes' => array('maxlength' => 255),
      );
      break;
  }
  return $element;
}

/**
 * Implements hook_field_presave().
 */
function yellow_pages_company_ct_field_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
  foreach ($items as $delta => $item) {

    if (isset($item['product'])) {
      $matches = array();
      preg_match('/^.*\[tid:(\d+)\]$/', $item['product'], $matches);
      $tid = isset($matches[1]) ? $matches[1] : NULL;
      if (!empty($tid)) {
        $items[$delta]['product_source'] = $item['product_source'];
        $items[$delta]['product'] = $tid;
      }
    }
  }
}

/**
 * Implements hook_field_is_empty().
 */
function yellow_pages_company_ct_field_is_empty($item, $field) {
  if (empty($item['product'])) {
    return TRUE;
  }

  return FALSE;
}

/**
 * Implements hook_field_formatter_info().
 */
function yellow_pages_company_ct_field_formatter_info() {
  return array(
    'yp_product_default' => array(
      'label' => t('Default'),
      'field types' => array('yp_product'),
    ),
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function yellow_pages_company_ct_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  switch ($display['type']) {
    case 'yp_product_default':
      foreach ($items as $delta => $item) {
        if (isset($item['product'])) {
          $element[$delta]['#markup'] = $item['product_source'] . ' - ' . $item['product'];
        }
      }
      break;
  }

  return $element;
}
