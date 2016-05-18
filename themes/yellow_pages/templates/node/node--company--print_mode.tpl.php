<?php
/**
 * @file
 * Returns the HTML for a print version of company node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<div id="node-print-version" class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="company-content">
    <h2 class="node-title"><?php print $title; ?> - Print Version</h2>
    <table class="contact-info">
      <tbody>
        <tr>
          <td>
            <?php print render($content['field_address']); ?>
            <div class="field-row-custom">
              <?php print render($content['field_landline_phone']); ?>
              <?php print render($content['field_fax']); ?>
              <?php print render($content['field_mobile_phone']); ?>
            </div>
            <div class="field-row-custom">
              <?php print render($content['field_company_site']); ?>
              <?php print render($content['field_email']); ?>
            </div>
          </td>
          <td>
            <?php print render($content['field_geocode']); ?>
          </td>
        </tr>
      </tbody>
    </table>
    <div class="field-row-tags">
      <?php print render($content['body']); ?>
      <?php print render($content['field_business_hours']); ?>
      <?php if (!empty($content['field_products'])): ?>
      <div class="field-products-wrapper">
        <div class="field-label"><?php print t('Products and services'); ?>:</div>
        <?php print render($content['field_products']); ?>
      </div>
      <?php endif; ?>
      <?php print render($content['group_products']); ?>
      <?php print render($content['group_services']); ?>
      <?php print render($content['group_we_sell']); ?>
      <?php print render($content['group_we_buy']); ?>
      <?php print render($content['group_we_export']); ?>
    </div>
  </div>
</div>

