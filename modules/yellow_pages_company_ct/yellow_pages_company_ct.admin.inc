<?php
/**
 * @file
 * Company content type admin routine.
 */

/**
 * Form builder for the company content type settings.
 */
function yellow_pages_company_ct_settings_form($form, &$form_state) {

  $form['user_agreement_page_link_en'] = array(
    '#type' => 'textfield',
    '#title' => t('User agreement page link (eng)'),
    '#default_value' => variable_get('user_agreement_page_link_en', ''),
  );

  $form['user_agreement_page_link_ru'] = array(
    '#type' => 'textfield',
    '#title' => t('User agreement page link (rus)'),
    '#default_value' => variable_get('user_agreement_page_link_ru', ''),
  );

  $form['user_agreement_page_link_ro'] = array(
    '#type' => 'textfield',
    '#title' => t('User agreement page link (rom)'),
    '#default_value' => variable_get('user_agreement_page_link_ro', ''),
  );

  return system_settings_form($form);
}
