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
#include <QAction>
#include <QBoxLayout>

#include "kndropproxycontainer.h"
#include "knmusicalbumview.h"
#include "knmusiclibrarymodel.h"
#include "knmusiccategorymodel.h"
#include "knmusiccategoryproxymodel.h"

#include "knlocalemanager.h"

#include "knmusiclibraryalbumtab.h"

KNMusicLibraryAlbumTab::KNMusicLibraryAlbumTab(QObject *parent) :
    KNMusicLibraryCategoryTab(parent)
{
    //Initial the drop proxy container.
    m_container=new KNDropProxyContainer;
    connect(m_container, &KNDropProxyContainer::dropProxyShow,
            this, &KNMusicLibraryAlbumTab::onActionTabShow);
    connect(m_container, &KNDropProxyContainer::dropProxyHide,
            this, &KNMusicLibraryAlbumTab::onActionTabHide);

    //Initial the layout for the container, only for auto resize splitter.
    QBoxLayout *mainLayout=new QBoxLayout(QBoxLayout::LeftToRight, m_container);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);
    m_container->setLayout(mainLayout);

    //Initial the album view.
    m_albumView=new KNMusicAlbumView(m_container);
    mainLayout->addWidget(m_albumView);

    //Initial the show in action.
    initialShowInAction();
    //Connect retranslate request.
    connect(KNLocaleManager::instance(), &KNLocaleManager::requireRetranslate,
            this, &KNMusicLibraryAlbumTab::retranslate);
    //Retranslate.
    retranslate();
}

QAction *KNMusicLibraryAlbumTab::showInAction()
{
    return m_showInAlbumTab;
}

QString KNMusicLibraryAlbumTab::caption()
{
    return tr("Albums");
}

QPixmap KNMusicLibraryAlbumTab::icon()
{
    return QPixmap(":/plugin/music/category/03_ablums.png");
}

QWidget *KNMusicLibraryAlbumTab::widget()
{
    return m_container;
}

void KNMusicLibraryAlbumTab::retranslate()
{
    m_showInAlbumTab->setText(tr("Go to Album"));
}

void KNMusicLibraryAlbumTab::setLibraryModel(KNMusicLibraryModel *model)
{
    //Save the library.
    m_musicLibrary=model;
    //Do connections.
    connect(m_container, &KNDropProxyContainer::requireAnalysisFiles,
            m_musicLibrary, &KNMusicLibraryModel::addFiles);
}

void KNMusicLibraryAlbumTab::setCategoryModel(KNMusicCategoryModel *model)
{
    //Save the model pointer.
    m_categoryModel=model;
    //Set the no category text.
    m_categoryModel->setNoCategoryText(tr("No Album"));
    //Apply category model.
    KNMusicLibraryCategoryTab::setCategoryModel(m_categoryModel);

    //! This should be done in constructor, but setModel() is a virtual
    //! function, so we moved here.
    //Set the proxy model to tree view.
    m_albumView->setModel(proxyCategoryModel());
    proxyCategoryModel()->sort(0, Qt::AscendingOrder);
}

void KNMusicLibraryAlbumTab::onActionSearch(const QString &text)
{
    ;
}

void KNMusicLibraryAlbumTab::initialShowInAction()
{
    //Initial the action.
    m_showInAlbumTab=new QAction(this);
}
