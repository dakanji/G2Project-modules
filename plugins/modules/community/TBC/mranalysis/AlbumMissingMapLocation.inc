<?php

/*
 * $RCSfile: AlbumMissingMapLocation.inc,v $
 * $Revision: 1848 $
 *
 * Gallery - a web based photo album viewer and editor
 * Copyright (C) 2000-2005 Bharat Mediratta
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
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

/**
 *
 * @package MRAnalysis
 * @author Mark Ridgwell <g2development@markridgwell.com>
 */

// Required Files\Classes
GalleryCoreApi::requireOnce('modules/mranalysis/classes/ItemList.class');

/**
 * @package MRAnalysis
 * @subpackage AlbumMissingMapLocationView
 */
class AlbumMissingMapLocationView extends GalleryView {
	/**
	 * @see GalleryView::loadTemplate
	 */
	public function loadTemplate(&$template, &$form) {
		global $gallery;

		$form['formName'] = 'AdminAlbumMissingMapLocation';

		$gallery->guaranteeTimeLimit(120);
		$query = '
            SELECT DISTINCT
                [GalleryAlbumItem::id]
            FROM
                [GalleryAlbumItem]
            LEFT JOIN
				[GalleryMapMap]
			ON
				[GalleryAlbumItem::id] = [GalleryMapMap::itemid]
            WHERE
                [GalleryMapMap::itemid] is NULL
            ORDER BY
				[GalleryAlbumItem::id]
        ';

		$items = ItemList::readItemsFromQuery($query);

		$template->setVariable('controller', 'mranalysis.AlbumMissingMapLocation');
		$template->setVariable('baditems', $items);

		return array(
			null,
			array(
				'body' => 'modules/mranalysis/templates/AlbumMissingMapLocation.tpl',
			),
		);
	}
}