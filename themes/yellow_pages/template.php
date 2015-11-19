<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_preprocess_page().
 */
function yellow_pages_preprocess_page(&$variables) {
  $status = drupal_get_http_header("status");
  $variables['page']['main_menu'] = menu_tree('main-menu');

  if($status == "404 Not Found") {
    $variables['theme_hook_suggestions'][] = 'page__404';
  }
  if($status == "403 Forbidden") {
    $variables['theme_hook_suggestions'][] = 'page__403';
  }

  // Add open graph meta for facebook share button.
  if (!empty($variables['node'])) {
    $meta = array(
      'title' => array(
        '#type' => 'html_tag',
        '#tag' => 'meta',
        '#attributes' => array(
          'property' => 'og:title',
          'content' => $variables['node']->title,
        ),
      ),
      'image' => array(
        '#type' => 'html_tag',
        '#tag' => 'meta',
        '#attributes' => array(
          'property' => 'og:image',
          'content' => '',
        ),
      ),
    );

    switch ($variables['node']->type) {
      case 'company':
        if (!empty($variables['node']->field_company_logo[LANGUAGE_NONE][0]['uri'])) {
          $uri = $variables['node']->field_company_logo[LANGUAGE_NONE][0]['uri'];
          $url = image_style_url('medium', $uri);
          $meta['image']['#attributes']['content'] = $url;
        }
      break;

      case 'article':
      case 'news':
        if (!empty($variables['node']->field_main_image[LANGUAGE_NONE][0]['uri'])) {
          $uri = $variables['node']->field_main_image[LANGUAGE_NONE][0]['uri'];
          $url = image_style_url('medium', $uri);
          $meta['image']['#attributes']['content'] = $url;
        }
      break;
    }

    foreach ($meta as $key => $val) {
      drupal_add_html_head($val, 'meta_og_' . $key);
    }
  }
}

/**
 * Implements hook_preprocess_hook().
 */
function yellow_pages_preprocess_yp_onecol_100(&$variables) {
  if (drupal_is_front_page()) {
    $form = drupal_get_form('search_block_form');
    $search_box = drupal_render($form);
    $variables['search_box'] = $search_box;
    $variables['site_name'] = variable_get('site_name', '');
    $variables['site_slogan'] = variable_get('site_slogan', '');
    $variables['site_description'] = variable_get('site_description', '');
  }
}

/**
 * Injects owl-carousel related files to page.
 */
function yellow_pages_inject_owl() {
  $path = drupal_get_path('theme', 'yellow_pages');
  drupal_add_js($path . '/js/owl.carousel.min.js');
  drupal_add_css($path . '/css/owl.carousel.css');
}

/**
 * Implements hook_preprocess_panels_pane().
 */
function yellow_pages_preprocess_panels_pane(&$vars) {
  // Add specific scripts and styles for news carousel.
  if ($vars['pane']->type == 'yp_news_carousel') {
    yellow_pages_inject_owl();
  }
}

/**
 * Implements hook_preprocess_node().
 */
function yellow_pages_preprocess_node(&$vars) {
  yellow_pages_inject_owl();

  $vars['classes_array'][] = 'node--' . $vars['type'] . '--' . $vars['view_mode'];
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__' . $vars['view_mode'];
}

/**
 * Implements hook_preprocess_field().
 */
function yellow_pages_preprocess_field(&$vars) {
  $vars['theme_hook_suggestions'][] = 'field__' . $vars['element']['#field_name'] . '__' . $vars['element']['#view_mode'];
}

/**
 * Implements hook_preprocess_menu_link().
 */
function yellow_pages_preprocess_menu_link(&$variables) {
  if ($variables['theme_hook_original'] == 'menu_link__menu_product_menu') {
    $variables['prefix'] = '<span>';
    $variables['suffix'] = '</span>';
  }
  elseif ($variables['theme_hook_original'] == 'menu_link__main_menu') {
    $alias_href = drupal_get_path_alias($variables['element']['#href'], 'ru');
    $variables['element']['#href'] = $alias_href;
  }
}

/**
 * Implements theme_menu_link().
 */
function yellow_pages_menu_link(array $variables) {
  $element = $variables ['element'];
  $sub_menu = $element['#below'] ? drupal_render($element ['#below']) : '';
  $prefix = isset($variables['prefix']) ? $variables['prefix'] : '';
  $suffix = isset($variables['suffix']) ? $variables['suffix'] : '';
  if ($suffix || $prefix) {
    $element ['#localized_options']['html'] = TRUE;
  }
  $output = l($prefix . $element ['#title'] . $suffix, $element ['#href'], $element ['#localized_options']);
  return '<li' . drupal_attributes($element ['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Implements hook_preprocess_region().
 */
function yellow_pages_preprocess_region(&$variables) {
  if ($variables['region'] == 'header') {
    $txt = '<div class="inner-menu-wrapper"><span class="menu-btn fa fa-bars"><span class="menu-text">' . t('Menu') . '</span></span>';
    $txt .= '</div><span class="fa fa-search search-link-mobile"></span>';
    $variables['content'] = $txt . $variables['content'];
  }
}

/**
 * Implements hook_css_alter().
 */
function yellow_pages_css_alter(&$css) {
  // Exclude all the unused core and modules css.
  $exclude = array(
    'profiles/yp/modules/contrib/addressfield/addressfield.css' => FALSE,
  );
  $css = array_diff_key($css, $exclude);
}

/**
 * Implements hook_theme().
 */
function yellow_pages_theme() {
  return array(
    'links_clear' => array(
      'render element' => 'element',
      'function' => 'yellow_pages_links_clear',
    ),
  );
}

function yellow_pages_html_head_alter(&$elements) {
  // Optimize the mobile viewport.
  if(isset($elements['circle_viewport'])) unset($elements['circle_viewport']);
}

/**
 * Implements theme_links_clear().
 */
function yellow_pages_links_clear($variables) {
  $links = $variables ['links'];
  if (!isset($variables ['attributes'])) $variables ['attributes'] = array();
  $attributes = $variables ['attributes'];
  if (!isset($variables ['heading'])) $variables ['heading'] = array();
  $heading = $variables ['heading'];
  global $language_url;
  $output = '';

  if (count($links) > 0) {
    // Treat the heading first if it is present to prepend it to the
    // list of links.
    if (!empty($heading)) {
      if (is_string($heading)) {
        // Prepare the array that will be used when the passed heading
        // is a string.
        $heading = array(
          'text' => $heading,
          // Set the default level of the heading.
          'level' => 'h2',
        );
      }
      $output .= '<' . $heading ['level'];
      if (!empty($heading ['class'])) {
        $output .= drupal_attributes(array('class' => $heading ['class']));
      }
      $output .= '>' . check_plain($heading ['text']) . '</' . $heading ['level'] . '>';
    }

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = array($key);

      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $class [] = 'first';
      }
      if ($i == $num_links) {
        $class [] = 'last';
      }
      if (isset($link ['href']) && ($link ['href'] == $_GET ['q'] || ($link ['href'] == '<front>' && drupal_is_front_page()))
         && (empty($link ['language']) || $link ['language']->language == $language_url->language)) {
        $class [] = 'active';
      }
      $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';

      if (isset($link ['href'])) {
        // Use path alias instead of drupal path.
        $link['href'] = drupal_get_path_alias($link['href'], 'ru');
        // Pass in $link as $options, they share the same keys.
        $output .= l($link ['title'], $link ['href'], $link);
      }
      elseif (!empty($link ['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes.
        if (empty($link ['html'])) {
          $link ['title'] = check_plain($link ['title']);
        }
        $span_attributes = '';
        if (isset($link ['attributes'])) {
          $span_attributes = drupal_attributes($link ['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link ['title'] . '</span>';
      }

      $i++;
      $output .= "</li>\n";
    }
  }

  return $output;
}

/**
 * Overrides theme_addressfield_container().
 *
 * Render a container for a set of address fields.
 */
function yellow_pages_addressfield_container($variables) {
  $element = $variables['element'];
  $element['#children'] = trim($element['#children']);
  if (strlen($element['#children']) > 0) {
    $attr = $element['#attributes'];
    $prefix = '';
    if (isset($attr['autocomplete'])) {
      if ($attr['autocomplete'] == 'postal-code') {
        $prefix = 'MD-';
      }
      unset($attr['autocomplete']);
    }
    $output = '<' . $element['#tag'] . drupal_attributes($attr) . '>';
    $output .= $prefix . $element['#children'];
    $output .= '</' . $element['#tag'] . ">";
    return $output;
  }
  else {
    return '';
  }
}

/**
 * Overrides theme_facetapi_deactivate_widget().
 */
function yellow_pages_facetapi_deactivate_widget($variables) {
  return '&#xf00d;';
}
