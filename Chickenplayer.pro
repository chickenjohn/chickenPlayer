#---------------------------------------------------------------------------
#
# Project created by QtCreator 2015-11-02T12:29:25
#
# Copyright (C) 2015 chickenjohn
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
#
# Attached below is the contact of chickenjohn:
# Email: chickenjohn93@hust.edu.cn
#----------------------------------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chickenplayer
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    aboutdialog.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    aboutdialog.h

FORMS    += mainwindow.ui \
    dialog.ui \
    aboutdialog.ui
