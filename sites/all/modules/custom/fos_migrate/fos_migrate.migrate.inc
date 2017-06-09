<?php

/**
 * Implements hook_migrate_api().
 */
function fos_migrate_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'FOS' => array(
        'title' => t('Friends of Silence D6'),
        // 'default_format' => 'filtered_html',
      ),
    ),
  );
  return $api;
}

/**
* Implementation of hook_flush_caches().
* https://www.acquia.com/blog/drupal-drupal-data-migration-part-1-basics
* example_d2d.module
*
* There needs to be some point at which your migrations are registered, or
* previously-registered migrations are updated with changed arguments. We choose to
* do this on a cache clear.
*/
function fos_migrate_flush_caches() {
/**
  * Each migration being registered takes an array of arguments, some required
  * and some optional. Start with the common arguments required by all - the
  * source_connection (connection key, set up in settings.php, pointing to
  * the Drupal 6 database) and source_version (major version of Drupal).
  */
$common_arguments = array(
    'source_connection' => 'fos_d6',
    'source_version' => 6,
    'group_name' => 'FOS',
);

// The description and the migration machine name are also required arguments,
// which will be unique for each migration you register.
$arguments = $common_arguments + array(
    'description' => t('Migration of users from FOS Drupal 6'),
    'machine_name' => 'FOSUser',
    //'picture_migration' => 'SojoUserFilesMigration',    
);

// We just use the migrate_d2d D6 migration class as-is.
Migration::registerMigration('FOSUserMigration', $arguments['machine_name'], $arguments);

/* Tag vocabulary */
$arguments = $common_arguments + array(
  'description' => t('Migration of tag terms from FOS Drupal 6'),
  'machine_name' => 'FOSTag',
  'source_vocabulary' => '44', // vid of the Drupal 6 tag vocabulary
  'destination_vocabulary' => 'tags',
);

Migration::registerMigration('DrupalTerm6Migration', $arguments['machine_name'], $arguments);

/* Author vocabulary */
$arguments = $common_arguments + array(
  'description' => t('Migration of author terms from FOS Drupal 6'),
  'machine_name' => 'FOSAuthor',
  'source_vocabulary' => '1', // vid of the Drupal 6 tag vocabulary
  'destination_vocabulary' => 'author',
);

Migration::registerMigration('DrupalTerm6Migration', $arguments['machine_name'], $arguments);

/* Source vocabulary */
$arguments = $common_arguments + array(
  'description' => t('Migration of source terms from FOS Drupal 6'),
  'machine_name' => 'FOSSource',
  'source_vocabulary' => '2', // vid of the Drupal 6 tag vocabulary
  'destination_vocabulary' => 'source',
);

Migration::registerMigration('DrupalTerm6Migration', $arguments['machine_name'], $arguments);

/* eBook vocabulary */
$arguments = $common_arguments + array(
  'description' => t('Migration of ebook terms from FOS Drupal 6'),
  'machine_name' => 'FOSEbook',
  'source_vocabulary' => '49', // vid of the Drupal 6 tag vocabulary
  'destination_vocabulary' => 'ebook',
);

Migration::registerMigration('DrupalTerm6Migration', $arguments['machine_name'], $arguments);

/* Files */
$arguments = $common_arguments + array(
    'description' => t('Migration of FOS files from Drupal 6'),
    'machine_name' => 'FOSFiles',
    'source_dir' => '/var/www/friendsofsilence.net/htdocs/sites/default/files', 
    'file_replace' => MigrateFile::FILE_EXISTS_REUSE,
    'default_uid' => 1,
);

Migration::registerMigration('FOSFilesMigration', $arguments['machine_name'], $arguments);

/* Member */
$arguments = $common_arguments + array(
  'description' => t('Migration of member nodes from Drupal 6 to Drupal 7 nodes'),
  'machine_name' => 'FOSMember',
  'source_type' => 'member',
  'destination_type' => 'member',
);

Migration::registerMigration('FOSMemberMigration', $arguments['machine_name'], $arguments);

/* Contribution */
$arguments = $common_arguments + array(
  'description' => t('Migration of contribution nodes from Drupal 6 to Drupal 7 nodes'),
  'machine_name' => 'FOSContribution',
  'source_type' => 'contribution',
  'destination_type' => 'contribution',
);

Migration::registerMigration('FOSContributionMigration', $arguments['machine_name'], $arguments);

/* Newsletter */
$arguments = $common_arguments + array(
  'description' => t('Migration of newsletter nodes from Drupal 6 to Drupal 7 nodes'),
  'machine_name' => 'FOSNewsletter',
  'source_type' => 'newsletter',
  'destination_type' => 'newsletter',
);

Migration::registerMigration('FOSNewsletterMigration', $arguments['machine_name'], $arguments);

/* Quotation */
$arguments = $common_arguments + array(
  'description' => t('Migration of quotation nodes from Drupal 6 to Drupal 7 nodes'),
  'machine_name' => 'FOSQuotation',
  'source_type' => 'quotation',
  'destination_type' => 'quotation',
);

Migration::registerMigration('FOSQuotationMigration', $arguments['machine_name'], $arguments);

/* Page */
$arguments = $common_arguments + array(
  'description' => t('Migration of page nodes from Drupal 6 to Drupal 7 nodes'),
  'machine_name' => 'FOSPage',
  'source_type' => 'page',
  'destination_type' => 'page',
);

Migration::registerMigration('FOSPageMigration', $arguments['machine_name'], $arguments);

/* Blog */
$arguments = $common_arguments + array(
  'description' => t('Migration of bloh nodes from Drupal 6 to Drupal 7 nodes'),
  'machine_name' => 'FOSBlog',
  'source_type' => 'blog',
  'destination_type' => 'blog',
);

Migration::registerMigration('FOSBlogMigration', $arguments['machine_name'], $arguments);

}// end of flush cache