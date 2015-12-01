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
  $strongarm->name = 'colorbox_load';
  $strongarm->value = 1;
  $export['colorbox_load'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_style';
  $strongarm->value = 'profiles/yp/libraries/colorbox/example5';
  $export['colorbox_style'] = $strongarm;

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
  $strongarm->name = 'owlcarousel_add_class_active_owlcarousel_settings_meida';
  $strongarm->value = 1;
  $export['owlcarousel_add_class_active_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_auto_height_owlcarousel_settings_meida';
  $strongarm->value = 0;
  $export['owlcarousel_auto_height_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_auto_play_owlcarousel_settings_meida';
  $strongarm->value = '0';
  $export['owlcarousel_auto_play_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_base_class_owlcarousel_settings_meida';
  $strongarm->value = 'owl-carousel';
  $export['owlcarousel_base_class_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_drag_before_anim_finish_owlcarousel_settings_meida';
  $strongarm->value = 1;
  $export['owlcarousel_drag_before_anim_finish_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_items_desktop_owlcarousel_settings_meida_items';
  $strongarm->value = '5';
  $export['owlcarousel_items_desktop_owlcarousel_settings_meida_items'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_items_desktop_owlcarousel_settings_meida_width';
  $strongarm->value = '1000';
  $export['owlcarousel_items_desktop_owlcarousel_settings_meida_width'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_items_desktop_small_owlcarousel_settings_meida_items';
  $strongarm->value = '4';
  $export['owlcarousel_items_desktop_small_owlcarousel_settings_meida_items'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_items_desktop_small_owlcarousel_settings_meida_width';
  $strongarm->value = '900';
  $export['owlcarousel_items_desktop_small_owlcarousel_settings_meida_width'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_items_mobile_owlcarousel_settings_meida_items';
  $strongarm->value = '1';
  $export['owlcarousel_items_mobile_owlcarousel_settings_meida_items'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_items_mobile_owlcarousel_settings_meida_width';
  $strongarm->value = '479';
  $export['owlcarousel_items_mobile_owlcarousel_settings_meida_width'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_items_owlcarousel_settings_meida';
  $strongarm->value = '6';
  $export['owlcarousel_items_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_items_scale_up_owlcarousel_settings_meida';
  $strongarm->value = 0;
  $export['owlcarousel_items_scale_up_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_items_tablet_owlcarousel_settings_meida_items';
  $strongarm->value = '3';
  $export['owlcarousel_items_tablet_owlcarousel_settings_meida_items'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_items_tablet_owlcarousel_settings_meida_width';
  $strongarm->value = '800';
  $export['owlcarousel_items_tablet_owlcarousel_settings_meida_width'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_items_tablet_small_owlcarousel_settings_meida_items';
  $strongarm->value = '2';
  $export['owlcarousel_items_tablet_small_owlcarousel_settings_meida_items'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_items_tablet_small_owlcarousel_settings_meida_width';
  $strongarm->value = '650';
  $export['owlcarousel_items_tablet_small_owlcarousel_settings_meida_width'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_json_path_owlcarousel_settings_meida';
  $strongarm->value = '';
  $export['owlcarousel_json_path_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_json_success_owlcarousel_settings_meida';
  $strongarm->value = '';
  $export['owlcarousel_json_success_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_lazy_effect_owlcarousel_settings_meida';
  $strongarm->value = 'fadeIn';
  $export['owlcarousel_lazy_effect_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_lazy_follow_owlcarousel_settings_meida';
  $strongarm->value = 1;
  $export['owlcarousel_lazy_follow_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_lazy_load_owlcarousel_settings_meida';
  $strongarm->value = 0;
  $export['owlcarousel_lazy_load_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_mouse_drag_owlcarousel_settings_meida';
  $strongarm->value = 1;
  $export['owlcarousel_mouse_drag_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_navigation_owlcarousel_settings_meida';
  $strongarm->value = 1;
  $export['owlcarousel_navigation_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_navigation_text_owlcarousel_settings_meida';
  $strongarm->value = array(
    0 => '<span class="fa fa-angle-left"></span>',
    1 => '<span class="fa fa-angle-right"></span>',
  );
  $export['owlcarousel_navigation_text_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_override_ajax_pagination_owlcarousel_settings_meida';
  $strongarm->value = 1;
  $export['owlcarousel_override_ajax_pagination_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_pagination_numbers_owlcarousel_settings_meida';
  $strongarm->value = 0;
  $export['owlcarousel_pagination_numbers_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_pagination_owlcarousel_settings_meida';
  $strongarm->value = 1;
  $export['owlcarousel_pagination_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_pagination_speed_owlcarousel_settings_meida';
  $strongarm->value = '800';
  $export['owlcarousel_pagination_speed_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_responsive_base_width_owlcarousel_settings_meida';
  $strongarm->value = 'window';
  $export['owlcarousel_responsive_base_width_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_responsive_owlcarousel_settings_meida';
  $strongarm->value = 1;
  $export['owlcarousel_responsive_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_responsive_refresh_rate_owlcarousel_settings_meida';
  $strongarm->value = '200';
  $export['owlcarousel_responsive_refresh_rate_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_rewind_nav_owlcarousel_settings_meida';
  $strongarm->value = 1;
  $export['owlcarousel_rewind_nav_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_rewind_speed_owlcarousel_settings_meida';
  $strongarm->value = '1000';
  $export['owlcarousel_rewind_speed_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_scroll_per_page_owlcarousel_settings_meida';
  $strongarm->value = 0;
  $export['owlcarousel_scroll_per_page_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_settings_default';
  $strongarm->value = 'owlcarousel_default';
  $export['owlcarousel_settings_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_settings_meida';
  $strongarm->value = 'meida';
  $export['owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_single_item_owlcarousel_settings_meida';
  $strongarm->value = 0;
  $export['owlcarousel_single_item_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_slide_speed_owlcarousel_settings_meida';
  $strongarm->value = '200';
  $export['owlcarousel_slide_speed_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_stop_on_hover_owlcarousel_settings_meida';
  $strongarm->value = 0;
  $export['owlcarousel_stop_on_hover_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_theme_owlcarousel_settings_meida';
  $strongarm->value = 'owl-theme';
  $export['owlcarousel_theme_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_touch_drag_owlcarousel_settings_meida';
  $strongarm->value = 1;
  $export['owlcarousel_touch_drag_owlcarousel_settings_meida'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'owlcarousel_transition_style_owlcarousel_settings_meida';
  $strongarm->value = '';
  $export['owlcarousel_transition_style_owlcarousel_settings_meida'] = $strongarm;

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
