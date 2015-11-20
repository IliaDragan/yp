<?php
/**
 * @file
 * yellow_pages_frontend.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function yellow_pages_frontend_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'media_field';
  $view->description = 'Display of media field in different content types.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Media field';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Media materials */
  $handler->display->display_options['fields']['field_media_materials']['id'] = 'field_media_materials';
  $handler->display->display_options['fields']['field_media_materials']['table'] = 'field_data_field_media_materials';
  $handler->display->display_options['fields']['field_media_materials']['field'] = 'field_media_materials';
  $handler->display->display_options['fields']['field_media_materials']['label'] = '';
  $handler->display->display_options['fields']['field_media_materials']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_media_materials']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_media_materials']['settings'] = array(
    'file_view_mode' => 'teaser',
  );
  $handler->display->display_options['fields']['field_media_materials']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_media_materials']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_media_materials']['multi_type'] = 'ul';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['arguments']['nid_1']['table'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid_1']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid_1']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Company media field pane */
  $handler = $view->new_display('panel_pane', 'Company media field pane', 'panel_pane_company_media_field');
  $handler->display->display_options['display_description'] = 'Owl carousel media field for company node.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'owlcarousel';
  $handler->display->display_options['style_options']['instance'] = 'owlcarousel_settings_meida';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['argument_input'] = array(
    'nid_1' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $translatables['media_field'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Company media field pane'),
    t('Owl carousel media field for company node.'),
    t('View panes'),
  );
  $export['media_field'] = $view;

  return $export;
}
