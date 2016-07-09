/***************************************************************************
 *   Copyright (C) 2016 by Vitalii Kachemtsev <LLIAKAJI@wwizard.net>         *
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

#include "categorysortmodel.h"

CategorySortModel::CategorySortModel(QObject *parent) :
    QSortFilterProxyModel(parent)
{
}

bool CategorySortModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    if (left.row() == 0 && right.row() > 0)
        return true;
    else if (left.row() > 0 && right.row() == 0)
        return false;
    return left.data().toString() < right.data().toString();
}
