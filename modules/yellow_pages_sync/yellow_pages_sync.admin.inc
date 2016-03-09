<?php
/**
 * @file
 * Sync admin routine.
 */

/**
 * For builder for the synchronisation routine.
 */
function yellow_pages_sync_admin_form($form, $form_state) {
  $form['source'] = array(
    '#type' => 'textfield',
    '#title' => t('Service URL'),
    '#required' => TRUE,
    '#default_value' => variable_get('yp_sync_source', SYNC_SOURCE),
    '#description' => t('NO trailing slash.'),
  );

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
    '#default_value' => array(),
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
 * Custom submit handler for the synchronisation routine.
 *
 * @see yellow_pages_sync_admin_form()
 */
function yellow_pages_sync_admin_form_submit($form, &$form_state) {
  $input = $form_state['values'];
  variable_set('yp_sync_source', trim($input['source']));
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
      $operations[] = array('yellow_pages_sync_taxonomy_force_parents', array());
    }
  }

  $batch = array(
    'operations' => $operations,
    'title' => t('Synchronizing with MDB data...'),
    'finished' => 'yellow_pages_sync_batch_finish',
  );

  if (!empty($operations)) {
    variable_set('i18n_string_source_language', 'ru');
    batch_set($batch);
  }
  else {
    drupal_set_message(t('Nothing selected.'), 'error');
  }
}
