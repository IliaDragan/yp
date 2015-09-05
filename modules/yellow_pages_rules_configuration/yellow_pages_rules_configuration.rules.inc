<?php
/**
 * @file
 * Custom rule.
 */

/**
 * Implements hook_rules_condition_info().
 */
function yellow_pages_rules_configuration_rules_condition_info() {
  return array(
    'yellow_pages_rules_configuration_check_node_10_days' => array(
      'label' => t('Check if node expire in 10 days.'),
      'module' => 'yellow_pages_rules_configuration',
      'arguments' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Content'),
        ),
      ),
    ),
  );
}

/**
 * Check if node will expire in 10 days.
 */
function yellow_pages_rules_configuration_check_node_10_days($node) {
  $tod_plus_10_days = date('Y-m-d', mktime(0, 0, 0) + (10 * 24 * 60 * 60));
  $check = (!empty($node->expire) && $node->expire == $tod_plus_10_days);
  return $check;
}

/**
 * Implements hook_rules_event_info().
 */
function yellow_pages_rules_configuration_rules_event_info() {
  $event = array(
    'node_expire_in_10_days' => array(
      'label' => t('Content expire in 10 days'),
      'group' => t('Node'),
      'variables' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
        ),
      ),
    ),
  );

  return $event;
}
