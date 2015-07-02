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
