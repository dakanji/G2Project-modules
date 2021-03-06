<?php
$blocks['ImageBlock'] = array(
	'description' => $gallery->i18n('Image Block'),
	'vars'        => array(
		'blocks' => array(
			'description' => $gallery->i18n('Image type'),
			'type'        => 'choice',
			'default'     => 'randomImage',
			'choices'     => array(
				'randomImage'  => $gallery->i18n('Random image'),
				'recentImage'  => $gallery->i18n('Recent image'),
				'viewedImage'  => $gallery->i18n('Viewed image'),
				'randomAlbum'  => $gallery->i18n('Random album'),
				'recentAlbum'  => $gallery->i18n('Recent album'),
				'viewedAlbum'  => $gallery->i18n('Viewed album'),
				'dailyImage'   => $gallery->i18n('Daily image'),
				'weeklyImage'  => $gallery->i18n('Weekly image'),
				'monthlyImage' => $gallery->i18n('Monthly image'),
				'dailyAlbum'   => $gallery->i18n('Daily album'),
				'weeklyAlbum'  => $gallery->i18n('Weekly album'),
				'monthlyAlbum' => $gallery->i18n('Monthly album'),
			),
		),
		'repeatBlock' => array(
			'description' => $gallery->i18n('Number of items'),
			'type'        => 'text',
			'default'     => '1',
		),
		'useDefaults' => array(
			'description' => $gallery->i18n('Use default settings'),
			'type'        => 'boolean',
			'default'     => 'true',
			'overrides'   => array(
				'showHeading',
				'showTitle',
				'showDate',
				'showViews',
				'showOwner',
			),
		),
		'showHeading' => array(
			'description' => $gallery->i18n('Show heading'),
			'type'        => 'boolean',
			'default'     => 'true',
		),
		'showTitle' => array(
			'description' => $gallery->i18n('Show title'),
			'type'        => 'boolean',
			'default'     => 'true',
		),
		'showDate' => array(
			'description' => $gallery->i18n('Show date'),
			'type'        => 'boolean',
			'default'     => 'true',
		),
		'showViews' => array(
			'description' => $gallery->i18n('Show view count'),
			'type'        => 'boolean',
			'default'     => 'false',
		),
		'showOwner' => array(
			'description' => $gallery->i18n('Show owner'),
			'type'        => 'boolean',
			'default'     => 'false',
		),
	),
);
