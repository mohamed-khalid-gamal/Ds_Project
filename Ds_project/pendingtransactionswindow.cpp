#include "pendingtransactionswindow.h"
#include "ui_pendingtransactionswindow.h"

pendingTransactionsWindow::pendingTransactionsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::pendingTransactionsWindow)
{
    ui->setupUi(this);
}

pendingTransactionsWindow::~pendingTransactionsWindow()
{
    delete ui;
}
