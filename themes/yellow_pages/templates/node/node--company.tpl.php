<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */
?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <div class="">
    <div class="row">
      <div class="col-sm-3">
        <?php print render($content['field_company_logo']); ?>
      </div>
      <?php if (!empty($content['field_geocode'])): ?>
        <div class="col-sm-6">
      <?php else: ?>
        <div class="col-sm-9">
      <?php endif; ?>
        <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
        <?php  $date = $node->changed; $date = Date('d.m.y', $date); ?>
        <div class="field-date-update">
          <strong><?php print t('Date of update: '); ?></strong><?php print $date; ?>
        </div>
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
        <div class="field-row-tags">
          <?php print render($content['field_categories']); ?>
        </div>
      </div>

      <!-- Social links. -->
      <?php if (isset($service_links_rendered) && !empty($service_links_rendered)): ; ?>
        <div class="social-links">
          <?php print $service_links_rendered; ?>
        </div>
      <?php endif;?>

      <?php if (!empty($content['field_geocode'])): ?>
        <div class="col-sm-3">
          <?php print render($content['field_geocode']); ?>
        </div>
      <?php endif; ?>
    </div>

    <!-- Tabbed content -->
    <?php print render($content['group_tabbed_content']); ?>
  </div>

  <?php if ($unpublished): ?>
    <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
  <?php endif; ?>
  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    // print render($content);
  ?>
  <?php if ($display_submitted): ?>
    <p class="submitted">
      <?php print $user_picture; ?>
      <?php print $submitted; ?>
    </p>
  <?php endif; ?>

</article>
