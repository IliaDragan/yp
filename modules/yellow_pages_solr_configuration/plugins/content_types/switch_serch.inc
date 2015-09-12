<?php
/**
 * @file
 * Switcher search.
 */

$plugin = array(
  'title' => t('Yellow pages switch search.'),
  'description' => t("Display block fot search switch."),
  'single' => TRUE,
  'category' => t('Yellow pages'),
  'render callback' => 'switch_search_content_type_render',
  'edit form' => 'switch_search_edit_form',
);

function switch_search_content_type_render($subtype, $conf, $panel_args, $context) {
  // Create a form with the radio buttons.
  $form = drupal_get_form('switch_search_form', $panel_args);

  $block = new stdClass();
  $block->content = $form;

  return $block;
}

function switch_search_form($form, &$form_state, $search_query) {
  $search_query = (empty($search_query)) ? '' : $search_query[0];
  $companies_url = l(t('Search companies'), 'search/companies/' . $search_query);
  $articles_url = l(t('Search content'), 'search/content/' . $search_query);
  $search_pages = array(
    'companies' => $companies_url,
    'content' => $articles_url,
  );

  $form = array(
    '#attached' => array(
      'js' => array(
        drupal_get_path('module', 'yellow_pages_solr_configuration') . '/js/switch_search.js'
      ),
    ),
  );
  $form['pages'] = array(
    '#type' => 'radios',
    '#required' => FALSE,
    '#options' => $search_pages,
    '#default_value' => arg(1),
  );

  return $form;
}

function switch_search_edit_form($form, &$form_state) {
  return $form;
}
