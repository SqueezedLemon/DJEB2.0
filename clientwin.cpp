#include "clientwin.h"
#include "ui_clientwin.h"
#include "mainwindow.h"
ClientWin::ClientWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWin)
{
    ui->setupUi(this);
}

ClientWin::~ClientWin()
{
    delete ui;
}

void ClientWin::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void ClientWin::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void ClientWin::on_pushButton_ChangePassword_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void ClientWin::on_pushButton_Logout_clicked()
{
    this->close();
    MainWindow *mainwindow;
    mainwindow= new MainWindow(this);
    mainwindow->show();
}

