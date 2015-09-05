<?php
/**
 * @file
 * yellow_pages_nodeviewcount.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function yellow_pages_nodeviewcount_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_:admin/structure/pages/%/operation/%
  $menu_links['management_:admin/structure/pages/%/operation/%'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/structure/pages/%/operation/%',
    'router_path' => 'admin/structure/pages/%/operation/%',
    'link_title' => '',
    'options' => array(
      'identifier' => 'management_:admin/structure/pages/%/operation/%',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
    'parent_identifier' => 'management_pages:admin/structure/pages',
  );


  return $menu_links;
}
