#pragma once
#include <iostream>
#include <string>
class User;
class Transaction;
class Admin {
    static const std::string username;
    static const std::string password;
public:
    void ListUsers(std::unordered_map<std::string, User>& allUsers);
    void EditUser(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions);
};


const std::string Admin::username = "admin";
const std::string Admin::password = "admin";


