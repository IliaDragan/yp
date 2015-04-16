/**
 * @file
 * Yellow Pages theme scripts.
 */

var Drupal = Drupal || {};

(function($, Drupal) {
  "use strict";

  Drupal.behaviors.yp = {
    attach: function () {
      $('.view-id-news.view-display-id-default .view-content').owlCarousel({
        nav : true,
        mouseDrag : false,
        items: 4,
      });

      var $div;
      var fields = ['.views-field-title', '.views-field-changed', '.views-field-body', '.views-field-nid'];
      $('.view-id-news.view-display-id-default .view-content .owl-item').each(function (i, e) {
        $div = $('<div />').addClass('views-row-field-wrapper');
        $(e).find('.views-row .views-field-field-list-image').after($div);
        for (i in fields) {
          $(e).find('.views-row ' + fields[i]).appendTo($div);
        }
      });
    }
  }

}) (jQuery, Drupal);
