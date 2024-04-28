#pragma once
#include <vector>
#include <unordered_map>
using namespace std;
class User;
class Transaction;

class Menu
{
public:
	void mainMenu(unordered_map<string, User>& allUsers, vector<Transaction>& allTransactions);
	void userMenu(User activeUser, unordered_map<string, User>& allUsers);
	void adminMenu();
};
