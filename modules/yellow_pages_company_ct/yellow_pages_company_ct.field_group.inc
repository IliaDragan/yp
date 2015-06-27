<?php
/**
 * @file
 * yellow_pages_company_ct.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function yellow_pages_company_ct_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|company|full';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_tabbed_content';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '21',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-details field-group-htab',
        'id' => '',
      ),
    ),
  );
  $export['group_details|node|company|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_price_lists|node|company|full';
  $field_group->group_name = 'group_price_lists';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_tabbed_content';
  $field_group->data = array(
    'label' => 'Price lists',
    'weight' => '26',
    'children' => array(
      0 => 'field_price_list',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-price-lists field-group-htab',
        'id' => '',
      ),
    ),
  );
  $export['group_price_lists|node|company|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabbed_content|node|company|full';
  $field_group->group_name = 'group_tabbed_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabbed content',
    'weight' => '9',
    'children' => array(
      0 => 'group_details',
      1 => 'group_products',
      2 => 'group_services',
      3 => 'group_we_sell',
      4 => 'group_we_buy',
      5 => 'group_price_lists',
      6 => 'group_vauchers',
      7 => 'group_filials',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabbed-content field-group-htabs',
      ),
    ),
  );
  $export['group_tabbed_content|node|company|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_we_buy|node|company|full';
  $field_group->group_name = 'group_we_buy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_tabbed_content';
  $field_group->data = array(
    'label' => 'We buy',
    'weight' => '25',
    'children' => array(
      0 => 'field_we_buy',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-we-buy field-group-htab',
        'id' => '',
      ),
    ),
  );
  $export['group_we_buy|node|company|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_we_sell|node|company|full';
  $field_group->group_name = 'group_we_sell';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_tabbed_content';
  $field_group->data = array(
    'label' => 'We sell',
    'weight' => '24',
    'children' => array(
      0 => 'field_we_sell',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-we-sell field-group-htab',
        'id' => '',
      ),
    ),
  );
  $export['group_we_sell|node|company|full'] = $field_group;

  return $export;
}
