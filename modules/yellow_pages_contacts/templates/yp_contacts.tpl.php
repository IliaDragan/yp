<?php
/**
 * @file
 * Template file for contacts.
 */
?>
<div class="yp-widget yp-contacts">
  <strong class="block-title"><?php print $title; ?></strong>
  <?php if (!empty($mail)): ?>
  <div class="entry contact-mail">
    <i class="fa fa-envelope-o"></i>
    <span class="item">
      <a href="mailto:<?php print $mail; ?>"><?php print $mail; ?></a>
    </span>
  </div>
  <?php endif; ?>
  <?php if (!empty($phone)): ?>
  <div class="entry contact-phone">
    <i class="fa fa-phone"></i>
    <span class="item"><?php print $phone; ?></span>
  </div>
  <?php endif; ?>
  <?php if (!empty($url) && !empty($link_title)): ?>
  <div class="entry contact-social">
    <i class="fa fa-facebook"></i>
    <span class="item">
      <?php print l($link_title, $url, array('attributes' => array('target' => '_blank'))); ?>
    </span>
  </div>
  <div class="entry contact-ad-order">
    <span class="item link">
      <?php print l(t('Advertisement order'), 'feedback/ad'); ?>
    </span>
  </div>
  <?php endif; ?>
</div>
