#include "forgetpasswordwindow.h"
#include "ui_forgetpasswordwindow.h"

forgetPasswordWindow::forgetPasswordWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::forgetPasswordWindow)
{
    ui->setupUi(this);
}
forgetPasswordWindow::forgetPasswordWindow(std::unordered_map<std::string,User> *allU,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::forgetPasswordWindow)
{
    ui->setupUi(this);
    allUsers = allU;
}

forgetPasswordWindow::~forgetPasswordWindow()
{
    delete ui;
    allUsers = NULL;
    delete allUsers;
}
