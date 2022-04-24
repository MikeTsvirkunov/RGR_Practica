#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "teacher.h"
#include "graphic.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_InfoButton_clicked()
{
    QMessageBox::about(this, "О программе", "Выполнил: Цвиркунов Михаил\nФакультет: ФИТиКС\nГруппа: ФИТ-211\nПреподаватель: Федотова И.В.");
}


void MainWindow::on_StartButton_clicked()
{
    hide();
    Teacher *info_w = new Teacher(this);
    info_w->show();
}


void MainWindow::on_pushButton_clicked()
{
    hide();
    Graphic *graph_win = new Graphic(this);
    graph_win->show();
}

