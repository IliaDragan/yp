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
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3f950459-f8e8-4d09-80b9-2b61daa560b3';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b791349b-f559-430f-b504-9edcea2406e5';
    $pane->panel = 'alpha_25';
    $pane->type = 'yp_advertisement';
    $pane->subtype = 'yp_advertisement';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'ads_amount' => '3',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b791349b-f559-430f-b504-9edcea2406e5';
    $display->content['new-b791349b-f559-430f-b504-9edcea2406e5'] = $pane;
    $display->panels['alpha_25'][0] = 'new-b791349b-f559-430f-b504-9edcea2406e5';
    $pane = new stdClass();
    $pane->pid = 'new-46cec6b6-e093-48a2-bd2a-a9071b33428d';
    $pane->panel = 'beta_75';
    $pane->type = 'switch_search';
    $pane->subtype = 'switch_search';
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
    $pane->uuid = '46cec6b6-e093-48a2-bd2a-a9071b33428d';
    $display->content['new-46cec6b6-e093-48a2-bd2a-a9071b33428d'] = $pane;
    $display->panels['beta_75'][0] = 'new-46cec6b6-e093-48a2-bd2a-a9071b33428d';
    $pane = new stdClass();
    $pane->pid = 'new-fc53f174-f8f4-4d89-9c54-35f0c1250682';
    $pane->panel = 'beta_75';
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
    $display->panels['beta_75'][1] = 'new-fc53f174-f8f4-4d89-9c54-35f0c1250682';
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
  $display->layout = 'yp_threecol_25_50_25';
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
      'beta_50' => NULL,
      'gamma_25' => NULL,
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
      'override_title' => 1,
      'override_title_text' => 'Filter by products:',
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
    $pane->pid = 'new-c00f6c1e-5dd5-45e8-bffe-c6318c0f475b';
    $pane->panel = 'alpha_25';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-Evl1IvUKKa4pFm0VgC8QpKJm61ePFjIs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Filter by region:',
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
    $pane->uuid = 'c00f6c1e-5dd5-45e8-bffe-c6318c0f475b';
    $display->content['new-c00f6c1e-5dd5-45e8-bffe-c6318c0f475b'] = $pane;
    $display->panels['alpha_25'][1] = 'new-c00f6c1e-5dd5-45e8-bffe-c6318c0f475b';
    $pane = new stdClass();
    $pane->pid = 'new-4cf63a67-5471-47dc-9416-cb3d19a2b120';
    $pane->panel = 'alpha_25';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-Wskhe2gYSJ0r021XTq5uM5rCH6gFA2pC';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Filter by locality:',
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
    $pane->uuid = '4cf63a67-5471-47dc-9416-cb3d19a2b120';
    $display->content['new-4cf63a67-5471-47dc-9416-cb3d19a2b120'] = $pane;
    $display->panels['alpha_25'][2] = 'new-4cf63a67-5471-47dc-9416-cb3d19a2b120';
    $pane = new stdClass();
    $pane->pid = 'new-0bf856a0-0654-4c71-9987-801c17cb37a7';
    $pane->panel = 'beta_50';
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
    $display->panels['beta_50'][0] = 'new-0bf856a0-0654-4c71-9987-801c17cb37a7';
    $pane = new stdClass();
    $pane->pid = 'new-f6de7a52-dac3-444b-9875-9341fda95d30';
    $pane->panel = 'beta_50';
    $pane->type = 'switch_search';
    $pane->subtype = 'switch_search';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f6de7a52-dac3-444b-9875-9341fda95d30';
    $display->content['new-f6de7a52-dac3-444b-9875-9341fda95d30'] = $pane;
    $display->panels['beta_50'][1] = 'new-f6de7a52-dac3-444b-9875-9341fda95d30';
    $pane = new stdClass();
    $pane->pid = 'new-87bcc6a2-7e08-4744-8424-829e1693f0aa';
    $pane->panel = 'gamma_25';
    $pane->type = 'yp_advertisement_search_result';
    $pane->subtype = 'yp_advertisement_search_result';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'ads_amount' => '7',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '87bcc6a2-7e08-4744-8424-829e1693f0aa';
    $display->content['new-87bcc6a2-7e08-4744-8424-829e1693f0aa'] = $pane;
    $display->panels['gamma_25'][0] = 'new-87bcc6a2-7e08-4744-8424-829e1693f0aa';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['search_with_solr'] = $page;

  return $pages;

}
