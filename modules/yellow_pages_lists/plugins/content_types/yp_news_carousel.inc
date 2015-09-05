<?php
/**
 * @file
 * Related articles plugin.
 */

$plugin = array(
  'title' => t('News carousel'),
  'category' => t('YellowPages'),
  'description' => t('Display latest news in carousel'),
  'single' => TRUE,
  'render callback' => 'yellow_pages_lists_news_carousel_plugin_render',
  'edit form' => 'yellow_pages_lists_news_carousel_plugin_edit_form',
);

function yellow_pages_lists_news_carousel_plugin_edit_form($form, &$form_state) {
  return $form;
}

function yellow_pages_lists_news_carousel_plugin_render($subtype, $conf, $panel_args, $context) {
  $plugin_data = new stdClass();
  $plugin_data->title = t('News');
  $plugin_data->content = yellow_pages_lists_news_carousel();

  return $plugin_data;
}
