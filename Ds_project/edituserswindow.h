#ifndef EDITUSERSWINDOW_H
#define EDITUSERSWINDOW_H
#include <unordered_map>
#include <QDialog>
#include <string>
#include "User.h"
#include "listusers.h"

namespace Ui {
class editUsersWindow;
}

class editUsersWindow : public QDialog
{
    Q_OBJECT

public:
    explicit editUsersWindow(QWidget *parent = nullptr);
    explicit editUsersWindow(std::unordered_map<std::string,User> *allU,QWidget *parent = nullptr);
    std::unordered_map<std::string,User>* allUsers;
    ~editUsersWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::editUsersWindow *ui;
    listUsers *listWin;
};

#endif // EDITUSERSWINDOW_H
