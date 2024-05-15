#include "edituserswindow.h"
#include "accountutil.h"
#include "ui_edituserswindow.h"
#include "listusers.h"

editUsersWindow::editUsersWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editUsersWindow)
{
        ui->setupUi(this);
}
editUsersWindow::editUsersWindow(std::unordered_map<std::string,User> *allU,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editUsersWindow)
{
    ui->setupUi(this);
    allUsers = allU;
}

editUsersWindow::~editUsersWindow()
{
    delete ui;
    allUsers = NULL;
    delete allUsers;
}

void editUsersWindow::on_pushButton_clicked()
{
    listWin = new listUsers(allUsers,this);
    listWin->show();
}


void editUsersWindow::on_pushButton_4_clicked()
{
    QWidget::close();
}


void editUsersWindow::on_pushButton_2_clicked() // change user
{
    QString oldname = ui->lineEdit->text();
    QString name = ui->lineEdit_2->text();
    QString pass = ui->lineEdit_3->text();
    ui->label_5->setStyleSheet("Color: darkred");
    if ((*allUsers).count(oldname.toStdString()) == 0){
        ui->label_5->setText("Message: User not Found");
    } else {
        ui->label_5->setStyleSheet("Color: darkgreen");
        ui->label_5->setText("Message: Username Changed Succesfully");
        AccountUtil account;
        (*allUsers)[oldname.toStdString()].setUsername(name.toStdString());
        }
 }


void editUsersWindow::on_pushButton_3_clicked() // change pass
{
    QString oldname = ui->lineEdit->text();
    QString name = ui->lineEdit_2->text();
    QString pass = ui->lineEdit_3->text();
    ui->label_5->setStyleSheet("Color: darkred");
    if ((*allUsers).count(oldname.toStdString()) == 0){
        ui->label_5->setText("Message: User not Found");
    }else {
        if(pass.length() < 8 || pass.length() > 16){
            ui->label_5->setText("Message: Invalid Password Length");
        } else {
            ui->label_5->setStyleSheet("Color: darkgreen");
            ui->label_5->setText("Message: Password changed Succesfully");
            AccountUtil account;
            (*allUsers)[oldname.toStdString()].setPassword(account.hashText(pass.toStdString()));
        }
    }
 }

