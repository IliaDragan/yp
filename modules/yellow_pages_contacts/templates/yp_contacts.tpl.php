<?php
/**
 * @file
 * Template file for contacts.
 */
?>
<div class="yp-widget yp-contacts">
  <h2 class="title"><?php print $title; ?></h2>
  <div class="entry contact-mail">
    <i class="fa fa-envelope-o"></i>
    <span class="item"><?php print $mail; ?></span>
  </div>
  <div class="entry contact-phone">
    <i class="fa fa-phone"></i>
    <span class="item"><?php print $phone; ?></span>
  </div>
  <div class="entry contact-social">
    <i class="fa fa-facebook"></i>
    <span class="item"><?php print !empty($url) ? l($link_title, $url, array('attributes' => array('target' => '_blank'))) : ''; ?></span>
  </div>
</div>
