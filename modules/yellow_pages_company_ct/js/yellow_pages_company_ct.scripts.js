/**
 * @file
 * Company page related scripts.
 */

'use strict';

var Drupal = Drupal || {};

(function($, Drupal) {
  Drupal.behaviors.company_page_gallery = {
    attach: function(context) {
      var carousel_settings = {
        nav : true,
          navText : [
            '<span class="fa fa-angle-left"></span>',
            '<span class="fa fa-angle-right"></span>'
          ],
          touchDrag : true,
          mouseDrag : true,
          pagination: true,
          items: 6
      };
      var $owl = $('.field-name-field-media-materials .field-items');
      $owl.owlCarousel(carousel_settings);
    }
  }
}) (jQuery, Drupal);
