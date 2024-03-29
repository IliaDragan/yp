<?php
/**
 * @file
 * Layout markup for frontpage.
 */
?>
<div <?php if (!empty($css_id)) { print 'id="$css_id"'; } ?> class="yp-onecol-100-layout">
  <?php if (drupal_is_front_page()) : ?>
  <div class="frontpage-header row">
    <div class="activity container">
      <div class="row">
        <div class="col-md-8">
          <?php if ($site_name): ?>
          <h3 class="slogan-header"><?php print t($site_name) ?></h3>
          <?php endif; ?>
          <?php if ($site_slogan): ?>
          <p class="slogan"><?php print t($site_slogan); ?></p>
          <?php endif; ?>
          <?php if ($site_description): ?>
          <p class="description"><?php print t($site_description); ?></p>
          <?php endif; ?>
          <div class="search-block-form">
            <?php print $search_box; ?>
          </div>
        </div>
        <div class="col-md-4 col-lg-push-1 col-lg-3">
          <a href="<?php print url('user-register'); ?>">
            <div class="activity-banner">
              <?php global $base_url; ?>
              <img src="<?php print $base_url; ?>/profiles/yp/themes/yellow_pages/images/notebook.png" alt="">
              <p><?php print t('<span class="yellow">Find and verify</span> information about your company.') ?></p>
            </div>
          </a>
        </div>
      </div>
    </div>
  </div>
  <?php endif; ?>
  <?php if (drupal_is_front_page()) : ?>
  <div class="container">
  <?php endif; ?>
  <div class="row">
    <div class="col-sm-12">
      <?php print $content['main']; ?>
    </div>
  </div>
  <?php if (drupal_is_front_page()) : ?>
    </div>
  <?php endif; ?>
</div>
