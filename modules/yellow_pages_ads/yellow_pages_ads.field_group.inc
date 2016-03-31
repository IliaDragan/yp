<?php
/**
 * @file
 * yellow_pages_ads.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function yellow_pages_ads_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ad_image|node|advertisement|form';
  $field_group->group_name = 'group_ad_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'advertisement';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image',
    'weight' => '6',
    'children' => array(
      0 => 'field_ad_image',
      1 => 'field_ad_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Image',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-ad-image field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_ad_image|node|advertisement|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ad_wysiwyg|node|advertisement|form';
  $field_group->group_name = 'group_ad_wysiwyg';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'advertisement';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'WYSIWYG',
    'weight' => '7',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'WYSIWYG',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-ad-wysiwyg field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_ad_wysiwyg|node|advertisement|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Image');
  t('WYSIWYG');

  return $field_groups;
}
