#include "pendingtransactionswindow.h"
#include "ui_pendingtransactionswindow.h"

pendingTransactionsWindow::pendingTransactionsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::pendingTransactionsWindow)
{
    ui->setupUi(this);
}

pendingTransactionsWindow::pendingTransactionsWindow(std::unordered_map<std::string,User> *allU,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::pendingTransactionsWindow)
{
    ui->setupUi(this);
    allUsers = allU;
}
pendingTransactionsWindow::~pendingTransactionsWindow()
{
    delete ui;
    allUsers = NULL;
    delete allUsers;
}
