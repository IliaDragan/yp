<?php
/**
 * @file
 * yellow_pages_feedback.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function yellow_pages_feedback_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
