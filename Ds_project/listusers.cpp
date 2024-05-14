#include "listusers.h"
#include "ui_listusers.h"

listUsers::listUsers(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::listUsers)
{
    ui->setupUi(this);
}

listUsers::listUsers(std::unordered_map<std::string,User> *allU,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::listUsers)
{
    ui->setupUi(this);
    allUsers = allU;
}

listUsers::~listUsers()
{
    delete ui;
    allUsers = NULL;
    delete allUsers;
}

void listUsers::on_pushButton_clicked()
{
    close();
}

