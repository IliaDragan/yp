<?php
/**
 * @file
 * yellow_pages_statistics.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function yellow_pages_statistics_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access yellow pages google analytics page'.
  $permissions['access yellow pages google analytics page'] = array(
    'name' => 'access yellow pages google analytics page',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'yellow_pages_statistics',
  );

  // Exported permission: 'access yellow pages node statistics'.
  $permissions['access yellow pages node statistics'] = array(
    'name' => 'access yellow pages node statistics',
    'roles' => array(
      'administrator' => 'administrator',
      'global editor' => 'global editor',
    ),
    'module' => 'yellow_pages_statistics',
  );

  // Exported permission: 'access yellow pages search statistics'.
  $permissions['access yellow pages search statistics'] = array(
    'name' => 'access yellow pages search statistics',
    'roles' => array(
      'administrator' => 'administrator',
      'global editor' => 'global editor',
    ),
    'module' => 'yellow_pages_statistics',
  );

  // Exported permission: 'administer yellow pages statistics'.
  $permissions['administer yellow pages statistics'] = array(
    'name' => 'administer yellow pages statistics',
    'roles' => array(),
    'module' => 'yellow_pages_statistics',
  );

  return $permissions;
}
