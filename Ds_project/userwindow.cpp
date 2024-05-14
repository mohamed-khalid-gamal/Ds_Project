#include "userwindow.h"
#include "ui_userwindow.h"
#include "sendMoneyWindow.h"
#include "requestmoneywindow.h"
#include "transactionhistory.h"
#include "pendingtransactionswindow.h"


userwindow::userwindow(QString actUser, std::unordered_map<std::string,User> *allU,std::stack<Transaction> *allT,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::userwindow)
{
    ui->setupUi(this);
    activeUser = actUser;
    allUsers = allU;
    allTransactions = allT;
    ui->label->setText("User: " + actUser);
    showBalance();
}

userwindow::~userwindow()
{
    delete ui;
    allUsers = NULL;
    allTransactions = NULL;
    delete allUsers;
    delete allTransactions;
}

void userwindow::on_pushButton_7_clicked() // Refresh Balance button
{
    showBalance();
}

void userwindow::showBalance(){
    float balanceF = (*this->allUsers)[activeUser.toStdString()].getBalance();
    std::string balanceS = std::to_string(balanceF);
    QString balanceQ = QString::fromStdString(balanceS);
    ui->label_2->setText("Balance: " + balanceQ);
}


void userwindow::on_pushButton_6_clicked() //Log out button
{
    QWidget::close();
}


void userwindow::on_pushButton_clicked()
{
    hide();
    sendMoneyWindow sendWin;
    sendWin.setModal(true);
    sendWin.exec();
    show();
}


void userwindow::on_pushButton_2_clicked()
{
    hide();
    requestMoneyWindow reqWin;
    reqWin.setModal(true);
    reqWin.exec();
    show();
}


void userwindow::on_pushButton_3_clicked()
{
    hide();
    transactionHistory tranWin;
    tranWin.setModal(true);
    tranWin.exec();
    show();
}


void userwindow::on_pushButton_4_clicked()
{
    hide();
    pendingTransactionsWindow penWin;
    penWin.setModal(true);
    penWin.exec();
    show();
}

