<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_preprocess_page().
 */
function yellow_pages_preprocess_page(&$variables) {
  $variables['page']['main_menu'] = menu_tree('main-menu');
}

/**
 * Implements hook_preprocess_hook().
 */
function yellow_pages_preprocess_yp_onecol_100(&$variables) {
  if (drupal_is_front_page()) {
    $form = drupal_get_form('search_block_form');
    $search_box = drupal_render($form);
    $variables['search_box'] = $search_box;
  }
}

/**
 * Implements hook_preprocess_views_view().
 */
function yellow_pages_preprocess_views_view(&$vars) {
  // Add specific scripts and styles for news carousel.
  if ($vars['name'] == 'news' && $vars['display_id'] == 'panel_pane_1') {
    $path = drupal_get_path('theme', 'yellow_pages');
    drupal_add_js($path . '/js/owl.carousel.min.js');
    drupal_add_css($path . '/css/owl.carousel.css');
  }
}