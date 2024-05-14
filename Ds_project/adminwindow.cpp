#include "adminwindow.h"
#include "ui_adminwindow.h"

adminwindow::adminwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminwindow)
{
    ui->setupUi(this);
}
adminwindow::adminwindow(std::unordered_map<std::string,User> *allU,std::stack<Transaction> *allT,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminwindow)
{
    ui->setupUi(this);
    allUsers = allU;
    allTransactions = allT;
}


adminwindow::~adminwindow()
{
    delete ui;
    allUsers = NULL;
    allTransactions = NULL;
    delete allUsers;
    delete allTransactions;
}

