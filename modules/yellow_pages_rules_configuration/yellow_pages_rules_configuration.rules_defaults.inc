<?php
/**
 * @file
 * yellow_pages_rules_configuration.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function yellow_pages_rules_configuration_default_rules_configuration() {
  $items = array();
  $items['rules_advert_expire_in_day'] = entity_import('rules_config', '{ "rules_advert_expire_in_day" : {
      "LABEL" : "Advert expire in day",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "yellow_pages_rules_configuration", "rules" ],
      "ON" : { "advert_expire_in_day" : [] },
      "IF" : [
        { "yellow_pages_rules_configuration_advert_expire_day" : { "node" : [ "node" ] } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "4" : "4" } },
            "subject" : "\\u0423 \\u0440\\u0435\\u043a\\u043b\\u0430\\u043c\\u043d\\u043e\\u0433\\u043e \\u043e\\u0431\\u044a\\u044f\\u0432\\u043b\\u0435\\u043d\\u0438\\u044f [node:title] \\u0447\\u0435\\u0440\\u0435\\u0437 \\u0434\\u0435\\u043d\\u044c \\u0438\\u0441\\u0442\\u0435\\u0447\\u0435\\u0442 \\u0441\\u0440\\u043e\\u043a \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0446\\u0438\\u0438.",
            "message" : "\\u0423 \\u0440\\u0435\\u043a\\u043b\\u0430\\u043c\\u043d\\u043e\\u0433\\u043e \\u043e\\u0431\\u044a\\u044f\\u0432\\u043b\\u0435\\u043d\\u0438\\u044f [node:title] \\u0447\\u0435\\u0440\\u0435\\u0437 \\u0434\\u0435\\u043d\\u044c \\u0438\\u0441\\u0442\\u0435\\u0447\\u0435\\u0442 \\u0441\\u0440\\u043e\\u043a \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0446\\u0438\\u0438.\\r\\n\\u041f\\u0440\\u043e\\u0441\\u043c\\u043e\\u0442\\u0440\\u0435\\u0442\\u044c \\u043e\\u0431\\u044a\\u044f\\u0432\\u043b\\u0435\\u043d\\u0438\\u0435 [node:url].\\r\\n\\u0412\\u043d\\u0435\\u0441\\u0442\\u0438 \\u0438\\u0437\\u043c\\u0435\\u043d\\u0435\\u043d\\u0438\\u044f \\u0432 \\u043e\\u0431\\u044a\\u044f\\u0432\\u043b\\u0435\\u043d\\u0438\\u0435 [node:edit-url]."
          }
        }
      ]
    }
  }');
  $items['rules_advert_expire_in_week'] = entity_import('rules_config', '{ "rules_advert_expire_in_week" : {
      "LABEL" : "Advert expire in week",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "yellow_pages_rules_configuration", "rules" ],
      "ON" : { "advert_expire_in_week" : [] },
      "IF" : [
        { "yellow_pages_rules_configuration_advert_expire_week" : { "node" : [ "node" ] } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "4" : "4" } },
            "subject" : "\\u0423 \\u0440\\u0435\\u043a\\u043b\\u0430\\u043c\\u043d\\u043e\\u0433\\u043e \\u043e\\u0431\\u044a\\u044f\\u0432\\u043b\\u0435\\u043d\\u0438\\u044f [node:title] \\u0447\\u0435\\u0440\\u0435\\u0437 \\u0441\\u0435\\u043c\\u044c \\u0434\\u043d\\u0435\\u0439 \\u0438\\u0441\\u0442\\u0435\\u0447\\u0435\\u0442 \\u0441\\u0440\\u043e\\u043a \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0446\\u0438\\u0438.",
            "message" : "\\u0423 \\u0440\\u0435\\u043a\\u043b\\u0430\\u043c\\u043d\\u043e\\u0433\\u043e \\u043e\\u0431\\u044a\\u044f\\u0432\\u043b\\u0435\\u043d\\u0438\\u044f [node:title] \\u0447\\u0435\\u0440\\u0435\\u0437 \\u0441\\u0435\\u043c\\u044c \\u0434\\u043d\\u0435\\u0439 \\u0438\\u0441\\u0442\\u0435\\u0447\\u0435\\u0442 \\u0441\\u0440\\u043e\\u043a \\u043f\\u0443\\u0431\\u043b\\u0438\\u043a\\u0430\\u0446\\u0438\\u0438.\\r\\n\\u041f\\u0440\\u043e\\u0441\\u043c\\u043e\\u0442\\u0440\\u0435\\u0442\\u044c \\u043e\\u0431\\u044a\\u044f\\u0432\\u043b\\u0435\\u043d\\u0438\\u0435 [node:url].\\r\\n\\u0412\\u043d\\u0435\\u0441\\u0442\\u0438 \\u0438\\u0437\\u043c\\u0435\\u043d\\u0435\\u043d\\u0438\\u044f \\u0432 \\u043e\\u0431\\u044a\\u044f\\u0432\\u043b\\u0435\\u043d\\u0438\\u0435 [node:edit-url]."
          }
        }
      ]
    }
  }');
  $items['rules_company_update_notification'] = entity_import('rules_config', '{ "rules_company_update_notification" : {
      "LABEL" : "Company update notification",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "company", "editor", "update" ],
      "REQUIRES" : [ "yellow_pages_company_ct", "rules" ],
      "ON" : { "node_update--company" : { "bundle" : "company" } },
      "IF" : [
        { "yellow_pages_company_editors_not_empty" : { "company_node_nid" : [ "node:nid" ] } }
      ],
      "DO" : [
        { "mail" : {
            "to" : "[node:company-editors-emails]",
            "subject" : "Company [node:title] modified",
            "message" : "Company [node:title] was modified. You can access new data following this link [node:url].",
            "language" : [ "" ]
          }
        }
      ]
    }
  }');
  $items['rules_node_expire'] = entity_import('rules_config', '{ "rules_node_expire" : {
      "LABEL" : "Node sticky on top expire in 10 days",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "yellow_pages_rules_configuration", "rules" ],
      "ON" : { "node_expire_in_10_days" : [] },
      "IF" : [
        { "yellow_pages_rules_configuration_check_node_10_days" : { "node" : [ "node" ] } }
      ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "4" : "4" } },
            "subject" : "\\u0423 \\u043f\\u0440\\u0435\\u0434\\u043f\\u0440\\u0438\\u044f\\u0442\\u0438\\u0435 [node:title] \\u0447\\u0435\\u0440\\u0435\\u0437 \\u0434\\u0435\\u0441\\u044f\\u0442\\u044c \\u0434\\u043d\\u0435\\u0439 \\u0438\\u0441\\u0442\\u0435\\u0447\\u0435\\u0442 \\u0441\\u0440\\u043e\\u043a \\u0022\\u0412 \\u0442\\u043e\\u043f\\u0435\\u0022.",
            "message" : "\\u0423 \\u043f\\u0440\\u0435\\u0434\\u043f\\u0440\\u0438\\u044f\\u0442\\u0438\\u0435 [node:title] \\u0447\\u0435\\u0440\\u0435\\u0437 \\u0434\\u0435\\u0441\\u044f\\u0442\\u044c \\u0434\\u043d\\u0435\\u0439 \\u0438\\u0441\\u0442\\u0435\\u0447\\u0435\\u0442 \\u0441\\u0440\\u043e\\u043a \\u0022\\u0412 \\u0442\\u043e\\u043f\\u0435\\u0022.\\r\\n\\u041f\\u0440\\u043e\\u0441\\u043c\\u043e\\u0442\\u0440\\u0435\\u0442\\u044c \\u043f\\u0440\\u0435\\u0434\\u043f\\u0440\\u0438\\u044f\\u0442\\u0438\\u0435 [node:url].\\r\\n\\u0412\\u043d\\u0435\\u0441\\u0442\\u0438 \\u0438\\u0437\\u043c\\u0435\\u043d\\u0435\\u043d\\u0438\\u044f \\u0432 \\u043f\\u0440\\u0435\\u0434\\u043f\\u0440\\u0438\\u044f\\u0442\\u0438\\u0435 [node:edit-url]."
          }
        }
      ]
    }
  }');
  $items['rules_node_sticky_on_top_expired'] = entity_import('rules_config', '{ "rules_node_sticky_on_top_expired" : {
      "LABEL" : "Node sticky on top expired",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "node_expire", "rules" ],
      "ON" : { "node_expired" : [] },
      "IF" : [
        { "node_expire_rules_expired_check" : { "node" : [ "node" ] } },
        { "AND" : [ { "node_is_sticky" : { "node" : [ "node" ] } } ] }
      ],
      "DO" : [
        { "node_make_unsticky" : { "node" : [ "node" ] } },
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "4" : "4" } },
            "subject" : "\\u0423 \\u043f\\u0440\\u0435\\u0434\\u043f\\u0440\\u0438\\u044f\\u0442\\u0438\\u0435 [node:title] \\u0438\\u0441\\u0442\\u0435\\u043a \\u0441\\u0440\\u043e\\u043a \\u0022\\u0412 \\u0442\\u043e\\u043f\\u0435\\u0022.",
            "message" : "\\u0423 \\u043f\\u0440\\u0435\\u0434\\u043f\\u0440\\u0438\\u044f\\u0442\\u0438\\u0435 [node:title] \\u0438\\u0441\\u0442\\u0435\\u043a \\u0441\\u0440\\u043e\\u043a \\u0022\\u0412 \\u0442\\u043e\\u043f\\u0435\\u0022.\\r\\n\\u041f\\u0440\\u043e\\u0441\\u043c\\u043e\\u0442\\u0440\\u0435\\u0442\\u044c \\u043f\\u0440\\u0435\\u0434\\u043f\\u0440\\u0438\\u044f\\u0442\\u0438\\u0435 [node:url].\\r\\n\\u0412\\u043d\\u0435\\u0441\\u0442\\u0438 \\u0438\\u0437\\u043c\\u0435\\u043d\\u0435\\u043d\\u0438\\u044f \\u0432 \\u043f\\u0440\\u0435\\u0434\\u043f\\u0440\\u0438\\u044f\\u0442\\u0438\\u0435 [node:edit-url]."
          }
        },
        { "node_expire_unset_expired" : { "node" : [ "node" ] } }
      ]
    }
  }');
  $items['rules_publish_advert'] = entity_import('rules_config', '{ "rules_publish_advert" : {
      "LABEL" : "Publish advert",
      "PLUGIN" : "reaction rule",
      "ACTIVE" : false,
      "OWNER" : "rules",
      "REQUIRES" : [ "yellow_pages_rules_configuration", "rules" ],
      "ON" : { "advert_publish" : [] },
      "IF" : [
        { "yellow_pages_rules_configuration_advert_publish" : { "node" : [ "node" ] } }
      ],
      "DO" : [ { "node_publish" : { "node" : [ "node" ] } } ]
    }
  }');
  return $items;
}
