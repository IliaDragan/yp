<?php

/**
 * @file
 * template.php
 */

/**
 * Implements hook_preprocess_page().
 */
function yellow_pages_preprocess_page(&$variables) {
  $block = module_invoke('locale', 'block_view', 'language');
  $variables['page']['language_switcher'] = $block['content'];
}
