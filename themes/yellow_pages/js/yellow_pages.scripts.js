/**
 * @file
 * Yellow Pages theme scripts.
 */

var Drupal = Drupal || {};

function getWindowWidth () {
  var windowWidth = 0;
  if (typeof(window.innerWidth) == 'number') {
      windowWidth = window.innerWidth;
  } else {
      if (document.documentElement && document.documentElement.clientWidth) {
          windowWidth = document.documentElement.clientWidth;
      } else {
          if (document.body && document.body.clientWidth) {
              windowWidth = document.body.clientWidth;
          }
      }
  }
  return windowWidth;
}

(function($, Drupal) {
  "use strict";

  Drupal.behaviors.yp_news_carousel = {
    attach: function (context) {
      if ($('.view-id-news.view-display-id-panel_pane_1', context).length === 0) {
        return;
      }

      var $owl = $('.view-id-news.view-display-id-panel_pane_1 .view-content');
      var carousel_Settings = {
        nav : true,
          navText : [
            '<span class="fa fa-angle-left"></span>',
            '<span class="fa fa-angle-right"></span>'
          ],
          touchDrag : true,
          mouseDrag : true,
          pagination: true,
          items: 4
      };

      function owlInitialize(){
        if(getWindowWidth() > 991) {
          $owl.owlCarousel(carousel_Settings);
        } else {
          $owl.trigger('destroy.owl.carousel').removeClass('owl-carousel owl-loaded');
          $owl.find('.owl-stage-outer').children().unwrap();
        }
      }
      var id;
      $(window).resize( function() {
        clearTimeout(id);
        id = setTimeout(owlInitialize, 500);
      });

      owlInitialize();
    }
  }

  Drupal.behaviors.search_form = {
    attach : function (context) {
      $('.search-block-form input.form-text, .search-block-form--2 input.form-text').attr('placeholder', Drupal.t('Facility search'));
    }
  }

  Drupal.behaviors.custom_select = {
    attach : function (context) {
      var $select = $('.no-touch select');
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
    attach : function (context) {
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
    attach : function (context) {
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
    attach : function (context) {
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
          if (menuBtnL > 300 && getWindowWidth() >= 768) {
            $innerMenuBlock.css({
              transform : 'translate3d(-' + menuBtnL + 'px, 0px ,0px)'
            })
          }
          else if (getWindowWidth() < 768) {
            $innerMenuBlock.css({
              transform : 'translate3d(-290px, 0px ,0px)'
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
  
  Drupal.behaviors.search_mobile = {
    attach : function (context) {
      var $searchLink = $('header .search-link-mobile');
       if ($searchLink.length) {
        $searchLink.click(function() {
          var $this = $(this),
              $searchBlock = $('header .block-search'),
              $mainContainer = $('.main-container');
          $searchBlock.show();
          $this.hide();
          $mainContainer.css('margin-top', '46px');
        });
       }
    }
  }

  Drupal.behaviors.horizontal_tabs_mobile = {
    attach : function (context) {
      var $horizontalTabs = $('div.horizontal-tabs');
       if ($horizontalTabs.length) {
        var $tab = $horizontalTabs.find('.horizontal-tab-button'),
            $tabsList = $horizontalTabs.find('.horizontal-tabs-list'),
            $tabsPane = $horizontalTabs.find('.horizontal-tabs-pane'),
            totalWidth = 0;
        for (var i = 0; i < $tab.length; i++) {
          totalWidth += parseInt($tab.eq(i).width(), 10);
        }
        if ((totalWidth) > $tabsList.outerWidth()) {
          $horizontalTabs.closest('.group-tabbed-content');
          var $sel = $('<select class="tabs-select">').insertBefore($horizontalTabs);
          $tabsList.hide();
          for (var j = 0; j < $tab.length; j++) {
            var tabVal = $tab.find('a strong').eq(j).html();
            $sel.append($("<option>").attr('value',j).text(tabVal));
          }
          $sel.change(function() {
            var selectedInd = $sel.find('option:selected').index();
            $tab.eq(selectedInd).find('a').trigger('click');
          });
        }
      }
    }
  }


}) (jQuery, Drupal);
