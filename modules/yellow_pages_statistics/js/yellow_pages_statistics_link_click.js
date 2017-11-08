/**
 * @file
 * Count clicks to links using jQuery.ajax.
 */

  Drupal.behaviors.statisticsRedirectCount = {
    attach: function (context, settings) {
      jQuery('.company-site-redirect-link', context).on('click', function() {
        var nid = this.id.slice(27);
        jQuery.ajax({
          url: Drupal.settings.basePath + 'ajax/count/company/' + nid,
        });
      });
      jQuery('.advertisement-redirect-link', context).on('click', function() {
        var nid = this.id.slice(28);
        jQuery.ajax({
          url: Drupal.settings.basePath + 'ajax/count/advertisement/' + nid,
        });
      });
    }
  }
