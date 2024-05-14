#include "edituserswindow.h"
#include "ui_edituserswindow.h"

editUsersWindow::editUsersWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editUsersWindow)
{
        ui->setupUi(this);
}
editUsersWindow::editUsersWindow(std::unordered_map<std::string,User> *allU,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editUsersWindow)
{
    ui->setupUi(this);
    allUsers = allU;
}

editUsersWindow::~editUsersWindow()
{
    delete ui;
    allUsers = NULL;
    delete allUsers;
}
