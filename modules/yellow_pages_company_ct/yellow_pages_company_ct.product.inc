<?php
/**
 * @file
 * Provides custom product field functionality.
 */

/**
 * Callback function that creates custom products fieldset.
 *
 * @param $products
 *   Products default values.
 *
 * @return array
 *   Form fieldset element renderable array.
 */
function yellow_pages_company_ct_product_subform($products) {
  module_load_include('inc', 'yellow_pages_company_ct', 'yellow_pages_company_ct.fields');

  $subform = array(
    '#type' => 'fieldset',
    '#title' => t('Products and services'),
    '#tree' => TRUE,
    '#weight' => 10,
    '#theme' => 'yellow_pages_products_form',
    '#prefix' => '<div id="products-add-more-wrapper">',
    '#suffix' => '</div>',
    '#attributes' => array(
      'class' => array('edit-products-fieldset')
    ),
    'add_more' => array(
      '#type' => 'submit',
      '#value' => t('Add more'),
      '#name' => 'products_add_more',
      '#submit' => array('yellow_pages_company_ct_company_edit_ajax_submit'),
      '#ajax' => array(
        'wrapper' => 'products-add-more-wrapper',
        'callback' => 'yellow_pages_company_ct_field_product_add_more_js',
        'method' => 'replace',
        'effect' => 'fade',
      ),
      '#attributes' => array(
        'class' => array('field-add-more-submit'),
      ),
    ),
  );

  $product_activity_list = _yp_product_activity_options_list();

  $i = 0;
  foreach ($products as $tid => $product) {
    $subform[$i] = array(
      '#type' => 'fieldset',
      'remove' => array(
        '#type' => 'submit',
        '#value' => t('Remove'),
        '#name' => 'remove-product-' . $i,
        '#submit' => array('yellow_pages_company_ct_company_edit_ajax_submit'),
        '#ajax' => array(
          'wrapper' => 'products-add-more-wrapper',
          'callback' => 'yellow_pages_company_ct_field_product_add_more_js',
          'method' => 'replace',
          'effect' => 'fade',
        ),
      ),
      'product_name' => array(
        '#type' => 'textfield',
        '#title' => '',
        '#size' => 40,
        '#autocomplete_path' => 'yp/editor_autocomplete/product',
        '#default_value' => $product['product_name'],
      ),
    );
    foreach ($product_activity_list as $key => $activity) {
      $subform[$i][$key] = array(
        '#type' => 'checkbox',
        '#title' => ' ',
        '#default_value' => (empty($product[$key]) ? FALSE : TRUE),
      );
    }
    $i++;
  }

  // Add empty field for new product.
  $field = array(
    '#type' => 'fieldset',
    'remove' => array(
      '#type' => 'submit',
      '#value' => t('Remove'),
      '#name' => 'remove-product-' . $i,
      '#submit' => array('yellow_pages_company_ct_company_edit_ajax_submit'),
      '#ajax' => array(
        'wrapper' => 'products-add-more-wrapper',
        'callback' => 'yellow_pages_company_ct_field_product_add_more_js',
        'method' => 'replace',
        'effect' => 'fade',
      ),
    ),
    'product_name' => array(
      '#type' => 'textfield',
      '#title' => '',
      '#size' => 40,
      '#autocomplete_path' => 'yp/editor_autocomplete/product',
      '#default_value' => '',
    ),
  );

  foreach ($product_activity_list as $key => $activity) {
    $field[$key] = array(
      '#type' => 'checkbox',
      '#title' => ' ',
      '#default_value' => FALSE,
    );
  }
  $subform[$i] = $field;

  return $subform;
}

/**
 * Returns HTML for products form fieldset element.
 *
 *  @param $variables
 *   An associative array containing:
 *   - form: Products fieldset form element.
 *
 * @ingroup themeable
 */
function theme_yellow_pages_products_form($variables) {
  module_load_include('inc', 'yellow_pages_company_ct', 'yellow_pages_company_ct.fields');
  $product_activity_list = _yp_product_activity_options_list();

  $header = array(
    '',
    t('Products and services')
  );
  foreach ($product_activity_list as $activity) {
    $header[] = array(
      'data' => $activity,
      'class' => array('activity-cell'),
    );
  }

  $rows = array();
  foreach ($variables['form'] as $tid => $fieldset) {
    if (is_int($tid)) {
      $row = array(
        drupal_render($fieldset['remove']),
        drupal_render($fieldset['product_name']),
      );
      foreach ($product_activity_list as $key => $activity) {
        $row[] = array(
          'data' => drupal_render($fieldset[$key]),
          'class' => array('activity-cell'),
        );
      }
      $rows[] = $row;
    }
  }
  $products = theme('table', array('rows' => $rows, 'header' => $header));
  $add_more = drupal_render($variables['form']['add_more']);

  return $products . $add_more;
}

/**
 * Provides product terms suggestons for enterprise editor.
 *
 * @param string $input
 *   String to search related terms on.
 */
function _products_autocomplete_editor($input) {
  global $language;

  $query = db_select('taxonomy_term_data', 't')
    ->fields('t', array('name'));
  $query->join('field_data_field_product_type', 'fpt', 't.tid = fpt.entity_id');
  $query->condition('fpt.field_product_type_value', YP_TERM_TYPE_PRODUCT, '=');

  if ($language->language == 'ro') {
    $query->join('i18n_string', 'i18n', "t.tid = i18n.objectid AND i18n.textgroup = 'taxonomy'");
    $query->join('locales_target', 'lt', "i18n.lid = lt.lid AND lt.language = 'ro'");
    $query->addExpression("CAST(lt.translation AS CHAR(10000) CHARACTER SET utf8)", 'translated_name');
    $query->havingCondition('translated_name', '%' . db_like($input) . '%', 'LIKE');
  }
  else {
    $query->condition('t.name', '%' . db_like($input) . '%', 'LIKE');
  }
  $query->range(0, 10);
  $result = $query->execute()->fetchAll();

  $response = array();

  foreach ($result as $r) {
    $name = empty($r->translated_name) ? $r->name : $r->translated_name;
    $response[$name] = $name;
  }

  echo drupal_json_output($response);
  drupal_exit(0);
}

/**
 * Ajax callback for products field "add more" submit.
 */
function yellow_pages_company_ct_field_product_add_more_js($form, $form_state) {
  return $form['products'];
}

/**
 * Transforms products from node entity to products values array.
 *
 * @param $node
 *   Company node object.
 *
 * @return array
 *   Products values array.
 */
function yellow_pages_company_ct_parse_products_from_node($node) {
  global $language;

  $products = array();
  foreach ($node->field_products[LANGUAGE_NONE] as $key => $product) {
    $tid = $product['product'];

    if (empty($products[$tid])) {
      $term = taxonomy_term_load($tid);
      $name = i18n_taxonomy_term_name($term, $language->language);
      $products[$tid] = array(
        'product_name' => $name,
      );
    }
    $source = $product['product_source'];
    $products[$tid][$source] = TRUE;
  }

  return $products;
}

/**
 * Creates products table for user view.
 *
 * @param $source
 *   Node object or $products form values.
 *
 * @param string $from
 *   Indicates from what source will $products be parsed ('node' or 'values').
 */
function yellow_pages_company_ct_products_view($source, $from = 'node') {
  module_load_include('inc', 'yellow_pages_company_ct', 'yellow_pages_company_ct.fields');
  $product_activity_list = _yp_product_activity_options_list();

  if ($from == 'node') {
    $products = yellow_pages_company_ct_parse_products_from_node($source);
  }
  else {
    $products = $source;
  }

  $header = array(
    array(
      'data' => t('Product'),
      'style' => "font-size: 10px; border: 1px solid #444444; padding: 2px 3px;",
    ),
  );
  foreach ($product_activity_list as $activity) {
    $header[] = array(
      'data' => $activity,
      'style' => "font-size: 10px; border: 1px solid #444444; padding: 2px 3px;",
    );
  }

  $rows = array();
  foreach ($products as $tid => $product) {
    $row = array(
      array(
        'data' => $product['product_name'],
        'style' => "font-size: 10px; border: 1px solid #444444; padding: 2px 3px;",
      ),
    );
    foreach ($product_activity_list as $key => $activity) {
      $row[] = array(
        'data' => (empty($product[$key]) ? '&#9744;' : '&#9745;'),
        'style' => "border: 1px solid #444444; text-align: center;",
      );
    }
    $rows[] = $row;
  }
  $attr = array(
    'style' => "border-collapse: collapse; width: 100%;",
  );
  return theme('table', array('rows' => $rows, 'header' => $header, 'attributes' => $attr));
}
