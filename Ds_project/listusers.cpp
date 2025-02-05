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
    std::string tmpBan;
    it = (*allUsers).begin();
    bool flag = false;
    while (it != (*allUsers).end()){
        if (it->second.getUsername() == "test"){
            it++;
            continue;
        }
        text+="\n~Username: " + it->second.getUsername() + "\n";
        std::string tmpBalance = std::to_string(it->second.getBalance());
        text+= "~Current balance: " + QString::fromStdString(tmpBalance) + "\n";
        if (it->second.getActive()){
           tmpBan  = "No";
        } else tmpBan = "Yes";
        text+= "~Banned: " + QString::fromStdString(tmpBan) + "\n";
        flag = true;
        it++;
    }
    if (!flag){
        return "No Users found.";
    }
    return text;
}

void listUsers::on_pushButton_3_clicked()
{
    QString user = ui->lineEdit->text();
    std::stack<Transaction> tempT = (*allUsers)[user.toStdString()].getTransactions();
    tranWin = new transactionHistory(tempT,this);
    tranWin->show();
}

