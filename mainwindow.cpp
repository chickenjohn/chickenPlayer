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

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->vol_chk->setChecked(true);
    ui->start_btn->setText(tr("Play"));
    mplayer_proc = new QProcess;
    pause_flag = false;
    load_flag = false;
    loc_flag = false;
    ter_on = false;
    ui->vol_slider->setValue(20);
    args << "none";

    fresh_time = new QTimer;
    connect(fresh_time,SIGNAL(timeout()),this,SLOT(timeup()));
    connect(mplayer_proc,SIGNAL(readyReadStandardOutput()),this,SLOT(info_getting()));
}

MainWindow::~MainWindow()
{
    mplayer_proc->close();
    delete ui;
}

void MainWindow::on_actionOpen_file_triggered()
{
    file_loc.clear();
    file_loc = QFileDialog::getOpenFileName(this,tr("Load a file"), "");

//  The modification of the path of file below is
//  because of the unique expression of directory
//  under Windows System. If you are in other OS,
//  change it.
    file_loc.replace("\\", "\\\\");
    loc_flag = true;
    play_video();
}

void MainWindow::play_video()
{
    if(load_flag)
    {
        fresh_time->stop();
        mplayer_proc->write("loadfile '");
        mplayer_proc->write(file_loc.toStdString().data());
        mplayer_proc->write("'\n");
        fresh_time->start(400);
    }
    else
    {
        args.clear();
        args << "-slave";
        args << "-quiet";
        args << "-wid" << QString::number(ui->player->winId(),10);
        args << "zoom";
        args << "-vo";
        args << "gl";
        args << file_loc.toStdString().data();
        mplayer_proc->setProcessChannelMode(QProcess::MergedChannels);
        mplayer_proc->start("mplayer",args);
        load_flag = true;
        pause_flag = false;
        fresh_time->start(400);
        ui->start_btn->setText(tr("Pause"));
    }
}



void MainWindow::on_start_btn_clicked()
{
    if(load_flag)
    {
        if(pause_flag)
        {
            fresh_time->stop();
            ui->start_btn->setText(tr("Play"));
        }
        else
        {
            fresh_time->start(400);
            ui->start_btn->setText(tr("Pause"));
        }
        pause_flag = !pause_flag;
        mplayer_proc->write("pause\n");
    }
    else if(!(file_loc.isNull()))
    {
        fresh_time->start(400);
        mplayer_proc->start("mplayer",args);
        load_flag = true;
    }
    else
    {
        ui->actionOpen_file->trigger();
    }
}

void MainWindow::on_stop_btn_clicked()
{
    mplayer_proc->write("stop\n");
    ui->start_btn->setText("Play");
    ui->horizontalSlider->setValue(0);
    load_flag = false;
    fresh_time->stop();
}

void MainWindow::info_getting()
{
    while(mplayer_proc->canReadLine())
    {
        message = mplayer_proc->readLine();
    }
}

void MainWindow::on_vol_chk_clicked()
{
    if(ui->vol_chk->isChecked())
    {
        mplayer_proc->write("mute 0\n");
    }
    else
    {
        mplayer_proc->write("mute 1\n");
    }
}

void MainWindow::on_vol_slider_valueChanged(int value)
{
    if(load_flag)
    {
        QString c_value = QString::number(value,10);
        mplayer_proc->write("volume ");
        mplayer_proc->write(c_value.toLatin1().data());
        mplayer_proc->write(" 1\n");
    }
}

void MainWindow::timeup()
{
    int cnt1;
    QString time_percent;
    QString message_cap;
    bool ok;
    mplayer_proc->write("get_percent_pos\n");
    message_cap = message;
    for(cnt1 = 0; cnt1 < message_cap.length(); cnt1++)
    {
        if(message_cap[cnt1] >= '0' && message_cap[cnt1] <= '9')
            time_percent.append(message_cap[cnt1]);
    }

    ui->horizontalSlider->setValue(time_percent.toInt(&ok,10));

    if(mplayer_proc->state() == QProcess::NotRunning)
    {
        load_flag = false;
        pause_flag = false;
        loc_flag = false;
        file_loc.clear();
        args.clear();
        ui->start_btn->setText(tr("Play"));
    }
}

void MainWindow::on_horizontalSlider_sliderPressed()
{
    if(load_flag)
    {
        fresh_time->stop();
    }
}

void MainWindow::on_horizontalSlider_sliderReleased()
{
    if(load_flag)
    {
        int position;
        position=ui->horizontalSlider->value();
        QString c_value = QString::number(position,10);
        ui->horizontalSlider->setSliderPosition(position);
        mplayer_proc->write("seek ");
        mplayer_proc->write(c_value.toLatin1().data());
        mplayer_proc->write(" 1\n");
        fresh_time->start(400);
        ui->start_btn->setText(tr("Pause"));
        pause_flag = false;
    }
}

void MainWindow::on_actionTerminal_triggered()
{
    if(load_flag)
    {
        Dialog *t_dialog = new Dialog;
        t_dialog->show();
        connect(mplayer_proc,SIGNAL(readyReadStandardOutput()),this,SLOT(send_ter()));
        connect(this,SIGNAL(send_msg(QString)),t_dialog,SLOT(receive_ter(QString)));
        ter_on = true;

    }
}

void MainWindow::send_ter()
{
    emit send_msg(message);
}

void MainWindow::on_actionAbout_triggered()
{
    aboutDialog *about_dia;
    about_dia = new aboutDialog;
    about_dia->show();
}

void MainWindow::on_actionSubtitle_triggered()
{
    if(load_flag)
    {
        sub_loc.clear();
        sub_loc = QFileDialog::getOpenFileName(this,tr("Load a subtitle"),"");
        sub_loc.replace("\\", "\\\\");

        mplayer_proc->write("sub_load '");
        mplayer_proc->write(sub_loc.toLatin1().data());
        mplayer_proc->write("'\n");
        mplayer_proc->write("sub_select 1\n");
    }
}
