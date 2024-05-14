#include "edituserswindow.h"
#include "ui_edituserswindow.h"
#include "listusers.h"

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

void editUsersWindow::on_pushButton_clicked()
{
    hide();
    listUsers listWin;
    listWin.setModal(true);
    listWin.exec();
    show();
}


void editUsersWindow::on_pushButton_4_clicked()
{
    QWidget::close();
}

