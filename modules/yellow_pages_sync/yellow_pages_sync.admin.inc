<?php
/**
 * @file
 * Sync admin routine.
 */

/**
 * Admin form structure.
 */
function yellow_pages_sync_admin_form($form, $form_state) {
  $form['options_wrapper'] = array(
    '#type' => 'fieldset',
    '#title' => t('Sync options'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['options_wrapper']['options'] = array(
    '#type' => 'checkboxes',
    '#options' => array(
      'taxonomy' => t('Categories/Products'),
      'nodes' => t('Enterprises'),
      'filials' => t('Filials linkage'),
      'logos' => t('Logos'),
    ),
    '#default_value' => array(
      'taxonomy',
      'nodes',
      'filials',
      'logos',
    ),
  );

  $form['page'] = array(
    '#type' => 'textfield',
    '#title' => t('Page'),
    '#description' => t('Start fetching enterprises from this page.'),
    '#default_value' => 1,
    '#element_validate' => array('element_validate_integer_positive'),
    '#size' => 5,
  );

  $form['page_only'] = array(
    '#type' => 'checkbox',
    '#title' => t('This page only'),
    '#description' => t('Sync enterprises from selected page only.'),
    '#default_value' => FALSE,
  );

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
  $input = $form_state['values'];
  $options = array_filter($input['options']);

  $arguments = array(
    'nodes' => array(
      array('page' => $input['page'], 'single' => $input['page_only']),
    ),
  );
  $operations = array();
  foreach ($options as $option) {
    $operations[] = array('yellow_pages_sync_' . $option, isset($arguments[$option]) ? $arguments[$option] : array());

    // Add a step when syncing taxonomy, to link with parents.
    if ($option == 'taxonomy') {
      $operations[] = array('yellow_pages_sync_taxonomy_parents', array());
    }
  }

  $batch = array(
    'operations' => $operations,
    'title' => t('Synchronizing with MDB data...'),
    'finished' => 'yellow_pages_sync_batch_finish',
  );

  if (!empty($operations)) {
    batch_set($batch);
  }
  else {
    drupal_set_message(t('Nothing selected.'), 'error');
  }
}
