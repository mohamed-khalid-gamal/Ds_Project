#include <iostream>
#include <vector>
#include <unordered_map>
#include "Transaction.h"
#include "User.h"
#include "SaveLoad.h"
#include "Menu.h"


int main()
{
	SaveLoad file;
	Menu menu;
	std::unordered_map<std::string, User> allUsers;
	std::vector<Transaction> allTransactions;
	menu.mainMenu(allUsers, allTransactions);
	file.saveUsers();
}