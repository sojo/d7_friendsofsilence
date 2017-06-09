<?php
class FOSFilesMigration extends DrupalFile6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }
	
	public function query() {
   $query = parent::query();
   $query->condition('f.filepath', '/tmp/%', 'NOT LIKE');
   //drush_print($query);
   return $query;
  }
  
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $row->uid = 1;
  }
}