/*
 * @file
 * Yellow pages print functionality.
 */

  Drupal.behaviors.nodePrint = {
    attach : function (context, settings) {
      var $body = jQuery('body', context);
      $body.addClass('contains-print-iframe');
      $body.append(settings.nodePrintVersionHTML);

//      function printNode () {
//        debugger;
//        var w = window.open(settings.nodePrintLink);
//        w.load();
//        w.print();
//        w.close();
//      }
//
//      window.print = function() {
//        alert('you can not print');
//        printNode();
//      }

//
//      jQuery(document).bind("keyup keydown", function(e){
//        debugger;
//        if(e.ctrlKey && e.keyCode == 80){
//          debugger;
//          printNode();
//          return false;
//        }
//      });
//      jQuery('.yp-print a', context).on('click', function(){
//        printNode();
//        return false;
//      });
    }
  }
