<?php
/**
 * @file
 * Advertisement node template override.
 */

$content['field_ad_url']['#items'][0]['html'] = TRUE;
$type = field_get_items('node', $node, 'field_ad_type');
$type = $type[0]['value'];
?>

<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="advertisement">
    <?php if ($type == 'image') : ?>
    <?php print l(render($content['field_ad_image']), $content['field_ad_url']['#items'][0]['url'], $content['field_ad_url']['#items'][0]); ?>
    <?php else: ?>
    <?php print $body[0]['safe_value']; ?>
    <?php endif; ?>
  </div>
</article>
