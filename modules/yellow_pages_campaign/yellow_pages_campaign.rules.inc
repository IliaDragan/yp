<?php
/**
 * @file
 * Node display rules administration.
 */

/**
 * Define campaign rules form structure.
 */
function yellow_pages_campaign_node_rules_form($form, &$form_state, $node) {
  $entity = entity_metadata_wrapper('node', $node);

  $default_rules = yellow_pages_campaign_saved_rules($entity->nid->value());
  if (!isset($form_state['rules_count'])) {
    $form_state['rules_count'] = !empty($default_rules) ? count($default_rules) : 1;
  }

  $form['rules_wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Display rules for <em>@title</em>', array('@title' => $entity->title->value())),
  );

  $form['rules_wrapper']['rules_table'] = array(
    '#type' => 'container',
    '#prefix' => '<div id="yellow-pages-rules-table-wrapper">',
    '#suffix' => '</div>',
    '#tree' => TRUE,
    '#theme' => 'yp_campaign_rule_element',
  );

  for ($i = 0; $i < $form_state['rules_count']; $i++) {
    $default = (array) $default_rules[$i];
    $form['rules_wrapper']['rules_table'][] = yellow_pages_campaign_single_rule_form($default);
  }

  $form['rules_wrapper']['rules_new'] = array(
    '#type' => 'submit',
    '#value' => t('Add rule'),
    '#ajax' => array(
      'callback' => '_yp_campaign_rule_callback',
      'method' => 'replace',
      'effect' => 'fade',
      'wrapper' => 'yellow-pages-rules-table-wrapper',
    ),
    '#submit' => array('yellow_pages_campaign_node_rules_form_ajax_submit'),
  );

//   $form['rules_wrapper']['rules_info'] = array(
//     '#type' => 'item',
//     '#markup' => t('<em>Note: To remove a rule, clear it\'s value and save the form.</em>'),
//   );

  $form['rules_save'] = array(
    '#type' => 'submit',
    '#value' => t('Save rules'),
  );

  $form['rules_node'] = array(
    '#type' => 'hidden',
    '#value' => $entity->nid->value(),
  );

  $form['#attached']['css'][] = drupal_get_path('module', 'yellow_pages_campaign') . '/css/yellow_pages_campaign.styles.css';

  return $form;
}

/**
 * Custom submit handler for campaign rules form.
 *
 * @see yellow_pages_campaign_node_rules_form()
 */
function yellow_pages_campaign_node_rules_form_submit($form, &$form_state) {
  $input = $form_state['input'];
  $nid = $input['rules_node'];
  $rules = array();

  foreach ($input['rules_table'] as $rule) {
    if ($rule['rule_type'] != YP_RULE_GENERIC && empty($rule['rule_value'])) {
      continue;
    }

    $rules[] = $rule;
  }

  yellow_pages_campaign_rules_save($rules, $nid);
}

/**
 * Defines a single rule form elements structure.
 *
 * @param array $default
 *   Default values for the each element.
 *
 * @return array
 *   Elements for one rule.
 */
function yellow_pages_campaign_single_rule_form($default) {
  $form = array();
  $rules = yellow_pages_campaign_rules_list();

  $form['rule_type'] = array(
    '#type' => 'select',
    '#options' => $rules,
    '#default_value' => isset($default['rule']) ? $default['rule'] : '',
  );

  $form['rule_value'] = array(
    '#type' => 'textfield',
    '#default_value' => isset($default['value']) ? $default['value'] : '',
  );

  return $form;
}

/**
 * Theme hook override to rearrange fields in a table.
 *
 * @see yellow_pages_campaign_node_rules_form()
 * @see yellow_pages_campaign_theme()
 */
function theme_yp_campaign_rule_element($variables) {
  $element = $variables['element'];

  $header = array(
    t('Rule'),
    t('Value'),
  );

  $rows = array();

  foreach (element_children($element) as $k => $v) {
    $rows[] = array(
      'data' => array(
        drupal_render($element[$k]['rule_type']),
        drupal_render($element[$k]['rule_value']),
      ),
      'class' => array('yellow-pages-rule-row'),
    );
  }

  $table = array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array(
      'class' => array(
        'yellow-pages-rules-table',
      )
    ),
  );

  $output = theme('table', $table);
  $output .= drupal_render_children($element);

  return $output;
}

/**
 * Custom ajax callback for new rule button trigger.
 *
 * @see yellow_pages_campaign_node_rules_form()
 */
function _yp_campaign_rule_callback($form, &$form_state) {
  return $form['rules_wrapper']['rules_table'];
}

/**
 * Custom submit handler for new rule button trigger.
 *
 * @see yellow_pages_campaign_node_rules_form()
 */
function yellow_pages_campaign_node_rules_form_ajax_submit($form, &$form_state) {
  $form_state['rules_count']++;
  $form_state['rebuild'] = TRUE;
}
