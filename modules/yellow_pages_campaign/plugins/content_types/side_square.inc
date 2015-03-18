<?php
/**
 * @file
 * Plugin definition file for square banner plugin.
 */

$plugin = array(
  'title' => t('Banner/Campaign (Side square)'),
  'description' => t('Display a set of square banners.'),
  'single' => TRUE,
  'content_types' => array('Banner/Campaign (Side square)'),
  'render callback' => 'yellow_pages_campaign_ad_render',
  'all contexts' => TRUE,
  'edit form' => 'yellow_pages_campaign_ad_render_edit_form',
  'category' => array(t('Yellow pages')),
);
