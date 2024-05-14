#include "listusers.h"
#include "ui_listusers.h"

listUsers::listUsers(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::listUsers)
{
    ui->setupUi(this);
}

listUsers::~listUsers()
{
    delete ui;
}
