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
          <img src="profiles/yp/themes/yellow_pages/images/mail-header.png" />
        </div>
        <div class="mail-text">
          <?php print $body ?>
        </div>
        <div class="mail-social">
          <p><?php print t('Social links:'); ?></p>
          <p>
            <a href="#" class="social-link google-plus"><img src="profiles/yp/themes/yellow_pages/images/google.png" /></a>
            <a href="#" class="social-link facebook"><img src="profiles/yp/themes/yellow_pages/images/facebook2.png" /></a>
            <a href="#" class="social-link twitter"><img src="profiles/yp/themes/yellow_pages/images/twitter.png" /></a>
            <a href="#" class="social-link linkedin"><img src="profiles/yp/themes/yellow_pages/images/linkedin.png" /></a>
            <a href="#" class="social-link vkontakte"><img src="profiles/yp/themes/yellow_pages/images/vkontakte.png" /></a>
          </p>
        </div>
        <div class="mail-footer">
          <p><?php print t('123 Stefan cel Mare str., Chisinau, Republic of Moldova'); ?></p>
          <p>2015 &copy; Yellow Pages of Moldova</p>
        </div>
      </div>
    </div>
  </body>
</html>
