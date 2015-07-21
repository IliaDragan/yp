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

  Drupal.behaviors.sticky_footer = {
    attach : function () {
      var $stickyFooter = $('.footer');
      if ($stickyFooter.length) {

        var vwptHeight = $(window).height();
        if (vwptHeight > $('body').height()) {
          var $mainwrapper = $('.main-container'),
            wrapperHeight = $mainwrapper.height(),
            $header = $('header#navbar'),
            $toolbar = $('#toolbar'),
            $regionAsides = $('.region-asides'),
            headerHeight = $header.outerHeight()|0,
            footerHeight = $stickyFooter.outerHeight()|0,
            regionsHeight = $regionAsides.outerHeight()|0,
            toolbarHeight = $toolbar.outerHeight()|0;

          $mainwrapper.css('min-height', 0);
          $mainwrapper.css('min-height', vwptHeight - (footerHeight + regionsHeight + headerHeight + toolbarHeight));
        } 
      }
    }
  }

  Drupal.behaviors.inner_menu = {
    attach : function () {
      var $innerMenuWrapper = $('.inner-menu-wrapper');
      if ($innerMenuWrapper.length) {
        var $extraMenuOverlay = $('.extra-menu-overlay'),
            $innerMenuBlock =  $extraMenuOverlay.find('.inner-menu-block'),
            $body = $('body');
        $innerMenuWrapper.find('.menu-btn').click(function() {
          $body.css('position', 'relative');
          var bodyPd = $body.css('padding-top');
          var menuBtnL = $(window).width() - $(this).offset().left + 42;
          $extraMenuOverlay.addClass('is-opened').css({
            top: bodyPd
          });
          console.log($innerMenuBlock.offset().left);
          if (menuBtnL > 300) {
            $innerMenuBlock.css({
              transform : 'translate3d(-' + menuBtnL + 'px, 0px ,0px)'
            })
          }
          else {
            $innerMenuBlock.css({
              transform : 'translate3d(-350px, 0px ,0px)'
            })
          }
        });
        var hideMenu = function() {
          $body.css('position', '');
          $innerMenuBlock.css({
            transform : 'translate3d(0px, 0px ,0px)'
          });
          setTimeout(function() {
            $extraMenuOverlay.removeClass('is-opened')
          }, 300);
        }
        $innerMenuWrapper.find('.menu-close').click(function() {
          hideMenu();
        });
        $extraMenuOverlay.click(function() {
          hideMenu();
        });
      }
    }
  }


}) (jQuery, Drupal);
