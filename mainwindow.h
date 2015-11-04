//----------------------------------------------------------------------------
//Copyright (C) 2015 chickenjohn

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

// Attached below is the contact of chickenjohn:
// Email: chickenjohn93@hust.edu.cn
//------------------------------------------------------------------------------

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <QProcess>
#include <QTimer>
#include <QThread>
#include <dialog.h>
#include <aboutdialog.h>

namespace Ui {
class MainWindow;
}



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QString file_loc;
    QString sub_loc;
    QString message;
    QStringList args;
    QProcess *mplayer_proc;
    bool pause_flag;
    bool load_flag;
    bool loc_flag;
    bool ter_on;
    void play_video(void);
    void close_video(void);
    QTimer *fresh_time;
    ~MainWindow();

signals:
    void send_msg(QString ter_message);

private slots:
    void on_actionOpen_file_triggered();
    void on_start_btn_clicked();
    void on_stop_btn_clicked();
    void info_getting();
    void on_vol_chk_clicked();
    void on_vol_slider_valueChanged(int value);
    void timeup();
    void on_horizontalSlider_sliderPressed();
    void on_horizontalSlider_sliderReleased();
    void on_actionTerminal_triggered();
    void send_ter();


    void on_actionAbout_triggered();

    void on_actionSubtitle_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
