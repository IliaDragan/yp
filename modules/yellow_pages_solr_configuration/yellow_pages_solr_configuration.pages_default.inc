<?php
/**
 * @file
 * yellow_pages_solr_configuration.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function yellow_pages_solr_configuration_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'search_with_solr';
  $page->task = 'page';
  $page->admin_title = 'Search with solr';
  $page->admin_description = '';
  $page->path = 'search/companies/!keywords';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'keywords' => array(
      'id' => 1,
      'identifier' => 'Keywords',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_search_with_solr__panel_context_a246716e-08b8-4ac5-bfe0-1caed9e8531c';
  $handler->task = 'page';
  $handler->subtask = 'search_with_solr';
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
  $display->uuid = '3f950459-f8e8-4d09-80b9-2b61daa560b3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e51643f4-27ff-44a3-a210-e44e78419ab6';
    $pane->panel = 'left_above';
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
    $pane->uuid = 'e51643f4-27ff-44a3-a210-e44e78419ab6';
    $display->content['new-e51643f4-27ff-44a3-a210-e44e78419ab6'] = $pane;
    $display->panels['left_above'][0] = 'new-e51643f4-27ff-44a3-a210-e44e78419ab6';
    $pane = new stdClass();
    $pane->pid = 'new-79f5b511-8298-47fe-96a8-bf9de4bde4fb';
    $pane->panel = 'left_above';
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
    $pane->uuid = '79f5b511-8298-47fe-96a8-bf9de4bde4fb';
    $display->content['new-79f5b511-8298-47fe-96a8-bf9de4bde4fb'] = $pane;
    $display->panels['left_above'][1] = 'new-79f5b511-8298-47fe-96a8-bf9de4bde4fb';
    $pane = new stdClass();
    $pane->pid = 'new-0bf856a0-0654-4c71-9987-801c17cb37a7';
    $pane->panel = 'right_above';
    $pane->type = 'views_panes';
    $pane->subtype = 'solr_views-solr_node_search';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_string_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0bf856a0-0654-4c71-9987-801c17cb37a7';
    $display->content['new-0bf856a0-0654-4c71-9987-801c17cb37a7'] = $pane;
    $display->panels['right_above'][0] = 'new-0bf856a0-0654-4c71-9987-801c17cb37a7';
    $pane = new stdClass();
    $pane->pid = 'new-546b73c5-c417-4e25-8cf0-876adfcb4fac';
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
    $pane->uuid = '546b73c5-c417-4e25-8cf0-876adfcb4fac';
    $display->content['new-546b73c5-c417-4e25-8cf0-876adfcb4fac'] = $pane;
    $display->panels['top'][0] = 'new-546b73c5-c417-4e25-8cf0-876adfcb4fac';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search_with_solr'] = $page;

  return $pages;

}
