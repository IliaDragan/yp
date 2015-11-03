<?php
/**
 * @file
 * yellow_pages_article_ct.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function yellow_pages_article_ct_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: navigation_articles:articles
  $menu_links['navigation_articles:articles'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'articles',
    'router_path' => 'articles',
    'link_title' => 'Articles',
    'options' => array(
      'attributes' => array(
        'title' => 'List of articles',
      ),
      'identifier' => 'navigation_articles:articles',
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
  t('Articles');


  return $menu_links;
}
