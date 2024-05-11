#pragma once
#include "Transaction.h"
#include "User.h"
#include "Admin.h"
#include <iostream>


void Admin::ListUsers(std::unordered_map<std::string, User>& allUsers)
{
	for (auto& pair : allUsers) {
		std::cout << "\n~Username: " << pair.second.getUsername() << std::endl;
		std::cout << "~Current balance: " << pair.second.getBalance() << std::endl;
		std::cout << "~Transaction History: "; pair.second.transactionHistory();
		std::cout << "\n";
	}
}
void Admin::EditUser(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions) {
	std::cout << "Enter the username of Account you want to edit :";
	std::string usernamesearched; 
	getline(std::cin, usernamesearched);
	User choosen = User::searchUser(usernamesearched, allUsers);
	std::cout << "(1) change username" << std::endl;
	std::cout << "(2) change password" << std::endl;
	std::cout << "(3) return to Admin Menu" << std::endl;
	std::cout << ">> ";
	int x; 
	std::cin >> x;
	std::cin.ignore();
	if (x == 1) {
		choosen.changeUsername(allUsers, true, allTransactions);
	}
	else if (x == 2) {
		choosen.changePassword(allUsers, true, allTransactions);
	}
	else {
		return;
	}
	 
}
