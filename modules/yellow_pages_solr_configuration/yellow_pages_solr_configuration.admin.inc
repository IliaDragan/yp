<?php
/**
 * @file
 * Solr search administrative routine.
 */

/**
 * Form builder for product facet rebuild form.
 */
function yellow_pages_solr_configuration_admin_rebuild_form($form, $form_state) {
  $form['rebuild'] = array(
    '#type' => 'submit',
    '#value' => t('Rebuild products facet'),
  );

  return $form;
}

/**
 * Custom submit handler for rebuild form.
 *
 * @see yellow_pages_solr_configuration_admin_rebuild_form()
 */
function yellow_pages_solr_configuration_admin_rebuild_form_submit($form, &$form_state) {
  yellow_pages_solr_configuration_rubuild_products_facet();
  drupal_set_message(t('Products facet rebuilt.'));
}

/**
 * Rebuild products facet.
 */
function yellow_pages_solr_configuration_rubuild_products_facet() {
  $tids = db_query('SELECT tid FROM {taxonomy_term_data}')
    ->fetchCol();

  $placeholders = array(
    ':tids' => $tids,
  );
  $result = db_query('SELECT tid, parent FROM {taxonomy_term_hierarchy} WHERE parent <> 0 AND (tid IN (:tids) OR parent IN (:tids))', $placeholders);

  $hierarchy = array();
  foreach ($result as $record) {
    $hierarchy[$record->tid][] = $record->parent;
  }

  cache_set(YP_PRODUCTS_HIERARACHY_CACHE, $hierarchy, 'cache_yp', CACHE_PERMANENT);

  $labels = array();
  sort($tids, SORT_ASC);
  $locales = array_keys(locale_language_list('name'));

  foreach ($locales as $locale) {
    $rows = array();

    if ($locale == 'en') {
      $result = db_query('SELECT tid, name FROM taxonomy_term_data WHERE tid IN (:tid) ORDER by tid', array(':tid' => $tids));
      $rows = $result->fetchAllKeyed();
    }
    else {
      $context_map = array_map(function ($v) {
        return 'term:' . $v . ':name';
      }, $tids);

      $result = db_query("SELECT context, translation FROM locales_source s INNER JOIN locales_target t ON s.lid = t.lid WHERE s.context IN (:context) AND t.language = :lang", array(':context' => $context_map, ':lang' => $locale));
      $_rows = $result->fetchAllKeyed();
      foreach ($tids as $id) {
        $rows[$id] = $_rows['term:' . $id . ':name'];
      }
    }

    $labels[$locale] = $rows;
  }

  cache_set('yp_products_labels', $labels, 'cache_yp', CACHE_PERMANENT);
}
