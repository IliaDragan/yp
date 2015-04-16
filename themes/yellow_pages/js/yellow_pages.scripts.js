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
        mouseDrag : false
      });
    }
  }

}) (jQuery, Drupal);
