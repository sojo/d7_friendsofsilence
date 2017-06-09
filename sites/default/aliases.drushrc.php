<?php
  
$aliases['fosprod'] = array(
  'root' => '/var/www/d7.friendsofsilence.net/htdocs',
  'remote-host' => 'd7.friendsofsilence.net',
  'remote-user' => '677e',
  'uri' => 'default',
  'path-aliases' => array(
    '%drush' => '/usr/local/bin/drush',
    '%dump-dir' => '/home/677e/drush-dump',
    '%files' => '/var/www/d7.friendsofsilence.net/htdocs/sites/default/files',
  ),
  'command-specific' => array(
    'sql-sync' => array(
      'source-dump' => '/home/677e/drush-dump/fos.production-sync.sql',
    ),
  ),
);