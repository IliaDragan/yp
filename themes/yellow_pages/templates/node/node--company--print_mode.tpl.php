<?php
/**
 * @file
 * Returns the HTML for a print version of company node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="company-content">
    <h2 class="node-title"><?php print $title; ?></h2>
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
      <?php print render($content['field_products']); ?>
    </div>

  </div>
</article>

