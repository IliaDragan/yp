<?php
/**
 * @file
 * yellow_pages_solr_configuration.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function yellow_pages_solr_configuration_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_facets_search_ids';
  $strongarm->value = array(
    'company_nodes' => array(
      'search_api_views:solr_views:solr_node_search' => 'search_api_views:solr_views:solr_node_search',
      'search_api_views:solr_views:panel_pane_1' => 'search_api_views:solr_views:panel_pane_1',
      'search_api_views:solr_views:panel_pane_2' => 'search_api_views:solr_views:panel_pane_2',
    ),
  );
  $export['search_api_facets_search_ids'] = $strongarm;

  return $export;
}
