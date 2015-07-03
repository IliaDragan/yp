<?php
/**
 * @file
 * Sync admin routine.
 */

/**
 * Admin form structure.
 */
function yellow_pages_sync_admin_form($form, $form_state) {
//   $node = node_load(158);
//   dump($node);
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );

  return $form;
}

/**
 *
 * @param unknown $form
 * @param unknown $form_state
 */
function yellow_pages_sync_admin_form_submit($form, &$form_state) {
  yellow_pages_sync_nodes();
}
