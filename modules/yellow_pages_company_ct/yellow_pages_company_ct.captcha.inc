<?php
/**
 * @file
 * yellow_pages_company_ct.captcha.inc
 */

/**
 * Implements hook_captcha_default_points().
 */
function yellow_pages_company_ct_captcha_default_points() {
  $export = array();

  $captcha = new stdClass();
  $captcha->disabled = FALSE; /* Edit this to true to make a default captcha disabled initially */
  $captcha->api_version = 1;
  $captcha->form_id = 'yellow_pages_company_ct_user_register_form';
  $captcha->module = 'captcha';
  $captcha->captcha_type = 'Math';
  $export['yellow_pages_company_ct_user_register_form'] = $captcha;

  return $export;
}
