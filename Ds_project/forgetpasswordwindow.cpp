#include "forgetpasswordwindow.h"
#include "ui_forgetpasswordwindow.h"

forgetPasswordWindow::forgetPasswordWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::forgetPasswordWindow)
{
    ui->setupUi(this);
}

forgetPasswordWindow::~forgetPasswordWindow()
{
    delete ui;
}
