<?php
/**
 * @file
 * Layout markup for searchpage.
 */
?>
<div <?php if (!empty($css_id)) { print 'id="$css_id"'; } ?> class="yp-threecol-25-50-25-layout">
  <div class="row">
    <div class="col-sm-3">
      <?php print $content['alpha_25']; ?>
    </div>
    <div class="col-sm-6">
      <?php print $content['beta_50']; ?>
    </div>
    <div class="col-sm-3">
      <?php print $content['gamma_25']; ?>
    </div>
  </div>
</div>
