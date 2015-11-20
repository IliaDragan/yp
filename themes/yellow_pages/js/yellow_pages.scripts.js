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
      if ($('.pane-yp-news-carousel', context).length === 0) {
        return;
      }

      var $owl = $('.pane-yp-news-carousel .pane-content', context);
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

      function owlInitialize() {
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
      $('.search-block-form input.form-text, .search-block-form--2 input.form-text', context).attr('placeholder', Drupal.t('Facility search'));
    }
  }

  Drupal.behaviors.custom_select = {
    attach : function (context) {
      var $select = $('.no-touch select', context);
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
      var $nodeTabsBlock = $('.node-tabs-block', context);
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
      var $stickyFooter = $('.footer', context);
      if ($stickyFooter.length) {

        var vwptHeight = $(window).height();
        if (vwptHeight > $('body').height()) {
          var $mainwrapper = $('.main-container'),
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
      var $innerMenuWrapper = $('.inner-menu-wrapper', context);
      if ($innerMenuWrapper.length) {
        var $extraMenuOverlay = $('.extra-menu-overlay'),
            $innerMenuBlock =  $extraMenuOverlay.find('.inner-menu-block'),
            $body = $('body');
        $innerMenuWrapper.find('.menu-btn').click(function() {
          $body.css('position', 'relative');
          var bodyPd = $body.css('padding-top'),
              menuBtnL = $(this).offset().left - 36,
              windowW = $(window).width(),
              menuInnerLeftMob = windowW - 290,
              menuInnerLeftAll = windowW - 350;
          $extraMenuOverlay.addClass('is-opened').css({
            top: bodyPd
          });
          if ((windowW - menuBtnL) > 300 && getWindowWidth() >= 768) {
            $innerMenuBlock.animate({
              left: menuBtnL
            });
          }
          else if (getWindowWidth() < 768) {
            $innerMenuBlock.animate({
              left: menuInnerLeftMob
            });
          }
          else {
            $innerMenuBlock.animate({
              left: menuInnerLeftAll
            });
          }
        });
        var hideMenu = function() {
          $body.css('position', '');
          $innerMenuBlock.animate({
            left: '100%'
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
      var $searchLink = $('header .search-link-mobile', context);
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

  Drupal.behaviors.toggle_mobile_menu = {
    attach : function (context) {
      var $filterBlock = $('.filter-block', context);
       if ($filterBlock.length) {
        for (var i = 0, len = $filterBlock.length; i < len; i++) {
          var $filterOPenLink = $filterBlock.eq(i).find('.pane-title');
          $filterOPenLink.click(function() {
            $(this).next('.pane-content').slideToggle();
          });
        }
      }
    }
  }

  Drupal.behaviors.tabs_for_print = {
    attach : function (context) {
      var $horizontalTabs = $('.horizontal-tabs', context);
       if ($horizontalTabs.length) {
        for (var i = 0, len = $('.horizontal-tab-button').length; i < len; i++) {
          var Tabtitle = $('.horizontal-tab-button').eq(i).find('strong').text();
          $('.field-group-htab').eq(i).find('.fieldset-wrapper').prepend('<span class="horizontal-tab-title">' + Tabtitle + '</span>')
        }
      }
    }
  }

  Drupal.behaviors.horizontal_tabs_mobile = {
    attach : function (context) {
      var $horizontalTabs = $('div.horizontal-tabs', context);
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

  Drupal.behaviors.owlGalleryVideo = {
    attach : function (context) {
      var $owlVideoItems = $('.view-media-field .file-video .content img', context);
      if ($owlVideoItems.length) {
        $owlVideoItems.each(function() {
          var $this = $(this);
          $this.after('<div class="video-icon-wrapper"><div class="video-icon"></div></div>');
        });
      }
    }
  }

  // Open service links in new window.
  $(document).ready(function () {
    $('a[class^="service-links"]').click(function(e) {
      var $this = $(this);
      if (!$this.hasClass('service-links-forward')) {
        e.preventDefault();
        var $url = $this.attr('href');
        window.open($url, '', 'toolbar=0,status=0,width=626,height=436');
      }
    });
  });



}) (jQuery, Drupal);
