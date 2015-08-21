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
  $page->name = 'search_content_with_solr';
  $page->task = 'page';
  $page->admin_title = 'Search content with solr';
  $page->admin_description = '';
  $page->path = 'search/content/!keywords';
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
  $handler->name = 'page_search_content_with_solr__panel_context_95e55e13-570f-4e76-b967-a4b722cb0114';
  $handler->task = 'page';
  $handler->subtask = 'search_content_with_solr';
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
  $display->layout = 'yp_onecol_100';
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
      'alpha_25' => NULL,
      'beta_75' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3f950459-f8e8-4d09-80b9-2b61daa560b3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-74bb5053-7d83-424d-ae92-6724834dd15c';
    $pane->panel = 'main';
    $pane->type = 'switch_serch';
    $pane->subtype = 'switch_serch';
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
    $pane->uuid = '74bb5053-7d83-424d-ae92-6724834dd15c';
    $display->content['new-74bb5053-7d83-424d-ae92-6724834dd15c'] = $pane;
    $display->panels['main'][0] = 'new-74bb5053-7d83-424d-ae92-6724834dd15c';
    $pane = new stdClass();
    $pane->pid = 'new-fc53f174-f8f4-4d89-9c54-35f0c1250682';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'solr_views-panel_pane_2';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'fc53f174-f8f4-4d89-9c54-35f0c1250682';
    $display->content['new-fc53f174-f8f4-4d89-9c54-35f0c1250682'] = $pane;
    $display->panels['main'][1] = 'new-fc53f174-f8f4-4d89-9c54-35f0c1250682';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search_content_with_solr'] = $page;

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
  $display->layout = 'yp_twocol_25_75';
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
      'alpha_25' => NULL,
      'beta_75' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3f950459-f8e8-4d09-80b9-2b61daa560b3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-60b6990d-4e03-435b-bcf2-0b40f397b1c4';
    $pane->panel = 'alpha_25';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-JhQr1vAI4ag71XN712aDqCkWYhtBV8ZO';
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
    $pane->uuid = '60b6990d-4e03-435b-bcf2-0b40f397b1c4';
    $display->content['new-60b6990d-4e03-435b-bcf2-0b40f397b1c4'] = $pane;
    $display->panels['alpha_25'][0] = 'new-60b6990d-4e03-435b-bcf2-0b40f397b1c4';
    $pane = new stdClass();
    $pane->pid = 'new-bbec92a0-b4e4-474d-a2f0-078a4c5ac5e1';
    $pane->panel = 'alpha_25';
    $pane->type = 'yp_advertisement';
    $pane->subtype = 'yp_advertisement';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'ads_amount' => '2',
      'ads_category' => 'sidebar',
      'ads_order' => 'random',
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bbec92a0-b4e4-474d-a2f0-078a4c5ac5e1';
    $display->content['new-bbec92a0-b4e4-474d-a2f0-078a4c5ac5e1'] = $pane;
    $display->panels['alpha_25'][1] = 'new-bbec92a0-b4e4-474d-a2f0-078a4c5ac5e1';
    $pane = new stdClass();
    $pane->pid = 'new-74bb5053-7d83-424d-ae92-6724834dd15c';
    $pane->panel = 'beta_75';
    $pane->type = 'switch_serch';
    $pane->subtype = 'switch_serch';
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
    $pane->uuid = '74bb5053-7d83-424d-ae92-6724834dd15c';
    $display->content['new-74bb5053-7d83-424d-ae92-6724834dd15c'] = $pane;
    $display->panels['beta_75'][0] = 'new-74bb5053-7d83-424d-ae92-6724834dd15c';
    $pane = new stdClass();
    $pane->pid = 'new-0bf856a0-0654-4c71-9987-801c17cb37a7';
    $pane->panel = 'beta_75';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0bf856a0-0654-4c71-9987-801c17cb37a7';
    $display->content['new-0bf856a0-0654-4c71-9987-801c17cb37a7'] = $pane;
    $display->panels['beta_75'][1] = 'new-0bf856a0-0654-4c71-9987-801c17cb37a7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search_with_solr'] = $page;

  return $pages;

}
