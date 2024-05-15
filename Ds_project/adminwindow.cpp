#include "adminwindow.h"
#include "ui_adminwindow.h"

adminwindow::adminwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminwindow)
{
    ui->setupUi(this);
}
adminwindow::adminwindow(std::unordered_map<std::string,User> *allU,std::stack<Transaction> *allT,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::adminwindow)
{
    ui->setupUi(this);
    allUsers = allU;
    allTransactions = allT;
}


adminwindow::~adminwindow()
{
    delete ui;
    allUsers = NULL;
    allTransactions = NULL;
    delete allUsers;
    delete allTransactions;
}


void adminwindow::on_pushButton_3_clicked() //Log out button
{
    QWidget::close();
}

void adminwindow::on_pushButton_clicked() //List Users Button
{
    listWin = new listUsers(allUsers,this);
    listWin->show();
}


void adminwindow::on_pushButton_2_clicked() // Edit Users Button
{
    editWin = new editUsersWindow(allUsers,this);
    editWin->show();
}


void adminwindow::on_pushButton_4_clicked()
{

}

