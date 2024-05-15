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
    ui->label_5->setStyleSheet("Color: darkred");
    if ((*allUsers).count(oldname.toStdString()) == 0){
        ui->label_5->setText("Message: User not Found");
    } else {
        ui->label_5->setStyleSheet("Color: darkgreen");
        ui->label_5->setText("Message: Username Changed Succesfully");
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


 void editUsersWindow::on_pushButton_5_clicked()
 {
     QString oldname = ui->lineEdit->text();
     ui->label_5->setStyleSheet("Color: darkred");
     if ((*allUsers).count(oldname.toStdString()) == 0){
         ui->label_5->setText("Message: User not Found");
     } else {
         std::unordered_map<std::string,User>::iterator it = allUsers->find(oldname.toStdString());
         (*allUsers).erase(it);
         ui->label_5->setStyleSheet("Color: darkgreen");
         ui->label_5->setText("Message: User removed Succesfully");
     }
 }


 void editUsersWindow::on_pushButton_6_clicked()
 {
     QString oldname = ui->lineEdit->text();
     ui->label_5->setStyleSheet("Color: darkred");
     if ((*allUsers).count(oldname.toStdString()) == 0){
         ui->label_5->setText("Message: User not Found");
     } else {
         (*allUsers)[oldname.toStdString()].setActive(false);
         ui->label_5->setStyleSheet("Color: darkgreen");
         ui->label_5->setText("Message: User Banned");
     }
 }


 void editUsersWindow::on_pushButton_7_clicked()
 {
     QString oldname = ui->lineEdit->text();
     ui->label_5->setStyleSheet("Color: darkred");
     if ((*allUsers).count(oldname.toStdString()) == 0){
         ui->label_5->setText("Message: User not Found");
     } else {
         (*allUsers)[oldname.toStdString()].setActive(true);
         ui->label_5->setStyleSheet("Color: darkgreen");
         ui->label_5->setText("Message: User Unbanned");
     }
 }

