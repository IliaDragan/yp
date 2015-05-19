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
  $display->layout = 'yp_twocol_25_75';
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
      'left_above' => NULL,
      'right_above' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
      'alpha_25' => NULL,
      'beta_75' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3cac362d-b627-40ee-bac2-0245e79b27c6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1ed7743c-6a66-4d7e-ae69-03a7e0e6b25f';
    $pane->panel = 'alpha_25';
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
    $display->panels['alpha_25'][0] = 'new-1ed7743c-6a66-4d7e-ae69-03a7e0e6b25f';
    $pane = new stdClass();
    $pane->pid = 'new-78d83587-b8b2-472d-9ffc-b8da97e3309c';
    $pane->panel = 'alpha_25';
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
    $display->panels['alpha_25'][1] = 'new-78d83587-b8b2-472d-9ffc-b8da97e3309c';
    $pane = new stdClass();
    $pane->pid = 'new-3e018318-3f88-4931-a65a-f05e5bbb98d4';
    $pane->panel = 'alpha_25';
    $pane->type = 'block';
    $pane->subtype = 'simpleads-ad_groups_2';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '3e018318-3f88-4931-a65a-f05e5bbb98d4';
    $display->content['new-3e018318-3f88-4931-a65a-f05e5bbb98d4'] = $pane;
    $display->panels['alpha_25'][2] = 'new-3e018318-3f88-4931-a65a-f05e5bbb98d4';
    $pane = new stdClass();
    $pane->pid = 'new-4cf4b860-bd43-4a12-92b5-ed5ec4e28fbd';
    $pane->panel = 'beta_75';
    $pane->type = 'views_panes';
    $pane->subtype = 'solr_views-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4cf4b860-bd43-4a12-92b5-ed5ec4e28fbd';
    $display->content['new-4cf4b860-bd43-4a12-92b5-ed5ec4e28fbd'] = $pane;
    $display->panels['beta_75'][0] = 'new-4cf4b860-bd43-4a12-92b5-ed5ec4e28fbd';
    $pane = new stdClass();
    $pane->pid = 'new-68709a91-88d2-4646-83c8-9ecb6391faf5';
    $pane->panel = 'beta_75';
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
    $display->panels['beta_75'][1] = 'new-68709a91-88d2-4646-83c8-9ecb6391faf5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['search_node__solr_search'] = $handler;

  return $export;
}
