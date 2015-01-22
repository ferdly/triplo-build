<?php
/**
 * @file
 * This file contains drush integration for the VBCO module.
 */

/**
 * Implements hook_drush_command().
 */
function views_block_cache_optimizer_drush_command() {
  $items = array();
  $items['vbco-enable-all'] = array(
    'description' => 'Optimize all the views to use the best block-cache setting.',
    'drupal dependencies' => array('views_block_cache_optimizer'),
    'callback' => 'views_block_cache_optimizer__optimise_all_views',
  );
  return $items;
}
