<?php
/**
 * @file
 * Code for the Yellow Pages statistics reports.
 */

/**
 * Page callback - node statistics tab.
 *
 * @param $node
 */
function yellow_pages_statistics_node_stat($node) {
  $statistics_node_types = array('company', 'advertisement');

  if (in_array($node->type, $statistics_node_types)) {
    $data = drupal_get_form('yellow_pages_statistics_node_stat_report_form', $node);
  }
  else {
    $data = t('No statistics information for this node.');
  }

  return $data;
}

/**
 * Form callback - show node statistics information by period.
 *
 * @param $node
 */
function yellow_pages_statistics_node_stat_report_form($form, &$form_state, $node) {
  $start_date = !empty($form_state['storage']['start_date']) ? $form_state['storage']['start_date'] : date('Y-m-d', strtotime('-1month'));
  $start_timestamp = strtotime($start_date);
  $end_date = !empty($form_state['storage']['end_date']) ? $form_state['storage']['end_date'] : date('Y-m-d');
  $end_timestamp = strtotime($end_date);
  // Get all company translations nids.
  if (empty($form_state['storage']['nids'])) {
    $nids = array();
    if (!empty($node->tnid)) {
      $nids = yellow_pages_core_node_get_translation_nids($node->tnid);
    }
    else {
      $nids[] = $node->nid;
    }
    $form_state['storage']['nids'] = $nids;
  }
  else {
    $nids = $form_state['storage']['nids'];
  }

  $form['period'] = array(
    '#title' => t('Select period'),
    '#type' => 'fieldset',
  );
  $form['period']['start_date'] = array(
    '#title' => t('Start date'),
    '#type' => 'date_popup',
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-3:0',
    '#default_value' => $start_date,
    '#required' => TRUE,
  );
  $form['period']['end_date'] = array(
    '#title' => t('End date'),
    '#type' => 'date_popup',
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-3:0',
    '#default_value' => $end_date,
    '#required' => TRUE,
  );
  $form['period']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Show'),
  );

  switch ($node->type) {
    case 'company':
      $table_views = 'nodeviewcount';
      $table_clicks = 'yp_company_statistics';
      break;

    case 'advertisement':
      $table_views = 'yp_ad_nodeviewcount';
      $table_clicks = 'yp_ad_statistics';

      break;
  }

  // Statistics total.
  $query = db_select($table_views, 'views')
    ->fields('views', array('id'))
    ->condition('nid', $nids, 'IN');
  $views = $query->execute()->rowCount();

  $query = db_select($table_clicks, 'clicks')
    ->fields('clicks', array('id'))
    ->condition('nid', $nids, 'IN');
  $clicks = $query->execute()->rowCount();

  // Statistics for period.
  $query = db_select($table_views, 'views')
    ->fields('views', array('id'))
    ->condition('nid', $nids, 'IN')
    ->condition('timestamp', array($start_timestamp, $end_timestamp), 'BETWEEN');
  $views_period = $query->execute()->rowCount();

  $query = db_select($table_clicks, 'clicks')
    ->fields('clicks', array('id'))
    ->condition('nid', $nids, 'IN')
    ->condition('timestamp', array($start_timestamp, $end_timestamp), 'BETWEEN');
  $clicks_period = $query->execute()->rowCount();

  $rows = array(
    array(
      array('data' => t('Period'), 'header' => TRUE),
      array('data' => t('Total'), 'header' => TRUE),
      array('data' => t('From @start to @end', array('@start' => format_date($start_timestamp, 'custom', 'd M Y'), '@end' => format_date($end_timestamp, 'custom', 'd M Y'))), 'header' => TRUE),
    ),
    array(
      array('data' => t('Views'), 'header' => TRUE),
      $views,
      $views_period,
    ),
    array(
      array('data' => t('Clicks'), 'header' => TRUE),
      $clicks,
      $clicks_period,
    ),
  );

  $form['statistics'] = array(
    '#markup' => theme('table', array('rows' => $rows)),
  );

  $form['#attached']['css'] = array(
    drupal_get_path('module', 'yellow_pages_statistics') . '/css/yellow_pages_statistics.css',
  );

  return $form;
}

/**
 * Submit action for yellow_pages_statistics_node_stat_report_form().
 */
function yellow_pages_statistics_node_stat_report_form_submit(&$form, &$form_state) {
  $values = $form_state['values'];
  $form_state['storage']['start_date'] = $values['start_date'];
  $form_state['storage']['end_date'] = $values['end_date'];
  $form_state['rebuild'] = TRUE;
}
