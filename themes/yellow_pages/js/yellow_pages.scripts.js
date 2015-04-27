/**
 * @file
 * Yellow Pages theme scripts.
 */

var Drupal = Drupal || {};

(function($, Drupal) {
  "use strict";

  Drupal.behaviors.yp_news_carousel = {
    attach: function () {
      $('.view-id-news.view-display-id-default .view-content').owlCarousel({
        nav : true,
        navText : [
          '<span class="glyphicon glyphicon-chevron-left"></span>',
          '<span class="glyphicon glyphicon-chevron-right"></span>'
        ],
        mouseDrag : false,
        items: 4
      });

      var $div;
      var fields = ['.views-field-title', '.views-field-changed', '.views-field-body', '.views-field-nid'];
      $('.view-id-news.view-display-id-default .view-content .owl-item').each(function (i, e) {
        $div = $('<div />').addClass('views-row-field-wrapper');
        $div.append('<div class="close"><i class="fa fa-times"></i></div>');
        $(e).find('.views-row .views-field-field-list-image').after($div);
        for (i in fields) {
          $(e).find('.views-row ' + fields[i]).appendTo($div);
        }
      });

      var $ele;
      $('.views-row-field-wrapper').on('click', function (evt, e) {
        $ele = $(this);

        $ele.addClass('active');
      });

      $('.views-row-field-wrapper .close').on('click', function (evt, e) {
        $ele = $(this).parents('.views-row-field-wrapper');

        $ele.removeClass('active');
        evt.stopPropagation();
      });
    }
  }

  Drupal.behaviors.search_form = {
    attach : function () {
      $('form.search-form input.form-text').attr('placeholder', Drupal.t('Facility search'));
    }
  }

}) (jQuery, Drupal);
