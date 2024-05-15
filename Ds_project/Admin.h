#pragma once
#include <unordered_map>
#include <stack>
#include <string>
#include <QString>
class User;
class Transaction;
class Admin {
public:
    QString ListUsers(std::unordered_map<std::string, User>* allUsers);
    void EditUser(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions);
};



