<?php
/**
 * @file
 * Layout markup for frontpage.
 */
?>
<div <?php if (!empty($css_id)) { print 'id="$css_id"'; } ?> class="yp-frontpage-layout">
  <?php if (drupal_is_front_page()) : ?>
  <div class="row">
    <div class="col-sm-12">
      <div class="frontpage-header">
        <div class="activity">
          <p class="slogan"><?php print t('All <span class="yellow">Moldova</span> facilities at your demand'); ?></p>
          <p class="description"><?php print t('Search companies by name, activity, take your own pick or make a tour through links'); ?></p>
          <div class="search-block-form">
            <?php print $search_box; ?>
          </div>
        </div>
      </div>
    </div>
  </div>
  <?php endif; ?>
  <div class="row">
    <div class="col-sm-12">
      <?php print $content['main']; ?>
    </div>
  </div>
  <div class="row">
    <div class="col-sm-4 first">
      <?php print $content['bottom_a']; ?>
    </div>
    <div class="col-sm-4">
      <?php print $content['bottom_b']; ?>
    </div>
    <div class="col-sm-4 last">
      <?php print $content['bottom_c']; ?>
    </div>
  </div>
</div>
