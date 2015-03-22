<?php
/**
 * @file
 * yellow_pages_solr_configuration.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function yellow_pages_solr_configuration_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'search_node__solr_search';
  $handler->task = 'search';
  $handler->subtask = 'node';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'solr search',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'solr_search',
    'access' => array(
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'twocol_stacked';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3cac362d-b627-40ee-bac2-0245e79b27c6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1ed7743c-6a66-4d7e-ae69-03a7e0e6b25f';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-l4Iygiwo6Ya6rqa6uV8ATNLR15hxcdvy';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1ed7743c-6a66-4d7e-ae69-03a7e0e6b25f';
    $display->content['new-1ed7743c-6a66-4d7e-ae69-03a7e0e6b25f'] = $pane;
    $display->panels['left'][0] = 'new-1ed7743c-6a66-4d7e-ae69-03a7e0e6b25f';
    $pane = new stdClass();
    $pane->pid = 'new-78d83587-b8b2-472d-9ffc-b8da97e3309c';
    $pane->panel = 'left';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-Wskhe2gYSJ0r021XTq5uM5rCH6gFA2pC';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '78d83587-b8b2-472d-9ffc-b8da97e3309c';
    $display->content['new-78d83587-b8b2-472d-9ffc-b8da97e3309c'] = $pane;
    $display->panels['left'][1] = 'new-78d83587-b8b2-472d-9ffc-b8da97e3309c';
    $pane = new stdClass();
    $pane->pid = 'new-7f69f7dd-cbe7-47ae-a861-36eaad7df0cf';
    $pane->panel = 'right';
    $pane->type = 'block';
    $pane->subtype = 'search-form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7f69f7dd-cbe7-47ae-a861-36eaad7df0cf';
    $display->content['new-7f69f7dd-cbe7-47ae-a861-36eaad7df0cf'] = $pane;
    $display->panels['right'][0] = 'new-7f69f7dd-cbe7-47ae-a861-36eaad7df0cf';
    $pane = new stdClass();
    $pane->pid = 'new-68709a91-88d2-4646-83c8-9ecb6391faf5';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'solr_views-solr_node_search';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '68709a91-88d2-4646-83c8-9ecb6391faf5';
    $display->content['new-68709a91-88d2-4646-83c8-9ecb6391faf5'] = $pane;
    $display->panels['right'][1] = 'new-68709a91-88d2-4646-83c8-9ecb6391faf5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['search_node__solr_search'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function yellow_pages_solr_configuration_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'yellow_pages_front_page';
  $page->task = 'page';
  $page->admin_title = 'Yellow pages front page';
  $page->admin_description = '';
  $page->path = 'yp_frontpage';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_yellow_pages_front_page__panel_context_8657b3da-e232-41a2-a1a7-bc0b70d89ee7';
  $handler->task = 'page';
  $handler->subtask = 'yellow_pages_front_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'twocol_bricks';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left_above' => NULL,
      'right_above' => NULL,
      'middle' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ba208f47-85a7-4fef-8417-63097643818d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-3cda04fa-a1a5-4a0e-bb16-f6ad83ff7016';
    $pane->panel = 'top';
    $pane->type = 'block';
    $pane->subtype = 'search-form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3cda04fa-a1a5-4a0e-bb16-f6ad83ff7016';
    $display->content['new-3cda04fa-a1a5-4a0e-bb16-f6ad83ff7016'] = $pane;
    $display->panels['top'][0] = 'new-3cda04fa-a1a5-4a0e-bb16-f6ad83ff7016';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3cda04fa-a1a5-4a0e-bb16-f6ad83ff7016';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['yellow_pages_front_page'] = $page;

  return $pages;

}
