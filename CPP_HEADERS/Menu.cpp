#include <iostream>
#include "Menu.h"
#include "Account.h"
#include "User.h"
using namespace std;
Account account;

void Menu::mainMenu(unordered_map<string, User>& allUsers, vector<Transaction>& allTransactions)
{
	int choice;
	while (true) {
		cout << "~Main Menu~\n"
			<< "(1) Log in\n"
			<< "(2) Register\n"
			<< "(3) Forget Password\n"
			<< "(4) Quit\n";
		cin >> choice;
		switch (choice) {
		case 1: account.logIn(allUsers, allTransactions); break;
		case 2: account.registerAccount(allUsers); break;
		case 3: account.forgetPassword(allUsers); break;
		case 4: exit(0);
		default: cout << "Please enter number from the list."; break;
		}
	}
}

void Menu::userMenu(User activeUser, unordered_map<string, User>& allUsers)
{
	cout << "Welcome " + activeUser.getUsername() + "!";
	getchar();
}


void Menu::adminMenu()
{
	cout << "Admin menu";
	getchar();
}
