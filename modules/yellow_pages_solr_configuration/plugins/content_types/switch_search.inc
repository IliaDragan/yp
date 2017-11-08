<?php
/**
 * @file
 * Switcher search.
 */

$plugin = array(
  'title' => t('Yellow pages switch search.'),
  'description' => t("Display block fot search switch."),
  'single' => TRUE,
  'category' => t('YellowPages'),
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
  $search_type = arg(1);

  $result_count = &drupal_static('yp_solr_hits', 0);

  $search_query = (empty($search_query)) ? '' : $search_query[0];
  $companies_link_text = t('Search companies');
  $content_link_text = t('Search content');
  if (!empty($result_count)) {
    ${$search_type . "_link_text"} .= " ($result_count)";
  }

  $companies_url = l($companies_link_text , 'search/companies/' . $search_query);
  $articles_url = l($content_link_text, 'search/content/' . $search_query);
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
    '#default_value' => $search_type,
  );

  return $form;
}

function switch_search_edit_form($form, &$form_state) {
  return $form;
}
