<?php
/**
 * @file
 * YellowPages rates block template.
 */
?>
<div class="yp-widget yp-rates">
  <h2 class="title">Currency rates <span class="info">(Banca Nationala)</span></h2>
  <?php foreach($rates as $currency => $rate) : ?>
  <div class="entry">
    <span class="<?php print drupal_html_class($currency); ?> currency info"><?php print $currency; ?></span>
    <span class="amount"><?php print $rate['nominal']; ?></span>
    <span class="rate"><?php print $rate['value']; ?></span>
  </div>
  <?php endforeach; ?>
  <p class="link"><?php print l('http://bnm.md/', 'http://bnm.md/', array('attributes' => array('target' => '_blank'))); ?></p>
</div>
