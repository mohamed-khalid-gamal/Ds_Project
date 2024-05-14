#include "sendmoneywindow.h"
#include "ui_sendmoneywindow.h"

sendMoneyWindow::sendMoneyWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sendMoneyWindow)
{
    ui->setupUi(this);
}
sendMoneyWindow::sendMoneyWindow(std::unordered_map<std::string,User> *allU,std::stack<Transaction> *allT,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sendMoneyWindow)
{
    ui->setupUi(this);
    allUsers = allU;
    allTransactions = allT;
}

sendMoneyWindow::~sendMoneyWindow()
{
    delete ui;
    allUsers = NULL;
    allTransactions = NULL;
    delete allUsers;
    delete allTransactions;
}
