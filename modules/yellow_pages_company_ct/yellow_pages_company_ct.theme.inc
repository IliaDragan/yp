<?php

/**
 * @file
 * Theme functions.
 */

/**
 * Returns HTML for enterprise work hours.
 */
function theme_business_hours($vars) {
  $markup = '';
  if (!empty($vars['hours'])) {
    $cells = array();
    foreach ($vars['hours'] as $hour) {
      $day_off = $hour['start'] == 'None' || $hour['end'] == 'None';
      $time = $day_off ? t('Day off') : $hour['start'] . ' - ' . $hour['end'];
      $cells[] = '<div>' . t($hour['day']) . '</div><div>' . $time . '</div>';
    }

    $table_vars = array(
      'rows' => array($cells),
      'attributes' => array(
        'class' => 'business-hours',
      ),
    );
    $markup = theme('table', $table_vars);
  }

  return $markup;
}

function theme_business_hours_for_email($vars) {
  $markup = '';
  $cell_style = "border: 1px solid #444444; padding: 5px; min-width: 65px; text-align: center; font-size: 10px;";
  $table_style = "border-collapse: collapse;";
  if (!empty($vars['hours'])) {
    $cells = array();
    foreach ($vars['hours'] as $hour) {
      $day_off = $hour['start'] == 'None' || $hour['end'] == 'None';
      $time = $day_off ? t('Day off') : $hour['start'] . ' - ' . $hour['end'];
      $cells[] = array(
        'data' => '<div style="text-transform: capitalize;">' . t($hour['day']) . '</div><div>' . $time . '</div>',
        'style' => $cell_style,
      );
    }

    $table_vars = array(
      'rows' => array($cells),
      'attributes' => array(
        'class' => 'business-hours',
        'style' => $table_style,
      ),
    );
    $markup = theme('table', $table_vars);
  }

  return $markup;
}