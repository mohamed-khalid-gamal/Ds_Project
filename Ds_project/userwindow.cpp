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
    sendWin = new sendMoneyWindow(activeUser,allUsers,allTransactions,this);
    sendWin->show();
}


void userwindow::on_pushButton_2_clicked()
{
    reqWin = new requestMoneyWindow(allUsers,allTransactions,this);
    reqWin->show();
}


void userwindow::on_pushButton_3_clicked()
{
    std::stack<Transaction> tempT = ((*allUsers)[activeUser.toStdString()].getTransactions());
    tranWin = new transactionHistory(tempT, this);
    tranWin->show();
}


void userwindow::on_pushButton_4_clicked()
{
    penWin = new pendingTransactionsWindow(allUsers,this);
    penWin->show();
}


void userwindow::on_pushButton_5_clicked()
{
    resetWin = new resetPinWindow(allUsers,this);
    resetWin->show();
}

