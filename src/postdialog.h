/***************************************************************************
 *   Copyright (C) 2016 by Vitalii Kachemtsev <LLIAKAJL@yandex.ru>         *
 *                                                                         *
 *   This file is part of Wine Wizard.                                     *
 *                                                                         *
 *   Wine Wizard is free software: you can redistribute it and/or modify   *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation, either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   Wine Wizard is distributed in the hope that it will be useful,        *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with Wine Wizard.  If not, see <http://www.gnu.org/licenses/>.  *
 *                                                                         *
 ***************************************************************************/

#ifndef POSTDIALOG_H
#define POSTDIALOG_H

#include "netdialog.h"

namespace Ui {
class PostDialog;
}

class PostDialog : public NetDialog
{
    Q_OBJECT

public:
    explicit PostDialog(const QString &url, const QUrlQuery &data, QWidget *parent = nullptr);
    ~PostDialog() override;

public slots:
    void reject() override;

private slots:
    void postFinished();

private:
    Ui::PostDialog *ui;
    QString mUrl;
    QUrlQuery mData;

    void post();
};

#endif // POSTDIALOG_H