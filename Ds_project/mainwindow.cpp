#include "mainwindow.h"
#include "adminwindow.h"
#include "registerwindow.h"
#include "ui_mainwindow.h"
#include "accountutil.h"
#include "userwindow.h"
#include "forgetpasswordwindow.h"
#include "SaveLoad.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SaveLoad file;
    *allTransactions = file.loadTransactions();
    *allUsers = file.loadUsers(*allTransactions);
}

MainWindow::~MainWindow()
{
    delete ui;
    SaveLoad file;
    file.saveUsers(*allUsers);
    file.saveTransactions(*allTransactions);
    allUsers = NULL;
    allTransactions = NULL;
    delete allUsers;
    delete allTransactions;
}

void MainWindow::on_pushButton_4_clicked()
{
    QApplication::quit();
}


void MainWindow::on_pushButton_2_clicked()
{
    registerwindow regwin(allUsers,this);
    hide();
    regwin.setModal(true);
    regwin.exec();
    show();
}


void MainWindow::on_pushButton_clicked()
{
    QString nameQ = ui->lineEdit->text();
    QString passQ = ui->lineEdit_2->text();
    std::string name = nameQ.toStdString();
    std::string pass = passQ.toStdString();
    AccountUtil account;
    ui->label_5->setStyleSheet("color: darkred");
    if(name == "admin" && pass == "admin"){
        logIn("admin");
    }
    if ((*allUsers).count(name) == 1){
        if(account.hashText(pass) == (*this->allUsers)[name].getPassword()){
            logIn(nameQ);
        } else {
            ui->label_5->setText("Message: Invalid Password");
        }
    } else {
        ui->label_5->setText("Message: Invalid Username");
    }
}

void MainWindow::logIn(QString name){
    userwindow userwindow(name,allUsers,allTransactions,this);
    adminwindow adminwindow(allUsers,allTransactions,this);
    ui->label_5->setStyleSheet("color: darkgreen");
    ui->label_5->setText("Message: No Errors");
    hide();
    if (name == "admin"){
        adminwindow.setModal(true);
        adminwindow.exec();
    } else {
        userwindow.setModal(true);
        userwindow.exec();
    }
    show();

};

void MainWindow::on_pushButton_3_clicked()
{
    forgetPasswordWindow forwin(allUsers,this);
    hide();
    forwin.setModal(true);
    forwin.exec();
    show();
}


void MainWindow::on_pushButton_5_clicked()
{
    if (ui->lineEdit_2->echoMode() == QLineEdit::Normal){
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
        ui->pushButton_5->setText("Show Pass");
    } else {
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
        ui->pushButton_5->setText("Hide Pass");
    }
}

