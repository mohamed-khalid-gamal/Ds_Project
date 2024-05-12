#pragma once
#include "Transaction.h"
#include "User.h"
#include "Account.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include "Menu.h"

void Account::logIn(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions)
{
	Menu menu;
	std::string name;
	std::string pass;
	std::cout << "~Log In (-1 at any point to go back to main menu)~\n";
	while (true)
	{
		std::cout << "Enter Username : ";
		getline(std::cin, name);
		if (name == "-1") return;
		else if (name.length() < 5 || name.length() > 16) {
			std::cout << "Wrong length please try again.\n";
			continue;
		}
		break;
	}
	int passwordFailTries = 0;
	while (true)
	{
		std::cout << "Enter Password : ";
		getline(std::cin, pass);
		if (pass == "-1") return;
		else if (name == "admin" && pass == "admin") {
				menu.adminMenu(allUsers,allTransactions);
				return;
			}
		else if (hashText(pass) != allUsers[name].getPassword()) {
			std::cout << "Wrong password! Please try again.\n";
			if (++passwordFailTries > 3) {
				std::cout << "Inputed wrong password too many times\n";
				return;
			}
			continue;
		}
		break;
	}
	menu.userMenu(allUsers.at(name), allUsers,allTransactions);
}

void Account::registerAccount(std::unordered_map<std::string, User>& allUsers)
{
	std::string name;
	std::string pass;
	std::cout << "~Register Account (-1 at any point to go back to main menu)~\n";
	while (true)
	{
		std::cout << "Enter Username : ";
		getline(std::cin, name);
		if (name == "-1") 
			return;
		else if (name.length() < 5 || name.length() > 16) {
			std::cout << "length must be between 5 and 16 please try again.\n";
			continue;
		}
		else if (name == allUsers[name].getUsername()) {
			std::cout << "Username is already taken please try again.\n";
			continue;
		}
		break;
	}
	while (true)
	{
		std::cout << "Enter Password : ";
		getline(std::cin, pass);
		if (pass == "-1")
			return; 
		else if (!User::validPassword(pass)) {
			std::cout << '\n';
			continue;
		}
		break;
	}
	User newUser = User(name, hashText(pass));
	allUsers[name] = newUser;
}

void Account::forgetPassword(std::unordered_map<std::string, User>& allUsers)
{
	std::string name;
	std::string pass;
	std::cout << "~Forget Password (-1 at any point to go back to main menu)~\n";
	while (true)
	{
		std::cout << "Enter Username : ";
		getline(std::cin, name);
		if (name == "-1") return;
		else if (name == allUsers[name].getUsername()) {
			break;
		}
		std::cout << "Username not found, try again!\n";
	}
	while (true)
	{
		std::cout << "Enter Password : ";
		getline(std::cin, pass);
		if (pass == "-1")
			return;
		else if (!User::validPassword(pass)) {
			std::cout << '\n';
			continue;
		}
		break;
	}
	allUsers[name].setPassword(hashText(pass));
}

std::string Account::hashText(std::string pendingText)
{
	int temp = 0;
	std::string hashedText;
	for (int i = 0; i < pendingText.length(); i++) {
		temp += pendingText[i];
	}
	hashedText = std::to_string(temp);
	return hashedText;
}
