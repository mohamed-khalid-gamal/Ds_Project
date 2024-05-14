#include "resetpinwindow.h"
#include "ui_resetpinwindow.h"

resetPinWindow::resetPinWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::resetPinWindow)
{
    ui->setupUi(this);
}

resetPinWindow::~resetPinWindow()
{
    delete ui;
}
