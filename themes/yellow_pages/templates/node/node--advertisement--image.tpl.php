<?php
/**
 * @file
 * Advertisement node template override for image ad type.
 */

?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix" <?php print $attributes; ?>>
  <div class="advertisement">
    <a href="<?php print $link_href; ?>" <?php print $link_attributes; ?>>
      <?php
      print render($content['field_ad_image']);
      ?>
    </a>
  </div>
</article>
