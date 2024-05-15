#include "resetpinwindow.h"
#include "ui_resetpinwindow.h"

resetPinWindow::resetPinWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::resetPinWindow)
{
    ui->setupUi(this);
}
resetPinWindow::resetPinWindow(std::unordered_map<std::string,User> *allU,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::resetPinWindow)
{
    ui->setupUi(this);
    allUsers = allU;
}

resetPinWindow::~resetPinWindow()
{
    delete ui;
}

void resetPinWindow::on_pushButton_clicked()
{
    close();
}

