<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_preprocess_page().
 */
function yellow_pages_preprocess_page(&$variables) {
  $block = module_invoke('locale', 'block_view', 'language');
  $variables['page']['language_switcher'] = $block['content'];
}

/**
 * Implements hook_preprocess_views_view().
 */
function yellow_pages_preprocess_views_view(&$vars) {
  // Add specific scripts and styles for news carousel.
  if ($vars['name'] == 'news' && $vars['display_id'] == 'default') {
    $path = drupal_get_path('theme', 'yellow_pages');
    drupal_add_js($path . '/js/owl.carousel.min.js');
    drupal_add_css($path . '/css/owl.carousel.css');
    drupal_add_css($path . '/css/news_carousel.css');
  }
}

/**
 * Implements hook_menu_link().
 */
function yellow_pages_menu_link(array $variables) {
  $element = $variables['element'];

  $element['#localized_options']['html'] = TRUE;
  $output = l('<span>' . $element['#title'] . '</span>', $element['#href'], $element['#localized_options']);

  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>\n";
}
