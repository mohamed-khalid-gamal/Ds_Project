#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "accountutil.h"
registerwindow::registerwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registerwindow)
{
    ui->setupUi(this);
}
registerwindow::registerwindow(std::unordered_map<std::string,User> *allU,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registerwindow)
{
    ui->setupUi(this);
    allUsers = allU;
}


registerwindow::~registerwindow()
{
    delete ui;
    allUsers = NULL;
    delete allUsers;
}
void registerwindow::on_pushButton_4_clicked()
{
    QWidget::close();
}

void registerwindow::on_pushButton_2_clicked()
{
    QString name = ui->lineEdit->text();
    QString pass = ui->lineEdit_2->text();
    ui->label_5->setStyleSheet("Color: darkred");
    if (name.length() < 5 || name.length() > 16){
    ui->label_5->setText("Message: Invalid Username Length");
    } else {
        if((*allUsers).count(name.toStdString()) == 1 || name.toStdString() == "admin"){
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
    ui->label_5->setStyleSheet("Color: darkgreen");
    std::unordered_map<std::string,User>::iterator it;
    it = allUsers->begin();
    ui->label_5->setText(QString::fromStdString(it->second.getUsername()));
}


void registerwindow::on_pushButton_clicked()
{
    if (ui->lineEdit_2->echoMode() == QLineEdit::Normal){
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
        ui->pushButton->setText("Show Pass");
    } else {
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
        ui->pushButton->setText("Hide Pass");
    }
}

