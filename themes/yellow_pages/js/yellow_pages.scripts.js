/**
 * @file
 * Yellow Pages theme scripts.
 */

var Drupal = Drupal || {};

(function($, Drupal) {
  "use strict";

  Drupal.behaviors.yp_news_carousel = {
    attach: function () {
      if ($('.view-id-news.view-display-id-panel_pane_1').length === 0) {
        return;
      }

      $('.view-id-news.view-display-id-panel_pane_1 .view-content').owlCarousel({
        nav : true,
        navText : [
          '<span class="fa fa-angle-left"></span>',
          '<span class="fa fa-angle-right"></span>'
        ],
        mouseDrag : false,
        pagination: true,
        items: 4
      });
    }
  }

  Drupal.behaviors.search_form = {
    attach : function () {
      $('.search-block-form input.form-text').attr('placeholder', Drupal.t('Facility search'));
    }
  }
  Drupal.behaviors.custom_select = {
    attach : function () {
      var $select = $('select');
       if ($select.length) {
           for (var i = 0, len = $select.length; i < len; i++) {
               var $this = $select.eq(i);
               if ($this.hasClass('multiple')) {
                   // chosen multiple
               } else if ($this.hasClass('custom')) {
                   // custom chosen
               } else {
                   // basic chosen no search
                   $this.chosen({
                       disable_search: true,
                       width: '100%',
                       display_disabled_options: false
                   });
               }
           }
       }
    }
  }

  Drupal.behaviors.node_tabs = {
    attach : function () {
      var $nodeTabsBlock = $('.node-tabs-block');
      if ($nodeTabsBlock.length) {
        $nodeTabsBlock.each(function() {
          var $this = $(this);
          var $nodeTabItem = $this.find('.panel-pane');
          var $headerTab = $this.find('.node-tabs-block-header');
          var $headerTabItem = $nodeTabItem.find('h2.pane-title');
          $headerTabItem.clone().appendTo($headerTab);
          var $headerTabMain = $headerTab.find('h2');
          $headerTabMain.wrapInner( "<span></span>")
          $headerTabMain.eq(0).addClass('is-active');
          for (var i = 0; i < $headerTabMain.length; i++) {
            var $headerTabMainSingle = $headerTabMain.eq(i);
            $headerTabMainSingle.click(function() {
              var $this = $(this);
              $this.siblings().removeClass('is-active');
              $this.addClass('is-active');
              $nodeTabItem.hide();
              $nodeTabItem.eq($this.index()).show();
            });
          }
        });
      }
    }
  }


}) (jQuery, Drupal);
