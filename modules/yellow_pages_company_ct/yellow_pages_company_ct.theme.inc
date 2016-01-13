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
    foreach ($vars['hours'] as $hour) {
      $weekday_match = $hour['day'] == $vars['weekday'];
      $markup .= $weekday_match ? '<tr class="today">' : '<tr>';
      $markup .= '<td class="weekday">' . t($hour['day']) . '</td>';
      $day_off = $hour['start'] == 'None' || $hour['end'] == 'None';
      $time = $day_off ? t('Day off') : $hour['start'] . ' - ' . $hour['end'];
      $markup .= '<td class="time">' . $time . '</td>';
      $markup .= '</tr>';
    }
    $markup = '<table class="business-hours"><tbody>' . $markup . '</tbody></table>';
  }

  return $markup;
}
