<?php
/**
 * @file
 * yellow_pages_rules_configuration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function yellow_pages_rules_configuration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
