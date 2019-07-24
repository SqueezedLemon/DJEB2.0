#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include<QMessageBox>

Dbase::Dbase(const QString &path)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if (!db.open()){
        qDebug() << "Error: connection with dbase fail";
    }else{
        qDebug() << "dbase: connection ok";
    }
}

Dbase::~Dbase()
{
    if (db.isOpen())
    {
        db.close();
    }
}

void Dbase::useradd(const QString Username,const QString Password ){

QSqlQuery qry;
qry.prepare("INSERT INTO Login(Username,Password) VALUES(:UserName,:Password)");
qry.bindValue(":UserName",Username);
qry.bindValue(":Password",Password);

if(!qry.exec()){
    qDebug() << "add user failed: " << qry.lastError();
}else{
    qDebug() << "add user success " << qry.lastError();
}
}

bool Dbase::unameExists(const QString &uname){
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT Username FROM Login WHERE Username = (:uname)");
    checkQuery.bindValue(":uname",uname);
    if(checkQuery.exec()){
        if(checkQuery.next()){
            return true;
        }
    }else{
        qDebug()<<"does email exist query failed "<<checkQuery.lastError();
    }
    return false;
}


bool Dbase::createTable()
{
    bool success = false;

    QSqlQuery query;
    query.prepare("CREATE TABLE Login( Username TEXT,Password TEXT);");

    if (!query.exec())
    {
        qDebug() << "Couldn't create the table 'user': one might already exist.";
        success = false;
    }

    return success;
}

void Dbase::afterLTable(const QString Username)
{


    QSqlQuery query;
    query.prepare("CREATE TABLE '"+Username+"'( Date TEXT,DailyJournal TEXT,Food INTEGER,Clothes INTEGER,Transport INTEGER,Education INTEGER);");
    if (!query.exec())
    {
        qDebug() << "Couldn't create the table : one might already exist.";
    }
    else
    {
        qDebug()<<"created user table";
    }


}

bool Dbase::dateExists( QString &date){
    QSqlQuery checkQuery;
    qDebug()<<GUsername;
    checkQuery.prepare("SELECT Date FROM admin WHERE Date = (:date)");
    checkQuery.bindValue(":date",date);
    if(checkQuery.exec()){
        if(checkQuery.next()){
            return true;
        }
    }else{
        qDebug()<<"date doesn't exist. "<<checkQuery.lastError();
    }
    return false;
}

void Dbase::addDate(const QString date)
{

    QSqlQuery qry;
    qry.prepare("INSERT INTO admin (Date) VALUES(:date)");
    qry.bindValue(":date",date);


    if(!qry.exec()){
        qDebug() << "date entry failed: " << qry.lastError();
    }else{
        qDebug() << "date entry success: " << qry.lastError();
    }
}

void Dbase::addDJ(const QString Date,const QString journal ){

    QSqlQuery qry;
    qry.prepare("UPDATE admin SET DailyJournal=:journal WHERE Date='"+Date+"' ");
    qry.bindValue(":journal",journal);

    if(!qry.exec()){
        qDebug() << "journal adding failed. " << qry.lastError();
    }else{
        qDebug() << "journal added. " << qry.lastError();
    }
}

QString Dbase::viewDJ(const QString Date ){
    QSqlQuery qry;
    qry.prepare("SELECT DailyJournal FROM admin WHERE Date='"+Date+"' ");


    if(!qry.exec()){
        qDebug() << "viewing journal failed " << qry.lastError();
    }else{
        if (qry.next()){
        int a=qry.record().indexOf("DailyJournal");
        QString DJ= qry.value(a).toString();
        qDebug() << "journal added. " <<DJ<< qry.lastError();
        return DJ;
    }
    }
}

QString Dbase::viewEB(const QString Date , const QString Column){
    QSqlQuery qry;
    QString temp=Column;
    qDebug()<<Column;
    qry.prepare("SELECT * FROM admin WHERE Date='"+Date+"' ");
//    qry.bindValue(":Column",Column);


    if(!qry.exec()){
        qDebug() << "viewing journal failed " << qry.lastError();
    }else{
        if (qry.next()){
            int a=qry.record().indexOf(Column);
            QString DJ= qry.value(a).toString();
            qDebug() << a <<DJ<< qry.lastError();
            return DJ;
        }
    }
}

QString Dbase::getField(const QString TBD)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM ExpensesField");


    if(!qry.exec()){
        qDebug() << "failed " << qry.lastError();
    }else{
        if (qry.next()){
            int a=qry.record().indexOf(TBD);
            QString DJ= qry.value(a).toString();
            qDebug() <<DJ<< qry.lastError();
            return DJ;
        }
    }
}

void Dbase::addField(const QString TBD,const QString Field)
{

    QSqlQuery qry;
    qry.prepare("UPDATE ExpensesField SET '"+TBD+"'=:tbd ");
    qry.bindValue(":tbd",Field);

    if(!qry.exec()){
        qDebug() << " failed. " << qry.lastError();
    }else{
        qDebug() << "journal added. " << qry.lastError();
    }
}

void Dbase::addColumn(const QString Column)
{

    QSqlQuery qry;
    qry.prepare("ALTER TABLE admin ADD COLUMN '"+Column+"' INTEGER ");

    if(!qry.exec()){
        qDebug() << " failed. " << qry.lastError();
    }else{
        qDebug() << "column added. " << qry.lastError();
    }
}

void Dbase::addExpense(const QString Date,const int Expense,const QString Field)
{

    QSqlQuery qry;
    qry.prepare("UPDATE admin SET '"+Field+"'=:food WHERE Date='"+Date+"' ");
    qry.bindValue(":food",Expense);

    if(!qry.exec()){
        qDebug() << " failed. " << qry.lastError();
    }else{
        qDebug() << "expense added. " << qry.lastError();
    }
}

bool Dbase::fieldExists( QString TBD)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM ExpensesField)");
    if(qry.exec()){
        if(qry.next()){
            int a=qry.record().indexOf(TBD);
            QString DJ= qry.value(a).toString();
            if (DJ=="")
                return true;


        }
    }else{
        qDebug()<<"date doesn't exist. "<<qry.lastError();
    }
    return false;
}

QString Dbase::getExpense(const QString TBD, const QString Date)
{
    QSqlQuery qry;
    qry.prepare("SELECT * FROM admin WHERE Date='"+Date+"'");


    if(!qry.exec()){
        qDebug() << "failed " << qry.lastError();
    }else{
        if (qry.next()){
            int a=qry.record().indexOf(TBD);
            QString DJ= qry.value(a).toString();
            qDebug() <<DJ<< qry.lastError();
            return DJ;
        }
    }
}






