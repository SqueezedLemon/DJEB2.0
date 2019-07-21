#include "clientwin.h"
#include "ui_clientwin.h"
#include "mainwindow.h"
#include<QTextStream>
#include <QTableView>
#include <QTableWidget>
QString GUsername1;
QString GDate;
QDate Gdate;


ClientWin::ClientWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ClientWin)
{
    ui->setupUi(this);
    GUsername1=GUsername;
    this->setWindowTitle("DJEB");

  ui->dateEdit_DJView->setDate(QDate::currentDate());

    ui->dateEdit_DJEdit->setDate(QDate::currentDate());
    ui->dateEdit_EBView->setDate(QDate::currentDate());
    ui->dateEdit_EBEdit->setDate(QDate::currentDate());
    ui->lineEdit_TBD1->setVisible(false);
    ui->lineEdit_TBD2->setVisible(false);
    ui->lineEdit_TBD3->setVisible(false);
    ui->lineEdit_TBD4->setVisible(false);
    ui->lineEdit_TBD5->setVisible(false);
    ui->lineEdit_TBD6->setVisible(false);
    ui->label_TBD1->setVisible(false);
    ui->label_TBD2->setVisible(false);
    ui->label_TBD3->setVisible(false);
    ui->label_TBD4->setVisible(false);
    ui->label_TBD5->setVisible(false);
    ui->label_TBD6->setVisible(false);


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
    QString Food=mydb.viewEB(GDate,"Food");
    ui->lineEdit_Food->setText(Food);
}



void ClientWin::on_dateEdit_EBView_userDateChanged(const QDate &date)
{
    QString Date=date.toString("dd-MM-yyyy");
    qDebug()<<Date;
    GDate=Date;
    Gdate=date;
    Dbase mydb("DJEB1.db");

    if (!mydb.dateExists (Date))
    {
        mydb.addDate(Date);
    }

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM admin WHERE Date='"+GDate+"'");
    qry.exec();
    model->setQuery(qry);


    ui->tableView_EBV->setModel(model);
    ui->tableView_EBV->setColumnHidden(0,true);
    ui->tableView_EBV->setColumnHidden(1,true);
}



void ClientWin::on_dateEdit_DJEdit_userDateChanged(const QDate &date)
{

    QString Date=date.toString("dd-MM-yyyy");
    qDebug()<<GUsername1;
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



void ClientWin::on_pushButton_DJESave2_clicked()
{
    QString DJ= ui->plainTextEdit_DJEdit->toPlainText();
    qDebug()<<DJ;
    Dbase mydb("DJEB1.db");
    mydb.addDJ(GDate,DJ);
    ui->textBrowser_DJView->setPlainText(DJ);
    QMessageBox::information(this,"Changes Saved","Changes Saved Successfully.");
}

void ClientWin::on_pushButton_7_clicked()
{
    QString TBD1=ui->label_TBD1->text();
    QString TBD2=ui->label_TBD2->text();
    QString TBD3=ui->label_TBD3->text();
    QString TBD4=ui->label_TBD4->text();
    QString TBD5=ui->label_TBD5->text();
    QString TBD6=ui->label_TBD6->text();
    QString Field=ui->lineEdit_Field->text();
    if (TBD1=="")
    {
     ui->label_TBD1->setText(Field);
    ui->label_TBD1->setVisible(true);
    ui->lineEdit_TBD1->setVisible(true);
    }

    else if (TBD2=="")
    {
     ui->label_TBD2->setText(Field);
        ui->label_TBD2->setVisible(true);
        ui->lineEdit_TBD2->setVisible(true);
    }

    else if (TBD3=="")
    {
     ui->label_TBD3->setText(Field);
        ui->label_TBD3->setVisible(true);
        ui->lineEdit_TBD3->setVisible(true);
    }

    else if (TBD4=="")
    {
     ui->label_TBD4->setText(Field);
        ui->label_TBD4->setVisible(true);
        ui->lineEdit_TBD4->setVisible(true);
    }

    else if (TBD5=="")
    {
     ui->label_TBD5->setText(Field);
        ui->label_TBD5->setVisible(true);
        ui->lineEdit_TBD5->setVisible(true);
    }

    else if (TBD6=="")
    {
     ui->label_TBD6->setText(Field);
        ui->label_TBD6->setVisible(true);
        ui->lineEdit_TBD6->setVisible(true);
    }

    else
    {
        QMessageBox::warning(this,"Max Field","Field Limit Reached");
    }
}
