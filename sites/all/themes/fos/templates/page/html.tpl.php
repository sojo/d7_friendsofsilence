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

<link rel="apple-touch-icon-precomposed" sizes="57x57" href="/sites/all/themes/fos/favicons/apple-touch-icon-57x57.png" />
<link rel="apple-touch-icon-precomposed" sizes="114x114" href="/sites/all/themes/fos/favicons/apple-touch-icon-114x114.png" />
<link rel="apple-touch-icon-precomposed" sizes="72x72" href="/sites/all/themes/fos/favicons/apple-touch-icon-72x72.png" />
<link rel="apple-touch-icon-precomposed" sizes="144x144" href="/sites/all/themes/fos/favicons/apple-touch-icon-144x144.png" />
<link rel="apple-touch-icon-precomposed" sizes="60x60" href="/sites/all/themes/fos/favicons/apple-touch-icon-60x60.png" />
<link rel="apple-touch-icon-precomposed" sizes="120x120" href="/sites/all/themes/fos/favicons/apple-touch-icon-120x120.png" />
<link rel="apple-touch-icon-precomposed" sizes="76x76" href="/sites/all/themes/fos/favicons/apple-touch-icon-76x76.png" />
<link rel="apple-touch-icon-precomposed" sizes="152x152" href="/sites/all/themes/fos/favicons/apple-touch-icon-152x152.png" />
<link rel="icon" type="image/png" href="/sites/all/themes/fos/favicons/favicon-196x196.png" sizes="196x196" />
<link rel="icon" type="image/png" href="/sites/all/themes/fos/favicons/favicon-96x96.png" sizes="96x96" />
<link rel="icon" type="image/png" href="/sites/all/themes/fos/favicons/favicon-32x32.png" sizes="32x32" />
<link rel="icon" type="image/png" href="/sites/all/themes/fos/favicons/favicon-16x16.png" sizes="16x16" />
<link rel="icon" type="image/png" href="/sites/all/themes/fos/favicons/favicon-128.png" sizes="128x128" />
<meta name="application-name" content="Friends of Silence"/>
<meta name="msapplication-TileColor" content="#FFFFFF" />
<meta name="msapplication-TileImage" content="/sites/all/themes/fos/favicons/mstile-144x144.png" />
<meta name="msapplication-square70x70logo" content="/sites/all/themes/fos/favicons/mstile-70x70.png" />
<meta name="msapplication-square150x150logo" content="/sites/all/themes/fos/favicons/mstile-150x150.png" />
<meta name="msapplication-wide310x150logo" content="/sites/all/themes/fos/favicons/mstile-310x150.png" />
<meta name="msapplication-square310x310logo" content="/sites/all/themes/fos/favicons/mstile-310x310.png" />


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
