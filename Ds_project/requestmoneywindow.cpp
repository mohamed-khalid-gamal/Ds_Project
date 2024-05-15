#include "requestmoneywindow.h"
#include "ui_requestmoneywindow.h"

requestMoneyWindow::requestMoneyWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::requestMoneyWindow)
{
    ui->setupUi(this);
}

requestMoneyWindow::requestMoneyWindow(QString sendU, std::unordered_map<std::string,User> *allU,std::stack<Transaction> *allT,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::requestMoneyWindow)
{
    ui->setupUi(this);
    allUsers = allU;
    allTransactions = allT;
    sendUser = sendU;
}

requestMoneyWindow::~requestMoneyWindow()
{
    delete ui;
    allUsers = NULL;
    allTransactions = NULL;
    delete allUsers;
    delete allTransactions;
}

void requestMoneyWindow::on_pushButton_2_clicked()
{
    QString recipient = ui->lineEdit->text();
    QString amount = ui->lineEdit_2->text();
    QString enteredPin = ui->lineEdit_3->text();
    QString realPin = QString::fromStdString((*allUsers)[sendUser.toStdString()].getPin());
    ui->label_4->setStyleSheet("color: darkred");
    try {
        if(enteredPin != realPin){
            ui->label_4->setText("Message: Invalid Pin Entered");
        } else {
            if((*allUsers).count(recipient.toStdString()) == 0){
                ui->label_4->setText("Message: User Does not Exist");
            } else {
                    ui->label_4->setStyleSheet("color: darkgreen");
                    ui->label_4->setText("Message: Successful Transaction.");
                    (*allUsers)[sendUser.toStdString()].requestMoney(allUsers,allTransactions,sendUser.toStdString(),recipient.toStdString(),amount.toFloat());
                }
            }
    } catch(const std::invalid_argument e){
        ui->label_4->setText("Message: Please enter a number in Balance field");
    }

}


void requestMoneyWindow::on_pushButton_clicked()
{
    close();
}

