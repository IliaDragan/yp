<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_preprocess_page().
 */
function yellow_pages_preprocess_page(&$variables) {
  $status = drupal_get_http_header("status");
  $variables['page']['main_menu'] = menu_tree('main-menu');

  if($status == "404 Not Found") {
    $variables['theme_hook_suggestions'][] = 'page__404';
  }
    if($status == "403 Forbidden") {
    $variables['theme_hook_suggestions'][] = 'page__403';
  }
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

/**
 * Implements hook_preprocess_node().
 */
function yellow_pages_preprocess_node(&$vars) {
  $vars['classes_array'][] = 'node--' . $vars['type'] . '--' . $vars['view_mode'];
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__' . $vars['view_mode'];
}

/**
 * Implements hook_preprocess_field().
 */
function yellow_pages_preprocess_field(&$vars) {
  $vars['theme_hook_suggestions'][] = 'field__' . $vars['element']['#field_name'] . '__' . $vars['element']['#view_mode'];
}

/**
 * Implements hook_preprocess_menu_link().
 */
function yellow_pages_preprocess_menu_link(&$variables) {
  if ($variables['theme_hook_original'] == 'menu_link__menu_category_menu') {
    $variables['prefix'] = '<span>';
    $variables['suffix'] = '</span>';
  }
}

function yellow_pages_menu_link(array $variables) {
  $element = $variables ['element'];
  $sub_menu = '';
  if ($element ['#below']) {
    $sub_menu = drupal_render($element ['#below']);
  }
  $prefix = isset($variables['prefix']) ? $variables['prefix'] : '';
  $suffix = isset($variables['suffix']) ? $variables['suffix'] : '';
  if ($suffix || $prefix) {
    $element ['#localized_options']['html'] = TRUE;
  }
  $output = l($prefix . $element ['#title'] . $suffix, $element ['#href'], $element ['#localized_options']);
  return '<li' . drupal_attributes($element ['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

function yellow_pages_preprocess_region(&$variables) {
  if ($variables['region'] == 'header') {
  }
}

function yellow_pages_css_alter(&$css) {
  // Exclude all the unused core and modules css.
    $exclude = array(
      'profiles/yp/modules/contrib/addressfield/addressfield.css' => FALSE,
    );
    $css = array_diff_key($css, $exclude);
  }