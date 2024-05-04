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
    void EditUser(unordered_map<string, User>& allUsers);
    void ListUsers(unordered_map<string, User>& allUsers);
};


const string Admin::username = "admin";
const string Admin::password = "admin";


