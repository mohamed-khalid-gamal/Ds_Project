#ifndef EDITUSERSWINDOW_H
#define EDITUSERSWINDOW_H
#include <unordered_map>
#include <QDialog>
#include <string>
#include "Transaction.h"
#include "User.h"

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

private:
    Ui::editUsersWindow *ui;
};

#endif // EDITUSERSWINDOW_H
