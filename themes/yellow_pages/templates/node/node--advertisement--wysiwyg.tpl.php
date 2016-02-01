<?php
/**
 * @file
 * Advertisement node template for wysiwyg ad type override.
 */
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix" <?php print $attributes; ?>>
  <div class="advertisement">
    <?php print render($body); ?>
  </div>
</article>
