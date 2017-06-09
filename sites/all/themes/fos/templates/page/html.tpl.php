<!DOCTYPE html>
<!-- Sorry no IE7 support! -->
<!-- @see http://foundation.zurb.com/docs/index.html#basicHTMLMarkup -->

<!--[if IE 8]><html class="no-js lt-ie9" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>"> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js" lang="<?php print $language->language ?>" dir="<?php print $language->dir ?>"> <!--<![endif]-->
<head>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>  
  <?php print $styles; ?>
  <script async='async' src='https://www.googletagservices.com/tag/js/gpt.js'></script>
  <script>var googletag = googletag || {}; googletag.cmd = googletag.cmd || [];</script>
  <?php print $scripts; ?>

  <link rel="apple-touch-icon-precomposed" sizes="180x180" href="/sites/all/themes/fos/favicons/apple-icon-180x180.png">
  <link rel="apple-touch-icon-precomposed" sizes="152x152" href="/sites/all/themes/fos/favicons/apple-icon-152x152.png">
  <link rel="apple-touch-icon-precomposed" sizes="144x144" href="/sites/all/themes/fos/favicons/apple-icon-144x144.png">
  <link rel="apple-touch-icon-precomposed" sizes="120x120" href="/sites/all/themes/fos/favicons/apple-icon-120x120.png">
  <link rel="apple-touch-icon-precomposed" sizes="114x114" href="/sites/all/themes/fos/favicons/apple-icon-114x114.png">
  <link rel="apple-touch-icon-precomposed" sizes="76x76" href="/sites/all/themes/fos/favicons/apple-icon-76x76.png">
  <link rel="apple-touch-icon-precomposed" sizes="72x72" href="/sites/all/themes/fos/favicons/apple-icon-72x72.png">
  <link rel="apple-touch-icon-precomposed" href="/sites/all/themes/fos/favicons/apple-icon.png">
  <link rel="icon" type="image/x-icon" sizes="192x192"  href="/sites/all/themes/fos/favicons/icon-192x192.png">
  <link rel="icon" type="image/x-icon" sizes="32x32" href="/sites/all/themes/fos/favicons/icon-32x32.png">
  <link rel="icon" type="image/x-icon" sizes="96x96" href="/sites/all/themes/fos/favicons/icon-96x96.png">
  <link rel="icon" type="image/x-icon" sizes="16x16" href="/sites/all/themes/fos/favicons/icon-16x16.png">
  <link rel="manifest" href="/sites/all/themes/fos/favicons//manifest.json">
  <meta name="msapplication-config" content="/sites/all/themes/fos/favicons/browserconfig.xml" />
  <meta name="msapplication-TileColor" content="#f58b2c">
  <meta name="msapplication-TileImage" content="/sites/all/themes/fos/favicons/apple-icon-144x144.png">
  <meta name="theme-color" content="#f58b2c">

  <!--[if lt IE 9]>
		<script src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
	<![endif]-->
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <div class="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
  <?php print _zurb_foundation_add_reveals(); ?>
  <script>
    (function ($, Drupal, window, document, undefined) {
      $(document).foundation();
    })(jQuery, Drupal, this, this.document);
  </script>
</body>
</html>
