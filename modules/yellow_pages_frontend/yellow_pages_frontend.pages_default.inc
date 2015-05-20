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
  $handler->name = 'node_view__companies';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -28;
  $handler->conf = array(
    'title' => 'Companies',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'companies',
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
  $display->layout = 'yp_twocol_stacked_75_25';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'alpha_100' => NULL,
      'beta_75' => NULL,
      'gamma_25' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a4963899-1b11-4766-8e5a-211e90fb92bb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-7299eb61-481f-4216-b2c0-e2b7b18b8eea';
    $pane->panel = 'alpha_100';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7299eb61-481f-4216-b2c0-e2b7b18b8eea';
    $display->content['new-7299eb61-481f-4216-b2c0-e2b7b18b8eea'] = $pane;
    $display->panels['alpha_100'][0] = 'new-7299eb61-481f-4216-b2c0-e2b7b18b8eea';
    $pane = new stdClass();
    $pane->pid = 'new-da8637c3-d56b-4cbc-adaa-301f4109a016';
    $pane->panel = 'alpha_100';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '%title',
      'override_title_heading' => 'h3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'da8637c3-d56b-4cbc-adaa-301f4109a016';
    $display->content['new-da8637c3-d56b-4cbc-adaa-301f4109a016'] = $pane;
    $display->panels['alpha_100'][1] = 'new-da8637c3-d56b-4cbc-adaa-301f4109a016';
    $pane = new stdClass();
    $pane->pid = 'new-75d0624b-feac-4b8e-aa60-60a97b77e3de';
    $pane->panel = 'beta_75';
    $pane->type = 'views_panes';
    $pane->subtype = 'articles-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Similar articles',
      'override_title_heading' => 'h3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '75d0624b-feac-4b8e-aa60-60a97b77e3de';
    $display->content['new-75d0624b-feac-4b8e-aa60-60a97b77e3de'] = $pane;
    $display->panels['beta_75'][0] = 'new-75d0624b-feac-4b8e-aa60-60a97b77e3de';
    $pane = new stdClass();
    $pane->pid = 'new-1d752665-26b0-47c2-9728-6758a616e6f6';
    $pane->panel = 'beta_75';
    $pane->type = 'views_panes';
    $pane->subtype = 'companies-panel_pane_1';
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
    $pane->uuid = '1d752665-26b0-47c2-9728-6758a616e6f6';
    $display->content['new-1d752665-26b0-47c2-9728-6758a616e6f6'] = $pane;
    $display->panels['beta_75'][1] = 'new-1d752665-26b0-47c2-9728-6758a616e6f6';
    $pane = new stdClass();
    $pane->pid = 'new-d1e90075-d4a5-428d-82d7-3f0f9fb5fa6e';
    $pane->panel = 'gamma_25';
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
    $pane->uuid = 'd1e90075-d4a5-428d-82d7-3f0f9fb5fa6e';
    $display->content['new-d1e90075-d4a5-428d-82d7-3f0f9fb5fa6e'] = $pane;
    $display->panels['gamma_25'][0] = 'new-d1e90075-d4a5-428d-82d7-3f0f9fb5fa6e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__companies'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__news';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'News',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'news',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'news' => 'news',
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
  $display->uuid = 'a126f51a-cf86-4c09-82ee-9c071d7efc69';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0667fd27-a44d-4f42-a355-ffd42e72e885';
    $pane->panel = 'alpha_75';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '%node:title',
      'override_title_heading' => 'h3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0667fd27-a44d-4f42-a355-ffd42e72e885';
    $display->content['new-0667fd27-a44d-4f42-a355-ffd42e72e885'] = $pane;
    $display->panels['alpha_75'][0] = 'new-0667fd27-a44d-4f42-a355-ffd42e72e885';
    $pane = new stdClass();
    $pane->pid = 'new-56561e6d-3858-413b-a822-bf93d7b73dec';
    $pane->panel = 'alpha_75';
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
    $pane->uuid = '56561e6d-3858-413b-a822-bf93d7b73dec';
    $display->content['new-56561e6d-3858-413b-a822-bf93d7b73dec'] = $pane;
    $display->panels['alpha_75'][1] = 'new-56561e6d-3858-413b-a822-bf93d7b73dec';
    $pane = new stdClass();
    $pane->pid = 'new-2e5256ac-e000-4cc2-bc98-a4b04f100b94';
    $pane->panel = 'alpha_75';
    $pane->type = 'views_panes';
    $pane->subtype = 'news-panel_pane_3';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '2e5256ac-e000-4cc2-bc98-a4b04f100b94';
    $display->content['new-2e5256ac-e000-4cc2-bc98-a4b04f100b94'] = $pane;
    $display->panels['alpha_75'][2] = 'new-2e5256ac-e000-4cc2-bc98-a4b04f100b94';
    $pane = new stdClass();
    $pane->pid = 'new-797456c8-71b9-457c-9455-7361d65f81b1';
    $pane->panel = 'alpha_75';
    $pane->type = 'views_panes';
    $pane->subtype = 'companies-panel_pane_1';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '797456c8-71b9-457c-9455-7361d65f81b1';
    $display->content['new-797456c8-71b9-457c-9455-7361d65f81b1'] = $pane;
    $display->panels['alpha_75'][3] = 'new-797456c8-71b9-457c-9455-7361d65f81b1';
    $pane = new stdClass();
    $pane->pid = 'new-3d9778b1-7abf-433d-b291-0b9d07b04a20';
    $pane->panel = 'beta_25';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_categories';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'i18n_taxonomy_term_reference_link',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3d9778b1-7abf-433d-b291-0b9d07b04a20';
    $display->content['new-3d9778b1-7abf-433d-b291-0b9d07b04a20'] = $pane;
    $display->panels['beta_25'][0] = 'new-3d9778b1-7abf-433d-b291-0b9d07b04a20';
    $pane = new stdClass();
    $pane->pid = 'new-b198df13-2eea-4b7b-adbe-5365ab0b3722';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b198df13-2eea-4b7b-adbe-5365ab0b3722';
    $display->content['new-b198df13-2eea-4b7b-adbe-5365ab0b3722'] = $pane;
    $display->panels['beta_25'][1] = 'new-b198df13-2eea-4b7b-adbe-5365ab0b3722';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3d9778b1-7abf-433d-b291-0b9d07b04a20';
  $handler->conf['display'] = $display;
  $export['node_view__news'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__node_page';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -30;
  $handler->conf = array(
    'title' => 'Articles',
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
              'article' => 'article',
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
  $display->layout = 'yp_twocol_75_25';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'main' => NULL,
      'alpha_75' => NULL,
      'beta_25' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'ed73dcf9-377c-4cbe-a3b8-1ffc8e98cb03';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d2e153b3-821a-4c7f-8151-35c873f5bad9';
    $pane->panel = 'alpha_75';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '%node:title',
      'override_title_heading' => 'h3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd2e153b3-821a-4c7f-8151-35c873f5bad9';
    $display->content['new-d2e153b3-821a-4c7f-8151-35c873f5bad9'] = $pane;
    $display->panels['alpha_75'][0] = 'new-d2e153b3-821a-4c7f-8151-35c873f5bad9';
    $pane = new stdClass();
    $pane->pid = 'new-07104128-fd54-47af-b116-fd2dc2fe25f4';
    $pane->panel = 'alpha_75';
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
    $display->panels['alpha_75'][1] = 'new-07104128-fd54-47af-b116-fd2dc2fe25f4';
    $pane = new stdClass();
    $pane->pid = 'new-8d802ac4-3a37-4f13-b900-f049ffb342db';
    $pane->panel = 'alpha_75';
    $pane->type = 'views_panes';
    $pane->subtype = 'articles-panel_pane_1';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8d802ac4-3a37-4f13-b900-f049ffb342db';
    $display->content['new-8d802ac4-3a37-4f13-b900-f049ffb342db'] = $pane;
    $display->panels['alpha_75'][2] = 'new-8d802ac4-3a37-4f13-b900-f049ffb342db';
    $pane = new stdClass();
    $pane->pid = 'new-495f8035-eddf-48ce-b102-8c309bc74b70';
    $pane->panel = 'alpha_75';
    $pane->type = 'views_panes';
    $pane->subtype = 'companies-panel_pane_1';
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
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '495f8035-eddf-48ce-b102-8c309bc74b70';
    $display->content['new-495f8035-eddf-48ce-b102-8c309bc74b70'] = $pane;
    $display->panels['alpha_75'][3] = 'new-495f8035-eddf-48ce-b102-8c309bc74b70';
    $pane = new stdClass();
    $pane->pid = 'new-f33d820c-cca1-4876-a2ad-add094193d1b';
    $pane->panel = 'beta_25';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_categories';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'i18n_taxonomy_term_reference_link',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f33d820c-cca1-4876-a2ad-add094193d1b';
    $display->content['new-f33d820c-cca1-4876-a2ad-add094193d1b'] = $pane;
    $display->panels['beta_25'][0] = 'new-f33d820c-cca1-4876-a2ad-add094193d1b';
    $pane = new stdClass();
    $pane->pid = 'new-33845fa8-7f1e-42bd-9e78-09c1782a389d';
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
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '33845fa8-7f1e-42bd-9e78-09c1782a389d';
    $display->content['new-33845fa8-7f1e-42bd-9e78-09c1782a389d'] = $pane;
    $display->panels['beta_25'][1] = 'new-33845fa8-7f1e-42bd-9e78-09c1782a389d';
  $display->hide_title = PANELS_TITLE_NONE;
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
  $page->name = 'articles';
  $page->task = 'page';
  $page->admin_title = 'Articles';
  $page->admin_description = '';
  $page->path = 'articles';
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
  $handler->name = 'page_articles__panel_context_30afce7b-4b96-45e8-858d-7bf9d03c61e0';
  $handler->task = 'page';
  $handler->subtask = 'articles';
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
  $display->uuid = '9e5acc8b-0c09-4b1d-9b20-c47a649ffedb';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-37bd4bd8-2ee3-48d6-af1b-0b81885f7486';
    $pane->panel = 'alpha_75';
    $pane->type = 'views_panes';
    $pane->subtype = 'articles-panel_pane_2';
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
    $pane->uuid = '37bd4bd8-2ee3-48d6-af1b-0b81885f7486';
    $display->content['new-37bd4bd8-2ee3-48d6-af1b-0b81885f7486'] = $pane;
    $display->panels['alpha_75'][0] = 'new-37bd4bd8-2ee3-48d6-af1b-0b81885f7486';
    $pane = new stdClass();
    $pane->pid = 'new-5c0d7460-2864-4873-bdbf-34e06cd07aa6';
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
    $pane->uuid = '5c0d7460-2864-4873-bdbf-34e06cd07aa6';
    $display->content['new-5c0d7460-2864-4873-bdbf-34e06cd07aa6'] = $pane;
    $display->panels['beta_25'][0] = 'new-5c0d7460-2864-4873-bdbf-34e06cd07aa6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['articles'] = $page;

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
  $display->layout = 'yp_onecol_100';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'main' => NULL,
      'bottom_a' => NULL,
      'bottom_b' => NULL,
      'bottom_c' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd081856a-d107-4fb4-a93d-2f6243949e1c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-eab6e1fc-1fb5-43de-804b-60e5b1a47267';
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
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'eab6e1fc-1fb5-43de-804b-60e5b1a47267';
    $display->content['new-eab6e1fc-1fb5-43de-804b-60e5b1a47267'] = $pane;
    $display->panels['main'][0] = 'new-eab6e1fc-1fb5-43de-804b-60e5b1a47267';
    $pane = new stdClass();
    $pane->pid = 'new-56adfffe-7812-41aa-80c0-5bf838bc73c7';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'news-panel_pane_1';
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
    $pane->uuid = '56adfffe-7812-41aa-80c0-5bf838bc73c7';
    $display->content['new-56adfffe-7812-41aa-80c0-5bf838bc73c7'] = $pane;
    $display->panels['main'][1] = 'new-56adfffe-7812-41aa-80c0-5bf838bc73c7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['frontpage'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'news';
  $page->task = 'page';
  $page->admin_title = 'News';
  $page->admin_description = '';
  $page->path = 'news';
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
  $handler->name = 'page_news__panel_context_ece99b97-c531-45ae-8ab4-c96774b99b1f';
  $handler->task = 'page';
  $handler->subtask = 'news';
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
  $display->uuid = 'bdd675cf-bc7f-4ac5-94cf-a9355e4adc8f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e2c554b3-6eb5-4372-8842-a42e3a2032c4';
    $pane->panel = 'alpha_75';
    $pane->type = 'views_panes';
    $pane->subtype = 'news-panel_pane_2';
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
    $pane->uuid = 'e2c554b3-6eb5-4372-8842-a42e3a2032c4';
    $display->content['new-e2c554b3-6eb5-4372-8842-a42e3a2032c4'] = $pane;
    $display->panels['alpha_75'][0] = 'new-e2c554b3-6eb5-4372-8842-a42e3a2032c4';
    $pane = new stdClass();
    $pane->pid = 'new-4d8256d4-e971-468f-a98c-8f295f162d14';
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
    $pane->uuid = '4d8256d4-e971-468f-a98c-8f295f162d14';
    $display->content['new-4d8256d4-e971-468f-a98c-8f295f162d14'] = $pane;
    $display->panels['beta_25'][0] = 'new-4d8256d4-e971-468f-a98c-8f295f162d14';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-e2c554b3-6eb5-4372-8842-a42e3a2032c4';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news'] = $page;

  return $pages;

}
