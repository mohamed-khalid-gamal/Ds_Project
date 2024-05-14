#include "edituserswindow.h"
#include "ui_edituserswindow.h"

editUsersWindow::editUsersWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editUsersWindow)
{
    ui->setupUi(this);
}

editUsersWindow::~editUsersWindow()
{
    delete ui;
}
