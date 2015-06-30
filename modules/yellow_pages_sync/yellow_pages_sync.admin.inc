<?php
/**
 * Sync admin routine.
 */

/**
 * Admin form structure.
 */
function yellow_pages_sync_admin_form($form, $form_state) {
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );

  return $form;
}

function yellow_pages_sync_admin_form_submit($form, &$form_state) {
  $conn = Database::getConnection('default', 'mdb');
  $query = $conn->select('enterprise_enterprise', 'ent');
  $query
  ->join('enterprise_title', 'ent_title', 'ent.id = ent_title.enterprise_id');
  $query
  ->fields('ent', array('activity'))
  ->fields('ent_title', array('title'))
  ->range(0, 1);

  $result = $query
  ->execute()
  ->fetchAll();

  foreach ($result as $ent) {
    if (empty($ent->title)) {
      continue;
    }

    $node = new stdClass();
    $node->type = 'company';
    $node->title = $ent->title;
    $node->language = 'en';
    //node_save($node);
  }
}

