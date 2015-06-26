<?php
/**
 * @file
 * YellowPages rates block template.
 */
?>
<div class="yp-widget yp-weather">
  <h2 class="title">Weather <span class="info">(Chisinau)</span></h2>
  <div class="entry">
    <span class="date <?php print $weather['classes']; ?>"><?php print date('D, d/m')?></span>
  </div>
  <div class="entry">
    <span class="temperature"><?php print $weather['temperature']; ?> &deg;</span>
  </div>
  <div class="entry">
    <span class="pressure"><?php print $weather['pressure']; ?>mm</span>
  </div>
  <div class="entry">
    <span class="wind"><?php print $weather['wind_dir']; ?>, <?php print $weather['wind_speed']; ?>m/s</span>
  </div>
  <p class="link"><?php print l('http://openweathermap.org/', 'http://openweathermap.org/', array('attributes' => array('target' => '_blank'))); ?></p>
</div>
