(function ($) {
$(document).ready(function() { 

  function slideshowLaunch(){
    $('#slideshow .clearing-thumbs li').first().find('img').trigger('click');
  }
  
  slideshowLaunch();
  
  
});})(jQuery);

