#include "transactionhistory.h"
#include "ui_transactionhistory.h"

transactionHistory::transactionHistory(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::transactionHistory)
{
    ui->setupUi(this);
}
transactionHistory::transactionHistory(std::stack<Transaction> allT,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::transactionHistory)
{
    ui->setupUi(this);
    allTransactions = allT;
}

transactionHistory::~transactionHistory()
{
    delete ui;
}

void transactionHistory::on_pushButton_clicked()
{
    QWidget::close();
}

