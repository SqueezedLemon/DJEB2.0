#ifndef CLIENTWIN_H
#define CLIENTWIN_H

#include <QMainWindow>
#include<QDate>
#include <QSignalMapper>
#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include<QMessageBox>

namespace Ui {
class ClientWin;
class MainWindow;
}

class ClientWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit ClientWin(QWidget *parent = nullptr);

    ~ClientWin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_ChangePassword_clicked();

    void on_pushButton_Logout_clicked();

    void on_dateEdit_DJView_userDateChanged(const QDate &date);

    void on_dateEdit_EBEdit_userDateChanged(const QDate &date);

    void on_dateEdit_EBView_userDateChanged(const QDate &date);

    void on_dateEdit_DJEdit_userDateChanged(const QDate &date);

    void on_pushButton_DJESave_clicked();

    void on_tabWidget_2_tabBarClicked(int index);
    void setColumnHidden(int column, bool hide);

    void on_pushButton_DJESave2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_EBSave_clicked();

private:
    Ui::ClientWin *ui;
    const QString GUsername;

};

#endif // CLIENTWIN_H
