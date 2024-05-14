#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "accountutil.h"
#include "SaveLoad.h"
registerwindow::registerwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registerwindow)
{
    ui->setupUi(this);
}
registerwindow::registerwindow(std::unordered_map<std::string,User> *allU,std::stack<Transaction> *allT,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registerwindow)
{
    ui->setupUi(this);
    allUsers = allU;
    allTransactions = allT;
}


registerwindow::~registerwindow()
{
    delete ui;
    allUsers = NULL;
    allTransactions = NULL;
    delete allUsers;
    delete allTransactions;
}

void registerwindow::on_pushButton_4_clicked()
{
    QWidget::close();
}

void registerwindow::on_pushButton_2_clicked()
{
    QString name = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();

    if (name.length() < 5 || name.length() > 16){
    ui->label_5->setText("Message: Invalid Username Length");
    } else {
        if(name.toStdString() == (*this->allUsers)[name.toStdString()].getUsername() || name.toStdString() == "admin"){
            ui->label_5->setText("Message: Name is already taken.");
        } else {
            if (pass.length() < 8 || pass.length() > 16){
                ui->label_5->setText("Message: Invalid Password Length");
             } else {
               registerUser(name,pass);
             }
            }
        }
}

void registerwindow::registerUser(QString name,QString pass){
    AccountUtil hash;
    std::string hashedPass = hash.hashText(pass.toStdString());
    User newUser;
    newUser.setUsername(name.toStdString());
    newUser.setPassword(hashedPass);
    newUser.setActive(true);
    newUser.setBalance(50);
    (*this->allUsers)[name.toStdString()] = newUser;
    ui->label_5->setText("message");
}


void registerwindow::on_pushButton_clicked()
{
    SaveLoad file;
    file.saveUsers((*this->allUsers));
    file.saveTransactions(*this->allTransactions);
    if (ui->lineEdit_2->echoMode() == QLineEdit::Normal){
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
        ui->pushButton->setText("Show Pass");
    } else {
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
        ui->pushButton->setText("Hide Pass");
    }
}

