<?php
/**
 * @file
 * yellow_pages_ads.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function yellow_pages_ads_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'AdSense Company 300x250';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'adsense_company_300_250';
  $fe_block_boxes->body = '<p><mediawrapper data=""><img alt="" class="media-element file-default" data-fid="890" data-media-element="1" src="http://yp.loc/sites/default/files/tumblr_m5mhdbpkvn1qbajzvo1_1280.jpg" style="width: 300px; height: 250px;" typeof="foaf:Image" /></mediawrapper></p>
';

  $export['adsense_company_300_250'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'AdSense Frontpage 468x60 left';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'adsense_front_468_60_left';
  $fe_block_boxes->body = '<p><mediawrapper data=""><img alt="" class="media-element file-default" data-fid="888" data-media-element="1" src="http://yp.loc/sites/default/files/background-beautiful-cool-cute-galaxy-favim.com-303879.jpg" style="width: 468px; height: 60px;" typeof="foaf:Image" /></mediawrapper></p>
';

  $export['adsense_front_468_60_left'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'AdSense Frontpage 468x60 right';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'adsense_front_468_60_right';
  $fe_block_boxes->body = '<p><mediawrapper data=""><img alt="" class="media-element file-default" data-fid="889" data-media-element="1" src="http://yp.loc/sites/default/files/clouds-background-tumblr-7812.jpg" style="width: 468px; height: 60px;" typeof="foaf:Image" /></mediawrapper></p>
';

  $export['adsense_front_468_60_right'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'AdSense News 728x90 First';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'adsense_news_728_90_first';
  $fe_block_boxes->body = '<p><mediawrapper data=""><img alt="" class="media-element file-default" data-fid="886" data-media-element="1" src="http://yp.loc/sites/default/files/cool-backgrounds-random-17514354-1024-640.jpg" style="width: 728px; height: 90px;" typeof="foaf:Image" /></mediawrapper></p>
';

  $export['adsense_news_728_90_first'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'AdSense News 728x90 Second';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'adsense_news_728_90_second';
  $fe_block_boxes->body = '<p><mediawrapper data=""><img alt="" class="media-element file-default" data-fid="887" data-media-element="1" src="http://yp.loc/sites/default/files/cool-background-random-17506456-1869-1168.jpg" style="width: 728px; height: 90px;" typeof="foaf:Image" /></mediawrapper></p>
';

  $export['adsense_news_728_90_second'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'AdSense Search 300x250';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'adsense_search_300_250';
  $fe_block_boxes->body = '<p><mediawrapper data=""><img alt="" class="media-element file-default" data-fid="891" data-media-element="1" src="http://yp.loc/sites/default/files/large.jpg" style="width: 300px; height: 250px;" typeof="foaf:Image" /></mediawrapper><br />
&nbsp;</p>
';

  $export['adsense_search_300_250'] = $fe_block_boxes;

  return $export;
}
