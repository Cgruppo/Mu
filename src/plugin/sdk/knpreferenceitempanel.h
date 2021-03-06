/*
 * Copyright (C) Kreogist Dev Team <kreogistdevteam@126.com>
 * This work is free. You can redistribute it and/or modify it under the
 * terms of the Do What The Fuck You Want To Public License, Version 2,
 * as published by Sam Hocevar. See the COPYING file for more details.
 */
#ifndef KNPREFERENCEITEMPANEL_H
#define KNPREFERENCEITEMPANEL_H

#include <QHash>
#include <QLinkedList>

#include <QScrollArea>

class QBoxLayout;
class QLabel;
class KNConfigure;
class KNPreferenceItem;
class KNPreferenceItemPanel : public QScrollArea
{
    Q_OBJECT
public:
    explicit KNPreferenceItemPanel(QWidget *parent = 0);
    bool advancedMode() const;
    void addTitle(QLabel *title, bool advanced=false);
    void addItem(KNPreferenceItem *item, bool advanced=false);
    void addWidget(QWidget *widget, bool advanced=false);

signals:
    void requireSetAdvancedVisible(const bool &ok);

public slots:
    void loadConfigure();
    void saveConfigure();
    void setAdvancedMode(bool advancedMode);
    void setNormalMode(bool normalMode)
    {
        setAdvancedMode(!normalMode);
    }

private:
    void setAdvancedWidget(QWidget *item);
    QBoxLayout *m_mainLayout;
    bool m_advancedMode=false;
    QLinkedList<KNPreferenceItem *> m_itemList;
};

#endif // KNPREFERENCEITEMPANEL_H
