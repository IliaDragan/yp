<?php

/**
 * @file
 * Hooks provided by the yellow_pages_sync module.
 */

/**
 * Allow modules to provide actions after node synchronized.
 *
 * @param object $entity
 *   The synced entity.
 *
 */
function hook_entity_sync_with_mdb($entity) {
  drupal_set_message(t('Entity @title was updated by synchronization.', array('@title' => $entity->title)));
}
