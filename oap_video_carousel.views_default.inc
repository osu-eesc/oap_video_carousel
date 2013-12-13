<?php
/**
 * @file
 * oap_video_carousel.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function oap_video_carousel_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'Video';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Video';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'jcarousel';
  $handler->display->display_options['style_options']['wrap'] = '0';
  $handler->display->display_options['style_options']['skin'] = 'osu-video';
  $handler->display->display_options['style_options']['visible'] = '';
  $handler->display->display_options['style_options']['scroll'] = '1';
  $handler->display->display_options['style_options']['auto'] = '0';
  $handler->display->display_options['style_options']['autoPause'] = 1;
  $handler->display->display_options['style_options']['easing'] = '';
  $handler->display->display_options['style_options']['vertical'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<?php
	global $base_url;
	$current_depth = count(explode(\'/\', request_path()));
	if ($current_depth == 2 && drupal_is_front_page()) {
		$current_depth--;
	}
?>
<div class="section-header">
  <span>[field_issue] <?php if ($current_depth > 1) print \'Related\'; ?> Multimedia</span>
  <a href="<?php print $base_url; ?>/videos.rss"></a>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* Relationship: Book: Parent */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'book_parent';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Relationship: Book: Top level book */
  $handler->display->display_options['relationships']['bid']['id'] = 'bid';
  $handler->display->display_options['relationships']['bid']['table'] = 'book';
  $handler->display->display_options['relationships']['bid']['field'] = 'bid';
  /* Field: Content: Issue */
  $handler->display->display_options['fields']['field_issue']['id'] = 'field_issue';
  $handler->display->display_options['fields']['field_issue']['table'] = 'field_data_field_issue';
  $handler->display->display_options['fields']['field_issue']['field'] = 'field_issue';
  $handler->display->display_options['fields']['field_issue']['label'] = '';
  $handler->display->display_options['fields']['field_issue']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_issue']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issue']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Video title */
  $handler->display->display_options['fields']['field_article_videos_2']['id'] = 'field_article_videos_2';
  $handler->display->display_options['fields']['field_article_videos_2']['table'] = 'field_data_field_article_videos';
  $handler->display->display_options['fields']['field_article_videos_2']['field'] = 'field_article_videos';
  $handler->display->display_options['fields']['field_article_videos_2']['ui_name'] = 'Video title';
  $handler->display->display_options['fields']['field_article_videos_2']['label'] = '';
  $handler->display->display_options['fields']['field_article_videos_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_article_videos_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_article_videos_2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_article_videos_2']['type'] = 'youtube_title';
  $handler->display->display_options['fields']['field_article_videos_2']['delta_offset'] = '0';
  /* Field: Video ID */
  $handler->display->display_options['fields']['field_article_videos_1']['id'] = 'field_article_videos_1';
  $handler->display->display_options['fields']['field_article_videos_1']['table'] = 'field_data_field_article_videos';
  $handler->display->display_options['fields']['field_article_videos_1']['field'] = 'field_article_videos';
  $handler->display->display_options['fields']['field_article_videos_1']['ui_name'] = 'Video ID';
  $handler->display->display_options['fields']['field_article_videos_1']['label'] = '';
  $handler->display->display_options['fields']['field_article_videos_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_article_videos_1']['alter']['text'] = '[field_article_videos_1]';
  $handler->display->display_options['fields']['field_article_videos_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_article_videos_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_article_videos_1']['type'] = 'youtube_id';
  $handler->display->display_options['fields']['field_article_videos_1']['settings'] = array(
    'file_view_mode' => 'media_original',
  );
  $handler->display->display_options['fields']['field_article_videos_1']['delta_offset'] = '0';
  /* Field: Video thumbnail */
  $handler->display->display_options['fields']['field_article_videos']['id'] = 'field_article_videos';
  $handler->display->display_options['fields']['field_article_videos']['table'] = 'field_data_field_article_videos';
  $handler->display->display_options['fields']['field_article_videos']['field'] = 'field_article_videos';
  $handler->display->display_options['fields']['field_article_videos']['ui_name'] = 'Video thumbnail';
  $handler->display->display_options['fields']['field_article_videos']['label'] = '';
  $handler->display->display_options['fields']['field_article_videos']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_article_videos']['alter']['text'] = '<a href="[field_article_videos_1]" class="youtube cboxElement">
[field_article_videos]
[title]
</a>';
  $handler->display->display_options['fields']['field_article_videos']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_article_videos']['alter']['link_class'] = 'colorbox-load';
  $handler->display->display_options['fields']['field_article_videos']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_article_videos']['alter']['preserve_tags'] = '<img><h2>';
  $handler->display->display_options['fields']['field_article_videos']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_article_videos']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_article_videos']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_article_videos']['settings'] = array(
    'file_view_mode' => 'default',
  );
  $handler->display->display_options['fields']['field_article_videos']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="http://youtube.com/embed/[field_article_videos_1]?fs=1&width=640&height=480&iframe=true&autoplay=1" class="colorbox-load">
<div class="play-button"></div>
[field_article_videos]
<p>[field_article_videos_2]</p>
</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Book: Depth */
  $handler->display->display_options['sorts']['depth']['id'] = 'depth';
  $handler->display->display_options['sorts']['depth']['table'] = 'book_menu_links';
  $handler->display->display_options['sorts']['depth']['field'] = 'depth';
  /* Sort criterion: Book: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'book_menu_links';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['arguments']['nid_1']['table'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid_1']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['nid_1']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid_1']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid_1']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid_2']['id'] = 'nid_2';
  $handler->display->display_options['arguments']['nid_2']['table'] = 'node';
  $handler->display->display_options['arguments']['nid_2']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid_2']['relationship'] = 'bid';
  $handler->display->display_options['arguments']['nid_2']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid_2']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid_2']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid_2']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid_2']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Article video(s) (field_article_videos:fid) */
  $handler->display->display_options['filters']['field_article_videos_fid']['id'] = 'field_article_videos_fid';
  $handler->display->display_options['filters']['field_article_videos_fid']['table'] = 'field_data_field_article_videos';
  $handler->display->display_options['filters']['field_article_videos_fid']['field'] = 'field_article_videos_fid';
  $handler->display->display_options['filters']['field_article_videos_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_article_videos_fid']['group'] = 1;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_5');

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Oregon\'s Agricultural Progress - Multimedia';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['description'] = 'Latest multimedia from Oregon\'s Agricultural Progress';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'title';
  $handler->display->display_options['row_options']['link_field'] = 'field_article_videos_1';
  $handler->display->display_options['row_options']['description_field'] = 'field_deck';
  $handler->display->display_options['row_options']['creator_field'] = 'nothing';
  $handler->display->display_options['row_options']['date_field'] = 'changed';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'nid',
    'guid_field_is_permalink' => 0,
  );
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Issue */
  $handler->display->display_options['fields']['field_issue']['id'] = 'field_issue';
  $handler->display->display_options['fields']['field_issue']['table'] = 'field_data_field_issue';
  $handler->display->display_options['fields']['field_issue']['field'] = 'field_issue';
  $handler->display->display_options['fields']['field_issue']['label'] = '';
  $handler->display->display_options['fields']['field_issue']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_issue']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_issue']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_issue']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '22';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Video URL */
  $handler->display->display_options['fields']['field_article_videos_1']['id'] = 'field_article_videos_1';
  $handler->display->display_options['fields']['field_article_videos_1']['table'] = 'field_data_field_article_videos';
  $handler->display->display_options['fields']['field_article_videos_1']['field'] = 'field_article_videos';
  $handler->display->display_options['fields']['field_article_videos_1']['ui_name'] = 'Video URL';
  $handler->display->display_options['fields']['field_article_videos_1']['label'] = '';
  $handler->display->display_options['fields']['field_article_videos_1']['alter']['text'] = '[field_article_videos_1]';
  $handler->display->display_options['fields']['field_article_videos_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_article_videos_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_article_videos_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_article_videos_1']['type'] = 'file_url_plain';
  $handler->display->display_options['fields']['field_article_videos_1']['settings'] = array(
    'file_view_mode' => 'media_original',
  );
  $handler->display->display_options['fields']['field_article_videos_1']['delta_offset'] = '0';
  /* Field: Video thumbnail */
  $handler->display->display_options['fields']['field_article_videos']['id'] = 'field_article_videos';
  $handler->display->display_options['fields']['field_article_videos']['table'] = 'field_data_field_article_videos';
  $handler->display->display_options['fields']['field_article_videos']['field'] = 'field_article_videos';
  $handler->display->display_options['fields']['field_article_videos']['ui_name'] = 'Video thumbnail';
  $handler->display->display_options['fields']['field_article_videos']['label'] = '';
  $handler->display->display_options['fields']['field_article_videos']['alter']['text'] = '<a href="[field_article_videos_1]" class="youtube cboxElement">
[field_article_videos]
[title]
</a>';
  $handler->display->display_options['fields']['field_article_videos']['alter']['external'] = TRUE;
  $handler->display->display_options['fields']['field_article_videos']['alter']['link_class'] = 'colorbox-load';
  $handler->display->display_options['fields']['field_article_videos']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_article_videos']['alter']['preserve_tags'] = '<img><h2>';
  $handler->display->display_options['fields']['field_article_videos']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_article_videos']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_article_videos']['type'] = 'file_rendered';
  $handler->display->display_options['fields']['field_article_videos']['settings'] = array(
    'file_view_mode' => 'default',
  );
  $handler->display->display_options['fields']['field_article_videos']['delta_offset'] = '0';
  /* Field: Content: Article video(s) (field_article_videos:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_article_videos';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delta']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delta']['separator'] = '';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '[nid]:[delta]';
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Oregon State Extension Service';
  $handler->display->display_options['fields']['nothing']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Deck */
  $handler->display->display_options['fields']['field_deck']['id'] = 'field_deck';
  $handler->display->display_options['fields']['field_deck']['table'] = 'field_data_field_deck';
  $handler->display->display_options['fields']['field_deck']['field'] = 'field_deck';
  $handler->display->display_options['fields']['field_deck']['label'] = '';
  $handler->display->display_options['fields']['field_deck']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_deck']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Article video(s) (field_article_videos:fid) */
  $handler->display->display_options['filters']['field_article_videos_fid']['id'] = 'field_article_videos_fid';
  $handler->display->display_options['filters']['field_article_videos_fid']['table'] = 'field_data_field_article_videos';
  $handler->display->display_options['filters']['field_article_videos_fid']['field'] = 'field_article_videos_fid';
  $handler->display->display_options['filters']['field_article_videos_fid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_article_videos_fid']['group'] = 1;
  /* Filter criterion: Content: Current Issue? (field_current_issue) */
  $handler->display->display_options['filters']['field_current_issue_value']['id'] = 'field_current_issue_value';
  $handler->display->display_options['filters']['field_current_issue_value']['table'] = 'field_data_field_current_issue';
  $handler->display->display_options['filters']['field_current_issue_value']['field'] = 'field_current_issue_value';
  $handler->display->display_options['filters']['field_current_issue_value']['value'] = array(
    'yes' => 'yes',
  );
  $handler->display->display_options['path'] = 'videos.rss';
  $handler->display->display_options['sitename_title'] = 0;
  $export['Video'] = $view;

  return $export;
}
