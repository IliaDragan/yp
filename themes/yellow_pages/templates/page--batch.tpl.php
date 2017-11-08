<?php
/**
 * @file
 * Default theme implementation to display a batch Drupal page.
 */
?>
<header id="navbar" role="banner">
  <div class="container">
    <div class="navbar-header">
      <?php if ($logo): ?>
        <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
          <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
        </a>
      <?php endif; ?>
      <?php
      print render($page['header']);
      ?>
    </div>
  </div>
</header>

  <div class="main-container container">
    <div class="row">
      <div class="col-sm-12">
        <?php
        if (!empty($page['help'])) {
          print render($page['help']);
        }
        ?>
      </div>
    </div>
    <div class="row">
      <div class="col-sm-12">
        <?php print $messages; ?>
        <h2 class="title"><?php print $title; ?></h2>
        <?php print render($page['content']); ?>
      </div>
    </div>
  </div>
  <div class="region-asides">
    <div class="container">
      <div class="row">
        <div class="col-sm-4 col-md-5">
          <?php
          if (!empty($page['aside_a'])) {
            print render($page['aside_a']);
          }
          ?>
        </div>
        <div class="col-sm-4 col-md-5">
          <?php
          if (!empty($page['aside_b'])) {
            print render($page['aside_b']);
          }
          ?>
        </div>
        <div class="col-sm-4 col-md-2">
          <?php
          if (!empty($page['aside_c'])) {
            print render($page['aside_c']);
          }
          ?>
        </div>
      </div>
    </div>
  </div>

  <footer id="footer" class="footer">
    <div class="footer-wrapper container">
    <span class="copyright mobile-hidden">
      <?php print '&copy; ' . date('Y');?>
    </span>
      <?php print render($page['main_menu']); ?>
      <span class="copyright mobile-only">
      <?php print '&copy; ' . date('Y');?>
    </span>
      <?php print render($page['footer']); ?>
    </div>
  </footer>

  <?php $usermenu = theme('links_clear', array('links' => menu_navigation_links('user-menu'), 'attributes' => array('class'=> array('user-menu')) )); ?>
  <?php $userclass = $usermenu ? 'has-user-menu' : 'no-user-menu'; ?>
  <?php $mainmenu = theme('links_clear', array('links' => menu_navigation_links('main-menu'))); ?>
  <div class="extra-menu-overlay">
    <div class="inner-menu-block">
      <div class="inner-menu-overlay <?php print $userclass; ?>">
        <ul class="nav-list-menu">
          <?php print $mainmenu; ?>
          <?php if ($usermenu): ?>
            <?php print $usermenu; ?>
          <?php endif; ?>
        </ul>
        <span class="menu-close fa fa-close"></span>
      </div>
    </div>
  </div>
