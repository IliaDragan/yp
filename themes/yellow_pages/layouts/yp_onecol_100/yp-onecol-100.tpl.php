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
        <div class="col-sm-8">
          <h3 class="slogan-header"><?php print t('YELLOW PAGES OF MOLDOVA') ?></h3>
          <p class="slogan"><?php print t('All <span class="yellow">Moldova</span> facilities at your demand'); ?></p>
          <p class="description"><?php print t('Search companies by name, activity, take your own pick or make a tour through links'); ?></p>
          <div class="search-block-form">
            <?php print $search_box; ?>
          </div>
        </div>
        <div class="col-sm-4 col-lg-push-1 col-lg-3">
          <div class="activity-banner">
            <img src="http://yp:8888/profiles/yp/themes/yellow_pages/images/notebook.png" alt="">
            <h5>Introducing mybook</h4>
            <p>Add business contacts and notes, and get things done anywhere!</p>
            <a href="#" class="button"><span class="fa fa-bookmark"></span>Start adding to <b>mybook</b></a>
          </div>
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
