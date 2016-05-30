<?php
/**
 * @file
 * yellow_pages_news_ct.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function yellow_pages_news_ct_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main|node|news|form';
  $field_group->group_name = 'group_main';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_news_settings';
  $field_group->data = array(
    'label' => 'Основное',
    'weight' => '9',
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
  $field_groups['group_main|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_media_materials|node|news|form';
  $field_group->group_name = 'group_media_materials';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_news_settings';
  $field_group->data = array(
    'label' => 'Медиа материалы',
    'weight' => '10',
    'children' => array(
      0 => 'field_list_image',
      1 => 'field_main_image',
      2 => 'field_video',
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
  $field_groups['group_media_materials|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_news_settings|node|news|form';
  $field_group->group_name = 'group_news_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Вертикальная группа',
    'weight' => '1',
    'children' => array(
      0 => 'group_main',
      1 => 'group_media_materials',
      2 => 'group_relations',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'label' => 'Вертикальная группа',
      'instance_settings' => array(
        'classes' => 'group-news-settings field-group-tabs',
      ),
    ),
  );
  $field_groups['group_news_settings|node|news|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_relations|node|news|form';
  $field_group->group_name = 'group_relations';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_news_settings';
  $field_group->data = array(
    'label' => 'Связи',
    'weight' => '11',
    'children' => array(
      0 => 'field_companies',
      1 => 'field_products',
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
  $field_groups['group_relations|node|news|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Вертикальная группа');
  t('Медиа материалы');
  t('Основное');
  t('Связи');

  return $field_groups;
}
