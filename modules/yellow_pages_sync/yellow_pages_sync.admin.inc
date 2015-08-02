<?php
/**
 * @file
 * Sync admin routine.
 */

/**
 * Admin form structure.
 */
function yellow_pages_sync_admin_form($form, $form_state) {
//   $node = node_load(229);
//   dump($node);
//   $term = taxonomy_term_load(40);
//   dump($term);

  $form['submit'] = array(
    '#type' => 'submit',
    '#prefix' => '<p>' . t('Import companies and products from MDB source.') . '</p>',
    '#value' => t('Start synchronisation'),
  );

  return $form;
}

/**
 *
 * @param unknown $form
 * @param unknown $form_state
 */
function yellow_pages_sync_admin_form_submit($form, &$form_state) {
  $batch = array(
    'operations' => array(
//       array('yellow_pages_sync_taxonomy', array()),
      array('yellow_pages_sync_nodes', array()),
    ),
    'title' => t('Synchronizing with MDB data...'),
    'finished' => 'yellow_pages_sync_batch_finish',
  );

  batch_set($batch);
}
