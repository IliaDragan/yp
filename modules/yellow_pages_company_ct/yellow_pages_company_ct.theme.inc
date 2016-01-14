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
      $markup .= '<td>';
      $markup .= '<div class="weekday">' . t($hour['day']) . '</div>';
      $day_off = $hour['start'] == 'None' || $hour['end'] == 'None';
      $time = $day_off ? t('Day off') : $hour['start'] . ' - ' . $hour['end'];
      $markup .= '<div class="time">' . $time . '</div>';
      $markup .= '</td>';
    }
    $markup = '<table class="business-hours"><tr>' . $markup . '</tr></table>';
  }

  return $markup;
}
