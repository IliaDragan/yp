<?php
/**
 * @file
 * yellow_pages_contacts.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function yellow_pages_contacts_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'yp_contacts_mail';
  $strongarm->value = 'inform@varo-inform.com';
  $export['yp_contacts_mail'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'yp_contacts_phone';
  $strongarm->value = '+373-22-737794';
  $export['yp_contacts_phone'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'yp_contacts_social';
  $strongarm->value = 'https://www.facebook.com/Varo-Inform-SRL-789837887694731/';
  $export['yp_contacts_social'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'yp_contacts_social_link_title';
  $strongarm->value = 'Varo-Inform';
  $export['yp_contacts_social_link_title'] = $strongarm;

  return $export;
}
