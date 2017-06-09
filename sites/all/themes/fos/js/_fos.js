(function ($) {
$(document).ready(function() {    
  
  $(document).keypress(function(e){
    var key = e.which;
    if (key === 96) {
      // toggle admin menu
      $('#admin-menu, .block-workbench, #tabs, .action-links, .node ul.links').toggle();
    }
  });
  
  
});})(jQuery);