#ifndef DATABASE_H
#define DATABASE_H


#include <QSqlDatabase>
#include<QList>
#include <QTableView>


class Dbase
{
public:
      Dbase(const QString& path);


 const QString GUsername;


    ~Dbase();

    bool isOpen() const;


    bool createTable();
    void afterLTable(const QString Username);


    void adduser(const QString &Username,const QString &Password );
    void useradd(const QString Username,const QString Password );
    bool dateExists( QString &date);
    void addDate(const QString date);
    void addDJ(const QString Date,const QString journal  );
    QString viewDJ(const QString Date);
    QString viewEB(const QString Date, const QString Column );
    QString getField(const QString TBD );
    void addField(const QString TBD,const QString Field);
    void addColumn(const QString TBD);
    void addExpense(const QString Date,const int Expense,const QString Field);
    bool fieldExists( QString TBD);



    bool removeUser(const QString& name);


    bool UsernameExists(const QString &Username);
    bool emailExists(const QString& email);
    bool unameExists(const QString &uname);
    bool passwordValid(const QString& passwd);


    void printAllUsers() const;

    bool removeAllUsers();



    bool userAuth(const QString& uname, const QString& pass) const;


    QList<QString> getAdminInfo(const QString& uname);


    bool getAdminInfo();


    QList<QString> getAllUsers();

    void changeAdminPassword(const QString& username,const QString& npasswd);

    ////functions for handling admin login

    void createAdmin_LoginTable();//create table for  admin that has log in

    void addAdmin_Login(QString &uname);//store data of admin that has log in

    void deleteAdmin_Login();//delete Admin_Login table



private:
    QSqlDatabase db;

    Dbase *dbase;

};



#endif
// DATABASE_H
