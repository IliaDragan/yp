<?php
/**
 * @file
 * yellow_pages_feedback.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function yellow_pages_feedback_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'feedback';
  $page->task = 'page';
  $page->admin_title = 'Feedback';
  $page->admin_description = '';
  $page->path = 'feedback/%type';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'type' => array(
      'id' => 1,
      'identifier' => 'String',
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
  $handler->name = 'page_feedback__panel_context_7b61b3cc-a21e-4e09-9ece-39d0f762bed0';
  $handler->task = 'page';
  $handler->subtask = 'feedback';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Ad feedback',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'ad',
            'case' => 1,
          ),
          'context' => 'argument_string_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'yp_twocol_75_25';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'alpha_75' => NULL,
      'beta_25' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3f304f3c-06f1-4c00-8b09-4a06d9a59be9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-625490ed-4ebf-4ef5-87bc-eaa838fa41da';
    $pane->panel = 'alpha_75';
    $pane->type = 'block';
    $pane->subtype = 'yellow_pages_feedback-yp_ad_request';
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
    $pane->uuid = '625490ed-4ebf-4ef5-87bc-eaa838fa41da';
    $display->content['new-625490ed-4ebf-4ef5-87bc-eaa838fa41da'] = $pane;
    $display->panels['alpha_75'][0] = 'new-625490ed-4ebf-4ef5-87bc-eaa838fa41da';
    $pane = new stdClass();
    $pane->pid = 'new-1f1735d1-7cd5-4b60-86bb-0889e2410780';
    $pane->panel = 'beta_25';
    $pane->type = 'block';
    $pane->subtype = 'simpleads-ad_groups_1';
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
    $pane->uuid = '1f1735d1-7cd5-4b60-86bb-0889e2410780';
    $display->content['new-1f1735d1-7cd5-4b60-86bb-0889e2410780'] = $pane;
    $display->panels['beta_25'][0] = 'new-1f1735d1-7cd5-4b60-86bb-0889e2410780';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['feedback'] = $page;

  return $pages;
}
