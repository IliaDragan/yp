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
      $class = 'inline-business-hours' . ($weekday_match ? ' today' : '');
      $markup .= '<div class="' . $class . '">';
      $markup .= '<table><tbody>';
      $markup .= '<tr><td class="weekday">' . t($hour['day']) . '</td></tr>';
      $day_off = $hour['start'] == 'None' || $hour['end'] == 'None';
      $time = $day_off ? t('Day off') : $hour['start'] . ' - ' . $hour['end'];
      $markup .= '<tr><td class="time">' . $time . '</td></tr>';
      $markup .= '</tbody></table>';
      $markup .= '</div>';
    }
    $markup = '<div class="business-hours">' . $markup . '</div>';
  }

  return $markup;
}
