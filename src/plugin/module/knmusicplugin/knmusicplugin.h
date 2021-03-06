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
#ifndef KNMUSICPLUGIN_H
#define KNMUSICPLUGIN_H

#include "knabstractmusicplugin.h"

class QBoxLayout;
class QSignalMapper;
class KNConnectionHandler;
class KNMouseDetectHeader;
class KNMusicTab;
class KNMusicPluginPreference;
class KNMusicCategoryTabWidget;
class KNMusicBackend;
class KNMusicGlobal;
class KNMusicParser;
class KNMusicLyricsManager;
class KNMusicSearchBase;
class KNMusicMainPlayerBase;
class KNMusicDetailDialogBase;
class KNMusicDetailTooltipBase;
class KNMusicHeaderPlayerBase;
class KNMusicHeaderLyricsBase;
class KNMusicNowPlayingBase;
class KNMusicLibraryBase;
class KNMusicPlaylistManagerBase;
class KNMusicSoloMenuBase;
class KNMusicMultiMenuBase;
class KNMusicLyricsDownloadDialogBase;
class KNMusicPlugin : public KNAbstractMusicPlugin
{
    Q_OBJECT
public:
    explicit KNMusicPlugin(QObject *parent = 0);
    ~KNMusicPlugin();
    QString caption();
    QPixmap icon();
    QPixmap headerIcon();
    QPixmap preferenceIcon();
    QWidget *centralWidget();
    QWidget *headerWidget();
    KNCategoryPreference *preference();

    void setPlatformExtras(KNPlatformExtras *plugin);
    inline void loadSearch(KNMusicSearchBase *plugin);
    inline void loadDetailTooptip(KNMusicDetailTooltipBase *plugin);
    inline void loadBackend(KNMusicBackend *plugin);
    inline void loadLyricsDownloadDialog(KNMusicLyricsDownloadDialogBase *plugin);
    inline void loadDetailDialog(KNMusicDetailDialogBase *plugin);
    inline void loadHeaderPlayer(KNMusicHeaderPlayerBase *plugin);
    inline void loadHeaderLyrics(KNMusicHeaderLyricsBase *plugin);
    inline void loadMainPlayer(KNMusicMainPlayerBase *plugin);
    inline void loadNowPlaying(KNMusicNowPlayingBase *plugin);
    inline void loadLibrary(KNMusicLibraryBase *plugin);
    inline void loadPlaylistManager(KNMusicPlaylistManagerBase *plugin);

signals:

public slots:
    void onArgumentsAvailable(const QStringList &data);
    void retranslate();
    void enablePlatformExtras();
    void disablePlatformExtras();
    void saveConfigure();

protected slots:
    int addMusicCategory(const QPixmap &icon,
                         const QString &caption,
                         QWidget *widget);
    virtual void addLeftHeaderWidget(QWidget *widget,
                                     int stretch=0,
                                     Qt::Alignment alignment=0);
    virtual void addRightHeaderWidget(QWidget *widget,
                                      int stretch=0,
                                      Qt::Alignment alignment=0);

private slots:
    void onActionShowTab(const int &tabIndex);

private:
    inline void initialInfrastructure();
    inline void initialParser();
    inline void initialLyricsManager();
    inline void initialSoloMenu(KNMusicSoloMenuBase *soloMenu);
    inline void initialMultiMenu(KNMusicMultiMenuBase *multiMenu);
    inline void addMusicTab(KNMusicTab *musicTab);
    inline void startThreads();
    QLinkedList<QObject *> m_pluginList;
    struct MusicTabItem
    {
        int index;
        KNMusicTab *tab;
    };
    QLinkedList<MusicTabItem> m_tabList;
    QString m_caption;
    KNMusicCategoryTabWidget *m_centralWidget=nullptr;
    KNMouseDetectHeader *m_headerWidget=nullptr;
    QBoxLayout *m_headerLeftLayout, *m_headerRightLayout;
    QThread m_parserThread;
    QSignalMapper *m_tabSwitchMapper;
    KNMusicGlobal *m_musicGlobal;
    KNMusicPluginPreference *m_musicPreference;

    KNMusicBackend *m_backend=nullptr;
    KNMusicNowPlayingBase *m_nowPlaying=nullptr;
    KNMusicLyricsManager *m_lyricsManager=nullptr;
    KNMusicHeaderPlayerBase *m_headerPlayer=nullptr;
    KNMusicMainPlayerBase *m_mainPlayer=nullptr;
    KNPlatformExtras *m_platformExtras=nullptr;
    KNConnectionHandler *m_extraHandler=nullptr;
};

#endif // KNMUSICPLUGIN_H
