#include "sendmoneywindow.h"
#include "ui_sendmoneywindow.h"

sendMoneyWindow::sendMoneyWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sendMoneyWindow)
{
    ui->setupUi(this);
}
sendMoneyWindow::sendMoneyWindow(QString sender,std::unordered_map<std::string,User> *allU,std::stack<Transaction> *allT,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sendMoneyWindow)
{
    ui->setupUi(this);
    allUsers = allU;
    allTransactions = allT;
    sendUser = sender;
}

sendMoneyWindow::~sendMoneyWindow()
{
    delete ui;
    allUsers = NULL;
    allTransactions = NULL;
    delete allUsers;
    delete allTransactions;
}

void sendMoneyWindow::on_pushButton_clicked()
{
    close();
}


void sendMoneyWindow::on_pushButton_2_clicked()
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
        } else if ((*allUsers)[recipient.toStdString()].getUsername() == sendUser.toStdString()){
            ui->label_4->setText("Message: Cant Send money to yourself.");
        } else {
            if((*allUsers)[sendUser.toStdString()].getBalance() <= stof(amount.toStdString())){
                ui->label_4->setText("Message: Not enuogh balance to continue operation");
            } else{
                if (stof(amount.toStdString()) < 1){
                    ui->label_4->setText("Message: Can not send an amount that is less than 1");
                } else {
                ui->label_4->setStyleSheet("color: darkgreen");
                ui->label_4->setText("Message: Successful Transaction.");
                sendMoney();
                }
            }

        }
    }
    } catch(const std::invalid_argument e){
        ui->label_4->setText("Message: Please enter a number in Balance field");
    }

}

void sendMoneyWindow::sendMoney()
{
    QString recipient = ui->lineEdit->text();
    QString amount = ui->lineEdit_2->text();

    (*allUsers)[sendUser.toStdString()].setBalance((*allUsers)[sendUser.toStdString()].getBalance() - amount.toFloat());
    (*allUsers)[recipient.toStdString()].setBalance((*allUsers)[recipient.toStdString()].getBalance() + amount.toFloat());

    Transaction trans = Transaction(sendUser.toStdString(), recipient.toStdString(),*allTransactions);
    trans.setisAccepted(true);
    trans.setAmount(amount.toFloat());

    (*allUsers)[sendUser.toStdString()].setTransaction(trans);
    (*allUsers)[recipient.toStdString()].setTransaction(trans);

    (*allTransactions).push(trans);
}
