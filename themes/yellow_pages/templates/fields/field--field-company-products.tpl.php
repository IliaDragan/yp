<?php
/**
 * @file
 * Rewrites output of the field_company_products field.
 */
?>
<?php if (!$label_hidden): ?>
  <strong><?php print $label ?>:</strong>
<?php endif; ?>
<ul class="<?php print $classes; ?>">
<?php foreach ($items as $delta => $item): ?>
<?php
  $item['#prefix'] = '<li>';
  $item['#suffix'] = ';</li>';
  $item['#href'] = url('search/companies', array('absolute' => TRUE)) . '?f[0]=field_company_products%253Aproduct%253Aparents_all%3A' . $item['#options']['entity']->tid;

  print render($item);
?>
<?php endforeach; ?>
</ul>
