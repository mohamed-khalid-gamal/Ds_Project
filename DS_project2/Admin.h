#pragma once
#include <iostream>
#include <string>
#include "User.h"
#include "Menu.h"
using namespace std;

class Admin {
    static const string username;
    static const string password;
public:
    void ListUsers(unordered_map<string, User>& allUsers);
    void EditUser(unordered_map<string, User>& allUsers, stack<Transaction>& allTransactions);
};


const string Admin::username = "admin";
const string Admin::password = "admin";


