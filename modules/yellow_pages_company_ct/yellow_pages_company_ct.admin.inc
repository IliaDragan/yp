<?php
/**
 * @file
 * Company content type admin routine.
 */

/**
 * Form builder for the company content type settings.
 */
function yellow_pages_company_ct_settings_form($form, &$form_state) {

  $form['user_agreement_page_link'] = array(
    '#type' => 'textfield',
    '#title' => t('User agreement page link'),
    '#default_value' => variable_get('user_agreement_page_link', ''),
  );

  return system_settings_form($form);
}
