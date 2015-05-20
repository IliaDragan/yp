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
  $items['rules_node_expire'] = entity_import('rules_config', '{ "rules_node_expire" : {
      "LABEL" : "Node sticky on top expire",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "node_expire", "rules" ],
      "ON" : { "node_expired" : [] },
      "IF" : [ { "node_expire_rules_expired_check" : { "node" : [ "node" ] } } ],
      "DO" : [
        { "node_make_unsticky" : { "node" : [ "node" ] } },
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "4" : "4" } },
            "subject" : "\\u0423 \\u043f\\u0440\\u0435\\u0434\\u043f\\u0440\\u0438\\u044f\\u0442\\u0438\\u0435 [node:title] \\u0438\\u0441\\u0442\\u0435\\u043a \\u0441\\u0440\\u043e\\u043a \\u0022\\u0412 \\u0442\\u043e\\u043f\\u0435.\\u0022",
            "message" : "\\u0423 \\u043f\\u0440\\u0435\\u0434\\u043f\\u0440\\u0438\\u044f\\u0442\\u0438\\u0435 [node:title] \\u0438\\u0441\\u0442\\u0435\\u043a \\u0441\\u0440\\u043e\\u043a \\u0022\\u0412 \\u0442\\u043e\\u043f\\u0435.\\u0022\\r\\n\\u041f\\u0440\\u043e\\u0441\\u043c\\u043e\\u0442\\u0440\\u0435\\u0442\\u044c \\u043f\\u0440\\u0435\\u0434\\u043f\\u0440\\u0438\\u044f\\u0442\\u0438\\u0435 [node:url].\\r\\n\\u0412\\u043d\\u0435\\u0441\\u0442\\u0438 \\u0438\\u0437\\u043c\\u0435\\u043d\\u0435\\u043d\\u0438\\u044f \\u0432 \\u043f\\u0440\\u0435\\u0434\\u043f\\u0440\\u0438\\u044f\\u0442\\u0438\\u0435 [node:edit-url]."
          }
        }
      ]
    }
  }');
  return $items;
}