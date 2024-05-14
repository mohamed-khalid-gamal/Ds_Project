#include "transactionhistory.h"
#include "ui_transactionhistory.h"

transactionHistory::transactionHistory(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::transactionHistory)
{
    ui->setupUi(this);
}

transactionHistory::~transactionHistory()
{
    delete ui;
}
