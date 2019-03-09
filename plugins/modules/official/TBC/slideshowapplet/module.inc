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
 * @package SlideshowApplet
 * @author Pierre-Luc Paour <paour@users.sourceforge.net>
 * @version $Revision: 20951 $
 */
class SlideshowAppletModule extends GalleryModule {
	public function __construct() {
		global $gallery;

		$this->setId('slideshowapplet');
		$this->setName($gallery->i18n('Slideshow Applet'));
		$this->setDescription(
			$gallery->i18n(
				'Fullscreen slideshow using a Java applet'
			)
		);
		$this->setVersion('2.0.0'); // Update upgrade() as required
		$this->setRequiredCoreApi(array(8, 0));
		$this->setRequiredModuleApi(array(4, 0));

		$this->_templateVersion = 1;

		$this->setGroup('display', $gallery->i18n('Display'));
		$this->setCallbacks('getItemLinks|getSiteAdminViews');
	}

	/**
	 * Class Loader
	 */
	public static function getme() {
		static $instance;

		if (!isset($instance)) {
			$instance = new SlideshowAppletModule();
		}

		return $instance;
	}

	/**
	 * @see GalleryPlugin::upgrade
	 */
	public function upgrade($currentVersion, $x1 = null) {
		global $gallery;

		list($ret, $params) = GalleryCoreApi::fetchAllPluginParameters(
			'module',
			'slideshowapplet'
		);

		if ($ret) {
			return $ret;
		}

		if (!isset($params['slideshowdefaultVariables'])) {
			// upgrade or install
			if (isset($params['slideshowRecursive'], $params['slideshowMaxPictures'])) {
				// definitely upgrade
				$newDefault = 'slideshowRecursive='
					. $params['slideshowRecursive']
					. '|slideshowMaxPictures='
					. $params['slideshowMaxPictures'];

				// remove the old parameters
				$ret = $this->removeParameter('slideshowRecursive');

				if ($ret) {
					return $ret;
				}

				$ret = $this->removeParameter('slideshowMaxPictures');

				if ($ret) {
					return $ret;
				}
			} else {
				// install
				$newDefault = 'slideshowRecursive=false|slideshowMaxPictures=0';
			}

			$ret = $this->setParameter('slideshowdefaultVariables', $newDefault);

			if ($ret) {
				return $ret;
			}
		}

		if (!isset($params['slideshowoverrideVariables'])) {
			$ret = $this->setParameter('slideshowoverrideVariables', 'toSysOut=true');

			if ($ret) {
				return $ret;
			}
		}

		return null;
	}

	/**
	 * @see GalleryModule::getItemLinks
	 */
	public function getItemLinks(
		$items,
		$wantsDetailedLinks,
		$permissions,
		$userId = null
	) {
		global $gallery;

		$links = array();
		foreach ($items as $item) {
			$itemId = $item->getId();
			if (isset($wantsDetailedLinks[$itemId])) {
				$showSlideshowLink = false;
				if ($item->getCanContainChildren()) {
					if (!isset($userId)) {
						$userId = $gallery->getActiveUserId();
					}

					list($ret, $query, $data) = GalleryCoreApi::buildItemQuery(
						'GalleryChildEntity',
						'id',
						'[GalleryChildEntity::parentId] = ?',
						null,
						null,
						'GalleryPhotoItem',
						'core.view',
						null,
						$userId
					);

					if (!$ret || !empty($query)) {
						array_unshift($data, $item->getId());

						list($ret, $searchResults) = $gallery->search($query, $data, null);

						if (!$ret) {
							$showSlideshowLink = $searchResults->resultCount() > 0;
						}
					}
				} else {
					/** @todo Check with isA instead of entityType (thus matching subclasses). */
					$showSlideshowLink = $item->getEntityType() === 'GalleryPhotoItem';
				}

				if ($showSlideshowLink) {
					$links[$itemId][] = array(
						'text'   => $this->translate('View Slideshow (Fullscreen)'),
						'params' => array(
							'view'   => 'slideshowapplet.SlideshowApplet',
							'itemId' => $itemId,
						),
					);
				}
			}
		}

		return array(null, $links);
	}

	/**
	 * @see GalleryModule::getRewriteRules
	 */
	public function getRewriteRules() {
		$rules           = array();
		$rule            = array();
		$rule['comment'] = $this->translate('View Slideshow (Fullscreen)');
		$rule['match']   = array(
			'view' => 'slideshowapplet.SlideshowApplet',
		);

		$rule['onLoad']   = array('rewrite', 'RewriteSimpleHelper', 'loadItemIdFromPath');
		$rule['pattern']  = 'v/%path%/slideshowapplet.html';
		$rule['keywords'] = array(
			'path' => array(
				'pattern'  => '([^?]+)',
				'function' => array('rewrite', 'RewriteSimpleHelper', 'parsePath'),
				'help'     => $this->translate('Path to an item (eg, /album/image.jpg.html)'),
			),
		);

		$rules[] = $rule;
		return $rules;
	}

	/**
	 * @see GalleryModule::getSiteAdminViews
	 */
	public function getSiteAdminViews() {
		return array(
			null,
			array(
				array(
					'name' => $this->translate('Slideshow Applet'),
					'view' => 'slideshowapplet.SlideshowAppletSiteAdmin',
				),
			),
		);
	}
}