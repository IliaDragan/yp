<?php
/**
 * @file
 * Rewrites output of the field_brands field.
 */
?>
<?php if (!$label_hidden): ?>
  <strong><?php print $label ?>:</strong>
<?php endif; ?>
<?php foreach ($items as $delta => $item): ?>
<?php
  $item['#suffix'] = '. ';
  $item['#markup'] = l($item['#markup'], 'search/companies/' . strtolower($item['#markup']));

  print render($item);
?>
<?php endforeach; ?>