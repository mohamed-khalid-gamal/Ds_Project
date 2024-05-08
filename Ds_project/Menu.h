#define MENU_H
#pragma once
#include <vector>
#include <unordered_map>
#include<string>
using namespace std;
class User;
class Transaction;

class Menu
{
public:
    static void mainMenu(unordered_map<string, User>& allUsers, vector<Transaction>& allTransactions);
    static void userMenu(User activeUser, unordered_map<string, User>& allUsers);
    static void adminMenu();
};
