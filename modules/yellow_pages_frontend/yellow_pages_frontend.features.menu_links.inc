<?php
/**
 * @file
 * yellow_pages_frontend.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function yellow_pages_frontend_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_about-project:node/133649.
  $menu_links['main-menu_about-project:node/133649'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/133649',
    'router_path' => 'node/%',
    'link_title' => 'About project',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'main-menu_about-project:node/133649',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_articles:articles.
  $menu_links['main-menu_articles:articles'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'articles',
    'router_path' => 'articles',
    'link_title' => 'Articles',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_articles:articles',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_contacts:node/138594.
  $menu_links['main-menu_contacts:node/138594'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/138594',
    'router_path' => 'node/%',
    'link_title' => 'Contacts',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_contacts:node/138594',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: main-menu_products-and-services:search/companies.
  $menu_links['main-menu_products-and-services:search/companies'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'search/companies',
    'router_path' => 'search/companies',
    'link_title' => 'Products and services',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_products-and-services:search/companies',
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About project');
  t('Articles');
  t('Contacts');
  t('Products and services');

  return $menu_links;
}
