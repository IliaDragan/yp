<?php
/**
 * @file
 * yellow_page_nodeviewcount.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function yellow_page_nodeviewcount_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function yellow_page_nodeviewcount_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
