<?php
/**
 * @file
* Related articles plugin.
*/

$plugin = array(
  'title' => t('Related companies'),
  'category' => t('YellowPages'),
  'description' => t('Displays related companies'),
  'single' => TRUE,
  'render callback' => 'yellow_pages_lists_related_companies_plugin_render',
  'edit form' => 'yellow_pages_lists_related_companies_plugin_edit_form',
  'required context' => new ctools_context_required(t('Node'), 'node'),
);

function yellow_pages_lists_related_companies_plugin_edit_form($form, &$form_state) {
  return $form;
}

function yellow_pages_lists_related_companies_plugin_render($subtype, $conf, $panel_args, $context) {
  $plugin_data = new stdClass();
  $plugin_data->title = t('Similar companies');
  $plugin_data->content = yellow_pages_lists_related_content('companies', $context->data);

  return $plugin_data;
}
