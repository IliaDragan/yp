<?php
/**
 * @file
 * Advertisement plugin definition.
 */

$plugin = array(
  'title' => t('Advertisement'),
  'category' => t('YellowPages'),
  'description' => t('Displays advertisements'),
  'single' => TRUE,
  'render callback' => 'yellow_pages_ads_plugin_render',
  'edit form' => 'yellow_pages_ads_plugin_edit_form',
);

/**
 * Plugin edit form.
 */
function yellow_pages_ads_plugin_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['ads_amount'] = array(
    '#type' => 'textfield',
    '#title' => t('Amount of ads to display'),
    '#default_value' => isset($conf['ads_amount']) ? $conf['ads_amount'] : 3,
    '#element_validate' => array('element_validate_integer_positive'),
    '#size' => 3,
  );

  return $form;
}

/**
 * Plugin edit form custom submit handler.
 *
 * @see yellow_pages_ads_plugin_edit_form()
 */
function yellow_pages_ads_plugin_edit_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  $form_state['conf']['ads_amount'] = $values['ads_amount'];
}


/**
 * Plugin render callback.
 */
function yellow_pages_ads_plugin_render($subtype, $conf, $panel_args, $context) {
  $plugin_data = new stdClass();
  $plugin_data->title = t('Advertisement');
  $plugin_data->content = 'HOLA!';

  return $plugin_data;
}
