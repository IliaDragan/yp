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
    'yellow_pages_rules_configuration_logo_expire_week' => array(
      'label' => t('Check if logo expire in week.'),
      'module' => 'yellow_pages_rules_configuration',
      'arguments' => array(
        'node' => array(
          'type' => 'node',
          'label' => t('Content'),
        ),
      ),
    ),
    'yellow_pages_rules_configuration_logo_expire_day' => array(
      'label' => t('Check if logo expire in day.'),
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
 * Check if logo expire in week.
 *
 * @param $node
 * @return bool
 */
function yellow_pages_rules_configuration_logo_expire_week($node) {
  $logo_expiration_date = field_get_items('node', $node, 'field_logo_expiration_date');
  if (!empty($logo_expiration_date[0]['value'])) {
    $exp_date = $logo_expiration_date[0]['value'];
  }
  $tod_plus_week = date('Y-m-d', strtotime('+1 week')) . ' 00:00:00';
  $check = (!empty($exp_date) && $exp_date == $tod_plus_week);

  return $check;
}

/**
 * Check if logo expire in day.
 *
 * @param $node
 * @return bool
 */
function yellow_pages_rules_configuration_logo_expire_day($node) {
  $logo_expiration_date = field_get_items('node', $node, 'field_logo_expiration_date');
  if (!empty($logo_expiration_date[0]['value'])) {
    $exp_date = $logo_expiration_date[0]['value'];
  }
  $tod_plus_day = date('Y-m-d', strtotime('+1 day')) . ' 00:00:00';
  $check = (!empty($exp_date) && $exp_date == $tod_plus_day);

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
