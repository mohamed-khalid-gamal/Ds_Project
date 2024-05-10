#pragma once
#include <stack>
#include <unordered_map>
class User;
class Transaction;
class Menu
{
public:
	void mainMenu(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions);
	void userMenu(User activeUser, std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions);
	void adminMenu(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions);
};
