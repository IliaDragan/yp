jQuery(document).ready(function($) {
  var yp_ads_nvc_insert_node_view = function(nids) {
    $.ajax({
      type: 'POST',
      url: Drupal.settings.basePath + 'yp/ads-nvc',
      dataType: 'json',
      data: {
        nids: JSON.stringify(nids)
      }
    });
  }

  var yp_ads_nvc_nids =  Drupal.settings.yp_ads_nvc;
  yp_ads_nvc_insert_node_view(yp_ads_nvc_nids);
});