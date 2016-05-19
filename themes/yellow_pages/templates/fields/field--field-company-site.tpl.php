<?php
/**
 * @file
 * Rewrites output of the field_company_site field.
 */
?>

<?php if (!$label_hidden): ?>
  <strong><?php print $label ?>:</strong>
<?php endif; ?>
<div class="field field-name-field-company-site field-type-link-field field-label-hidden">
  <div class="field-items">
  <?php foreach ($items as $delta => $item): ?>
    <div class="field-item even">
    <?php
      $url = 'redirect/enterprise/' . $element['#object']->nid;
      $options = array(
        'attributes' => array('target' => '_blank'),
      );
      print l($item['#element']['url'], $url, $options);
    ?>
    </div>
  <?php endforeach; ?>
  </div>
</div>
