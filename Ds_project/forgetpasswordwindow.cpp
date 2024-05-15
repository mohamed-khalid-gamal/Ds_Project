#include "forgetpasswordwindow.h"
#include "ui_forgetpasswordwindow.h"
#include "accountutil.h"

forgetPasswordWindow::forgetPasswordWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::forgetPasswordWindow)
{
    ui->setupUi(this);
}
forgetPasswordWindow::forgetPasswordWindow(std::unordered_map<std::string,User> *allU,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::forgetPasswordWindow)
{
    ui->setupUi(this);
    allUsers = allU;
}

forgetPasswordWindow::~forgetPasswordWindow()
{
    delete ui;
    allUsers = NULL;
    delete allUsers;
}

void forgetPasswordWindow::on_pushButton_6_clicked()
{
    close();
}


void forgetPasswordWindow::on_pushButton_3_clicked()
{
    if (ui->lineEdit_4->echoMode() == QLineEdit::Normal){
        ui->lineEdit_4->setEchoMode(QLineEdit::Password);
        ui->pushButton_3->setText("Show Pass");
    } else {
        ui->lineEdit_4->setEchoMode(QLineEdit::Normal);
        ui->pushButton_3->setText("Hide Pass");
    }
}


void forgetPasswordWindow::on_pushButton_5_clicked()
{
    QString name = ui->lineEdit_3->text();
    QString pass = ui->lineEdit_4->text();
    ui->label_5->setStyleSheet("Color: darkred");
    if ((*allUsers).count(name.toStdString()) == 0){
        ui->label_5->setText("Message: User not Found");
    } else {
            if (pass.length() < 8 || pass.length() > 16){
                ui->label_5->setText("Message: Invalid Password Length");
            } else {
                forgetPass(name,pass);
        }
    }
}

void forgetPasswordWindow::forgetPass(QString name, QString pass){
    ui->label_5->setStyleSheet("Color: darkgreen");
    ui->label_5->setText("Message: Password reset successfully");
    AccountUtil account;
    (*allUsers)[name.toStdString()].setPassword(account.hashText(pass.toStdString()));
}

