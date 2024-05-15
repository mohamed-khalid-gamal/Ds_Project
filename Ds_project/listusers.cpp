#include "listusers.h"
#include "ui_listusers.h"
#include <ostream>

listUsers::listUsers(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::listUsers)
{
    ui->setupUi(this);
}

listUsers::listUsers(std::unordered_map<std::string,User> *allU,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::listUsers)
{
    ui->setupUi(this);
    allUsers = allU;
    ui->label->setText(getUsers());
}

listUsers::~listUsers()
{
    delete ui;
    allUsers = NULL;
    delete allUsers;
}

void listUsers::on_pushButton_clicked()
{
    close();
}


void listUsers::on_pushButton_2_clicked()
{
    ui->label->setText(getUsers());
}

QString listUsers::getUsers() {
    QString text;
    std::unordered_map<std::string,User>::iterator it;
    it = (*allUsers).begin();
    while (it != (*allUsers).end()){
        if (it->second.getUsername() == "test"){
            it++;
            continue;
        }
        text+="\n~Username: " + it->second.getUsername() + "\n";
        std::string tmpBalance = std::to_string(it->second.getBalance());
        text+= "~Current balance: " + QString::fromStdString(tmpBalance) + "\n";
        text+="~Transaction History: \n";
        text+= it->second.transactionHistory() + "\n";
        it++;
    }
    return text;
}
