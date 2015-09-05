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
$category = field_get_items('node', $node, 'field_ad_category');
$category = $category[0]['value'];
$ad_content = '';

if ($type == 'image' && isset($content['field_ad_image']['#items'][0]['uri'])) {
  $ad_image = file_create_url($content['field_ad_image']['#items'][0]['uri']);
  $ad_url = isset($content['field_ad_url']['#items'][0]['url']) ? $content['field_ad_url']['#items'][0]['url'] : '';
  $content['field_ad_url']['#items'][0]['html'] = TRUE;
  $content['field_ad_url']['#items'][0]['attributes']['style'] = 'background: url("' . $ad_image . '") 50% 0 no-repeat; display:block; margin: 0 auto; border:none;';
  $size = '';
  if ($category == 'topbar') {
    $size = 'width:100%; height:90px;';
  }
  elseif ($category == 'sidebar') {
    $size = 'width:315px; height:430px;';
  }
  // @todo
  // Other types as well.

  $content['field_ad_url']['#items'][0]['attributes']['style'] .= $size;

  $ad_content = l('', $ad_url, $content['field_ad_url']['#items'][0]);
}
else {
  $ad_body = isset($body[0]['safe_value']) ? $body[0]['safe_value'] : '';
  $ad_content = $ad_body;
}
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="advertisement">
    <?php print $ad_content; ?>
  </div>
</article>
