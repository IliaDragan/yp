<?php
/**
 * @file
 * YellowPages rates block template.
 */
?>
<div class="yp-widget yp-weather">
  <h2 class="title"><?php print t('Weather'); ?> <span class="info"><?php print t('(Chisinau)')?></span></h2>
  <div class="entry">
    <span class="date <?php print $weather['classes']; ?>"><?php print date('D, d/m')?></span>
  </div>
  <div class="entry">
    <span class="temperature"><?php print $weather['temperature']; ?> &deg;C</span>
  </div>
  <div class="entry">
    <span class="pressure"><?php print $weather['pressure']; ?><?php print t('mm'); ?></span>
  </div>
  <div class="entry">
    <span class="wind"><?php print $weather['wind_dir']; ?>, <?php print $weather['wind_speed']; ?><?php print t('m/s'); ?></span>
  </div>
  <p class="link"><?php print l('openweathermap.org', 'http://openweathermap.org/', array('attributes' => array('target' => '_blank'))); ?></p>
</div>
