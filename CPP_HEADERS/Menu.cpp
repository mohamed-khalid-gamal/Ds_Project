#include <iostream>
#include "Menu.h"
#include "Account.h"
#include "User.h"

Account account;

void Menu::mainMenu(std::unordered_map<std::string, User>& allUsers, std::vector<Transaction>& allTransactions)
{
	int choice;
	while (true) {
		std::cout << "~Main Menu~\n"
			<< "(1) Log in\n"
			<< "(2) Register\n"
			<< "(3) Forget Password\n"
			<< "(4) Quit\n";
		std::cin >> choice;
		switch (choice) {
		case 1: account.logIn(allUsers, allTransactions); break;
		case 2: account.registerAccount(allUsers); break;
		case 3: account.forgetPassword(allUsers); break;
		case 4: exit(0);
		default: std::cout << "Please enter number from the list."; break;
		}
	}
}

void Menu::userMenu(User activeUser, std::unordered_map<std::string, User>& allUsers)
{
	std::cout << "Welcome " + activeUser.getUsername() + "!";
	getchar();
}


void Menu::adminMenu()
{
	std::cout << "Admin menu";
	getchar();
}
