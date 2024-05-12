#include "mainwindow.h"
#include "registerwindow.h"
#include "ui_mainwindow.h"
#include "SaveLoad.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SaveLoad file;
    allTransactions = file.loadTransactions();
    allUsers = file.loadUsers(allTransactions);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    SaveLoad file;
    file.saveUsers(allUsers);
    file.saveTransactions(allTransactions);
    QWidget::close();
}


void MainWindow::on_pushButton_2_clicked()
{
    registerwindow regwin(allUsers,allTransactions,this);
    hide();
    regwin.setModal(true);
    regwin.exec();
    show();
}

