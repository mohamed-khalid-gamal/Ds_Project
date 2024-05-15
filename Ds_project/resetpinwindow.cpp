#include "resetpinwindow.h"
#include "ui_resetpinwindow.h"
#include "Transaction.h"
resetPinWindow::resetPinWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::resetPinWindow)
{
    ui->setupUi(this);
}
resetPinWindow::resetPinWindow(QString actUser, std::unordered_map<std::string,User> *allU,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::resetPinWindow)
{
    ui->setupUi(this);
    allUsers = allU;
    activeUser = actUser;
}

resetPinWindow::~resetPinWindow()
{
    delete ui;
}

void resetPinWindow::on_pushButton_clicked()
{
    close();
}


void resetPinWindow::on_pushButton_2_clicked()
{
    QString oldPin = ui->lineEdit->text();
    QString newPin = ui->lineEdit_2->text();
    if(oldPin.toStdString() != (*allUsers)[activeUser.toStdString()].getPin()){
        ui->label_4->setStyleSheet("color: darkred");
        ui->label_4->setText("Message: Old Pin is incorrect");
    } else {
        if (newPin.length() != 6){
            ui->label_4->setText("Message: Pin must be 6 numbers long");
        }else {
        ui->label_4->setStyleSheet("color: darkgreen");
        ui->label_4->setText("Message: Pin Reset Succesfully");
        (*allUsers)[activeUser.toStdString()].setPin(newPin.toStdString());
        }
    }
}
