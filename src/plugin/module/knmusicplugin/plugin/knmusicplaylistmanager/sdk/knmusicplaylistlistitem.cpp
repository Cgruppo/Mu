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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#include "knmusicplaylistmodel.h"

#include "knmusicplaylistlistitem.h"

#include <QDebug>

KNMusicPlaylistListItem::KNMusicPlaylistListItem() :
    QStandardItem()
{
    m_playlistModel=new KNMusicPlaylistModel;
}

KNMusicPlaylistListItem::~KNMusicPlaylistListItem()
{
    delete m_playlistModel;
}

KNMusicPlaylistModel *KNMusicPlaylistListItem::playlistModel()
{
    return m_playlistModel;
}

QString KNMusicPlaylistListItem::playlistFilePath() const
{
    return m_playlistFilePath;
}

void KNMusicPlaylistListItem::setPlaylistFilePath(const QString &playlistFilePath)
{
    m_playlistFilePath = playlistFilePath;
}
bool KNMusicPlaylistListItem::changed() const
{
    return m_changed;
}

void KNMusicPlaylistListItem::setChanged(bool changed)
{
    m_changed = changed;
}
QJsonArray KNMusicPlaylistListItem::playlistContent() const
{
    return m_playlistContent;
}

void KNMusicPlaylistListItem::setPlaylistContent(const QJsonArray &playlistContent)
{
    m_playlistContent = playlistContent;
}

void KNMusicPlaylistListItem::clearPlaylistContent()
{
    m_playlistContent=QJsonArray();
}
bool KNMusicPlaylistListItem::built() const
{
    return m_builded;
}

void KNMusicPlaylistListItem::setBuilt(bool builded)
{
    m_builded = builded;
}



