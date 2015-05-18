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
