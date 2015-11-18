<?php
/**
 * @file
 * Frontpage layout plugin definition.
 */

$plugin['yp_threecol_25_50_25'] = array(
  'title' => t('Three Column 25%-50%-25%'),
  'category' => 'YellowPages',
  'icon' => 'yp_threecol_25_50_25.png',
  'theme' => 'yp_threecol_25_50_25',
  'css' => 'yp_threecol_25_50_25.css',
  'regions' => array(
    'alpha_25' => t('Alpha 25'),
    'beta_50' => t('Beta 50'),
    'gamma_25' => t('Gamma 25'),
  ),
  'regions_image_styles' => array(),
);
