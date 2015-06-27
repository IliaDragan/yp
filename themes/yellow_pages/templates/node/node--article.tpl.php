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
<?php // dpm($content); ?>
  <div class="node-main-image-block">
      <header>
        <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>

        

        <?php if ($unpublished): ?>
          <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
        <?php endif; ?>
      </header>
    <?php print render($content['field_main_image']); ?>
  </div>
  

  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    //print render($content);
    print render($content['body']);
  ?>

  <!-- Social links. -->
  <?php if (isset($service_links_rendered) && !empty($service_links_rendered)): ; ?>
    <div class="social-links">
      <?php print $service_links_rendered; ?>
    </div>
  <?php endif;?>

  <?php if ($display_submitted): ?>
    <p class="submitted">
      <?php print $user_picture; ?>
      <?php print $submitted; ?>
    </p>
  <?php endif; ?>

</article>
