/***************************************************************************
 *   Copyright (C) 2016 by Vitalii Kachemtsev <LLIAKAJI@wwizard.net>       *
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

#include <QDesktopServices>
#include <QSettings>
#include <QDir>
#include <QUrl>

#include "ui_settingsdialog.h"
#include "settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    QSettings s("winewizard", "settings");
    s.beginGroup("VideoSettings");
    int w = s.value("ScreenWidth", -1).toInt();
    int h = s.value("ScreenHeight", -1).toInt();
    int m = s.value("VideoMemorySize", -1).toInt();
    s.endGroup();
    ui->screenSizeAuto->setChecked(w >= 0 && h >= 0);
    ui->memoryAuto->setChecked(m >= 0);
    ui->width->setValue(w);
    ui->height->setValue(h);
    ui->memory->setValue(m);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::accept()
{
    QSettings s("winewizard", "settings");
    s.beginGroup("VideoSettings");
    if (ui->screenSizeAuto->isChecked())
    {
        s.setValue("ScreenWidth", ui->width->value());
        s.setValue("ScreenHeight", ui->height->value());
    }
    else
    {
        s.setValue("ScreenWidth", -1);
        s.setValue("ScreenHeight", -1);
    }
    s.setValue("VideoMemorySize", ui->memoryAuto->isChecked() ? ui->memory->value() : -1);
    s.endGroup();
    QDialog::accept();
}

void SettingsDialog::on_buttonBox_helpRequested()
{
    QDesktopServices::openUrl(QUrl("http://wwizard.net/help"));
}
