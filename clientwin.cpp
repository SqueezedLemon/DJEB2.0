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
    Dbase mydb("DJEB1.db");
    QString A= mydb.getField("TBD1");
    if (A=="")
        {
            ui->lineEdit_TBD1->setVisible(false);
            ui->label_TBD1->setVisible(false);
        }
    else
        {
            ui->label_TBD1->setText(A);
            ui->label_TBD1->setVisible(true);
            ui->lineEdit_TBD1->setVisible(true);
        }

        QString B= mydb.getField("TBD2");
        if (B=="")
        {
            ui->lineEdit_TBD2->setVisible(false);
            ui->label_TBD2->setVisible(false);
        }
        else
        {
            ui->label_TBD2->setText(B);
            ui->label_TBD2->setVisible(true);
            ui->lineEdit_TBD2->setVisible(true);
        }

        QString C= mydb.getField("TBD3");
        if (C=="")
        {
            ui->lineEdit_TBD3->setVisible(false);
            ui->label_TBD3->setVisible(false);
        }
        else
        {
            ui->label_TBD3->setText(C);
            ui->label_TBD3->setVisible(true);
            ui->lineEdit_TBD3->setVisible(true);
        }

        QString D= mydb.getField("TBD4");
        if (D=="")
        {
            ui->lineEdit_TBD4->setVisible(false);
            ui->label_TBD4->setVisible(false);
        }
        else
        {
            ui->label_TBD4->setText(D);
            ui->label_TBD4->setVisible(true);
            ui->lineEdit_TBD4->setVisible(true);
        }

        QString E= mydb.getField("TBD5");
        if (E=="")
        {
            ui->lineEdit_TBD5->setVisible(false);
            ui->label_TBD5->setVisible(false);
        }
        else
        {
            ui->label_TBD5->setText(E);
            ui->label_TBD5->setVisible(true);
            ui->lineEdit_TBD5->setVisible(true);
        }

        QString F= mydb.getField("TBD6");
        if (F=="")
        {
            ui->lineEdit_TBD6->setVisible(false);
            ui->label_TBD6->setVisible(false);
        }
        else
        {
            ui->label_TBD6->setText(B);
            ui->label_TBD6->setVisible(true);
            ui->lineEdit_TBD6->setVisible(true);
        }

connect(ui->lineEdit_Field, SIGNAL(returnPressed()),ui->pushButton_7,SIGNAL(clicked()));


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

    QString Clothes=mydb.viewEB(GDate,"Clothes");
    ui->lineEdit_Clothes->setText(Clothes);

    QString Transport=mydb.viewEB(GDate,"Transport");
    ui->lineEdit_Transport->setText(Transport);

    QString Education=mydb.viewEB(GDate,"Education");
    ui->lineEdit_Education->setText(Education);

    if (!mydb.fieldExists("TBD1"))
    {
        QString EC=mydb.getField("TBD1");
        QString E=mydb.getExpense(EC,GDate);
        ui->lineEdit_TBD1->setText(E);
    }

    if (!mydb.fieldExists("TBD2"))
    {
        QString FC=mydb.getField("TBD2");
        QString F=mydb.getExpense(FC,GDate);
        ui->lineEdit_TBD2->setText(F);
    }

    if (!mydb.fieldExists("TBD3"))
    {
        QString GC=mydb.getField("TBD3");
        QString G=mydb.getExpense(GC,GDate);
        ui->lineEdit_TBD3->setText(G);
    }

    if (!mydb.fieldExists("TBD4"))
    {
        QString HC=mydb.getField("TBD4");
        QString H=mydb.getExpense(HC,GDate);
        ui->lineEdit_TBD4->setText(H);
    }

    if (!mydb.fieldExists("TBD5"))
    {
        QString IC=mydb.getField("TBD5");
        QString I=mydb.getExpense(IC,GDate);
        ui->lineEdit_TBD5->setText(I);
    }

    if (!mydb.fieldExists("TBD6"))
    {
        QString JC=mydb.getField("TBD6");
        QString J=mydb.getExpense(JC,GDate);
        ui->lineEdit_TBD6->setText(J);
    }
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

    int AT,BT,CT,DT,ET,FT,GT,HT,IT,JT;

    QString Food=mydb.viewEB(GDate,"Food");
    AT=Food.toInt();

    QString Clothes=mydb.viewEB(GDate,"Clothes");
     BT=Clothes.toInt();

    QString Transport=mydb.viewEB(GDate,"Transport");
     CT=Transport.toInt();

    QString Education=mydb.viewEB(GDate,"Education");
     DT=Education.toInt();

    if (!mydb.fieldExists("TBD1"))
    {
        QString EC=mydb.getField("TBD1");
        QString E=mydb.getExpense(EC,GDate);
         ET=E.toInt();
    }

    if (!mydb.fieldExists("TBD2"))
    {
        QString FC=mydb.getField("TBD2");
        QString F=mydb.getExpense(FC,GDate);
         FT=F.toInt();
    }

    if (!mydb.fieldExists("TBD3"))
    {
        QString GC=mydb.getField("TBD3");
        QString G=mydb.getExpense(GC,GDate);
         GT=G.toInt();
    }

    if (!mydb.fieldExists("TBD4"))
    {
        QString HC=mydb.getField("TBD4");
        QString H=mydb.getExpense(HC,GDate);
         HT=H.toInt();
    }

    if (!mydb.fieldExists("TBD5"))
    {
        QString IC=mydb.getField("TBD5");
        QString I=mydb.getExpense(IC,GDate);
         IT=I.toInt();
    }

    if (!mydb.fieldExists("TBD6"))
    {
        QString JC=mydb.getField("TBD6");
        QString J=mydb.getExpense(JC,GDate);
         JT=J.toInt();
    }
    int Total=AT+BT+CT+DT+ET+FT+GT+HT+IT+JT;
    ui->label_Total->setNum(Total);

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
    Dbase mydb("DJEB1.db");
    QString TBD1=ui->label_TBD1->text();
    QString TBD2=ui->label_TBD2->text();
    QString TBD3=ui->label_TBD3->text();
    QString TBD4=ui->label_TBD4->text();
    QString TBD5=ui->label_TBD5->text();
    QString TBD6=ui->label_TBD6->text();
    QString Field=ui->lineEdit_Field->text();
    ui->lineEdit_Field->setText("");

    if (TBD1=="")
    {
     ui->label_TBD1->setText(Field);
    ui->label_TBD1->setVisible(true);
    ui->lineEdit_TBD1->setVisible(true);
    mydb.addField("TBD1",Field);
    mydb.addColumn(Field);
    ui->dateEdit_EBView->setDate(Gdate);
    }

    else if (TBD2=="")
    {
     ui->label_TBD2->setText(Field);
        ui->label_TBD2->setVisible(true);
        ui->lineEdit_TBD2->setVisible(true);
        mydb.addField("TBD2",Field);
        mydb.addColumn(Field);
        ui->dateEdit_EBView->setDate(Gdate);
    }

    else if (TBD3=="")
    {
     ui->label_TBD3->setText(Field);
        ui->label_TBD3->setVisible(true);
        ui->lineEdit_TBD3->setVisible(true);
        mydb.addField("TBD3",Field);
        mydb.addColumn(Field);
        ui->dateEdit_EBView->setDate(Gdate);
    }

    else if (TBD4=="")
    {
     ui->label_TBD4->setText(Field);
        ui->label_TBD4->setVisible(true);
        ui->lineEdit_TBD4->setVisible(true);
        mydb.addField("TBD4",Field);
        mydb.addColumn(Field);
        ui->dateEdit_EBView->setDate(Gdate);
    }

    else if (TBD5=="")
    {
     ui->label_TBD5->setText(Field);
        ui->label_TBD5->setVisible(true);
        ui->lineEdit_TBD5->setVisible(true);
        mydb.addField("TBD5",Field);
        mydb.addColumn(Field);
        ui->dateEdit_EBView->setDate(Gdate);
    }

    else if (TBD6=="")
    {
     ui->label_TBD6->setText(Field);
        ui->label_TBD6->setVisible(true);
        ui->lineEdit_TBD6->setVisible(true);
        mydb.addField("TBD6",Field);
        mydb.addColumn(Field);
        ui->dateEdit_EBView->setDate(Gdate);
    }

    else
    {
        QMessageBox::warning(this,"Max Field","Field Limit Reached");
    }
}

void ClientWin::on_pushButton_EBSave_clicked()
{
    Dbase mydb("DJEB1.db");
    QString A= ui->lineEdit_Food->text();
    int Ai=A.toInt();
    mydb.addExpense(GDate,Ai,"Food");

    QString B= ui->lineEdit_Clothes->text();
    int Bi=B.toInt();
    mydb.addExpense(GDate,Bi,"Clothes");

    QString C= ui->lineEdit_Transport->text();
    int Ci=C.toInt();
    mydb.addExpense(GDate,Ci,"Transport");

    QString D= ui->lineEdit_Education->text();
    int Di=D.toInt();
    mydb.addExpense(GDate,Di,"Education");

    if (!mydb.fieldExists("TBD1"))
    {
        QString EC=mydb.getField("TBD1");
        QString E= ui->lineEdit_TBD1->text();
        int Ei=E.toInt();
        mydb.addExpense(GDate,Ei,EC);
    }

    if (!mydb.fieldExists("TBD2"))
    {
        QString FC=mydb.getField("TBD2");
        QString F= ui->lineEdit_TBD2->text();
        int Fi=F.toInt();
        mydb.addExpense(GDate,Fi,FC);
    }

    if (!mydb.fieldExists("TBD3"))
    {
        QString GC=mydb.getField("TBD3");
        QString G= ui->lineEdit_TBD3->text();
        int Gi=G.toInt();
        mydb.addExpense(GDate,Gi,GC);
    }

    if (!mydb.fieldExists("TBD4"))
    {
        QString HC=mydb.getField("TBD4");
        QString H= ui->lineEdit_TBD4->text();
        int Hi=H.toInt();
        mydb.addExpense(GDate,Hi,HC);
    }

    if (!mydb.fieldExists("TBD5"))
    {
        QString IC=mydb.getField("TBD5");
        QString I= ui->lineEdit_TBD5->text();
        int Ii=I.toInt();
        mydb.addExpense(GDate,Ii,IC);
    }

    if (!mydb.fieldExists("TBD6"))
    {
        QString JC=mydb.getField("TBD6");
        QString J= ui->lineEdit_TBD6->text();
        int Ji=J.toInt();
        mydb.addExpense(GDate,Ji,JC);
    }
        QMessageBox::information(this,"Changes Saved","Changes Saved Successfully.");

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM admin WHERE Date='"+GDate+"'");
    qry.exec();
    model->setQuery(qry);
    ui->tableView_EBV->setModel(model);
    ui->tableView_EBV->setColumnHidden(0,true);
    ui->tableView_EBV->setColumnHidden(1,true);

    int AT,BT,CT,DT,ET,FT,GT,HT,IT,JT;

    QString Food=mydb.viewEB(GDate,"Food");
    AT=Food.toInt();

    QString Clothes=mydb.viewEB(GDate,"Clothes");
    BT=Clothes.toInt();

    QString Transport=mydb.viewEB(GDate,"Transport");
    CT=Transport.toInt();

    QString Education=mydb.viewEB(GDate,"Education");
    DT=Education.toInt();

    if (!mydb.fieldExists("TBD1"))
    {
        QString EC=mydb.getField("TBD1");
        QString E=mydb.getExpense(EC,GDate);
        ET=E.toInt();
    }

    if (!mydb.fieldExists("TBD2"))
    {
        QString FC=mydb.getField("TBD2");
        QString F=mydb.getExpense(FC,GDate);
        FT=F.toInt();
    }

    if (!mydb.fieldExists("TBD3"))
    {
        QString GC=mydb.getField("TBD3");
        QString G=mydb.getExpense(GC,GDate);
        GT=G.toInt();
    }

    if (!mydb.fieldExists("TBD4"))
    {
        QString HC=mydb.getField("TBD4");
        QString H=mydb.getExpense(HC,GDate);
        HT=H.toInt();
    }

    if (!mydb.fieldExists("TBD5"))
    {
        QString IC=mydb.getField("TBD5");
        QString I=mydb.getExpense(IC,GDate);
        IT=I.toInt();
    }

    if (!mydb.fieldExists("TBD6"))
    {
        QString JC=mydb.getField("TBD6");
        QString J=mydb.getExpense(JC,GDate);
        JT=J.toInt();
    }
    int Total=AT+BT+CT+DT+ET+FT+GT+HT+IT+JT;
    ui->label_Total->setNum(Total);


}

void ClientWin::on_pushButton_EBSaveV_clicked()
{
    Dbase mydb("DJEB1.db");
    QString A= ui->lineEdit_Food->text();
    int Ai=A.toInt();
    mydb.addExpense(GDate,Ai,"Food");

    QString B= ui->lineEdit_Clothes->text();
    int Bi=B.toInt();
    mydb.addExpense(GDate,Bi,"Clothes");

    QString C= ui->lineEdit_Transport->text();
    int Ci=C.toInt();
    mydb.addExpense(GDate,Ci,"Transport");

    QString D= ui->lineEdit_Education->text();
    int Di=D.toInt();
    mydb.addExpense(GDate,Di,"Education");

    if (!mydb.fieldExists("TBD1"))
    {
        QString EC=mydb.getField("TBD1");
        QString E= ui->lineEdit_TBD1->text();
        int Ei=E.toInt();
        mydb.addExpense(GDate,Ei,EC);
    }

    if (!mydb.fieldExists("TBD2"))
    {
        QString FC=mydb.getField("TBD2");
        QString F= ui->lineEdit_TBD2->text();
        int Fi=F.toInt();
        mydb.addExpense(GDate,Fi,FC);
    }

    if (!mydb.fieldExists("TBD3"))
    {
        QString GC=mydb.getField("TBD3");
        QString G= ui->lineEdit_TBD3->text();
        int Gi=G.toInt();
        mydb.addExpense(GDate,Gi,GC);
    }

    if (!mydb.fieldExists("TBD4"))
    {
        QString HC=mydb.getField("TBD4");
        QString H= ui->lineEdit_TBD4->text();
        int Hi=H.toInt();
        mydb.addExpense(GDate,Hi,HC);
    }

    if (!mydb.fieldExists("TBD5"))
    {
        QString IC=mydb.getField("TBD5");
        QString I= ui->lineEdit_TBD5->text();
        int Ii=I.toInt();
        mydb.addExpense(GDate,Ii,IC);
    }

    if (!mydb.fieldExists("TBD6"))
    {
        QString JC=mydb.getField("TBD6");
        QString J= ui->lineEdit_TBD6->text();
        int Ji=J.toInt();
        mydb.addExpense(GDate,Ji,JC);
    }
    QMessageBox::information(this,"Changes Saved","Changes Saved Successfully.");

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("SELECT * FROM admin WHERE Date='"+GDate+"'");
    qry.exec();
    model->setQuery(qry);
    ui->tableView_EBV->setModel(model);
    ui->tableView_EBV->setColumnHidden(0,true);
    ui->tableView_EBV->setColumnHidden(1,true);

    int AT,BT,CT,DT,ET,FT,GT,HT,IT,JT;

    QString Food=mydb.viewEB(GDate,"Food");
    AT=Food.toInt();

    QString Clothes=mydb.viewEB(GDate,"Clothes");
    BT=Clothes.toInt();

    QString Transport=mydb.viewEB(GDate,"Transport");
    CT=Transport.toInt();

    QString Education=mydb.viewEB(GDate,"Education");
    DT=Education.toInt();

    if (!mydb.fieldExists("TBD1"))
    {
        QString EC=mydb.getField("TBD1");
        QString E=mydb.getExpense(EC,GDate);
        ET=E.toInt();
    }

    if (!mydb.fieldExists("TBD2"))
    {
        QString FC=mydb.getField("TBD2");
        QString F=mydb.getExpense(FC,GDate);
        FT=F.toInt();
    }

    if (!mydb.fieldExists("TBD3"))
    {
        QString GC=mydb.getField("TBD3");
        QString G=mydb.getExpense(GC,GDate);
        GT=G.toInt();
    }

    if (!mydb.fieldExists("TBD4"))
    {
        QString HC=mydb.getField("TBD4");
        QString H=mydb.getExpense(HC,GDate);
        HT=H.toInt();
    }

    if (!mydb.fieldExists("TBD5"))
    {
        QString IC=mydb.getField("TBD5");
        QString I=mydb.getExpense(IC,GDate);
        IT=I.toInt();
    }

    if (!mydb.fieldExists("TBD6"))
    {
        QString JC=mydb.getField("TBD6");
        QString J=mydb.getExpense(JC,GDate);
        JT=J.toInt();
    }
    int Total=AT+BT+CT+DT+ET+FT+GT+HT+IT+JT;
    ui->label_Total->setNum(Total);

    ui->tabWidget->setCurrentIndex(0);
    ui->dateEdit_EBView->setDate(Gdate);
}

void ClientWin::on_pushButton_3_clicked()
{
    Dbase mydb("DJEB1.db");
    QString Old,New,CNew,DOld;
    Old= ui->lineEdit->text();
    New= ui->lineEdit_2->text();
    CNew= ui->lineEdit_3->text();

    QSqlQuery qry;

    if(qry.exec("select * from Login where  Password='"+Old+"'"))
    {
        if (New==CNew)
        {
        if(qry.next())
        {
            mydb.changePassword(New);
            QMessageBox::information(this,"Password","Password Changed Succesfully.");
        }
        }
    }
    else
    {
        QMessageBox::warning(this,"Warning","Password Mismatch.");
    }

}
