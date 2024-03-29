<?php
/**
 * @file
 * yellow_pages_solr_configuration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function yellow_pages_solr_configuration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function yellow_pages_solr_configuration_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_index().
 */
function yellow_pages_solr_configuration_default_search_api_index() {
  $items = array();
  $items['company_nodes'] = entity_import('search_api_index', '{
    "name" : "Company nodes",
    "machine_name" : "company_nodes",
    "description" : null,
    "server" : "yp",
    "item_type" : "node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "body:value" : { "type" : "text", "boost" : "2.0" },
        "city_filter" : { "type" : "string" },
        "field_address:locality" : { "type" : "text", "boost" : "0.8" },
        "field_address:thoroughfare" : { "type" : "text", "boost" : "0.8" },
        "field_brands" : { "type" : "list\\u003Ctext\\u003E" },
        "field_email" : { "type" : "list\\u003Ctext\\u003E", "boost" : "0.2" },
        "field_fax" : { "type" : "list\\u003Ctext\\u003E", "boost" : "0.3" },
        "field_invisible_field" : { "type" : "text", "boost" : "8.0" },
        "field_landline_phone" : { "type" : "list\\u003Ctext\\u003E", "boost" : "0.3" },
        "field_mobile_phone" : { "type" : "list\\u003Ctext\\u003E", "boost" : "0.3" },
        "field_products:product" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_products:product:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_products:product:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_region" : { "type" : "string" },
        "language" : { "type" : "string" },
        "nid" : { "type" : "integer" },
        "search_api_language" : { "type" : "string" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : { "company" : "company", "news" : "news", "article" : "article" }
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 1,
          "weight" : "0",
          "settings" : {
            "lang_field" : "language",
            "languages" : { "en" : "en", "ro" : "ro", "ru" : "ru" }
          }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 1, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "field_invisible_field" : true,
              "body:value" : true,
              "field_products:product" : true,
              "field_products:product:name" : true,
              "field_products:product:parents_all" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "title" : true, "body:value" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 1,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_products:product:name" : true,
              "field_products:product:parents_all" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc\\r\\nex e\\r\\n\\u0438 \\u0438\\u043b\\u0438 \\u043d\\u0430 \\u043f\\u043e\\u0434 \\u0432 \\u0438\\u0437\\r\\n\\u0219i \\u00een pe la lui"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function yellow_pages_solr_configuration_default_search_api_server() {
  $items = array();
  $items['yp'] = entity_import('search_api_server', '{
    "name" : "yp",
    "machine_name" : "yp",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "localhost",
      "port" : "8983",
      "path" : "\\/solr",
      "http_user" : "root",
      "http_pass" : "WLZQE5Jk6y",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO"
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
