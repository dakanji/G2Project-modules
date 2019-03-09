<?php

/*
 * Gallery - a web based photo album viewer and editor
 * Copyright (C) 2000-2008 Bharat Mediratta
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA  02110-1301, USA.
 */

/**
 * Photo printing at photoworks.com
 *
 * @package PhotoAccess
 * @author Bharat Mediratta <bharat@menalto.com>
 * @version $Revision: 18172 $
 */
class PhotoAccessModule extends GalleryModule {
	public function __construct() {
		global $gallery;

		$this->setId('photoaccess');
		$this->setName($gallery->i18n('PhotoWorks'));
		$this->setDescription(
			$gallery->i18n(
				'PhotoWorks Photo Printing Module'
			)
		);
		$this->setVersion('2.0.0'); // Update upgrade() as required
		$this->setRequiredCoreApi(array(8, 0));
		$this->setRequiredModuleApi(array(4, 0));
		$this->_templateVersion = 1;
		$this->setGroup('commerce', $gallery->i18n('Commerce'));
		$this->setCallbacks('getItemLinks');
	}

	/**
	 * @see GalleryModule::upgrade
	 */
	public function upgrade($currentVersion) {
		global $gallery;

		if (!isset($currentVersion)) {
			$currentVersion = '0';
		} elseif (version_compare($currentVersion, '1.0.0', '<')) {
			// Instead of enumerating all previous versions...
			$currentVersion = '1.0.0';
		}

		list($ret, $coreParams) = GalleryCoreApi::fetchAllPluginParameters('module', 'core');

		if ($ret) {
			return $ret;
		}

		switch ($currentVersion) {
			case '0':
				// Register our permission
				$ret = GalleryCoreApi::registerPermission(
					$this->getId(),
					'photoaccess.print',
					$gallery->i18n('[photoworks] Print')
				);

				if ($ret) {
					return $ret;
				}

				// Give everybody print permission by default
				$gallery->guaranteeTimeLimit(300);
				$ret = GalleryCoreApi::addGroupPermission(
					$coreParams['id.rootAlbum'],
					$coreParams['id.everybodyGroup'],
					'photoaccess.print',
					true
				);

				if ($ret) {
					return $ret;
				}

				break;

			case '1.0.0':
				$ret = GalleryCoreApi::registerPermission(
					$this->getId(),
					'photoaccess.print',
					$gallery->i18n('[photoworks] Print')
				);

				if ($ret) {
					return $ret;
				}

				$gallery->guaranteeTimeLimit(300);
				$ret = GalleryCoreApi::addGroupPermission(
					$coreParams['id.rootAlbum'],
					$coreParams['id.everybodyGroup'],
					'photoaccess.print',
					true
				);

				if ($ret) {
					return $ret;
				}

				// Fall Through
			case '1.0.1':
			case '1.0.2':
			case '1.0.3':
			case '1.0.4':
			case '1.0.5':
			case '1.0.6':
			case '1.0.7':
			case '1.0.7.1':
				// .mo file migration
			case '1.0.8':
			case '1.0.9':
				// Implementing new version of the cart plugin interface
			case '1.0.10':
			case '1.0.11':
			case '1.0.12':
			case '1.0.13':
			case '2.0.0':
				// Updated GalleryCoreApi requirement to 8.0
				// Upgraded GalleryModule requirement to 4.0
			case 'end of upgrade path':
				/*
				 * Leave this bogus case at the end of the legitimate case statements
				 * so that we always properly terminate our upgrade path with a break.
				 */
				break;

			default:
				return GalleryCoreApi::error(
					ERROR_BAD_PLUGIN,
					__FILE__,
					__LINE__,
					sprintf('Unknown module version %s', $currentVersion)
				);
		}

		return null;
	}

	/**
	 * @see GalleryModule::performFactoryRegistrations
	 */
	public function performFactoryRegistrations() {
		foreach (array('1_0', '1_1') as $version) {
			$ret = GalleryCoreApi::registerFactoryImplementation(
				'CartPluginInterface_' . $version,
				'PhotoAccessCartPlugin',
				'photoaccess',
				'modules/photoaccess/classes/PhotoAccessCartPlugin.class',
				'photoaccess',
				null
			);

			if ($ret) {
				return $ret;
			}
		}

		return null;
	}

	/**
	 * @see GalleryModule::getItemLinks
	 */
	public function getItemLinks($items, $wantsDetailedLinks, $permissions) {
		$links = array();

		foreach ($items as $item) {
			$itemId = $item->getId();

			if (isset($wantsDetailedLinks[$itemId], $permissions[$itemId]['photoaccess.print'])
				&& GalleryUtilities::isA($item, 'GalleryPhotoItem')
			) {
				$links[$itemId][] = array(
					'text'   => $this->translate('Print on PhotoWorks.com'),
					'params' => array(
						'controller' => 'photoaccess.PrintPhoto',
						'itemId'     => $itemId,
						'returnUrl'  => '%CURRENT_URL%',
					),
				);
			}
		}

		return array(null, $links);
	}
}