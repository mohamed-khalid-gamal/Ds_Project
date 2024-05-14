#include "sendmoneywindow.h"
#include "ui_sendmoneywindow.h"

sendMoneyWindow::sendMoneyWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::sendMoneyWindow)
{
    ui->setupUi(this);
}

sendMoneyWindow::~sendMoneyWindow()
{
    delete ui;
}
