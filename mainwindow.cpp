#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QPixmap>
#include<QStackedWidget>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowTitle("DJEB");
//    bool UsernameExists(const QString &Username);
//    mydb=QSqlDatabase::addDatabase("QSQLITE");
//     mydb.setDatabaseName("DJEB.db");
        Dbase mydb("DJEB1.db");
        mydb.createTable();
     //  createTable();
       ui->stackedWidget->setCurrentIndex(0);
//     createTable();
     connect(ui->lineEdit_Password, SIGNAL(returnPressed()),ui->pushButton,SIGNAL(clicked()));
     connect(ui->lineEdit_SCPassword, SIGNAL(returnPressed()),ui->pushButton_CreateAcc,SIGNAL(clicked()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{



    QString Username,Password;
    Username=ui->lineEdit_Username->text();

    Password=ui->lineEdit_Password->text();



    Dbase mydb("DJEB1.db");

    QSqlQuery qry;

    if(qry.exec("select * from Login where Username='"+Username+"'and Password='"+Password+"'"))
    {

       if(qry.next())
           {

           Dbase dbase(Username);
            qDebug()<<"username and password is correct";
            this->close();
            clientwin = new ClientWin(this);
           // dbase=new Dbase(Username);
            clientwin->show();

        }
       else{

            qDebug()<<"failed";
            QMessageBox::warning(this,"Login","Username or Password is incorrect.");
        }
    }
}

//bool MainWindow::createTable()
//{
//    bool success = false;

//    QSqlQuery query;
//    query.prepare("CREATE TABLE Login( Username TEXT,Password TEXT);");

//    if (!query.exec())
//    {
//        qDebug() << "Couldn't create the table 'user': one might already exist.";
//        success = false;
//    }

//    return success;
//}

//bool MainWindow::UsernameExists(const QString &Username)
//{
//    bool success= false;
//    QSqlQuery query;
//    query.prepare("select * from Login where Username='"+Username+"';");
//    if (query.exec())
//    {
//        qDebug() << "Username already exists.";
//        success = true;
//    }
//    return success;
//}

void MainWindow::on_pushButton_SignUp_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_CreateAcc_clicked()
{
    QString name= ui->username->text();
    QString Password= ui->lineEdit_SPassword->text();
    QString CPassword= ui->lineEdit_SCPassword->text();
    Dbase mydb("DJEB1.db");
    qDebug()<<mydb.unameExists(name);


    if (mydb.unameExists(name))
    {
        QMessageBox::warning(this,"Username","Username already exists.");
    }
    else if (Password!=CPassword)
    {
         QMessageBox::warning(this,"Password","Password do not match.");
    }
    else
    {
       mydb.useradd(name,Password);
       mydb.afterLTable(name);
       QMessageBox::information(this,"Sign Up Info","Sign Up Successful");
       ui->stackedWidget->setCurrentIndex(0);

    }
}


void MainWindow::on_pushButton_CreateAcc_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
