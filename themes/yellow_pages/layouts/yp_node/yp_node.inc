<?php
/**
 * @file
 * Frontpage layout plugin definition.
 */

$plugin['yp_node'] = array(
  'title' => t('YellowPages Node'),
  'category' => 'YellowPages',
  'icon' => 'yp_node.png',
  'theme' => 'yp_node',
  'css' => 'yp_node.css',
  'regions' => array(
    'main' => t('Main'),
  ),
  'regions_image_styles' => array(),
);
