#ifndef dbase_H
#define dbase_H

#include <QSqlDatabase>
#include<QList>


class Dbase
{
public:

    Dbase(const QString& path);


    ~Dbase();

    bool isOpen() const;


    bool createTable();


    void adduser(const QString &Username,const QString &Password );
    void useradd(const QString Username,const QString Password );


    bool removeUser(const QString& name);



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
};


#endif // dbase_H
