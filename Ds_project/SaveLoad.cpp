#pragma once
#include <unordered_map>
#include <Qfile>
#include <QTextStream>
#include "Transaction.h"
#include "User.h"
#include "SaveLoad.h"
#include <QDir>
template <typename T>
std::stack <T> SaveLoad::reverseStack(std::stack <T> orig){
    std::stack <T> reversed;
    while (!orig.empty())
    {
        reversed.push(orig.top());
        orig.pop();
    }
    return reversed;
}

std::unordered_map<std::string, User> SaveLoad::loadUsers(std::stack<Transaction> allTransaction)
{

    QFile file("./users.txt");
    if (!file.exists()){
        std::unordered_map<std::string,User>* usersT = new std::unordered_map<std::string,User>;
        return *usersT;
    }
    if (!file.open(QFile::ReadOnly | QFile::Text)){

    }
    std::unordered_map<std::string, User> users;
    User temp;
    std::stack <Transaction> allTrans;
    Transaction tmp;
    QTextStream ifile(&file);
    QString text;
    while (!ifile.atEnd())
    {
        allTrans = allTransaction;
        text = ifile.readLine();
        std::string username = text.toStdString();
        temp.setUsername(text.toStdString());
        text = ifile.readLine();
        temp.setPassword(text.toStdString());
        text = ifile.readLine();
        temp.setBalance(stof(text.toStdString()));
        text = ifile.readLine();
        temp.setPin(text.toStdString());
        text = ifile.readLine();
        temp.setActive((bool)stoi(text.toStdString()));
        while(!allTrans.empty()){
            tmp = allTrans.top();
            if (tmp.getsender() == username || tmp.getrecipient() == username) {
                temp.setTransaction(tmp);
            }
            allTrans.pop();
         }
        users.insert(make_pair(temp.getUsername(), temp));
        temp = User();
    }
    file.close();
    return users;
}

void SaveLoad::saveUsers(std::unordered_map<std::string, User> users)
{
    QFile file("./users.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text)){

    }
    QTextStream out(&file);
    std::unordered_map<std::string, User>::iterator it;
    it = users.begin();
    std::string temp;
    while(it != users.end())
    {
        temp = it->second.getUsername();
        out << QString::fromStdString(temp) << "\n";
        temp = it->second.getPassword();
        out << QString::fromStdString(temp) << "\n";
        temp = std::to_string(it->second.getBalance());
        out << QString::fromStdString(temp) << "\n";
        temp = it->second.getPin();
        out << QString::fromStdString(temp) << "\n";
        temp = std::to_string(it->second.getActive());
        out << QString::fromStdString(temp) << "\n";
        it++;
    }
    file.flush();
    file.close();
}

std::stack <Transaction> SaveLoad::loadTransactions()
{
    QString text;
    std::stack <Transaction> transactions;
    QFile file("./transactions.txt");
    if (!file.exists()){
        std::stack<Transaction>* transactionsT = new std::stack<Transaction>;
        return *transactionsT;
    }
    if (!file.open(QFile::ReadOnly | QFile::Text)){

    }
    QTextStream ifile(&file);
    while (!ifile.atEnd())
    {
        Transaction tmp;
        text = ifile.readLine();
        tmp.setid(std::stoi(text.toStdString()));
        text = ifile.readLine();
        tmp.setAmount(std::stof(text.toStdString()));
        text = ifile.readLine();
        tmp.setsender(text.toStdString());
        text = ifile.readLine();
        tmp.setrecipient(text.toStdString());
        text = ifile.readLine();
        tmp.setdatePlaceHolder(text.toStdString());
        text = ifile.readLine();
        bool bol = (bool)stoi(text.toStdString());
        tmp.setisAccepted(bol);
        transactions.push(tmp);
    }
    file.close();
    return transactions;
}

void SaveLoad::saveTransactions(std::stack <Transaction> transactions)
{
    QFile file("./transactions.txt");
    if (!file.open(QFile::WriteOnly | QFile::Text)){

    }
    QTextStream ofile(&file);
    std::stack <Transaction> temp = reverseStack(transactions);
    while (!temp.empty())
    {
        Transaction tmp = temp.top();
        ofile << QString::fromStdString(std::to_string(tmp.getId())) << "\n" << QString::fromStdString(std::to_string(tmp.getAmount())) << "\n"
              << QString::fromStdString(tmp.getsender()) << "\n"<< QString::fromStdString(tmp.getrecipient()) << "\n"
              << QString::fromStdString(tmp.getdatePlaceHolder()) << "\n" << QString::fromStdString(std::to_string(tmp.getisAccepted())) << "\n";
        temp.pop();
    }
    file.close();
}
