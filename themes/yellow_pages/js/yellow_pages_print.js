/*
 * @file
 * Yellow pages print functionality.
 */

  Drupal.behaviors.nodePrint = {
    attach : function (context, settings) {
      var $body = jQuery('body', context);
      $body.addClass('contains-print-iframe');
      $body.append(settings.nodePrintVersionHTML);

      function hidePrintVersion() {
        jQuery('#node-print-version', context).addClass('node-print-version');
      }

      jQuery(document).ready(function() {
        if (Drupal.hasOwnProperty('geoField')) {
          if (Drupal.geoField.hasOwnProperty('maps')) {
            if (Drupal.geoField.maps.hasOwnProperty(settings.nodeMapVariableName)) {
              var map = Drupal.geoField.maps[settings.nodeMapVariableName];
              google.maps.event.addListenerOnce(map, 'idle', function(){
                hidePrintVersion();
              });
            }
            else {
              hidePrintVersion();
            }
          }
          else {
            hidePrintVersion();
          }
        }
        else {
          hidePrintVersion();
        }
      });
    }
  }
