<?php
/**
 * @file
 * Frontpage layout plugin definition.
 */

$plugin['yp_frontpage'] = array(
  'title' => t('YellowPages Frontpage'),
  'category' => 'YellowPages',
  'icon' => 'yp_onecol_100.png',
  'theme' => 'yp_frontpage',
  'css' => 'yp_frontpage.css',
  'regions' => array(
    'main' => t('Main'),
  ),
  'regions_image_styles' => array(),
);
