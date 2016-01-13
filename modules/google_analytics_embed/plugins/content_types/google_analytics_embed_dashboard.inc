<?php


$plugin = array(
  'single' => TRUE,  // Just do this one, it is needed.
  'title' => t('Google Analytics Dashboard'),
  'description' => t('A large overview of key Google Analytics data'),
  'category' => t('Administration'),
  'render callback' => 'google_analytics_embed_dashboard_render', // A function that will return the renderable content.
  'defaults' => array( // Array of defaults for the settings form.
    'text' => '',
  ),
  'all contexts' => TRUE, // This is NEEDED to be able to use substitution strings in your pane.
);



/**
 * Run-time rendering of the body of the block (content type)
 * See ctools_plugin_examples for more advanced info
 */
function google_analytics_embed_dashboard_render($subtype, $conf, $args, $contexts) {
  $block = new stdClass();
  $block->title = '';
  $block->content = theme('google_analytics_embed_dashboard', array()); 
  return $block;
}
