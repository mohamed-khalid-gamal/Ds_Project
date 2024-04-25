#pragma once
#include <vector>
#include <unordered_map>
class User;
class Transaction;

class Menu
{
public:
	void mainMenu(std::unordered_map<std::string, User>& allUsers, std::vector<Transaction>& allTransactions);
	void userMenu(User activeUser, std::unordered_map<std::string, User>& allUsers);
	void adminMenu();
};
