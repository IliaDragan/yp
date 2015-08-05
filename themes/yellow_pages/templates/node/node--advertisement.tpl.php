<?php
/**
 * @file
 * Advertisement node template override.
 */

$content['field_ad_url']['#items'][0]['html'] = TRUE;
$type = field_get_items('node', $node, 'field_ad_type');
$type = $type[0]['value'];
$ad_url = isset($content['field_ad_url']['#items'][0]['url']) ? $content['field_ad_url']['#items'][0]['url'] : '';
$ad_body = isset($body[0]['safe_value']) ? $body[0]['safe_value'] : '';
?>

<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="advertisement">
    <?php if ($type == 'image') : ?>
    <?php print l(render($content['field_ad_image']), $ad_url, $content['field_ad_url']['#items'][0]); ?>
    <?php else: ?>
    <?php print $ad_body; ?>
    <?php endif; ?>
  </div>
</article>
