<?php
/**
 * @file
 * Layout markup for frontpage.
 */
?>
<div <?php if (!empty($css_id)) { print 'id="$css_id"'; } ?> class="yp-node-layout">
  <div class="row">
    <div class="col-sm-12">
      <?php print $content['main']; ?>
    </div>
  </div>
</div>
