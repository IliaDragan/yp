<?php
/**
 * @file
 * Advertisement node template override.
 */
// @todo
// That's lame.
// Move outside of template.
$type = field_get_items('node', $node, 'field_ad_type');
$type = $type[0]['value'];
$ad_content = '';

if ($type == 'image' && isset($content['field_ad_image']['#items'][0]['uri'])) {
  $ad_image = file_create_url($content['field_ad_image']['#items'][0]['uri']);
  $content['field_ad_url']['#items'][0]['html'] = TRUE;
  $content['field_ad_url']['#items'][0]['attributes']['style'] = 'width:100%; height:90px; background: url("' . $ad_image . '") 50% 0 no-repeat; display:block;margin: 0 auto;border:none;';

  $ad_content = l('', $ad_url, $content['field_ad_url']['#items'][0]);
}
else {
  $ad_url = isset($content['field_ad_url']['#items'][0]['url']) ? $content['field_ad_url']['#items'][0]['url'] : '';
  $ad_body = isset($body[0]['safe_value']) ? $body[0]['safe_value'] : '';
  $ad_content = $ad_body;
}
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="advertisement">
    <?php print $ad_content; ?>
  </div>
</article>
