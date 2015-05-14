<?php
/**
 * @file
 * yellow_pages_taxonomy.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function yellow_pages_taxonomy_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-category-menu.
  $menus['menu-category-menu'] = array(
    'menu_name' => 'menu-category-menu',
    'title' => 'Category menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Category menu');


  return $menus;
}
