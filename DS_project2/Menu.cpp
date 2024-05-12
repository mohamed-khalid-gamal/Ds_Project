#pragma once
#include <iostream>
#include "Transaction.h"
#include "User.h"
#include "Menu.h"
#include "Account.h"
#include "Admin.h"
Account account;
Admin admin;

void Menu::mainMenu(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions)
{
	int choice;
	while (true) {
		std::cout << "\n~Main Menu~\n"
			<< "(1) Log in\n"
			<< "(2) Register\n"
			<< "(3) Forget Password\n"
			<< "(4) Quit\n"
			<< ">> ";
		std::cin >> choice;
		std::cin.ignore();
		switch (choice) {
		case 1: account.logIn(allUsers, allTransactions); break;
		case 2: account.registerAccount(allUsers); break;
		case 3: account.forgetPassword(allUsers); break;
		case 4: return;
		default: std::cout << "Please enter number from the list."; continue;
		}
	}
}

void Menu::userMenu(User activeUser, std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions)
{
	int choice;
	while (true) {
		std::cout << "\nWelcome " + activeUser.getUsername() + "!\n"
				<< "(1) Check Balance\n"
				<< "(2) Send Money\n"
				<< "(3) Request Money\n"
				<< "(4) User Transaction History\n"
				<< "(5) Pending Transactions\n"
				<< "(6) Reset Pin\n"
				<< "(7) Log out\n"
				<<">> ";
			std::cin >> choice;
			std::cin.ignore();
			switch (choice) {
			case 1: std:: cout << "Balance: " << activeUser.getBalance() << std::endl; continue;
			case 2: activeUser.sendMoney(allUsers,allTransactions); continue;
			case 3: activeUser.requestMoney(allUsers,allTransactions); continue;
			case 4: activeUser.transactionHistory(); continue;
			case 5: activeUser.pendingRequests(allUsers, allTransactions); continue;
			case 6: activeUser.setUserPinMenu(activeUser); continue;
			case 7: return;
			default: std::cout << "Please enter number from the list."; continue;
			}
		}
}

void Menu::adminMenu(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions)
{
	int choice;
	while (true) {
		std::cout << "\nWelcome admin!\n"
			<< "(1) List User\n"
			<< "(2) Edit User\n"
			<< "(3) Log out\n"
			<<">> ";
		std::cin >> choice;
		std::cin.ignore();
		switch (choice) {
		case 1: admin.ListUsers(allUsers); continue;
		case 2: admin.EditUser(allUsers,allTransactions); continue;
		case 3: return;
		default: std::cout << "Please enter number from the list.\n"; continue;
		}
	}
}
