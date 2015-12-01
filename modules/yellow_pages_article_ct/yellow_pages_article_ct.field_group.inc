<?php
/**
 * @file
 * yellow_pages_article_ct.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function yellow_pages_article_ct_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_article_settings|node|article|form';
  $field_group->group_name = 'group_article_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'group_main',
      1 => 'group_media_materials',
      2 => 'group_relations',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-article-settings field-group-tabs',
      ),
    ),
  );
  $export['group_article_settings|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main|node|article|form';
  $field_group->group_name = 'group_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_article_settings';
  $field_group->data = array(
    'label' => 'Основное',
    'weight' => '4',
    'children' => array(
      0 => 'body',
      1 => 'language',
      2 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-main field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_main|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media_materials|node|article|form';
  $field_group->group_name = 'group_media_materials';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_article_settings';
  $field_group->data = array(
    'label' => 'Медиа материалы',
    'weight' => '5',
    'children' => array(
      0 => 'field_list_image',
      1 => 'field_main_image',
      2 => 'field_video',
      3 => 'field_front_image',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-media-materials field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_media_materials|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_relations|node|article|form';
  $field_group->group_name = 'group_relations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_article_settings';
  $field_group->data = array(
    'label' => 'Связи',
    'weight' => '6',
    'children' => array(
      0 => 'field_products',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-relations field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_relations|node|article|form'] = $field_group;

  return $export;
}
