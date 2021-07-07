<?php

/**
 * @file
 * Theme the 'amazon-item' 'thumbnail' image style.
 * Many, many available variables. See template_preprocess_amazon_item().
 * Everything that gets put into $variables there is available.
 */
?>
<div class="<?php print $classes; ?>">
<?php if (!empty($invalid_asin)) { print "<div class='invalid_asin'>This item is no longer valid on Amazon.</div>"; } ?>
<?php if (!empty($smallimage_gallery)): ?>
	<?php foreach($smallimage_gallery as $image) {
			print $image;
		}
	?>
<?php endif; ?>
</div>
