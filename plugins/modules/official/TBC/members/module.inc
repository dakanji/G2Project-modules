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
 * The implementation of the members module
 * @package Members
 * @author Robert Balousek <rbalousek@hotmail.com>
 * @version $Revision: 18172 $
 */
class MembersModule extends GalleryModule {
	public function __construct() {
		global $gallery;

		$this->setId('members');
		$this->setName($gallery->i18n('Members'));
		$this->setDescription(
			$gallery->i18n(
				'Members List and Profiles'
			)
		);

		// Update upgrade() as required
		$this->setVersion('2.0.0');
		$this->setRequiredCoreApi(array(8, 0));
		$this->setRequiredModuleApi(array(4, 0));

		$this->_templateVersion = 1;

		$this->setGroup('gallery', $gallery->i18n('Gallery'));
		$this->setCallbacks('getSiteAdminViews');
	}

	/**
	 * Class Loader
	 */
	public static function getme() {
		static $instance;

		if (!isset($instance)) {
			$instance = new MembersModule();
		}

		return $instance;
	}

	/**
	 * @see GalleryModule::upgrade
	 */
	public function upgrade($currentVersion, $x1 = null) {
		if (!isset($currentVersion)) {
			list($ret, $viewSelectedGroupId) = GalleryCoreApi::getPluginParameter(
				'module',
				'core',
				'id.everybodyGroup'
			);

			if ($ret) {
				return $ret;
			}

			foreach (array(
				'canViewMembersModule' => $viewSelectedGroupId,
				'canViewEmailAddress'  => 0,
			) as $key => $value) {
				$ret = $this->setParameter($key, $value);

				if ($ret) {
					return $ret;
				}
			}
		}

		return null;
	}

	/**
	 * @see GalleryModule::getSiteAdminViews
	 */
	public function getSiteAdminViews() {
		return array(
			null,
			array(
				array(
					'name' => $this->translate('Members'),
					'view' => 'members.AdminMembers',
				),
			),
		);
	}
}
