<?php
/**
 * API documentation for the views block-cache optimizer (vbco) module.
 */


/**
 * Suggest a block-cache setting for a views plugin handler.
 *
 * @param String $handler_name
 * Name of the views handler: for example "views_handler_field_comment_link_approve".
 * @param String $handler_type
 * Type of handler, for example: "filter", "field", "argument", etc.
 *
 * @return Int
 * The suggested block-cache setting for this handler: for example
 * DRUPAL_CACHE_PER_PAGE | DRUPAL_CACHE_PER_ROLE
 */
function hook_views_block_cache_optimizer_suggestion($handler_name, $handler_type) {
  // My module provides a views-field displaying a location map, which is only
  // available to users with the 'view mymodule location map' permission,
  // therefore this handler requires caches per-role.
  if ($type == 'field' && $handler_name == 'mymodule_handler_field_location_map') {
    return DRUPAL_CACHE_PER_ROLE;
  }
}
