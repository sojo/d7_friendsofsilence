<!--.page -->
<div role="document" class="page">  

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

</div>
<!--/.page -->
