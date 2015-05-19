<?php
/**
 * @file
 * Layout markup for searchpage.
 */
?>
<div <?php if (!empty($css_id)) { print 'id="$css_id"'; } ?> class="yp-twocol-75-25-layout">
  <div class="row">
    <div class="col-sm-9">
      <?php print $content['alpha_75']; ?>
    </div>
    <div class="col-sm-3">
      <?php print $content['beta_25']; ?>
    </div>
  </div>
</div>
