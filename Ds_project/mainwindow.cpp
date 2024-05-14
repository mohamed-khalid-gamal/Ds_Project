#include "mainwindow.h"
#include "adminwindow.h"
#include "registerwindow.h"
#include "ui_mainwindow.h"
#include "accountutil.h"
#include "userwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::MainWindow(std::unordered_map<std::string,User> *allU,std::stack<Transaction> *allT,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    allTransactions = allT;
    allUsers = allU;
}

MainWindow::~MainWindow()
{
    delete ui;
    allUsers = NULL;
    allTransactions = NULL;
    delete allUsers;
    delete allTransactions;
}

void MainWindow::on_pushButton_4_clicked()
{
    QWidget::close();
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
