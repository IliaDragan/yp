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
