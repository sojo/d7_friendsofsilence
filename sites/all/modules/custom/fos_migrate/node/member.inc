<?php
class FOSMemberMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    //$this->sourceFields['tags_and_topics'] = 'Combined tags and topics';
    
    parent::__construct($arguments);
    $this->removeFieldMapping('field_member_zip5');
    $this->removeFieldMapping('uid');
    $this->addFieldMapping('uid')->defaultValue(1);
    $this->removeFieldMapping('revision');
    $this->removeFieldMapping('revision_uid');
		$this->addFieldMapping('revision')->defaultValue(TRUE);
		$this->addFieldMapping('revision_uid')->defaultValue(1);

    $this->addFieldMapping('field_prefix', 'field_member_prefix');
    $this->addFieldMapping('field_first_name', 'field_member_firstname');
    $this->addFieldMapping('field_mi', 'field_member_mi');
    $this->addFieldMapping('field_last_name', 'field_member_lastname');
    $this->addFieldMapping('field_suffix', 'field_member_suffix');
    $this->addFieldMapping('field_greeting', 'field_member_greeting');
    $this->addFieldMapping('field_address1', 'field_member_address1');
    $this->addFieldMapping('field_address2', 'field_member_address2');
    $this->addFieldMapping('field_street_address', 'field_member_streetaddress');
    $this->addFieldMapping('field_city', 'field_member_city');
    $this->addFieldMapping('field_state', 'field_member_state');
    $this->addFieldMapping('field_zip', 'field_member_zip');
    $this->addFieldMapping('field_country', 'field_member_country');
    $this->addFieldMapping('field_phone', 'field_member_phone');
    $this->addFieldMapping('field_cell_phone', 'field_member_cellphone');
    $this->addFieldMapping('field_email', 'field_member_email');
    $this->addFieldMapping('field_active', 'field_member_active');
    $this->addFieldMapping('field_email_only', 'field_member_emailonly');
    $this->addFieldMapping('field_share_contact', 'field_member_sharecontact');
    $this->addFieldMapping('field_non_us', 'field_member_non_us');
    $this->addFieldMapping('field_personid', 'field_member_personid');
    $this->addFieldMapping('field_sid', 'field_member_sid');

    $this->addUnmigratedSources(array('field_member_zip5', 'upload', 'upload:description', 'upload:list', 'upload:weight', 'daycount', 'timestamp', 'totalcount', 'log'));

    /*
    $this->removeFieldMapping('body:summary');
    $this->removeFieldMapping('path');
    $this->removeFieldMapping('teaser');
    $this->removeFieldMapping('pathauto');
    $this->addFieldMapping('pathauto')
      ->defaultValue('1');    
    $this->removeFieldMapping('comment');
    $this->addFieldMapping('comment')
      ->defaultValue(1);
    $this->removeFieldMapping('language');
    $this->addFieldMapping('language')
      ->defaultValue('und');
  
    destination:
    field_issue_month:to
    field_publish_date:to
    
    source:
    field_inside:format
    upload
    
  
    $this->addFieldMapping('field_issue_month', 'field_issue');
    $this->addFieldMapping('field_issue_month:to', 'field_issue:value2');
    
    $this->addFieldMapping('field_issue_volume', 'field_volume');
    $this->addFieldMapping('field_issue_number', 'field_issue_number');

    $this->addFieldMapping('field_publish_date', 'field_publish_date');

    
    $this->addFieldMapping('field_subtitle', 'field_issue_subtitle');
    $this->addFieldMapping('field_subtitle:language')
      ->defaultValue('und'); ;
      
    $this->addFieldMapping('field_main_image', 'field_cover_image')
      ->sourceMigration('SojoIssueFiles');
    $this->addFieldMapping('field_main_image:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_main_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_main_image:language')
      ->defaultValue('und');
    $this->addFieldMapping('field_main_image:alt','field_cover_image:alt');
    $this->addFieldMapping('field_main_image:title','field_cover_image:alt');
    
    $this->addFieldMapping('field_tags', 'tags_and_topics')->sourceMigration('SojoTag');
    $this->addFieldMapping('field_tags:source_type')
      ->defaultValue('tid');

    $this->addUnmigratedSources(array('teaser','field_issue_image', 'field_issue_subdirectory', 'field_issue_month_tag', 'field_cover_image_data', 'field_cover_image:list', 'field_issue_id', 'field_issue_featured_articles', 'field_issue_featured_columns'));
    $this->addUnmigratedDestinations(array('field_tracking_tag','field_features'));
    */
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
		$row->field_member_active = ($row->field_member_active == 'on') ? 1 : 0;
		$row->field_member_emailonly = ($row->field_member_emailonly == 'on') ? 1 : 0;
		$row->field_member_sharecontact = ($row->field_member_sharecontact == 'on') ? 1 : 0;
		$row->field_member_non_us = ($row->field_member_non_us == 'on') ? 1 : 0;
    /*
    $topics = $row->{14};
    $tags = $row->{15};
    $row->tags_and_topics = SojoSharedMigrationFunctions::addTopicsToTags($topics, $tags); 
    $body = $row->body;
    $inside = $row->field_inside;
    if (strlen($body) == 0) {
      if (strlen($inside) > 0) {
        $row->body = $inside;
      }
    }
    else {
      if (strlen($inside) > strlen($body)) {
        $row->body = $inside;
      }
    }
    */
  }

  public function complete($entity, stdClass $row) {
  	/*
  
		if (isset($row->field_cover_image)) {
    	$alt = isset($row->{'field_cover_image:alt'}) ? $row->{'field_cover_image:alt'} : '' ;
			//$title = isset($row->{'field_cover_image_title'}) ? $row->{'field_cover_image_title'} : '' ;
	    $fid = $entity->field_main_image[LANGUAGE_NONE][0]['fid'];
	    $file = file_load($fid);
	    //$file->field_caption = array(
	    //  LANGUAGE_NONE => array(
	    //    0 => array(
	    //      'value' => $description,
	    //      'format' => 'plain_text',
	    //    )
	    //  )
	    //);
	    $file->field_file_image_alt_text = array(
	      LANGUAGE_NONE => array(
	        0 => array(
	          'value' => $alt,
	          'format' => 'plain_text',
	        )
	      )
	    );
	    $file->field_file_image_title_text = array(
	      LANGUAGE_NONE => array(
	        0 => array(
	          'value' => $alt,
	          'format' => 'plain_text',
	        )
	      )
	    );
	    entity_save('file', $file);
		}
		
    $query = db_update('node')
      ->condition('nid', $entity->nid)
      ->condition('vid', $entity->vid)
      ->fields(array('live_issue' => $row->status))
      ->execute();

    //Migrate path to redirect. We do this here since we need the new NID.
    if (isset($row->path)) {
      $redirect = new stdClass();
      redirect_object_prepare($redirect);
      $redirect->source = $row->path;
      $redirect->redirect = 'node/' . $entity->nid;
      // Check if the redirect exists before saving.
      $hash = redirect_hash($redirect);
      if (!redirect_load_by_hash($hash)) {
        redirect_save($redirect);
      }
    }
  */
  }

}  
  

