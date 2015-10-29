<?php

/**
 * @file
 * Default theme implementation for company node changed fields.
 *
 * Available variables:
 * - $diff: The differences between fields of changed and unchanged node
 */
?>
<b style="font-size: 18px;">
  <?php print t('Modified fields:'); ?>
</b>
<div style="color: green;">
  <ul>
    <?php foreach($diff as $field): ?>
      <li>
        <b><?php print $field['label']; ?></b>
        <?php print var_export($field, TRUE); ?>
      </li>
    <?php endforeach; ?>
  </ul>
</div>
