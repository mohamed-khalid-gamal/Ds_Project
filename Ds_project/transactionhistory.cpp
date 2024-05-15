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
    ui->label->setText(getTransactions());
}

transactionHistory::~transactionHistory()
{
    delete ui;
}

void transactionHistory::on_pushButton_clicked()
{
    QWidget::close();
}


void transactionHistory::on_pushButton_2_clicked()
{
    ui->label->setText(getTransactions());
}


QString transactionHistory::getTransactions() {
    QString text;
    std::string stringT;
    std::stack<Transaction> allT = allTransactions;
    if (allT.empty()){
        text = "No Transactions found.";
        return text;
    }
    while(!(allT.empty())){
        Transaction temp = allT.top();
        text+= "\nTransaction ID : ";
        text+= QString::fromStdString(std::to_string(temp.getId())) + "\n";
        text+= "Transaction amount : ";
        text+=  QString::fromStdString(std::to_string(temp.getAmount())) + "\n";
        text+= "Sender : ";
        text+=temp.getsender() + "\n";
        text+="Recipient : ";
        text+= temp.getrecipient() + "\n";
        text+= "Date : ";
        text+= temp.getdatePlaceHolder() + "\n";
        text+= "Accepted : ";
        if (temp.getisAccepted()){
            stringT = "Yes";
        } else {
            stringT = "No";
        }
        text+= QString::fromStdString(stringT) + "\n";
        allT.pop();
    }
    return text;
}
