#include "clientwin.h"
#include "ui_clientwin.h"
#include "mainwindow.h"
#include<QTextStream>
QString GDate;
QDate Gdate;

ClientWin::ClientWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWin)
{
    ui->setupUi(this);
    ui->dateEdit_DJView->setDate(QDate::currentDate());
    ui->dateEdit_DJEdit->setDate(QDate::currentDate());
    ui->dateEdit_EBView->setDate(QDate::currentDate());
    ui->dateEdit_EBEdit->setDate(QDate::currentDate());

//    QSignalMapper *signal = new QSignalMapper(this);
//    connect(ui->tab_DJView, SIGNAL(clicked()),signal,);
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


void ClientWin::on_dateEdit_DJView_userDateChanged(const QDate &date)
{
   QString Date=date.toString("dd-MM-yyyy");
   qDebug()<<Date;
   GDate=Date;
   Gdate=date;
   Dbase mydb("DJEB1.db");

   if (!mydb.dateExists(Date))
   {
       mydb.addDate(Date);
   }

   QString DJ=mydb.viewDJ(Date);
   qDebug()<<DJ;
   ui->textBrowser_DJView->setPlainText(DJ);


}



void ClientWin::on_dateEdit_EBEdit_userDateChanged(const QDate &date)
{
    QString Date=date.toString("dd-MM-yyyy");
    qDebug()<<date;
    GDate=Date;
    Gdate=date;
    Dbase mydb("DJEB1.db");

    if (!mydb.dateExists(Date))
    {
        mydb.addDate(Date);
    }
}



void ClientWin::on_dateEdit_EBView_userDateChanged(const QDate &date)
{
    QString Date=date.toString("dd-MM-yyyy");
    qDebug()<<Date;
    GDate=Date;
    Gdate=date;
    Dbase mydb("DJEB1.db");

    if (!mydb.dateExists(Date))
    {
        mydb.addDate(Date);
    }
}



void ClientWin::on_dateEdit_DJEdit_userDateChanged(const QDate &date)
{
    QString Date=date.toString("dd-MM-yyyy");
    qDebug()<<Date;
    GDate=Date;
    Gdate=date;
    Dbase mydb("DJEB1.db");

    if (!mydb.dateExists(Date))
    {
        mydb.addDate(Date);
    }
    QString DJ=mydb.viewDJ(Date);
    qDebug()<<DJ;
    ui->plainTextEdit_DJEdit->setPlainText(DJ);
}

void ClientWin::on_pushButton_DJESave_clicked()
{
    QString DJ= ui->plainTextEdit_DJEdit->toPlainText();
    qDebug()<<DJ;
    Dbase mydb("DJEB1.db");
    mydb.addDJ(GDate,DJ);
    ui->textBrowser_DJView->setPlainText(DJ);
    ui->tabWidget_2->setCurrentIndex(0);
    ui->dateEdit_DJView->setDate(Gdate);
}

