<?php
/**
 * @file
 * Sync admin routine.
 */

/**
 * Admin form structure.
 */
function yellow_pages_sync_admin_form($form, $form_state) {

//   $term = taxonomy_term_load(89);
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
//   $xml_file = drupal_get_path('module', 'yellow_pages_sync') . '/data/enterprises.xml';
//   $xml_data = file_get_contents($xml_file);

  $batch = array(
    'operations' => array(
//       array('yellow_pages_sync_taxonomy', array()),
//       array('yellow_pages_sync_nodes', array()),
      array('yellow_pages_sync_filials', array()),
    ),
    'title' => t('Synchronizing with MDB data...'),
    'finished' => 'yellow_pages_sync_batch_finish',
  );

  batch_set($batch);
}
