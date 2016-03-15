Drupal.behaviors.statisticsPrint = {
  attach : function (context) {
    var $printCheckboxes = jQuery('#print-checkboxes', context);
    //jQuery('#print-wrapper', context)
    //  .mouseenter(function(){
    //    $printCheckboxes.show();
    //  })
    //  .mouseleave(function(){
    //    $printCheckboxes.hide();
    //  })
    //  .trigger('mouseleave');






    jQuery('#print-search', context).on('change', function(){
      var obj = jQuery(this);
      if (obj.attr('checked') == 'checked') {
        jQuery('.print-search', context).removeClass('no-print');
        alert('checked');
      }
      else {
        jQuery('.print-search', context).addClass('no-print');
        alert('unchecked');
      }

    });







  }
}