<?php
/**
 * @file
 * yellow_pages_company_ct.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function yellow_pages_company_ct_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access epostcard'.
  $permissions['access epostcard'] = array(
    'name' => 'access epostcard',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'forward',
  );

  // Exported permission: 'access forward'.
  $permissions['access forward'] = array(
    'name' => 'access forward',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'forward',
  );

  // Exported permission: 'access service links'.
  $permissions['access service links'] = array(
    'name' => 'access service links',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'service_links',
  );

  // Exported permission: 'administer forward'.
  $permissions['administer forward'] = array(
    'name' => 'administer forward',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'forward',
  );

  // Exported permission: 'override email address'.
  $permissions['override email address'] = array(
    'name' => 'override email address',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'forward',
  );

  // Exported permission: 'override flood control'.
  $permissions['override flood control'] = array(
    'name' => 'override flood control',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'forward',
  );

  // Exported permission: 'use PHP for service visibility'.
  $permissions['use PHP for service visibility'] = array(
    'name' => 'use PHP for service visibility',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'service_links',
  );

  // Exported permission: 'use products autocomplete'.
  $permissions['use products autocomplete'] = array(
    'name' => 'use products autocomplete',
    'roles' => array(
      'administrator' => 'administrator',
      'enterprise editor' => 'enterprise editor',
      'global editor' => 'global editor',
    ),
    'module' => 'yellow_pages_company_ct',
  );

  return $permissions;
}
