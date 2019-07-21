#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "QtSql"
#include "QtDebug"
#include "QFileInfo"
#include "clientwin.h"
#include "database.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_SignIn_clicked();

    void on_pushButton_SignUp_clicked();

    void on_pushButton_SignUp_clicked(bool checked);

    void on_pushButton_CreateAcc_clicked();



    void on_pushButton_CreateAcc_2_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase mydb;
    ClientWin *clientwin;
    bool createTable();

};

#endif // MAINWINDOW_H
