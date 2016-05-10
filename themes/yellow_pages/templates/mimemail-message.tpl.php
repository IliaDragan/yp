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
$theme_path = drupal_get_path('theme', 'yellow_pages');
?>
<html>
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  </head>
  <body style="text-align: center;">
    <div style="display: inline-block; width: 600px;">
      <div style="display: block; max-height: 234px; width: 600px;">
        <img src="<?php print $theme_path; ?>/images/mail-header.png" />
      </div>
      <div style="background-color: #f4f4f4; padding: 10px 20px; text-align: left; width: 560px; color: #2e2e2e; min-height: 170px;">
        <?php print $body ?>
      </div>
      <div class="mail-footer" style="background-color: #2e2e2e; padding: 10px 20px; color: white; box-sizing: border-box;">
        <p><?php print date ('Y'); ?> &copy; Yellow Pages of Moldova</p>
      </div>
    </div>
  </body>
</html>
