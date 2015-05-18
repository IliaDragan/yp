<?php
/**
 * @file
 * Layout markup for searchpage.
 */
?>
<div <?php if (!empty($css_id)) { print 'id="$css_id"'; } ?> class="yp-twocol-25-75-layout">
  <div class="row">
    <div class="col-sm-4">
      <?php print $content['alpha_25']; ?>
    </div>
    <div class="col-sm-8">
      <?php print $content['beta_75']; ?>
    </div>
  </div>
</div>
