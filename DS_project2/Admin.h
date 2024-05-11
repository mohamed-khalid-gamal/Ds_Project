#pragma once
#include <iostream>
#include <string>
class User;
class Transaction;
class Admin {
public:
    void ListUsers(std::unordered_map<std::string, User>& allUsers);
    void EditUser(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions);
};



