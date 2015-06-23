<?php
/**
 * @file
 * Frontpage layout plugin definition.
 */

$plugin['yp_twocol_stacked_75_25'] = array(
  'title' => t('Two Column Stacked 100%-75%-25%'),
  'category' => 'YellowPages',
  'icon' => 'yp_twocol_stacked_75_25.png',
  'theme' => 'yp_twocol_stacked_75_25',
  'css' => 'yp_twocol_stacked_75_25.css',
  'regions' => array(
    'alpha_100' => t('Alpha 100'),
    'beta_75' => t('Beta 75'),
    'tabs_75' => t('tabs_1 75'),
    'gamma_25' => t('Gamma 25'),
  ),
  'regions_image_styles' => array(),
);
