#include "mainwindow.h"
#include "adminwindow.h"
#include "registerwindow.h"
#include "ui_mainwindow.h"
#include "SaveLoad.h"
#include "accountutil.h"
#include "userwindow.h"

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
    delete allUsers;
    delete allTransactions;
}

void MainWindow::on_pushButton_4_clicked()
{
    SaveLoad file;
    file.saveUsers(*allUsers);
    file.saveTransactions(*allTransactions);
    QWidget::close();
}


void MainWindow::on_pushButton_2_clicked()
{
    registerwindow regwin(allUsers, allTransactions,this);
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

    if(name == "admin" && pass == "admin"){
        logIn("admin");
    }
    if (name == (*this->allUsers)[name].getUsername()){
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
