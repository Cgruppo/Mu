/*
 * Copyright (C) Kreogist Dev Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#ifndef KNMUSICALBUMMODEL_H
#define KNMUSICALBUMMODEL_H

#include "knmusiccategorymodel.h"

namespace KNMusicLibraryAlbumCategory
{
enum KNMusicAlbumRole
{
    CategoryArtistList=CategoryArtworkKeyRole+1,
    CategoryAlbumArtist
};
}

using namespace KNMusicLibraryAlbumCategory;

class KNMusicAlbumModel : public KNMusicCategoryModel
{
    Q_OBJECT
public:
    explicit KNMusicAlbumModel(QObject *parent = 0);

signals:
    void albumRemoved(QModelIndex removedIndex);

public slots:
    void onCategoryAdded(const QList<QStandardItem *> &musicRow);
    void onCategoryRemoved(const QList<QStandardItem *> &musicRow);
    void onCategoryRecover(const QList<QStandardItem *> &musicRow);
};

#endif // KNMUSICALBUMMODEL_H
