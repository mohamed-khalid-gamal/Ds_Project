#pragma once
#include "Transaction.h"
#include "User.h"
#include "Admin.h"
#include "Account.h"
#include <iostream>


void Admin::ListUsers(std::unordered_map<std::string, User>& allUsers) {

	std::unordered_map<std::string, User> updatedUsers;

	for ( auto& pair : allUsers) {
		if (pair.second.getUsername() != "test") {
			updatedUsers[pair.first] = pair.second;
		}
	}
	if (updatedUsers.empty()) {
		std::cout << "No users found." << std::endl;
	}
	else {
		for (auto& pair : updatedUsers) {
			std::cout << "\n~Username: " << pair.second.getUsername() << std::endl;
			std::cout << "~Current balance: " << pair.second.getBalance() << std::endl;
			std::cout << "~Transaction History: ";
			pair.second.transactionHistory();
			std::cout << std::endl;
		}
	}
	updatedUsers.clear();
}
void Admin::EditUser(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions) {
	std::cout << "~Edit users (-1 at any point to go back to main menu)~\n";
	ListUsers(allUsers);
	std::cout << "Enter the username of Account you want to edit : ";
	std::string usernamesearched; 
	getline(std::cin, usernamesearched);
	if (usernamesearched == "-1")
		return;
	User choosen = User::searchUser(usernamesearched, allUsers);
	if (choosen.getUsername() != "test") {
		std::cout << "(1) change username" << std::endl;
		std::cout << "(2) change password" << std::endl;
		std::cout << "(3) return to Admin Menu" << std::endl;
		std::cout << ">> ";
		int x;
		std::cin >> x;
		std::cin.ignore();
		if (x == 1) {
			choosen.changeUsername(allUsers, allTransactions);
		}
		else if (x == 2) {
			choosen.changePassword(allUsers, allTransactions);
		}
		else {
			return;
		}
	}
	
	 
}
