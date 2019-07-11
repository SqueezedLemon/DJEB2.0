#ifndef CLIENTWIN_H
#define CLIENTWIN_H

#include <QMainWindow>
#include<QDate>
#include <QSignalMapper>

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

private:
    Ui::ClientWin *ui;
};

#endif // CLIENTWIN_H
