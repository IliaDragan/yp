<?php
/**
 * @file
 * yellow_pages_frontend.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function yellow_pages_frontend_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_sql_norevisions_enabled_entities';
  $strongarm->value = array(
    'field_sql_norevisions_comment_comment_node_advertisement_enabled' => 1,
    'field_sql_norevisions_comment_comment_node_article_enabled' => 1,
    'field_sql_norevisions_comment_comment_node_company_enabled' => 1,
    'field_sql_norevisions_comment_comment_node_news_enabled' => 1,
    'field_sql_norevisions_node_advertisement_enabled' => 1,
    'field_sql_norevisions_node_article_enabled' => 1,
    'field_sql_norevisions_node_company_enabled' => 1,
    'field_sql_norevisions_node_news_enabled' => 1,
    'field_sql_norevisions_file_image_enabled' => 1,
    'field_sql_norevisions_file_video_enabled' => 1,
    'field_sql_norevisions_file_audio_enabled' => 1,
    'field_sql_norevisions_file_document_enabled' => 1,
    'field_sql_norevisions_taxonomy_term_products_enabled' => 1,
    'field_sql_norevisions_user_user_enabled' => 1,
  );
  $export['field_sql_norevisions_enabled_entities'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'front';
  $export['site_frontpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_yellow_pages_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 1,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 1,
    'toggle_secondary_menu' => 1,
    'default_logo' => 1,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
    'circle_clearcss' => 1,
    'circle_css_normalize' => 1,
    'circle_css_layout' => 0,
    'circle_css_circlestyles' => 0,
    'circle_css_ie' => 1,
    'circle_css_onefile' => 0,
    'circle_css_bootstrap' => 1,
    'circle_css_bootstrap_version' => '3.0.2',
    'circle_js_bootstrap' => 0,
    'circle_js_bootstrap_version' => '3.0.2',
    'circle_css_bootstrap_local' => 0,
    'circle_js_bootstrap_local' => 0,
    'circle_css_foundation' => 0,
    'circle_css_foundation_version' => '4.3.2',
    'circle_js_foundation' => 0,
    'circle_js_foundation_version' => '4.3.2',
    'circle_css_foundation_local' => 0,
    'circle_js_foundation_local' => 0,
    'circle_modernizr' => 1,
    'circle_modernizr_local' => 0,
    'circle_js_htmlshiv' => 1,
    'circle_js_htmlshiv_local' => 0,
    'circle_js_placeholder' => 0,
    'circle_js_jquerycdn' => 0,
    'circle_js_jquerycdn_version' => '0',
    'circle_footer_js' => 0,
    'circle_js_onefile' => 0,
    'breadcrumb_separator' => '',
    'breadcrumb_append_current' => 0,
    'breadcrumb_hide_single' => 0,
    'humanstxt' => FALSE,
    'circles_enable_less' => 0,
    'circle_css_framework' => 'bootstrap',
  );
  $export['theme_yellow_pages_settings'] = $strongarm;

  return $export;
}
