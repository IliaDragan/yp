<?php

function yellow_pages_company_ct_product_subform($products) {
  module_load_include('inc', 'yellow_pages_company_ct', 'yellow_pages_company_ct.fields');

  //var_dump($products);die;
  $subform = array(
    '#type' => 'fieldset',
    '#title' => 'Products',
    '#tree' => TRUE,
    '#theme' => 'yellow_pages_products_form',
    '#prefix' => '<div id="products-add-more-wrapper">',
    '#suffix' => '</div>',
    'add_more' => array(
      '#type' => 'submit',
      '#value' => t('Add more'),
      '#name' => 'products_add_more',
      '#submit' => array('yellow_pages_company_ct_company_edit_ajax_submit'),
      '#ajax' => array(
        'wrapper' => 'products-add-more-wrapper',
        'callback' => 'field_product_add_more_js',
        'method' => 'replace',
        'effect' => 'fade',
      ),
      '#attributes' => array(
        'class' => array ('field-add-more-submit'),
      ),
    ),
  );

  $product_activity_list = _yp_product_activity_options_list();

  $i = 0;
  foreach ($products as $tid => $product) {
    $subform[$i] = array(
      '#type' => 'fieldset',
      'product_name' => array(
        '#type' => 'textfield',
        '#title' => '',
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
    'product_name' => array(
      '#type' => 'textfield',
      '#title' => '',
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
  $subform[] = $field;

  return $subform;
}

//function products_add_more_submit(&$form, &$form_state) {
//  $form_state['rebuild'] = TRUE;
//}

function theme_yellow_pages_products_form($variables) {
  module_load_include('inc', 'yellow_pages_company_ct', 'yellow_pages_company_ct.fields');
  $product_activity_list = _yp_product_activity_options_list();


  $header = array(t('Product'));
  foreach ($product_activity_list as $activity) {
    $header[] = $activity;
  }

  $rows = array();
  foreach ($variables['form'] as $tid => $fieldset) {
    if (is_int($tid)) {
      $row = array(
        drupal_render($fieldset['product_name']),
      );
      foreach ($product_activity_list as $key => $activity) {
        $row[] = drupal_render($fieldset[$key]);
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

function field_product_add_more_js($form, $form_state) {
  return $form['products'];
}

function parse_products_from_node($node) {
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
