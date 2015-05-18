/**
 * @file
 * Yellow Pages theme scripts.
 */

var Drupal = Drupal || {};

(function($, Drupal) {
  "use strict";

  Drupal.behaviors.yp_news_carousel = {
    attach: function () {
      if ($('.view-id-news.view-display-id-default').length === 0) {
        return;
      }

      $('.view-id-news.view-display-id-default .view-content').owlCarousel({
        nav : true,
        navText : [
          '<span class="glyphicon glyphicon-chevron-left"></span>',
          '<span class="glyphicon glyphicon-chevron-right"></span>'
        ],
        mouseDrag : false,
        items: 4
      });
    }
  }

  Drupal.behaviors.search_form = {
    attach : function () {
      $('.search-block-form input.form-text').attr('placeholder', Drupal.t('Facility search'));
    }
  }

}) (jQuery, Drupal);
