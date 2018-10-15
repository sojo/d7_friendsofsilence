<!--.page -->
<div role="document" class="page">  

  <!--.l-header -->
  <header role="banner" class="l-header" id="header">  
    <?php if (!empty($page['very_top_bar'])): ?>
      <section id="very-top-bar" class="l-verytop row">
          <?php print render($page['very_top_bar']); ?>
      </section>
    <?php endif; ?>

    <div id="top-bar-wrapper">
      <div class="top-bar" data-topbar <?php print $top_bar_options; ?>>
        <ul class="title-area">
          <li class="name"><h1><?php print $linked_site_name; ?></h1></li>
          <li class="toggle-topbar menu-icon">
            <a href="#"><span></span></a></li>
        </ul>
        
        <section class="top-bar-section">
          <nav id="main-menu" class="right">
            <?php   
              $block = module_invoke('menu_block', 'block_view', '2');
              print render($block['content']);     
            ?>
          </nav>
        </section>
      </div>
    </div>

    <?php if (!empty($page['header'])): ?>
      <!--.l-header-region -->
      <section class="l-header-region row">
        <div class="columns">
          <?php print render($page['header']); ?>
        </div>
      </section>
      <!--/.l-header-region -->
    <?php endif; ?>

  </header>
  <!--/.l-header -->
  
  <?php if ($breadcrumb): print $breadcrumb; endif; ?>
  <?php if(isset($sponsor_indicator)){print $sponsor_indicator;}?>

  <?php $tabcheck = render($tabs); if($tabcheck): ?>
    <div id="tabs">
      <?php print render($tabs); ?>
    </div>
    <?php if (!empty($tabs2)): print render($tabs2); endif; ?>
  <?php endif; ?>

  <?php if ($messages): ?>
    <!--.l-messages -->
    <section class="l-messages">
      <?php if ($messages): print $messages; endif; ?>
    </section>
    <!--/.l-messages -->
  <?php endif; ?>

  <?php if (!empty($page['help'])): ?>
    <!--.l-help -->
    <section class="l-help row">
      <div class="columns">
        <?php print render($page['help']); ?>
      </div>
    </section>
    <!--/.l-help -->
  <?php endif; ?>

  <?php if (!empty($page['featured'])): ?>
    <!--.l-featured-region -->
    <section id="featured-region" class="l-featured-region">
      <?php print render($page['featured']); ?>
    </section>
    <!--/.l-featured-region -->
  <?php endif; ?>

  <!--.l-main -->
  <main role="main" class="row l-main">
    <!-- .l-main region -->
    <div class="<?php print $main_grid; ?> main columns">
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlight panel callout">
          <?php print render($page['highlighted']); ?>
        </div>
      <?php endif; ?>

      <a id="main-content"></a>
      
      <?php if ($action_links): ?>
        <ul class="action-links">
          <?php print render($action_links); ?>
        </ul>
      <?php endif; ?>


        <?php print render($title_prefix); ?>
        <h1 id="page-title" class="title"><?php print $title; ?></h1>
        <?php print render($title_suffix); ?>

      
      <?php print render($page['content']); ?>
    </div>
    <!--/.l-main region -->
  </main>
  <!--/.l-main -->


  <!--.l-footer -->
  <footer class="l-footer" role="contentinfo">
    <div class="footer-top">
        <?php print render($page['footer']); ?>
    </div>
    <div class="footer-bottom clearfix">
      <div class="footer-bottom-right">
      </div>
      <div class="footer-bottom-left">
        <div class="footer-logo"><?php print l('Friends of Silence', '/') ?></div>
        <div class="footer-copyright">Unless otherwise noted, all material<br />&copy; Friends of Silence <?php print date('Y') ?></div>
      </div>

    </div>
  </footer>
  <!--/.l-footer -->
</div>
<!--/.page -->
