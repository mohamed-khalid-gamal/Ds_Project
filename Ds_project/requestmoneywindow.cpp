#include "requestmoneywindow.h"
#include "ui_requestmoneywindow.h"

requestMoneyWindow::requestMoneyWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::requestMoneyWindow)
{
    ui->setupUi(this);
}

requestMoneyWindow::~requestMoneyWindow()
{
    delete ui;
}
