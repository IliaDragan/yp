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
    'yellow_pages_rules_configuration_advert_publish' => array(
      'label' => t('Check if advert should be published.'),
      'module' => 'yellow_pages_rules_configuration',
      'arguments' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Content'),
        ),
      ),
    ),
    'yellow_pages_rules_configuration_advert_expire_week' => array(
      'label' => t('Check if advert expire in week.'),
      'module' => 'yellow_pages_rules_configuration',
      'arguments' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Content'),
        ),
      ),
    ),
    'yellow_pages_rules_configuration_advert_expire_day' => array(
      'label' => t('Check if advert expire in day.'),
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
 * Check if advert should be published.
 *
 * @param $node
 * @return bool
 */
function yellow_pages_rules_configuration_advert_publish($node) {
  $ad_schedule = field_get_items('node', $node, 'field_ad_schedule');
  $publish_date = strtotime($ad_schedule[0]['value']);
  $tod = date('Y-m-d', mktime(0, 0, 0));
  $check = (!empty($publish_date) && $publish_date == $tod);
  return $check;
}

/**
 * Check if advert expire in week.
 *
 * @param $node
 * @return bool
 */
function yellow_pages_rules_configuration_advert_expire_week($node) {
  $ad_schedule = field_get_items('node', $node, 'field_ad_schedule');
  $unpublish_date = strtotime($ad_schedule[0]['value2']);
  $tod_plus_week = mktime(0, 0, 0) + (7 * 24 * 60 * 60);
  $check = (!empty($unpublish_date) && $unpublish_date == $tod_plus_week);
  return $check;
}

/**
 * Check if advert expire in day.
 *
 * @param $node
 * @return bool
 */
function yellow_pages_rules_configuration_advert_expire_day($node) {
  $ad_schedule = field_get_items('node', $node, 'field_ad_schedule');
  $unpublish_date = strtotime($ad_schedule[0]['value2']);
  $tod_plus_day = mktime(0, 0, 0) + (24 * 60 * 60);
  $check = (!empty($unpublish_date) && $unpublish_date == $tod_plus_day);
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
    'advert_publish' => array(
      'label' => t('Publish advert'),
      'group' => t('Node'),
      'variables' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
        ),
      ),
    ),
    'advert_expire_in_week' => array(
      'label' => t('Advert expire in week'),
      'group' => t('Node'),
      'variables' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
        ),
      ),
    ),
    'advert_expire_in_day'  => array(
      'label' => t('Advert expire in day'),
      'group' => t('Node'),
      'variables' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
        ),
      ),
    ),
    'logo_expire_in_week' => array(
      'label' => t('Logo expire in week'),
      'group' => t('Node'),
      'variables' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Node'),
        ),
      ),
    ),
    'logo_expire_in_day'  => array(
      'label' => t('Logo expire in day'),
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

/**
 * Implement hook_rules_action_info().
 */
function yellow_pages_rules_configuration_rules_action_info() {
  return array(
    'yellow_pages_rules_configuration_verify_logo_expiration_date' => array(
      'label' => t('Verify logo expiration date'),
      'group' => t('Node'),
    ),
    'yellow_pages_rules_configuration_verify_node_expire_10_days' => array(
      'label' => t('Verify node expire in 10 days'),
      'group' => t('Node'),
    ),
  );
}

/**
 * Rules action callback.
 *
 * This function verify logo expiration dates and invokes corresponding event.
 */
function yellow_pages_rules_configuration_verify_logo_expiration_date() {
  $tod_plus_week = date('Y-m-d', strtotime('+1 week')) . ' 00:00:00';
  $tod_plus_day = date('Y-m-d', strtotime('+1 day')) . ' 00:00:00';

  // Verify nodes whose logo expire in a week.
  $query_week = db_select('field_data_field_logo_expiration_date', 'd')
    ->fields('d', array('entity_id'))
    ->condition('d.entity_type', 'node')
    ->condition('d.field_logo_expiration_date_value', $tod_plus_week);
  $result = $query_week->execute();

  foreach ($result as $record) {
    $node = node_load($record->entity_id);
    rules_invoke_event('logo_expire_in_week', $node);
  }

  // Verify nodes whose logo expire in a day.
  $query_day = db_select('field_data_field_logo_expiration_date', 'd')
    ->fields('d', array('entity_id'))
    ->condition('d.entity_type', 'node')
    ->condition('d.field_logo_expiration_date_value', $tod_plus_day);
  $result = $query_day->execute();

  foreach ($result as $record) {
    $node = node_load($record->entity_id);
    rules_invoke_event('logo_expire_in_day', $node);
  }
}

/**
 * Rules action callback.
 *
 * This function verify nodes expiration dates and invokes corresponding event.
 */
function yellow_pages_rules_configuration_verify_node_expire_10_days() {
  $tod = mktime(0, 0, 0);

  $query = db_select('node', 'n')
    ->fields('n', array('nid'));
  $query->innerJoin('node_expire', 'ne', 'ne.nid = n.nid');
  $query->condition('ne.expire', strtotime('+10 day', $tod));
  $result = $query->execute();

  foreach ($result as $record) {
    $node = node_load($record->nid);
    rules_invoke_event('node_expire_in_10_days', $node);
  }
}
