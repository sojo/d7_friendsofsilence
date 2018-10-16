<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
 
  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>
      <a href="<?php print $node_url; ?>"><?php print $title; ?></a>
    </h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <div class="author-newsletter">
    <?php
	    if($content['field_author']){
	    	print render($content['field_author']);
    	}
	    if($content['field_newsletter_reference']){
	    	print render($content['field_newsletter_reference']);
    	}
    ?>
  </div>
  
  <?php print render($content['body']) ?>
  <?php print render($content['field_quotation_bi_line']) ?>
  <div class="amazon-link">
    <?php
	    if($content['field_quotation_amazon']){
	    	print render($content['field_quotation_amazon']);
    	}
    ?>	  
  </div>
  
  
  <div class="node-tags">
	  <?php
		  //print all tag fields
		  $tags = array('author', 'source', 'ebook', 'tags');
		  foreach($tags as $tag){
			  print '<div class="tag tag-'.$tag.'">';
			  print render($content['field_'.$tag]);
			  print '</div>';
			  
		  }
	   ?>
  </div>
  
  <?php print render($content['links']); ?>

</article>
