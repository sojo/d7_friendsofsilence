	<?php

class FOSUserMigration extends DrupalUser6Migration {
  public function __construct(array $arguments) {
    $this->sourceFields['roles'] = 'user roles';
    parent::__construct($arguments);
  } 
  
	public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $row->roles[] = 3;
    return TRUE;
    
  }
  
	public function query() {
   $query = parent::query();
   $query->condition('u.uid',array(3,343,461,472,635), 'IN');
   return $query;
  }

  public function complete($account, $row) {

  }
}