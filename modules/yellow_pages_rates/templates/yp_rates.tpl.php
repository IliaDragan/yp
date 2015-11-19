<?php
/**
 * @file
 * YellowPages rates block template.
 */
?>
<div class="yp-widget yp-rates">
  <h5 class="block-title"><?php print t('Currency rates'); ?> <span class="info"><?php print t('(Banca Nationala)'); ?></span></h5>
  <?php foreach($rates as $currency => $rate) : ?>
  <div class="entry">
    <span class="<?php print drupal_html_class($currency); ?> currency info"><?php print $currency; ?></span>
    <span class="amount"><?php print $rate['nominal']; ?></span>
    <span class="rate"><?php print $rate['value']; ?></span>
  </div>
  <?php endforeach; ?>
  <p class="link"><?php print l('bnm.md', 'http://bnm.md/', array('attributes' => array('target' => '_blank'))); ?></p>
</div>
