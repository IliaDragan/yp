<?php
/**
 * @file
 * Frontpage layout plugin definition.
 */

$plugin['yp_twocol_75_25'] = array(
  'title' => t('Two Column 75%-25%'),
  'category' => 'YellowPages',
  'icon' => 'yp_twocol_75_25.png',
  'theme' => 'yp_twocol_75_25',
  'css' => 'yp_twocol_75_25.css',
  'regions' => array(
    'alpha_75' => t('Alpha 75'),
    'tabs_75' => t('tabs 75'),
    'beta_25' => t('Beta 25'),
  ),
  'regions_image_styles' => array(),
);
