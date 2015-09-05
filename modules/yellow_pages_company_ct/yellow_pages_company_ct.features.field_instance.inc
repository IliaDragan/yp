<?php
/**
 * @file
 * yellow_pages_company_ct.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function yellow_pages_company_ct_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-company-body'
  $field_instances['node-company-body'] = array(
    'bundle' => 'company',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 0,
      ),
      'slider_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Description of activity',
    'required' => 0,
    'settings' => array(
      'display_summary' => 1,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-company-field_address'
  $field_instances['node-company-field_address'] = array(
    'bundle' => 'company',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => 15,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => 1,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            'address' => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => 2,
      ),
      'slider_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'addressfield',
        'settings' => array(
          'format_handlers' => array(
            0 => 'address',
          ),
          'use_widget_handlers' => 1,
        ),
        'type' => 'addressfield_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_address',
    'label' => 'Address',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'addressfield',
      'settings' => array(
        'available_countries' => array(
          'MD' => 'MD',
        ),
        'default_country' => 'MD',
        'format_handlers' => array(
          'address' => 'address',
          'address-hide-country' => 'address-hide-country',
          'address-hide-postal-code' => 0,
          'address-hide-street' => 0,
          'organisation' => 0,
          'name-full' => 0,
          'name-oneline' => 0,
          'address-optional' => 0,
        ),
      ),
      'type' => 'addressfield_standard',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-company-field_advertisements'
  $field_instances['node-company-field_advertisements'] = array(
    'bundle' => 'company',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 21,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'search_index' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'slider_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_advertisements',
    'label' => 'Advertisements',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-company-field_articles'
  $field_instances['node-company-field_articles'] = array(
    'bundle' => 'company',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 22,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'search_index' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'slider_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_articles',
    'label' => 'Articles',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 28,
    ),
  );

  // Exported field_instance: 'node-company-field_company_logo'
  $field_instances['node-company-field_company_logo'] = array(
    'bundle' => 'company',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'medium',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => 'content',
          'image_style' => 'medium',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'slider_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => 'content',
          'image_style' => 'medium',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_company_logo',
    'label' => 'Logo',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '2 MB',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 'public',
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'media_internet' => 0,
          'upload' => 'upload',
          'youtube' => 0,
        ),
      ),
      'type' => 'media_generic',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-company-field_company_site'
  $field_instances['node-company-field_company_site'] = array(
    'bundle' => 'company',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 5,
      ),
      'search_index' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'slider_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_company_site',
    'label' => 'Site URL',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-company-field_email'
  $field_instances['node-company-field_email'] = array(
    'bundle' => 'company',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 13,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 6,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 5,
      ),
      'slider_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_email',
    'label' => 'Email',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-company-field_fax'
  $field_instances['node-company-field_fax'] = array(
    'bundle' => 'company',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 19,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'search_index' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'slider_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fax',
    'label' => 'Fax',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-company-field_geocode'
  $field_instances['node-company-field_geocode'] = array(
    'bundle' => 'company',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'leaflet',
        'settings' => array(
          'height' => 400,
          'icon' => array(
            'html' => '',
            'htmlClass' => '',
            'iconAnchor' => array(
              'x' => '',
              'y' => '',
            ),
            'iconImageStyle' => '',
            'iconSize' => array(
              'x' => '',
              'y' => '',
            ),
            'iconType' => 'marker',
            'iconUrl' => '',
            'popupAnchor' => array(
              'x' => '',
              'y' => '',
            ),
            'shadowAnchor' => array(
              'x' => '',
              'y' => '',
            ),
            'shadowUrl' => '',
          ),
          'leaflet_map' => 'OSM Mapnik',
          'popup' => array(
            'show' => 0,
            'text' => '',
          ),
          'vector_display' => array(
            'clickable' => 0,
            'color' => '',
            'dashArray' => '',
            'fill' => 0,
            'fillColor' => '',
            'fillOpacity' => '',
            'opacity' => '',
            'stroke' => 0,
            'stroke_override' => 0,
            'weight' => '',
          ),
          'zoom' => array(
            'initialZoom' => -1,
            'maxZoom' => -1,
            'minZoom' => 1,
          ),
        ),
        'type' => 'geofield_leaflet',
        'weight' => 16,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'leaflet',
        'settings' => array(
          'height' => 300,
          'icon' => array(
            'html' => '',
            'htmlClass' => '',
            'iconAnchor' => array(
              'x' => '',
              'y' => '',
            ),
            'iconImageStyle' => '',
            'iconSize' => array(
              'x' => '',
              'y' => '',
            ),
            'iconType' => 'marker',
            'iconUrl' => '',
            'popupAnchor' => array(
              'x' => '',
              'y' => '',
            ),
            'shadowAnchor' => array(
              'x' => '',
              'y' => '',
            ),
            'shadowUrl' => '',
          ),
          'leaflet_map' => 'OSM Mapnik',
          'popup' => array(
            'show' => 0,
            'text' => '',
          ),
          'vector_display' => array(
            'clickable' => 0,
            'color' => '',
            'dashArray' => '',
            'fill' => 0,
            'fillColor' => '',
            'fillOpacity' => '',
            'opacity' => '',
            'stroke' => 0,
            'stroke_override' => 0,
            'weight' => '',
          ),
          'zoom' => array(
            'initialZoom' => -1,
            'maxZoom' => -1,
            'minZoom' => 1,
          ),
        ),
        'type' => 'geofield_leaflet',
        'weight' => 8,
      ),
      'search_index' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'slider_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_geocode',
    'label' => 'Geocode',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'geocoder',
      'settings' => array(
        'delta_handling' => 'default',
        'geocoder_field' => 'field_address',
        'geocoder_handler' => 'google',
        'handler_settings' => array(
          'google' => array(
            'all_results' => 0,
            'geometry_type' => 'point',
            'reject_results' => array(
              'APPROXIMATE' => 0,
              'GEOMETRIC_CENTER' => 0,
              'RANGE_INTERPOLATED' => 0,
              'ROOFTOP' => 0,
            ),
          ),
        ),
      ),
      'type' => 'geocoder',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-company-field_landline_phone'
  $field_instances['node-company-field_landline_phone'] = array(
    'bundle' => 'company',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 18,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'slider_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_landline_phone',
    'label' => 'Landline phone',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-company-field_mdb_sync_date'
  $field_instances['node-company-field_mdb_sync_date'] = array(
    'bundle' => 'company',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'search_index' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'slider_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_mdb_sync_date',
    'label' => 'MDB sync date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 1,
        'input_format' => 'Y-m-d H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_text',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-company-field_media_materials'
  $field_instances['node-company-field_media_materials'] = array(
    'bundle' => 'company',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'mediafield',
        'settings' => array(
          'file_view_mode' => 'default',
        ),
        'type' => 'media',
        'weight' => 8,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'mediafield',
        'settings' => array(
          'file_view_mode' => 'default',
        ),
        'type' => 'media',
        'weight' => 13,
      ),
      'search_index' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'slider_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_media_materials',
    'label' => 'Media materials',
    'required' => 0,
    'settings' => array(
      'file_extensions' => 'jpg jpeg gif png',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 0,
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 0,
          'image' => 'image',
          'video' => 'video',
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'media_internet' => 'media_internet',
          'upload' => 'upload',
        ),
      ),
      'type' => 'media_generic',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-company-field_mobile_phone'
  $field_instances['node-company-field_mobile_phone'] = array(
    'bundle' => 'company',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 17,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'search_index' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'slider_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_mobile_phone',
    'label' => 'Mobile phone',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-company-field_price_list'
  $field_instances['node-company-field_price_list'] = array(
    'bundle' => 'company',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'mediafield',
        'settings' => array(
          'file_view_mode' => 'default',
        ),
        'type' => 'media',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'mediafield',
        'settings' => array(
          'file_view_mode' => 'default',
        ),
        'type' => 'media',
        'weight' => 11,
      ),
      'search_index' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'slider_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_price_list',
    'label' => 'Price list',
    'required' => 0,
    'settings' => array(
      'file_extensions' => 'xls xlsx pdf',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'media',
      'settings' => array(
        'allowed_schemes' => array(
          'public' => 0,
          'youtube' => 0,
        ),
        'allowed_types' => array(
          'audio' => 0,
          'document' => 'document',
          'image' => 0,
          'video' => 0,
        ),
        'browser_plugins' => array(
          'media_default--media_browser_1' => 0,
          'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
          'media_internet' => 0,
          'upload' => 'upload',
          'youtube' => 0,
        ),
      ),
      'type' => 'media_generic',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-company-field_products'
  $field_instances['node-company-field_products'] = array(
    'bundle' => 'company',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'yellow_pages_company_ct',
        'settings' => array(),
        'type' => 'yp_product_default',
        'weight' => 23,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'yellow_pages_company_ct',
        'settings' => array(),
        'type' => 'yp_product_parent',
        'weight' => 9,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'yellow_pages_company_ct',
        'settings' => array(),
        'type' => 'yp_product_default',
        'weight' => 6,
      ),
      'slider_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'yellow_pages_company_ct',
        'settings' => array(),
        'type' => 'yp_product_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_products',
    'label' => 'Products',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'yellow_pages_company_ct',
      'settings' => array(),
      'type' => 'yp_product_field_products',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-company-field_social_links'
  $field_instances['node-company-field_social_links'] = array(
    'bundle' => 'company',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'socialfield',
        'settings' => array(
          'link_text' => FALSE,
        ),
        'type' => 'socialfield_formatter',
        'weight' => 12,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'socialfield',
        'settings' => array(
          'link_text' => FALSE,
        ),
        'type' => 'socialfield_formatter',
        'weight' => 7,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'socialfield',
        'settings' => array(
          'link_text' => FALSE,
        ),
        'type' => 'socialfield_formatter',
        'weight' => 4,
      ),
      'slider_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'socialfield',
        'settings' => array(
          'link_text' => FALSE,
        ),
        'type' => 'socialfield_formatter',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_social_links',
    'label' => 'Social links',
    'required' => 0,
    'settings' => array(
      'services' => array(
        'facebook' => 'facebook',
        'googleplus' => 'googleplus',
      ),
      'used_services' => array(
        'facebook' => 'facebook',
        'googleplus' => 'googleplus',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'socialfield',
      'settings' => array(),
      'type' => 'socialfield_widget',
      'weight' => 7,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Address');
  t('Advertisements');
  t('Articles');
  t('Description of activity');
  t('Email');
  t('Fax');
  t('Geocode');
  t('Landline phone');
  t('Logo');
  t('MDB sync date');
  t('Media materials');
  t('Mobile phone');
  t('Price list');
  t('Products');
  t('Site URL');
  t('Social links');

  return $field_instances;
}
