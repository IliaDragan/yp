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
      'default_widget' => 'yp_product_field_products',
      'default_formatter' => 'yp_product_default',
      'property_type' => 'yp_product',
      'property_callbacks' => array('yellow_pages_company_ct_property_info_callback'),
    ),
  );
}

/**
 * Callback to alter the property info of yp_product fields.
 *
 * @see yellow_pages_company_ct_field_info()
 */
function yellow_pages_company_ct_property_info_callback(&$info, $entity_type, $field, $instance, $field_type) {
  $name = $field['field_name'];
  $property = &$info[$entity_type]['bundles'][$instance['bundle']]['properties'][$name];

  $property['type'] = ($field['cardinality'] != 1) ? 'list<yp_product>' : 'yp_product';
  $property['getter callback'] = 'entity_metadata_field_verbatim_get';
  $property['setter callback'] = 'entity_metadata_field_verbatim_set';
  $property['auto creation'] = 'yp_product_auto_creation';
  $property['property info'] = yp_product_data_property_info();

  unset($property['query callback']);
}

function yp_product_auto_creation($property_name, $context) {
  return yp_product_default_values($context['field'], $context['instance']);
}

function yp_product_default_values($field, $instance, array $product = array()) {
  $default_values = array();

  $context = array(
    'field' => $field,
    'instance' => $instance,
    'product' => $product,
  );
  drupal_alter('yp_product_default_values', $default_values, $context);

  return $default_values;
}

/**
 * Defines info for the properties of the yp_product field data structure.
 */
function yp_product_data_property_info($name = NULL) {
  // Build an array of basic property information for the product field.
  $properties = array(
    'product_source' => array(
      'label' => t('Product activity type'),
      'options list' => '_yp_product_activity_options_list',
      'type' => 'integer',
    ),
    'product' => array(
      'label' => t('Product term name'),
      'type' => 'taxonomy_term',
    ),
  );

  // Add the default values for each of the yp_product field properties.
  foreach ($properties as $key => &$value) {
    $value += array(
      'description' => !empty($name) ? t('!label of field %name', array('!label' => $value['label'], '%name' => $name)) : '',
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
    );
  }

  return $properties;
}

/**
 * Provides possible values for product source (activity).
 *
 * @return array
 *   Set of product sources.
 */
function _yp_product_activity_options_list($field = NULL, $instance = NULL) {
  return array(
    YP_PRODUCT_SELL => t('We sell'),
    YP_PRODUCT_BUY => t('We buy'),
    YP_PRODUCT_MANUFACTURE => t('Manufacture'),
    YP_PRODUCT_SERVICES => t('Service'),
    YP_PRODUCT_EXPORT => t('We export'),
  );
}

/**
 * Implements hook_field_widget_info().
 */
function yellow_pages_company_ct_field_widget_info() {
  return array(
    'yp_product_field_products' => array(
      'label' => t('Target products'),
      'field types' => array('yp_product'),
    ),
    'yp_product_field_categories' => array(
      'label' => t('Target categories'),
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
    case 'yp_product_field_products':
      $element['product_source'] = array(
        '#type' => 'select',
        '#title' => t('Activity'),
        '#default_value' => isset($items[$delta]['product_source']) ? $items[$delta]['product_source'] : '',
        '#options' => _yp_product_activity_options_list(),
        '#required' => $element['#required'],
      );

      $term = isset($items[$delta]['product']) ? taxonomy_term_load($items[$delta]['product']) : NULL;
      $element['product'] = array(
        '#type' => 'textfield',
        '#autocomplete_path' => 'yp/autocomplete/product',
        '#title' => t('Product'),
        '#default_value' => !empty($term) ? $term->name . ' [tid:' . $term->tid . ']' : '',
        '#required' => $element['#required'],
        '#size' => 64,
        '#attributes' => array('maxlength' => 255),
      );
      break;
    case 'yp_product_field_categories':
      $element['product_source'] = array(
        '#type' => 'hidden',
        '#value' => 0,
      );

      $term = isset($items[$delta]['product']) ? taxonomy_term_load($items[$delta]['product']) : NULL;
      $element['product'] = array(
        '#type' => 'textfield',
        '#autocomplete_path' => 'yp/autocomplete/category',
        '#title' => t('Category'),
        '#default_value' => !empty($term) ? $term->name . ' [tid:' . $term->tid . ']' : '',
        '#required' => $element['#required'],
        '#size' => 64,
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
    'yp_product_parent' => array(
      'label' => t('Parent category'),
      'field types' => array('yp_product'),
    ),
  );
}

/**
 * Implements hook_field_formatter_prepare_view().
 */
function yellow_pages_company_ct_field_formatter_prepare_view($entity_type, $entities, $field, $instances, $langcode, &$items, $displays) {
  foreach ($entities as $id => $entity) {
    $parents = array();
    $tids = array();
    foreach ($items[$id] as $delta => $item) {
      if (isset($item['product'])) {
        $tids[] = $item['product'];
      }
    }

    $terms = taxonomy_term_load_multiple($tids);

    foreach ($items[$id] as $delta => $item) {
      if (isset($item['product']) && isset($terms[$item['product']])) {
        $term = $terms[$item['product']];
        $items[$id][$delta]['taxonomy_term'] = $term;

        $parents = taxonomy_get_parents($term->tid);
        $items[$id][$delta]['top_most'] = end($parents);
      }
    }
  }
}

/**
 * Implements hook_field_formatter_view().
 */
function yellow_pages_company_ct_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  global $language;

  $element = array();
  $parents = array();
  $product_sources = _yp_product_activity_options_list();

  foreach ($items as $delta => $item) {
    if (isset($item['taxonomy_term'])) {
      $term = $item['taxonomy_term'];
      $top_most = $item['top_most'];

      switch ($display['type']) {
        case 'yp_product_default':
          // @todo
          // DRY
          $source = $product_sources[$item['product_source']];
          $uri = entity_uri('taxonomy_term', $term);
          $element[$delta] = array(
            '#type' => 'link',
            '#title' => $source . ': ' . i18n_taxonomy_term_name($term, $language->language),
            '#href' => $uri['path'],
            '#options' => $uri['options'],
          );

          break;
        case 'yp_product_parent':
          if ($top_most == false) {
            break;
          }
          // Do not display same parents more than once.
          if (in_array($top_most->tid, $parents)) {
            break;
          }

          $term = $top_most;
          $parents[] = $top_most->tid;
          // @todo
          // DRY
          $uri = entity_uri('taxonomy_term', $term);
          $element[$delta] = array(
            '#type' => 'link',
            '#title' => i18n_taxonomy_term_name($term, $language->language),
            '#href' => $uri['path'],
            '#options' => $uri['options'],
          );
          break;
      }
    }
  }

  return $element;
}
