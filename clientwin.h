#ifndef CLIENTWIN_H
#define CLIENTWIN_H

#include <QMainWindow>

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

private:
    Ui::ClientWin *ui;
};

#endif // CLIENTWIN_H
