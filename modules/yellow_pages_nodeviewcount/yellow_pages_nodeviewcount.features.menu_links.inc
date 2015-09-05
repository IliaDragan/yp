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

  // Exported menu link: management_node-view-count-statistics:admin/config/content/node-views-count-statistics
  $menu_links['management_node-view-count-statistics:admin/config/content/node-views-count-statistics'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/node-views-count-statistics',
    'router_path' => 'admin/config/content/node-views-count-statistics',
    'link_title' => 'Node view count statistics',
    'options' => array(
      'identifier' => 'management_node-view-count-statistics:admin/config/content/node-views-count-statistics',
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
    'parent_identifier' => 'management_content-authoring:admin/config/content',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Node view count statistics');


  return $menu_links;
}
