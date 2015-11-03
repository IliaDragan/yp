/**
 * @file
 * Switch search frontend functionality.
 */

(function($) {
  $(document).ready(function() {
    // Click the label link when a radio button is clicked.
    $('#switch-search-form input[type=radio]').change(function() {
      var link = $(this).parent().find('a');
      window.location = link.attr('href');
    });

    // When a label link is click, also check the radio button.
    $('#switch-search-form a').click(function(event) {
      var radio = $(this).parent().parent().find('input[type="radio"]');
      if (radio.is(':checked')) {
        // If it is already checked do nothing.
        event.preventDefault();
        return false;
      }
      else {
        // Check the radio button and continue handling the click event.
        radio.attr('checked', 'checked');
        return true;
      }
    });
  });
}(jQuery));
