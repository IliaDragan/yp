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

  // Exported menu link: management_node-view-count-settings:admin/config/content/nodeviewcount
  $menu_links['management_node-view-count-settings:admin/config/content/nodeviewcount'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/nodeviewcount',
    'router_path' => 'admin/config/content/nodeviewcount',
    'link_title' => 'Node view count settings',
    'options' => array(
      'identifier' => 'management_node-view-count-settings:admin/config/content/nodeviewcount',
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
  // Exported menu link: management_node-view-count-statistics:admin/config/content/node-views-count-statistic
  $menu_links['management_node-view-count-statistics:admin/config/content/node-views-count-statistic'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/config/content/node-views-count-statistic',
    'router_path' => 'admin/config/content/node-views-count-statistic',
    'link_title' => 'Node view count statistics',
    'options' => array(
      'identifier' => 'management_node-view-count-statistics:admin/config/content/node-views-count-statistic',
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
  t('Node view count settings');
  t('Node view count statistics');


  return $menu_links;
}
