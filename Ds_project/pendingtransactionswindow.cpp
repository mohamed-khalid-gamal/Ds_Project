#include "pendingtransactionswindow.h"
#include "ui_pendingtransactionswindow.h"
#include "SaveLoad.h"

pendingTransactionsWindow::pendingTransactionsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::pendingTransactionsWindow)
{
    ui->setupUi(this);
}

pendingTransactionsWindow::pendingTransactionsWindow(QString activeU,std::unordered_map<std::string,User>* allU,std::stack<Transaction> allT,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::pendingTransactionsWindow)
{
    ui->setupUi(this);
    allTransactions = allT;
    activeUser = activeU;
    allUsers = allU;
    ui->label->setText(getPendingTransactions());
}
pendingTransactionsWindow::~pendingTransactionsWindow()
{
    delete ui;
    allUsers = NULL;
    delete allUsers;
}

void pendingTransactionsWindow::on_pushButton_clicked()
{
    close();
}


void pendingTransactionsWindow::on_pushButton_4_clicked()
{
    ui->label->setText(getPendingTransactions());
}

QString pendingTransactionsWindow::getPendingTransactions(){
    QString text;
    std::string stringT;
    std::stack<Transaction> allT = allTransactions;
    if (allT.empty()){
        text = "No Transactions found.";
        return text;
    }
    while(!(allT.empty())){
        Transaction temp = allT.top();
        if(temp.getisAccepted()){
            allT.pop();
            continue;
        }
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


void pendingTransactionsWindow::on_pushButton_2_clicked()
{
    QString tranID = ui->lineEdit->text();
    std::stack<Transaction> tempUserTransactions = (*allUsers)[activeUser.toStdString()].getTransactions();
    std::stack<Transaction> tempUserTransactions2 = tempUserTransactions;
    while (!tempUserTransactions.empty()) {
        if(tranID.toInt() == tempUserTransactions.top().getId()){
            tempUserTransactions.top().setisAccepted(true);
        }
        tempUserTransactions2.push(tempUserTransactions.top());
        tempUserTransactions.pop();
    }
    tempUserTransactions2 = SaveLoad::reverseStack(tempUserTransactions2);
    (*allUsers)[activeUser.toStdString()].setTransactions(tempUserTransactions2);
}

