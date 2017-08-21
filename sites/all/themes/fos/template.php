<?php
  
function fos_preprocess_page(&$variables) {
	//add simple page tempalte for ?display=none
	if(isset($_GET['display'])){
		if($_GET['display'] == 'none'){
			$variables['theme_hook_suggestions'][] = "page__simple";;
		}	
	}
}