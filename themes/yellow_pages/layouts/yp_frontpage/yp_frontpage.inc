<?php
/**
 * @file
 * Frontpage layout plugin definition.
 */

$plugin['yp_frontpage'] = array(
  'title' => t('YellowPages Frontpage'),
  'category' => 'YellowPages',
  'icon' => 'yp_frontpage.png',
  'theme' => 'yp_frontpage',
  'css' => 'yp_frontpage.css',
  'regions' => array(
    'main' => t('Main'),
    'bottom_a' => t('Bottom A'),
    'bottom_b' => t('Bottom B'),
    'bottom_c' => t('Bottom C'),
  ),
  'regions_image_styles' => array(),
);
