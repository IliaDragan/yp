<?php
/**
 * @file
 * yellow_pages_email_configurations.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function yellow_pages_email_configurations_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'edit mimemail user settings'.
  $permissions['edit mimemail user settings'] = array(
    'name' => 'edit mimemail user settings',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'mimemail',
  );

  // Exported permission: 'send arbitrary files'.
  $permissions['send arbitrary files'] = array(
    'name' => 'send arbitrary files',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'mimemail',
  );

  return $permissions;
}
