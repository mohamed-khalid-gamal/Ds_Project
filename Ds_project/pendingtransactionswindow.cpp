#include "pendingtransactionswindow.h"
#include "ui_pendingtransactionswindow.h"
#include "SaveLoad.h"

pendingTransactionsWindow::pendingTransactionsWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::pendingTransactionsWindow)
{
    ui->setupUi(this);
}

pendingTransactionsWindow::pendingTransactionsWindow(QString activeU,std::unordered_map<std::string,User>* allU,std::stack<Transaction>* allTP,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::pendingTransactionsWindow)
{
    ui->setupUi(this);
    allTransactionsPointer = allTP;
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
    std::stack<Transaction> allT = (*allUsers)[activeUser.toStdString()].getTransactions();
    bool flag = false;
    while(!(allT.empty())){
        Transaction temp = allT.top();
        if(temp.getisAccepted() || temp.getrecipient() == activeUser.toStdString()){
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
        flag = true;
        allT.pop();
    }
    if(!flag){
        text = "No Transactions found.";
    }
    return text;
}


void pendingTransactionsWindow::on_pushButton_2_clicked()
{
    QString tranID = ui->lineEdit->text();
    std::stack<Transaction> tempUserTransactions = (*allUsers)[activeUser.toStdString()].getTransactions();
    std::stack<Transaction> tempUserTransactions2;
    //Updating user's transactions
    while (!tempUserTransactions.empty()) {
        if(tranID.toInt() == tempUserTransactions.top().getId()
            && (tempUserTransactions.top().getsender() == activeUser.toStdString()))
        {
            tempUserTransactions.top().setisAccepted(true);
            float oldBalance =(*allUsers)[tempUserTransactions.top().getsender()].getBalance();
            float oldBalance2 =(*allUsers)[tempUserTransactions.top().getrecipient()].getBalance();
            (*allUsers)[tempUserTransactions.top().getsender()].setBalance(oldBalance - tempUserTransactions.top().getAmount());
            (*allUsers)[tempUserTransactions.top().getrecipient()].setBalance(oldBalance2 + tempUserTransactions.top().getAmount());
            (*allUsers)[tempUserTransactions.top().getrecipient()].setActive(true);
        }
        tempUserTransactions2.push(tempUserTransactions.top());
        tempUserTransactions.pop();
    }
    (*allUsers)[activeUser.toStdString()].setTransactions(SaveLoad::reverseStack(tempUserTransactions2));
    acceptRequest(*allTransactionsPointer, tranID,activeUser);
}

void pendingTransactionsWindow::acceptRequest(std::stack<Transaction>& allTransactions,QString id,QString actUser){
    std::stack<Transaction> tempAllTransactions = (*allUsers)[activeUser.toStdString()].getTransactions();
    std::stack<Transaction> tempAllTransactions2;
    //Updating alltransactions
    while (!tempAllTransactions.empty()) {
        if(id.toInt() == tempAllTransactions.top().getId()
            && (tempAllTransactions.top().getsender() == actUser.toStdString()))
        {
            tempAllTransactions.top().setisAccepted(true);
        }
        tempAllTransactions2.push(tempAllTransactions.top());
        tempAllTransactions.pop();
    }
    while (!allTransactions.empty()){
        allTransactions.pop();
    }
    while (!tempAllTransactions2.empty()){
        allTransactions.push(tempAllTransactions2.top());
        tempAllTransactions2.pop();
    }
    allTransactions = SaveLoad::reverseStack(allTransactions);
}
