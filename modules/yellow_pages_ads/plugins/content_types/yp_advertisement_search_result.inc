<?php
/**
 * @file
 * Advertisement plugin definition.
 */

$plugin = array(
  'title' => t('Advertisement (Search Result Context)'),
  'category' => t('YellowPages'),
  'description' => t('Displays advertisements based on search results'),
  'single' => TRUE,
  'render callback' => 'yellow_pages_ads_search_result_plugin_render',
  'edit form' => 'yellow_pages_ads_search_result_plugin_edit_form',
);

/**
 * Plugin edit form.
 */
function yellow_pages_ads_search_result_plugin_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  $form['ads_amount'] = array(
    '#type' => 'textfield',
    '#title' => t('Amount of ads to display'),
    '#default_value' => isset($conf['ads_amount']) ? $conf['ads_amount'] : YP_ADS_AMOUNT,
    '#element_validate' => array('element_validate_integer_positive'),
    '#size' => 3,
  );

  $field_ad_category = field_info_field('field_ad_category');
  $form['ads_category'] = array(
    '#type' => 'select',
    '#title' => t('Filter by category'),
    '#options' => $field_ad_category['settings']['allowed_values'],
    '#default_value' => isset($conf['ads_category']) ? $conf['ads_category'] : 'sidebar',
  );

  $form['ads_order'] = array(
    '#type' => 'select',
    '#title' => t('Ads order'),
    '#options' => array(
      'random' => t('Random'),
      'asc' => t('Ascending'),
      'desc' => t('Descending'),
    ),
    '#default_value' => isset($conf['ads_order']) ? $conf['ads_order'] : 'random',
  );

  return $form;
}

/**
 * Plugin edit form custom submit handler.
 *
 * @see yellow_pages_ads_plugin_edit_form()
 */
function yellow_pages_ads_search_result_plugin_edit_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  $form_state['conf']['ads_amount'] = $values['ads_amount'];
  $form_state['conf']['ads_category'] = $values['ads_category'];
  $form_state['conf']['ads_order'] = $values['ads_order'];
}

/**
 * Plugin render callback.
 */
function yellow_pages_ads_search_result_plugin_render($subtype, $conf, $panel_args, $context) {
  $amount = isset($conf['ads_amount']) ? $conf['ads_amount'] : YP_ADS_AMOUNT;
  $category = isset($conf['ads_category']) ? $conf['ads_category'] : 'sidebar';
  $order = isset($conf['ads_order']) ? $conf['ads_order'] : 'random';

  $view_result = drupal_static('yp_advertisement_view_result', array());
//   dump($view_result);

  $nodes = yellow_pages_ads_get_ads($amount, $category, $order);
  $content = yellow_pages_ads_create_content($nodes);

  $plugin_data = new stdClass();
  $plugin_data->title = t('Advertisement');
  $plugin_data->content = $content;

  return $plugin_data;
}
