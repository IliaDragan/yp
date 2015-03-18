<?php
/**
 * @file
 * Plugin definition file for wide banner plugin.
 */

$plugin = array(
  'title' => t('Banner/Campaign (Top wide)'),
  'description' => t('Display a set of wide banners.'),
  'single' => TRUE,
  'content_types' => array('Banner/Campaign (Top wide)'),
  'render callback' => 'yellow_pages_campaign_ad_render',
  'all contexts' => TRUE,
  'edit form' => 'yellow_pages_campaign_ad_render_edit_form',
  'category' => array(t('Yellow pages')),
);
