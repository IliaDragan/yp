/**
 * @file
 * Company form script.
 */

Drupal.behaviors.ypCompanyForm = {
  attach: function (context, settings) {
    jQuery('#edit-business-hours .form-checkbox', context).on('change', function(){
      var $this = jQuery(this);
      var $parent = $this.parents('.edit-weekday');
      var id = $parent.attr('id');
      var $start = $parent.find('#' + id + '-start');
      var $end = $parent.find('#' + id + '-end');
      if ($this.prop('checked')) {
        $start.val('09:00');
        $start.trigger("chosen:updated");
        $end.val('18:00');
        $end.trigger("chosen:updated");
      }
      else {
        $start.val('None');
        $start.trigger("chosen:updated");
        $end.val('None');
        $end.trigger("chosen:updated");
      }
    });
  }
}
