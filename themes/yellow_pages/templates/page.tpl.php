<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['header']
 * - $page['help']
 * - $page['content']
 * - $page['aside_a']
 * - $page['aside_b']
 * - $page['aside_c']
 * - $page['footer']
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable
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

<?php if($is_front): ?>
<div class="main-container homepage-container">
<?php else: ?>
<div class="main-container container">
<?php endif; ?>
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
