#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include "Transaction.h"
#include "User.h"
#include "SaveLoad.h"
#include "Menu.h"


int main()
{
	SaveLoad files;
	Menu menu;
	std::stack<Transaction> allTransactions = files.loadTransactions();
	std::unordered_map<std::string, User> allUsers = files.loadUsers(allTransactions);
	menu.mainMenu(allUsers, allTransactions);
	files.saveUsers(allUsers);
	files.saveTransactions(allTransactions);
}