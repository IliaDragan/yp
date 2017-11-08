function yellowPagesStatisticsPrint() {
  jQuery('.print-checkbox input').each(function(){
    var $this = jQuery(this);
    var id = $this.attr('id');
    var selector = '.' + id;
    if ($this.attr('checked') == 'checked') {
      jQuery(selector).removeClass('no-print');
    }
    else {
      jQuery(selector).addClass('no-print');
    }
  });
  window.print();
}
