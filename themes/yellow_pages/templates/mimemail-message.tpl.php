<?php

/**
 * @file
 * Default theme implementation to format an HTML mail.
 *
 * Copy this file in your default theme folder to create a custom themed mail.
 * Rename it to mimemail-message--[module]--[key].tpl.php to override it for a
 * specific mail.
 *
 * Available variables:
 * - $recipient: The recipient of the message
 * - $subject: The message subject
 * - $body: The message body
 * - $css: Internal style sheets
 * - $module: The sending module
 * - $key: The message identifier
 *
 * @see template_preprocess_mimemail_message()
 */
$theme_path = realpath(drupal_get_path('theme', 'yellow_pages'));
?>
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
    <?php if ($css): ?>
      <style type="text/css">
        <?php print $css ?>
      </style>
    <?php endif; ?>
  </head>
  <body id="mimemail-body" <?php if ($module && $key): print 'class="'. $module .'-'. $key .'"'; endif; ?>>
    <div id="center">
      <div id="main">
        <div class="mail-header">
          <img src="<?php print $theme_path; ?>/images/mail-header.png" />
        </div>
        <div class="mail-text">
          <?php print $body ?>
        </div>
        <div class="mail-social" style="padding: 10px 20px;">
          <p><?php print t('Social links:'); ?></p>
          <p>
            <a href="#" class="social-link google-plus" style="display: inline-block; height: 25px; width: 50px;"><img src="profiles/yp/themes/yellow_pages/images/google.png" /></a>
            <a href="#" class="social-link facebook" style="display: inline-block; height: 25px; width: 50px;"><img src="profiles/yp/themes/yellow_pages/images/facebook2.png" /></a>
            <a href="#" class="social-link twitter" style="display: inline-block; height: 25px; width: 50px;"><img src="profiles/yp/themes/yellow_pages/images/twitter.png" /></a>
            <a href="#" class="social-link linkedin" style="display: inline-block; height: 25px; width: 50px;"><img src="profiles/yp/themes/yellow_pages/images/linkedin.png" /></a>
            <a href="#" class="social-link vkontakte" style="display: inline-block; height: 25px; width: 50px;"><img src="profiles/yp/themes/yellow_pages/images/vkontakte.png" /></a>
          </p>
        </div>
        <div class="mail-footer" style="background-color: #2e2e2e; padding: 10px 20px;">
          <p><?php print t('123 Stefan cel Mare str., Chisinau, Republic of Moldova'); ?></p>
          <p>2015 &copy; Yellow Pages of Moldova</p>
        </div>
      </div>
    </div>
  </body>
</html>
