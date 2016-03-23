<?php
/**
 * @file
 * yellow_pages_company_ct.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function yellow_pages_company_ct_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_additional_information|node|company|form';
  $field_group->group_name = 'group_additional_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_company_info';
  $field_group->data = array(
    'label' => 'Additional information',
    'weight' => '26',
    'children' => array(
      0 => 'body',
      1 => 'field_media_materials',
      2 => 'field_price_list',
      3 => 'field_social_links',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-additional-information field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_additional_information|node|company|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advertisement|node|company|form';
  $field_group->group_name = 'group_advertisement';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_company_info';
  $field_group->data = array(
    'label' => 'Advertisements',
    'weight' => '27',
    'children' => array(
      0 => 'field_advertisements',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-advertisement field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_advertisement|node|company|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_articles|node|company|form';
  $field_group->group_name = 'group_articles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_company_info';
  $field_group->data = array(
    'label' => 'Articles',
    'weight' => '28',
    'children' => array(
      0 => 'field_articles',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-articles field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_articles|node|company|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_company_info|node|company|form';
  $field_group->group_name = 'group_company_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '1',
    'children' => array(
      0 => 'group_additional_information',
      1 => 'group_advertisement',
      2 => 'group_articles',
      3 => 'group_contacts',
      4 => 'group_main_content',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-company-info field-group-tabs',
      ),
    ),
  );
  $field_groups['group_company_info|node|company|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contacts|node|company|form';
  $field_group->group_name = 'group_contacts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_company_info';
  $field_group->data = array(
    'label' => 'Contacts',
    'weight' => '25',
    'children' => array(
      0 => 'field_address',
      1 => 'field_fax',
      2 => 'field_geocode',
      3 => 'field_landline_phone',
      4 => 'field_mobile_phone',
      5 => 'field_filials',
      6 => 'field_region',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contacts field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_contacts|node|company|form'] = $field_group;

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
    'weight' => '22',
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
  $field_groups['group_details|node|company|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_filials|node|company|full';
  $field_group->group_name = 'group_filials';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_tabbed_content';
  $field_group->data = array(
    'label' => 'Filials',
    'weight' => '31',
    'children' => array(
      0 => 'field_filials',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-filials field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_filials|node|company|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_content|node|company|form';
  $field_group->group_name = 'group_main_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_company_info';
  $field_group->data = array(
    'label' => 'Main content',
    'weight' => '23',
    'children' => array(
      0 => 'field_company_logo',
      1 => 'field_company_site',
      2 => 'field_email',
      3 => 'field_mdb_sync_date',
      4 => 'field_products',
      5 => 'field_logo_expiration_date',
      6 => 'field_changed_by_editor_date',
      7 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-main-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_main_content|node|company|form'] = $field_group;

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
    'weight' => '28',
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
  $field_groups['group_price_lists|node|company|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_products|node|company|full';
  $field_group->group_name = 'group_products';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_tabbed_content';
  $field_group->data = array(
    'label' => 'Products',
    'weight' => '23',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-products field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_products|node|company|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_services|node|company|full';
  $field_group->group_name = 'group_services';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_tabbed_content';
  $field_group->data = array(
    'label' => 'Services',
    'weight' => '24',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-services field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_services|node|company|full'] = $field_group;

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
    'weight' => '10',
    'children' => array(
      0 => 'group_details',
      1 => 'group_filials',
      2 => 'group_price_lists',
      3 => 'group_products',
      4 => 'group_services',
      5 => 'group_vouchers',
      6 => 'group_we_buy',
      7 => 'group_we_export',
      8 => 'group_we_sell',
      9 => 'group_working_hours',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tabbed-content field-group-htabs',
      ),
    ),
  );
  $field_groups['group_tabbed_content|node|company|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_vouchers|node|company|full';
  $field_group->group_name = 'group_vouchers';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_tabbed_content';
  $field_group->data = array(
    'label' => 'Vouchers',
    'weight' => '29',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-vouchers field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_vouchers|node|company|full'] = $field_group;

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
    'weight' => '26',
    'children' => array(),
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
  $field_groups['group_we_buy|node|company|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_we_export|node|company|full';
  $field_group->group_name = 'group_we_export';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_tabbed_content';
  $field_group->data = array(
    'label' => 'We export',
    'weight' => '27',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-we-export field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_we_export|node|company|full'] = $field_group;

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
    'weight' => '25',
    'children' => array(),
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
  $field_groups['group_we_sell|node|company|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_working_hours|node|company|full';
  $field_group->group_name = 'group_working_hours';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_tabbed_content';
  $field_group->data = array(
    'label' => 'Working hours',
    'weight' => '30',
    'children' => array(
      0 => 'field_business_hours',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-working-hours field-group-htab',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_working_hours|node|company|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional information');
  t('Advertisements');
  t('Articles');
  t('Contacts');
  t('Details');
  t('Filials');
  t('Main content');
  t('Price lists');
  t('Products');
  t('Services');
  t('Tabbed content');
  t('Vouchers');
  t('We buy');
  t('We export');
  t('We sell');
  t('Working hours');

  return $field_groups;
}
