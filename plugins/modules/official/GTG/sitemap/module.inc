<?php

/*
 * Gallery - a web based photo album viewer and editor
 * Copyright (C) 2000-2008 Bharat Mediratta
 *
 * This program is free software; you can redistribute it and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software Foundation;
 * either version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this program;
 * if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor,
 * Boston, MA  02110-1301, USA.
 */

/**
 * Module that creates a Google Sitemap for your Gallery2 install.
 * @package Sitemap
 * @author Bharat Mediratta <bharat@menalto.com>
 * @version $Revision: 20951 $
 */
class SitemapModule extends GalleryModule {
	public function __construct() {
		global $gallery;

		$this->setId('sitemap');
		$this->setName($gallery->i18n('Sitemap'));
		$this->setDescription(
			$gallery->i18n(
				'Generate a  Sitemap for Search Engines'
			)
		);

		// Update upgrade() as required
		$this->setVersion('2.0.0');
		$this->setRequiredCoreApi(array(8, 0));
		$this->setRequiredModuleApi(array(4, 0));

		$this->_templateVersion = 1;

		$this->setGroup('export', $gallery->i18n('Export'));
		$this->setCallbacks('getSiteAdminViews');
	}

	/**
	 * Class Loader
	 */
	public static function getMe() {
		static $instance;

		if (!isset($instance)) {
			$instance = new SitemapModule();
		}

		return $instance;
	}

	/**
	 * @see GalleryModule::getSiteAdminViews
	 */
	public function getSiteAdminViews() {
		$data = array(
			array(
				'name' => $this->translate('Google Sitemap'),
				'view' => 'sitemap.AdminSitemap',
			),
		);

		return array(null, $data);
	}

	/**
	 * @see GalleryModule::getRewriteRules
	 */
	public function getRewriteRules() {
		$rules         = array();
		$rule          = array();
		$rule['match'] = array(
			'view' => 'sitemap.Sitemap',
		);

		$rule['pattern'] = 'sitemap';
		$rule['comment'] = $this->translate('Download Sitemap');
		$rules[]         = $rule;

		return $rules;
	}
}