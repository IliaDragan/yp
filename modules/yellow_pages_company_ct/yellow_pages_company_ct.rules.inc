<?php

/**
 * @file
 * Yellow pages company content type conditions for Rules.
 */

/**
 * Implements hook_rules_condition_info().
 */
function yellow_pages_company_ct_rules_condition_info() {
  $conditions = array();
  $conditions['yellow_pages_company_editors_not_empty'] = array(
    'label' => t('Check if company has related users.'),
    'parameter' => array(
      'company_node_nid' => array(
        'type' => 'integer',
        'label' => t('Company node nid'),
        'description' => t('Select the nid of company node'),
      ),
    ),
    'group' => t('Custom'),
  );

  return $conditions;
}

/**
 * The 'yellow_pages_company_editors_not_empty' condition.
 *
 * @param $company_node_nid
 *   An integer representing the company node nid.
 *
 * @return
 *   TRUE if company node has related editors, FALSE otherwise.
 */
function yellow_pages_company_editors_not_empty($company_node_nid) {
  return _check_company_has_editors($company_node_nid);
}
