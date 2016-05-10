/**
 * @file
 */

"use strict";

(function($, Drupal) {
  Drupal.behaviors.yp_geomap = {
    attach: function (context) {
      $('.address-coordinates').click(function() {
        var coordinates = $(this).attr('data-coordinates');

        window.open('https://www.google.com/maps/place/' + coordinates + '/@' + coordinates + ',17z');
      });
    }
  }
}) (jQuery, Drupal);
