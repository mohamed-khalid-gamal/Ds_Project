#include "requestmoneywindow.h"
#include "ui_requestmoneywindow.h"

requestMoneyWindow::requestMoneyWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::requestMoneyWindow)
{
    ui->setupUi(this);
}

requestMoneyWindow::requestMoneyWindow(std::unordered_map<std::string,User> *allU,std::stack<Transaction> *allT,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::requestMoneyWindow)
{
    ui->setupUi(this);
    allUsers = allU;
    allTransactions = allT;
}

requestMoneyWindow::~requestMoneyWindow()
{
    delete ui;
    allUsers = NULL;
    allTransactions = NULL;
    delete allUsers;
    delete allTransactions;
}
