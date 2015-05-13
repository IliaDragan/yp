<?php
/**
 * @file
 * yellow_pages_frontend.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function yellow_pages_frontend_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__node_page';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Company node page',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'node_page',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'company' => 'company',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'yp_node';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'ed73dcf9-377c-4cbe-a3b8-1ffc8e98cb03';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f2a1601a-4e11-4df9-b2ad-539bc8bf7456';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-category-menu';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-category-menu',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f2a1601a-4e11-4df9-b2ad-539bc8bf7456';
    $display->content['new-f2a1601a-4e11-4df9-b2ad-539bc8bf7456'] = $pane;
    $display->panels['main'][0] = 'new-f2a1601a-4e11-4df9-b2ad-539bc8bf7456';
    $pane = new stdClass();
    $pane->pid = 'new-07104128-fd54-47af-b116-fd2dc2fe25f4';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'yellow_pages_print-yp_print';
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
    $pane->uuid = '07104128-fd54-47af-b116-fd2dc2fe25f4';
    $display->content['new-07104128-fd54-47af-b116-fd2dc2fe25f4'] = $pane;
    $display->panels['main'][1] = 'new-07104128-fd54-47af-b116-fd2dc2fe25f4';
    $pane = new stdClass();
    $pane->pid = 'new-7128bcd5-452a-476e-be5a-234ffd54bfa0';
    $pane->panel = 'main';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h2',
      'class' => '',
      'id' => '',
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '7128bcd5-452a-476e-be5a-234ffd54bfa0';
    $display->content['new-7128bcd5-452a-476e-be5a-234ffd54bfa0'] = $pane;
    $display->panels['main'][2] = 'new-7128bcd5-452a-476e-be5a-234ffd54bfa0';
    $pane = new stdClass();
    $pane->pid = 'new-d2e153b3-821a-4c7f-8151-35c873f5bad9';
    $pane->panel = 'main';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'd2e153b3-821a-4c7f-8151-35c873f5bad9';
    $display->content['new-d2e153b3-821a-4c7f-8151-35c873f5bad9'] = $pane;
    $display->panels['main'][3] = 'new-d2e153b3-821a-4c7f-8151-35c873f5bad9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__node_page'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function yellow_pages_frontend_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'frontpage';
  $page->task = 'page';
  $page->admin_title = 'Frontpage';
  $page->admin_description = '';
  $page->path = 'front';
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
  $handler->name = 'page_frontpage__panel_context_c7e65fb1-48a1-4e23-b81d-b8ed4f4836f7';
  $handler->task = 'page';
  $handler->subtask = 'frontpage';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'yp_frontpage';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'main' => NULL,
      'bottom_a' => NULL,
      'bottom_b' => NULL,
      'bottom_c' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd081856a-d107-4fb4-a93d-2f6243949e1c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0ff84a64-16cf-459b-99d6-0c86b60eb78a';
    $pane->panel = 'bottom_a';
    $pane->type = 'block';
    $pane->subtype = 'yellow_pages_contacts-yp_contacts';
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
    $pane->uuid = '0ff84a64-16cf-459b-99d6-0c86b60eb78a';
    $display->content['new-0ff84a64-16cf-459b-99d6-0c86b60eb78a'] = $pane;
    $display->panels['bottom_a'][0] = 'new-0ff84a64-16cf-459b-99d6-0c86b60eb78a';
    $pane = new stdClass();
    $pane->pid = 'new-d8f967e6-55fd-4e50-89d6-617949d52b1c';
    $pane->panel = 'bottom_b';
    $pane->type = 'block';
    $pane->subtype = 'yellow_pages_rates-yp_rates';
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
    $pane->uuid = 'd8f967e6-55fd-4e50-89d6-617949d52b1c';
    $display->content['new-d8f967e6-55fd-4e50-89d6-617949d52b1c'] = $pane;
    $display->panels['bottom_b'][0] = 'new-d8f967e6-55fd-4e50-89d6-617949d52b1c';
    $pane = new stdClass();
    $pane->pid = 'new-25f32235-0109-43b4-ad5a-139bde95a7a9';
    $pane->panel = 'bottom_c';
    $pane->type = 'block';
    $pane->subtype = 'yellow_pages_weather-yp_weather';
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
    $pane->uuid = '25f32235-0109-43b4-ad5a-139bde95a7a9';
    $display->content['new-25f32235-0109-43b4-ad5a-139bde95a7a9'] = $pane;
    $display->panels['bottom_c'][0] = 'new-25f32235-0109-43b4-ad5a-139bde95a7a9';
    $pane = new stdClass();
    $pane->pid = 'new-d4bf85b5-3932-4974-af5c-8ba9de367f5c';
    $pane->panel = 'main';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-category-menu';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-category-menu',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd4bf85b5-3932-4974-af5c-8ba9de367f5c';
    $display->content['new-d4bf85b5-3932-4974-af5c-8ba9de367f5c'] = $pane;
    $display->panels['main'][0] = 'new-d4bf85b5-3932-4974-af5c-8ba9de367f5c';
    $pane = new stdClass();
    $pane->pid = 'new-0f5e282d-abb0-472b-810f-8adf6e03c9c3';
    $pane->panel = 'main';
    $pane->type = 'views';
    $pane->subtype = 'news';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-views-news-carousel',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0f5e282d-abb0-472b-810f-8adf6e03c9c3';
    $display->content['new-0f5e282d-abb0-472b-810f-8adf6e03c9c3'] = $pane;
    $display->panels['main'][1] = 'new-0f5e282d-abb0-472b-810f-8adf6e03c9c3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['frontpage'] = $page;

  return $pages;

}