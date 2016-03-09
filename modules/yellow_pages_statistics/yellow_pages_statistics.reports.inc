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
  $start_timestamp = strtotime($start_date . ' 00:00');
  $end_date = !empty($form_state['storage']['end_date']) ? $form_state['storage']['end_date'] : date('Y-m-d');
  $end_timestamp = strtotime($end_date . ' 23:59');

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

  $module_path = drupal_get_path('module', 'yellow_pages_statistics');
  $form['base_stat'] = array(
    '#type' => 'fieldset',
    '#title' => t('Statistics for selected period'),
  );
  $form['base_stat']['statistics'] = array(
    '#markup' => yellow_pages_statistics_get_statistics_data_for_node($node, $start_timestamp, $end_timestamp, $module_path),
  );
  $form['base_stat']['search'] = array(
    '#markup' => yellow_pages_statistics_get_search_statistics_data_for_node($node, $start_timestamp, $end_timestamp, $module_path),
  );
  if (!empty($node->field_advertisements['und'][0]['target_id'])) {
    $adv = node_load($node->field_advertisements['und'][0]['target_id']);
    $form['related_stat'] = array(
      '#type' => 'fieldset',
      '#title' => t('Company related advertisement statistics for selected period'),
    );
    $form['related_stat']['related_statistics'] = array(
      '#markup' => yellow_pages_statistics_get_statistics_data_for_node($adv, $start_timestamp, $end_timestamp, $module_path),
    );
  }

  $form['#attached']['css'] = array(
    $module_path . '/css/yellow_pages_statistics.css',
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

/**
 * Returns node statistic data for selected period.
 *
 * @param $node
 *   Node object of which statistic will be showed.
 * @param $start
 *   Start date timestamp.
 * @param $end
 *   End date timestamp.
 * @param $module_path
 *
 * @return string
 */
function yellow_pages_statistics_get_statistics_data_for_node(&$node, $start, $end, $module_path) {
  // Get all translations nodes nids.
  $nids = array();
  if (!empty($node->tnid)) {
    $nids = yellow_pages_core_node_get_translation_nids($node->tnid);
  }
  else {
    $nids[] = $node->nid;
  }

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
  $query_views = db_select($table_views, 'views')
    ->fields('views', array('id', 'timestamp'))
    ->condition('nid', $nids, 'IN')
    ->condition('timestamp', array($start, $end), 'BETWEEN');
  $result_views = $query_views->execute();
  $views_period = $result_views->rowCount();

  $query_clicks = db_select($table_clicks, 'clicks')
    ->fields('clicks', array('id', 'timestamp'))
    ->condition('nid', $nids, 'IN')
    ->condition('timestamp', array($start, $end), 'BETWEEN');
  $result_clicks = $query_clicks->execute();
  $clicks_period = $result_clicks->rowCount();

  $rows = array(
    array(
      array('data' => t('Period'), 'header' => TRUE),
      array('data' => t('Total'), 'header' => TRUE),
      array('data' => t('From @start to @end', array('@start' => format_date($start, 'custom', 'd M Y'), '@end' => format_date($end, 'custom', 'd M Y'))), 'header' => TRUE),
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
  $statistics_table = theme('table', array('rows' => $rows));

  // Create chart.
  $dates = yellow_pages_core_date_range($start, $end, '+1 day', 'd M Y', 'Ymd');
  $chart_data = array();
  foreach ($dates as $key => $date) {
    $chart_data[$key] = array(
      'date' => $date,
      'views' => 0,
      'clicks' => 0,
    );
  }

  foreach ($result_views as $view) {
    $date = date('Ymd', $view->timestamp);
    $chart_data[$date]['views']++;
  }

  foreach ($result_clicks as $click) {
    $date = date('Ymd', $click->timestamp);
    $chart_data[$date]['clicks']++;
  }
  $chart_prepared_array = array(
    array(
      array('label' => t('Date'), 'type' => 'string'),
      array('label' => t('Views'), 'type' => 'number'),
      array('label' => t('Clicks'), 'type' => 'number'),
    ),
  );
  foreach ($chart_data as $row) {
    $chart_prepared_array[] = array(
      $row['date'],
      $row['views'],
      $row['clicks'],
    );
  }
  $js_data = array('nodeStatistics' => array(
    $node->type . 'ChartData' => json_encode($chart_prepared_array),
  ));

  drupal_add_js($js_data, 'setting');
  drupal_add_js('http://www.google.com/jsapi', array('type' => 'external', 'group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/yellow_pages_statistics_node.chart.js');

  $chart = '<div id="'.$node->type.'Chart"></div>';

  return $statistics_table . $chart;
}

/**
 * Returns node search statistic data for selected period.
 *
 * @param $node
 *   Node object of which statistic will be showed.
 * @param $start
 *   Start date timestamp.
 * @param $end
 *   End date timestamp.
 * @param $module_path
 *
 * @return string
 */
function yellow_pages_statistics_get_search_statistics_data_for_node(&$node, $start, $end, $module_path) {
  if ($node->type == 'company') {
    // Get all translations nodes nids.
    $nids = array();
    if (!empty($node->tnid)) {
      $nids = yellow_pages_core_node_get_translation_nids($node->tnid);
    }
    else {
      $nids[] = $node->nid;
    }

    $languages = array();
    foreach ($nids as $lang => $nid) {
      $language = i18n_language_load($lang);
      $languages[$nid] = t($language->name);
    }

    $rows = array();

    $query = db_select('yp_search_company_statistics', 'scs')
      ->fields('scs', array('nid', 'timestamp', 'page', 'keywords'))
      ->condition('timestamp', array($start, $end), 'BETWEEN')
      ->condition('nid', $nids, 'IN');
    $result = $query->execute();

    $total = $result->rowCount();

    if (!empty($total)) {
      foreach ($result as $row) {
        $rows[] = array(
          format_date($row->timestamp, 'custom', 'd M Y H:i'),
          $row->keywords,
          $row->page + 1,
          $languages[$row->nid],
        );
      }

      $rows[] = array(
        t('TOTAL'),
        array(
          'data' => t('@total views', array('@total' => $total)),
          'colspan' => 3,
        ),
      );
    }

    $table = array(
      'header' => array(
        t('Date/time'),
        t('Search phrase'),
        t('Page'),
        t('Language'),
      ),
      'caption' => t('Search statistics'),
      'empty' => t('No search statistics for this period.'),
      'rows' => $rows,
    );

    return theme('table', $table);
  }
  else {
    return '';
  }
}

/**
 * Form callback - show search statistics information by period.
 */
function yellow_pages_search_statistics($form, &$form_state) {
  $start_date = !empty($form_state['storage']['start_date']) ? $form_state['storage']['start_date'] : date('Y-m-d', strtotime('-1month'));
  $start_timestamp = strtotime($start_date . ' 00:00');
  $end_date = !empty($form_state['storage']['end_date']) ? $form_state['storage']['end_date'] : date('Y-m-d');
  $end_timestamp = strtotime($end_date . ' 23:59');

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

  $query = db_select('yp_search_statistics', 'yss')
    ->fields('yss', array('keywords'))
    ->condition('timestamp', array($start_timestamp, $end_timestamp), 'BETWEEN');
  $query->addExpression('COUNT(yss.id)', 'search_count');
  $query->groupBy('yss.keywords');
  $query->orderBy('search_count', 'DESC');
  $result = $query->execute();

  $rows = array();
  while($record = $result->fetchAssoc()) {
    $rows[] = $record;
  }

  $table = array(
    'header' => array(
      t('Search phrase'),
      t('Count of searching'),
    ),
    'caption' => t('Search phrases statistics'),
    'empty' => t('No search phrases statistics for this period.'),
    'rows' => $rows,
  );

  $form['result'] = array(
    '#markup' => theme('table', $table),
  );

  $module_path = drupal_get_path('module', 'yellow_pages_statistics');
  $form['#attached']['css'] = array(
    $module_path . '/css/yellow_pages_statistics.css',
  );

  return $form;
}

/**
 * Submit action for yellow_pages_search_statistics().
 */
function yellow_pages_search_statistics_submit(&$form, &$form_state) {
  $values = $form_state['values'];
  $form_state['storage']['start_date'] = $values['start_date'];
  $form_state['storage']['end_date'] = $values['end_date'];
  $form_state['rebuild'] = TRUE;
}
