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

  // Exported menu: menu-product-menu.
  $menus['menu-product-menu'] = array(
    'menu_name' => 'menu-product-menu',
    'title' => 'Product menu',
    'description' => 'Automated menu items based on product terms.',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Automated menu items based on product terms.');
  t('Product menu');

  return $menus;
}
