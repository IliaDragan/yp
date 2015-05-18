<?php
/**
 * @file
 * yellow_pages_news_ct.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function yellow_pages_news_ct_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_news:news
  $menu_links['navigation_news:news'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'news',
    'router_path' => 'news',
    'link_title' => 'News',
    'options' => array(
      'attributes' => array(
        'title' => 'List of news',
      ),
      'identifier' => 'navigation_news:news',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('News');


  return $menu_links;
}
