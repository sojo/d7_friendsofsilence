<?php

class WebformSettings extends Migration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $simple_fields = array('confirmation', 'redirect_url', 'status', 'block', 'teaser', 'allow_draft', 'auto_save', 'submit_notice', 'submit_text', 'submit_limit', 'submit_interval', 'total_submit_limit', 'total_submit_interval');
    $complex_fields = array('nid', 'confirmation_format');
    $fields = array_merge($simple_fields, $complex_fields);

    $query = $this->query($fields);
    $table_name = 'webform';

    $this->source = new MigrateSourceSQL($query, $fields, NULL,  array('map_joinable' => FALSE, 'skip_count' => FALSE));

    $this->destination = new MigrateDestinationTable($table_name);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array('type' => 'int',
                       'unsigned' => TRUE,
                       'not null' => TRUE,
                       'description' => 'Source node ID',
                       'alias' => 'n',
                      ),
      ),
      MigrateDestinationTable::getKeySchema($table_name)
    );

    $this->addSimpleMappings($simple_fields);

    $this->addFieldMapping('nid', 'nid');

    $this->addFieldMapping('confirmation_format', 'confirmation_format')
           ->callbacks(array($this, 'mapFormat'));

    if (db_field_exists($table_name, 'preview_message')) {
      $this->addFieldMapping('preview_message')->defaultValue('');
    }
    if (db_field_exists($table_name, 'preview_message_format')) {
      $this->addFieldMapping('preview_message_format')->defaultValue($arguments['default_format']);
    }
    if (db_field_exists($table_name, 'preview_excluded_components')) {
      $this->addFieldMapping('preview_excluded_components')->defaultValue('');
    }
  }

  protected function query($fields) {
    $connection = migrate_webform_get_source_connection();
    $query = $connection
           ->select('webform', 'w') 
           ->fields('w', $fields)
           ->orderBy('nid', 'ASC');
    return $query;
  }

  // Copied from migrate_d2d. Extending DrupalMigrate wasn't so hot...
  protected function mapFormat($format) {
    if (!is_array($format)) {
      $format = array($format);
    }
    $result = array();
    foreach ($format as $format_value) {
      if (isset($format_value) && isset($this->formatMappings[$format_value])) {
        $result[] = $this->formatMappings[$format_value];
      }
      else {
        $result[] = NULL;
      }
    }
    // Only return an array if we have to
    if (count($result) > 1) {
      return $result;
    }
    else {
      return reset($result);
    }
  }

  public function prepareRow($row) {
    // skip?
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $row->nid = $this->handleSourceMigration($this->arguments['node_migrations'], $row->nid);

    // Node creation filled the table with a bunch of junk defaults.
    db_delete('webform')
      ->condition('nid', $row->nid)
      ->execute();

  }

  public function prepare($entity, $row) {
  }

}
