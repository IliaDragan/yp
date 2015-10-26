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
  </head>
  <body style="text-align: center;">
    <div style="display: inline-block; width: 600px;">
      <div style="display: block; height: 424px; width: 600px;">
        <img src="<?php print $theme_path; ?>/images/mail-header.png" />
      </div>
      <div style="background-color: #f4f4f4; margin-top: -190px; padding: 10px 20px; text-align: left; width: 600px; color: #2e2e2e; box-sizing: border-box;">
        <?php print $body ?>
      </div>
      <div style="padding: 10px 20px; color: #2e2e2e; box-sizing: border-box;">
        <p><?php print t('Social links:'); ?></p>
        <p>
          <a href="#" style="display: inline-block; height: 25px; width: 50px; text-decoration: none;">
            <img src="<?php print $theme_path; ?>/images/google.png" />
          </a>
          <a href="#" style="display: inline-block; height: 25px; width: 50px; text-decoration: none;">
            <img src="<?php print $theme_path; ?>/images/facebook2.png" />
          </a>
          <a href="#" style="display: inline-block; height: 25px; width: 50px; text-decoration: none;">
            <img src="<?php print $theme_path; ?>/images/twitter.png" />
          </a>
          <a href="#" style="display: inline-block; height: 25px; width: 50px; text-decoration: none;">
            <img src="<?php print $theme_path; ?>/images/linkedin.png" />
          </a>
          <a href="#" style="display: inline-block; height: 25px; width: 50px; text-decoration: none;">
            <img src="<?php print $theme_path; ?>/images/vkontakte.png" />
          </a>
        </p>
      </div>
      <div class="mail-footer" style="background-color: #2e2e2e; padding: 10px 20px; color: white; box-sizing: border-box;">
        <p><?php print t('123 Stefan cel Mare str., Chisinau, Republic of Moldova'); ?></p>
        <p>2015 &copy; Yellow Pages of Moldova</p>
      </div>
    </div>
  </body>
</html>
