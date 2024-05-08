#pragma once
#include <stack>
#include <unordered_map>
using namespace std;
class User;
class Transaction;

class Menu
{
public:
	void mainMenu(unordered_map<string, User>& allUsers, stack<Transaction>& allTransactions);
	void userMenu(User activeUser, unordered_map<string, User>& allUsers, stack<Transaction>& allTransactions);
	void adminMenu(unordered_map<string, User>& allUsers, stack<Transaction>& allTransactions);
};
