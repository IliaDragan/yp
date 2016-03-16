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
    '#title' => t('Statistics of @title from @start to @end', array('@title' => $node->title, '@start' => date('d.m.Y', $start_timestamp), '@end' => date('d.m.Y', $end_timestamp))),
  );
  $form['base_stat']['statistics'] = array(
    '#markup' => yellow_pages_statistics_get_statistics_data_for_node($node, $start_timestamp, $end_timestamp, $module_path),
  );
  $form['base_stat']['search'] = array(
    '#markup' => yellow_pages_statistics_get_search_statistics_data_for_node($node, $start_timestamp, $end_timestamp, $module_path),
  );

  $has_related_adv = !empty($node->field_advertisements['und'][0]['target_id']);
  if ($has_related_adv) {
    $adv = node_load($node->field_advertisements['und'][0]['target_id']);
    $form['related_stat'] = array(
      '#type' => 'fieldset',
      '#title' => t('Company related advertisement statistics for selected period'),
    );
    $form['related_stat']['related_statistics'] = array(
      '#markup' => yellow_pages_statistics_get_statistics_data_for_node($adv, $start_timestamp, $end_timestamp, $module_path),
    );
  }

  $form['period']['print_button'] = array(
    '#markup' => yellow_pages_statistics_print_button($node->type, $has_related_adv, $module_path),
  );

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
      $views_title = t('Company card views');
      $clicks_title = t('Clicks on the site link');
      break;

    case 'advertisement':
      $table_views = 'yp_ad_nodeviewcount';
      $table_clicks = 'yp_ad_statistics';
      $views_title = t('Banner views');
      $clicks_title = t('Clicks on the banner');
      break;
  }

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
  $chart_prepared_views_array = array(
    array(
      array('label' => t('Date'), 'type' => 'string'),
      array('label' => $views_title, 'type' => 'number'),
    ),
  );
  $chart_prepared_clicks_array = array(
    array(
      array('label' => t('Date'), 'type' => 'string'),
      array('label' => $clicks_title, 'type' => 'number'),
    ),
  );
  foreach ($chart_data as $row) {
    $chart_prepared_views_array[] = array(
      $row['date'],
      $row['views'],
    );
    $chart_prepared_clicks_array[] = array(
      $row['date'],
      $row['clicks'],
    );
  }
  $js_data = array('nodeStatistics' => array(
    $node->type . 'ViewsChartData' => array(
      'title' => $views_title . ': ' . $views_period,
      'values' => json_encode($chart_prepared_views_array),
    ),

    $node->type . 'ClicksChartData' => array(
      'title' => $clicks_title . ': ' . $clicks_period,
      'values' => json_encode($chart_prepared_clicks_array),
    )
  ));

  drupal_add_js($js_data, 'setting');
  drupal_add_js('http://www.google.com/jsapi', array('type' => 'external', 'group' => JS_LIBRARY));
  drupal_add_js($module_path . '/js/yellow_pages_statistics_node.chart.js');

  $views_chart = '<div id="'.$node->type.'-views-chart" class="print-views-'.$node->type.'"></div>';
  $clicks_chart = '<div id="'.$node->type.'-clicks-chart" class="print-clicks-'.$node->type.'"></div>';

  return $views_chart . $clicks_chart;
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
      'attributes' => array(
        'class' => array('print-search'),
      ),
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

/**
 * Function that create print button and its options for statistics page.
 *
 * @param $type
 *   Node content type.
 * @param $has_adv
 *   Flag if node has related advertisement.
 * @param $module_path
 *   Path to yellow_page_statistics module.
 *
 * @return string
 *   Html of print button and its options depend on params.
 */
function yellow_pages_statistics_print_button($type, $has_adv, $module_path) {
  $output = '<div id="print-wrapper" class="clearfix">';
  $output .= '<a id="print-button" class="button" href="javascript:yellowPagesStatisticsPrint();">' . t('Print') . '</a>';

  $views_title = ucfirst($type) . ' views count';
  $clicks_title = ucfirst($type) . ' clicks';
  $output .= '<div id="print-checkboxes" class="clearfix">';
  $output .= '<div class="print-checkbox"><input type="checkbox" name="' . $type . '_views" value="' . $type . ' views" id="print-views-' . $type . '" checked="checked">' . t($views_title) . '</div>';
  $output .= '<div class="print-checkbox"><input type="checkbox" name="' . $type . '_clicks" value="' . $type . ' clicks" id="print-clicks-' . $type . '" checked="checked">' . t($clicks_title) . '</div>';

  if ($type == 'company') {
    $output .= '<div class="print-checkbox"><input type="checkbox" name="search" value="Search" id="print-search" checked="checked">' . t('Search statistics') . '</div>';

    if ($has_adv) {
      $output .= '<div class="print-checkbox"><input type="checkbox" name="advertisement_views" value="advertisement views" id="print-views-advertisement" checked="checked">' . t('Advertisement views count') . '</div>';
      $output .= '<div class="print-checkbox"><input type="checkbox" name="advertisement_clicks" value="advertisement clicks" id="print-clicks-advertisement" checked="checked">' . t('Advertisement clicks') . '</div>';
    }
  }

  $output .= '</div>';
  $output .= '</div>';

  drupal_add_js($module_path . '/js/yellow_pages_statistics_print.js');

  return $output;
}
