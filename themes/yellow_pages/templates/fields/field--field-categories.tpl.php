<?php
/**
 * @file
 */
?>
<?php if (!$label_hidden): ?>
  <strong><?php print $label ?>:</strong>
<?php endif; ?>
<ul class="<?php print $classes; ?>">
<?php foreach ($items as $delta => $item): ?>
<?php
  $item['#prefix'] = '<li>';
  $item['#suffix'] = '</li>;';
  $item['#href'] = url('search/companies', array('absolute' => TRUE)) . '?f[0]=' . $element['#field_name'] . '%3A' . $item['#options']['entity']->tid;

  print render($item);
?>
<?php endforeach; ?>
</ul>
