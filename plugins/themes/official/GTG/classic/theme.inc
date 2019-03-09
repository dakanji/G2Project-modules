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
 * Theme with columns for thumbnails, item info and subalbum links
 * @package Themes
 * @subpackage Classic
 * @author Bharat Mediratta <bharat@menalto.com>
 * @author Alan Harder <alan.harder@sun.com>
 * @version $Revision: 18172 $
 */
class ClassicTheme extends GalleryTheme {
	public function __construct() {
		global $gallery;

		$this->setId('classic');
		$this->setName($gallery->i18n('Classic'));
		$this->setDescription(
			$gallery->i18n(
				'Classic Gallery2 root album look and feel'
			)
		);
		$this->setVersion('2.0.0');
		$this->setRequiredCoreApi(array(8, 0));
		$this->setRequiredThemeApi(array(3, 0));
		$this->setStandardSettings(
			array(
				'rows'            => 10,
				'columns'         => 1,
				'showImageOwner'  => 0,
				'showAlbumOwner'  => 1,
				'albumFrame'      => '',
				'itemFrame'       => '',
				'photoFrame'      => '',
				'showMicroThumbs' => 0,
				'colorpack'       => '',
				'sidebarBlocks'   => serialize(
					array(
						array(
							'search.SearchBlock',
							array(
								'showAdvancedLink' => true,
							),
						),
						array(
							'core.ItemLinks',
							array(
								'useDropdown' => false,
							),
						),
						array('core.PeerList', array()),
						array('imageblock.ImageBlock', array()),
					)
				),
				'albumBlocks'     => serialize(
					array(array('comment.ViewComments', array()))
				),
				'photoBlocks'     => serialize(
					array(
						array('exif.ExifInfo', array()),
						array('comment.ViewComments', array()),
					)
				),
				'showSubalbums'   => 1,
				'subalbumDepth'   => 0,
				'subalbumSort'    => 0,
			)
		);
	}

	/**
	 * @see GalleryTheme::getSettings
	 */
	public function getSettings($itemId = null) {
		list($ret, $settings, $params) = parent::getSettings($itemId);

		if ($ret) {
			return array($ret, null, null);
		}

		// Add in our custom settings
		$settings[] = array(
			'key'   => 'showSubalbums',
			'name'  => $this->translate('Show subalbum links'),
			'type'  => 'checkbox',
			'value' => $params['showSubalbums'],
		);
		$settings[] = array(
			'key'        => 'subalbumDepth',
			'name'       => $this->translate('Depth of subalbums links (0=no limit)'),
			'type'       => 'text-field',
			'typeParams' => array(
				'size' => 2,
			),
			'value'      => $params['subalbumDepth'],
		);
		$settings[] = array(
			'key'   => 'subalbumSort',
			'name'  => $this->translate(
				'Show subalbums by sort order of each album (affects performance)'
			),
			'type'  => 'checkbox',
			'value' => $params['subalbumSort'],
		);

		return array(null, $settings, $params);
	}

	/**
	 * @see GalleryTheme::validateSettings
	 */
	public function validateSettings($settings) {
		$error = parent::validateSettings($settings);

		if (!is_numeric($settings['subalbumDepth'])) {
			$error['subalbumDepth'] = $this->translate('You must enter a number');
		}

		return $error;
	}

	/**
	 * @see GalleryTheme::showAlbumPage
	 */
	public function showAlbumPage(&$template, $item, $params, $childIds) {
		$ret = $this->loadCommonTemplateData(
			$template,
			$item,
			$params,
			array(
				'owner',
				'viewCount',
				'childCount',
				'descendentCount',
				'parents',
				'systemLinks',
				'itemLinks',
				'itemSummaries',
				'permissions',
				'thumbnails',
				'pageNavigator',
				'jumpRange',
			),
			$childIds
		);

		if ($ret) {
			return array($ret, null);
		}

		// Add in our extra stuff
		$theme =& $template->getVariableByReference('theme');

		if ($params['showSubalbums']) {
			$theme['tree'] = $theme['treeItems'] = array();

			if ($params['subalbumDepth'] > 0) {
				$subalbumDepth = $params['subalbumDepth'];
			} else {
				$subalbumDepth = null;
			}

			if (!empty($childIds)) {
				$ret = $this->_buildTree(
					$childIds,
					$theme['tree'],
					$theme['treeItems'],
					$subalbumDepth,
					$params['subalbumSort'],
					$theme['actingUserId']
				);

				if ($ret) {
					return array($ret, null);
				}
			}
		}

		// Add our header and styles
		return array(null, 'theme.tpl');
	}

	/**
	 * @see GalleryTheme::showPhotoPage
	 */
	public function showPhotoPage(&$template, $item, $params) {
		$dataTypes = array(
			'owner',
			'parents',
			'systemLinks',
			'permissions',
			'itemLinks',
			'itemLinksDetailed',
			'itemNavigator',
			'imageViews',
		);

		if (!empty($params['showMicroThumbs'])) {
			$dataTypes[] = 'navThumbnails';
		}

		$ret = $this->loadCommonTemplateData($template, $item, $params, $dataTypes);

		if ($ret) {
			return array($ret, null);
		}

		return array(null, 'theme.tpl');
	}

	/**
	 * @see GalleryTheme::showModulePage
	 */
	public function showModulePage(&$template, $item, $params, $templateFile) {
		$ret = $this->loadCommonTemplateData(
			$template,
			$item,
			$params,
			array('parents', 'systemLinks')
		);

		if ($ret) {
			return array($ret, null);
		}

		return array(null, 'theme.tpl');
	}

	/**
	 * @see GalleryTheme::showAdminPage
	 */
	public function showAdminPage(&$template, $item, $params, $templateFile) {
		$ret = $this->loadCommonTemplateData(
			$template,
			$item,
			$params,
			array('parents', 'systemLinks')
		);

		if ($ret) {
			return array($ret, null);
		}

		return array(null, 'theme.tpl');
	}

	/**
	 * @see GalleryTheme::showErrorPage
	 */
	public function showErrorPage(&$template) {
		return array(null, 'error.tpl');
	}

	/**
	 * @see GalleryTheme::showProgressBarPage
	 */
	public function showProgressBarPage(&$template, $item, $params) {
		$ret = $this->loadCommonTemplateData(
			$template,
			$item,
			$params,
			array('parents', 'systemLinks')
		);

		if ($ret) {
			return array($ret, null);
		}

		return array(null, 'theme.tpl');
	}

	/**
	 * Build template data for subalbum tree
	 * @return GalleryStatus a status code
	 * @access private
	 */
	public function _buildTree(
		$childIds,
		&$treeList,
		&$treeItems,
		$maxDepth,
		$subalbumSort,
		$userId
	) {
		list($ret, $items) = GalleryCoreApi::loadEntitiesById($childIds, 'GalleryItem');

		if ($ret) {
			return $ret;
		}

		$treeIds = array();

		foreach ($items as $item) {
			if (!GalleryUtilities::isA($item, 'GalleryAlbumItem')) {
				continue;
			}

			if ($subalbumSort) {
				// Apply sort preference of each album
				$ret = $this->_doBuildTree(
					$item,
					$item->getId(),
					$treeList,
					$treeItems,
					$maxDepth,
					$userId,
					1
				);

				if ($ret) {
					return $ret;
				}
			} else {
				$id = $item->getId();

				list($ret, $tree) = GalleryCoreApi::fetchAlbumTree($id, $maxDepth, $userId);

				if ($ret) {
					return $ret;
				}

				$treeList[$id] = array();

				$this->_parseTree($tree, $treeList[$id], $treeIds);
			}
		}

		if (!empty($treeIds)) {
			list($ret, $items) = GalleryCoreApi::loadEntitiesById($treeIds, 'GalleryAlbumItem');

			if ($ret) {
				return $ret;
			}

			foreach ($items as $item) {
				$treeItems[$item->getId()] = (array)$item;
			}
		}

		return null;
	}

	/**
	 * Helper function for _buildTree
	 * @return GalleryStatus a status code
	 * @access private
	 */
	public function _doBuildTree(
		$album,
		$branchId,
		&$treeList,
		&$treeItems,
		$maxDepth,
		$userId,
		$depth
	) {
		list($ret, $subAlbumIds) = GalleryCoreApi::fetchChildAlbumItemIds(
			$album,
			null,
			null,
			$userId
		);

		if ($ret) {
			return $ret;
		}

		if (!empty($subAlbumIds)) {
			list($ret, $subAlbums) = GalleryCoreApi::loadEntitiesById(
				$subAlbumIds,
				'GalleryAlbumItem'
			);

			if ($ret) {
				return $ret;
			}

			foreach ($subAlbums as $subAlbum) {
				$id                    = $subAlbum->getId();
				$treeList[$branchId][] = array(
					'id'    => $id,
					'depth' => $depth - 1,
				);

				$treeItems[$id] = (array)$subAlbum;

				if (!isset($maxDepth) || $depth < $maxDepth) {
					$ret = $this->_doBuildTree(
						$subAlbum,
						$branchId,
						$treeList,
						$treeItems,
						$maxDepth,
						$userId,
						$depth + 1
					);

					if ($ret) {
						return $ret;
					}
				}
			}
		}

		return null;
	}

	/**
	 * Helper function for _buildTree
	 * @access private
	 */
	public function _parseTree($tree, &$treeList, &$treeIds, $depth = 1) {
		foreach ($tree as $id => $list) {
			$treeIds[]  = $id;
			$treeList[] = array(
				'id'    => $id,
				'depth' => $depth,
			);

			if (!empty($list)) {
				$this->_parseTree($list, $treeList, $treeIds, $depth + 1);
			}
		}
	}
}