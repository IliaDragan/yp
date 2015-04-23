<?php
/**
 * @file
 * Admin interface.
 */

/**
 * Contacts settings form.
 */
function yellow_pages_contacts_admin_form($form, &$form_state) {
  $form['yp_contacts_mail'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail'),
    '#default_value' => variable_get('yp_contacts_mail', ''),
    '#description' => t('Example: noreply@gmail.com'),
  );

  $form['yp_contacts_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Telephone'),
    '#default_value' => variable_get('yp_contacts_phone', ''),
    '#description' => t('Example: +373-22-123456'),
  );

  $form['yp_contacts_social'] = array(
    '#type' => 'textfield',
    '#title' => t('Social'),
    '#default_value' => variable_get('yp_contacts_social', ''),
    '#description' => t('Example: http://facebook.com'),
  );

  return system_settings_form($form);
}

function yellow_pages_contacts_admin_form_validate($form, &$form_state) {
  $input = $form_state['input'];

  if (!empty($input['yp_contacts_mail']) && !valid_email_address($input['yp_contacts_mail'])) {
    form_set_error('yp_contacts_mail', t('Provided email address is not valid.'));
  }

  if (!empty($input['yp_contacts_phone']) && !preg_match('/^\+(\d){3}\-(\d){2}\-(\d){6}$/', $input['yp_contacts_phone'])) {
    form_set_error('yp_contacts_phone', t('Provided phone number is not valid.'));
  }

  if (!empty($input['yp_contacts_social']) && !valid_url($input['yp_contacts_social'], TRUE)) {
    form_set_error('yp_contacts_social', t('Provided URL is not valid.'));
  }
}
