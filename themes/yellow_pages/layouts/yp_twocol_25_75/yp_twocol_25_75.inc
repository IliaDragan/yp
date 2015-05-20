<?php
/**
 * @file
 * Frontpage layout plugin definition.
 */

$plugin['yp_twocol_25_75'] = array(
  'title' => t('Two Column 25%-75%'),
  'category' => 'YellowPages',
  'icon' => 'yp_twocol_25_75.png',
  'theme' => 'yp_twocol_25_75',
  'css' => 'yp_twocol_25_75.css',
  'regions' => array(
    'alpha_25' => t('Alpha 25'),
    'beta_75' => t('Beta 75'),
  ),
  'regions_image_styles' => array(),
);
