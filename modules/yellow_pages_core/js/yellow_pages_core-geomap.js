/**
 * @file
 */

"use strict";

(function($, Drupal) {
  Drupal.behaviors.yp_geomap = {
    attach: function (context) {
      $('.addressfield-popup-map').click(function() {
        var nid = $(this).attr('data-nid');

        window.open('/node/' + nid + '/geomap');
      });
    }
  }
}) (jQuery, Drupal);
