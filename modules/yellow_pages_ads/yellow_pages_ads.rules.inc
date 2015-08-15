<?php
/**
 * @file
 * Advertisement rules logic.
 */


/**
 * Defines ad's display rules form.
 */
function yellow_pages_ads_node_display_rules_form($form, &$form_state, $nid) {
  if (!isset($form_state['storage']['rules'])) {
    $form_state['storage']['rules'] = 1;
  }

  $form['rules_wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Rules'),
  );

  $form['rules_wrapper']['rules'] = array(
    '#tree' => TRUE,
    '#prefix' => '<div id="ads-rules-form">',
    '#suffix' => '</div>',
    '#theme' => array('yellow_pages_ads_rules_form'),
  );

  $existing_rules = variable_get('yellow_pages_ads_rules', array());
  $existing_rules = isset($existing_rules[$nid]) ? $existing_rules[$nid] : array();

  $num = count($existing_rules) + $form_state['storage']['rules'];

  for ($i = 0; $i < $num; $i++) {
    $default = isset($existing_rules[$i]) ? $existing_rules[$i] : array();
    $form['rules_wrapper']['rules'][] = _yellow_pages_ads_node_display_rules_form_chunk($default);
  }

  $form['rules_wrapper']['add_rule'] = array(
    '#type' => 'submit',
    '#value' => t('Add another'),
    '#submit' => array('yellow_pages_ads_node_display_rules_form_ajax_submit'),
    '#ajax' => array(
      'callback' => 'yellow_pages_ads_node_display_rules_form_ajax_callback',
      'method' => 'replace',
      'effect' => 'fade',
      'wrapper' => 'ads-rules-form',
    ),
  );

  $form['node_nid'] = array(
    '#type' => 'hidden',
    '#value' => $nid,
  );

  $form['save_rules'] = array(
    '#type' => 'submit',
    '#value' => t('Save display rules'),
  );

  return $form;
}

/**
 * Custom submit handler for ad's rules form.
 *
 * @see yellow_pages_ads_node_display_rules_form()
 */
function yellow_pages_ads_node_display_rules_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  $rules = array_filter($values['rules'], function($v) {
    return !empty($v['entity']);
  });

  $nid = $values['node_nid'];
  $existing_rules = variable_get('yellow_pages_ads_rules', array());
  $existing_rules[$nid] = $rules;
  variable_set('yellow_pages_ads_rules', $existing_rules);
}

/**
 * Custom ajax submit handler for new rule row.
 *
 * @see yellow_pages_ads_node_display_rules_form()
 */
function yellow_pages_ads_node_display_rules_form_ajax_submit($form, &$form_state) {
  $form_state['storage']['rules'] += 1;
  $form_state['rebuild'] = TRUE;
}

/**
 * Custom ajax callback handler for new rule row.
 *
 * @see yellow_pages_ads_node_display_rules_form()
 */
function yellow_pages_ads_node_display_rules_form_ajax_callback($form, &$form_state) {
  return $form['rules_wrapper']['rules'];
}

/**
 * Defines single rule row form structure.
 *
 * @param array $default
 *   Default values for the fields, if any.
 *
 * @return array
 *   Form structure.
 */
function _yellow_pages_ads_node_display_rules_form_chunk(array $default = array()) {
  $form_chunk = array();

  $form_chunk['rule'] = array(
    '#type' => 'select',
    '#options' => array(
      t('Hide'),
      t('Show'),
    ),
    '#default_value' => isset($default['rule']) ? $default['rule'] : 1,
  );

  $form_chunk['entity'] = array(
    '#type' => 'textfield',
    '#default_value' => isset($default['entity']) ? $default['entity'] : '',
    '#autocomplete_path' => 'yellow_pages_ads/autocomplete',
  );

  return $form_chunk;
}

/**
 * Overrides theme implementation, assembling rows in table view.
 *
 * @see yellow_pages_ads_theme()
 * @see yellow_pages_ads_node_display_rules_form()
 */
function theme_yellow_pages_ads_rules_form($elements) {
  $output = '';

  $header = array(
    t('Action'),
    t('Page'),
  );

  $rows = array();

  foreach (element_children($elements['element']) as $k => $v) {
    $rows[] = array(
      drupal_render($elements['element'][$k]['rule']),
      drupal_render($elements['element'][$k]['entity']),
    );
  }

  $output .= theme('table', array('header' => $header, 'rows' => $rows));

  return $output;
}

/**
 * Defines autocomplete handler.
 *
 * @param string $s
 *   User input string.
 *
 * @see yellow_pages_ads_menu()
 */
function yellow_pages_ads_autocomplete($s) {
  $skip_types = array(
    'advertisement',
  );

  $query = db_select('node', 'n');
  $query->fields('n', array('nid', 'title'));
  $query->condition('title', '%' . $s . '%', 'LIKE');
  $query->condition('type', $skip_types, 'NOT IN');
  $result = $query->execute()->fetchAll();

  $response = array();
  foreach ($result as $row) {
    $response[$row->title . ' [nid:' . $row->nid . ']'] = $row->title;
  }

  drupal_json_output($response);
}
