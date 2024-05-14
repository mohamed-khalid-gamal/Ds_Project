#include "userwindow.h"
#include "ui_userwindow.h"

userwindow::userwindow(QString actUser, std::unordered_map<std::string,User> *allU,std::stack<Transaction> *allT,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::userwindow)
{
    ui->setupUi(this);
    activeUser = actUser;
    allUsers = allU;
    allTransactions = allT;
    ui->label->setText("User: " + actUser);
}

userwindow::~userwindow()
{
    delete ui;
    allUsers = NULL;
    allTransactions = NULL;
    delete allUsers;
    delete allTransactions;
}
