#include <iostream>
#include "Menu.h"
#include "Account.h"
#include "User.h"
using namespace std;
Account account;

void Menu::mainMenu(unordered_map<string, User>& allUsers, stack<Transaction>& allTransactions)
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
		case 4: return;
		default: cout << "Please enter number from the list."; break;
		}
	}
}

void Menu::userMenu(User activeUser, unordered_map<string, User>& allUsers, stack<Transaction>& allTransactions)
{
	int choice;
	while (true) {
			cout << "Welcome " + activeUser.getUsername() + "!"
				<< "(1) Check Balance\n"
				<< "(2) Send Money\n"
				<< "(3) Request Money\n"
				<< "(4) User Transaction History\n"
				<< "(5) Pending Transactions\n"
				<< "(5) Reset Pin\n"
				<< "(6) Quit\n";
			cin >> choice;
			switch (choice) {
			case 1: activeUser.getBalance(); continue;
			case 2: activeUser.sendMoney(allUsers,allTransactions); continue;
			case 3: activeUser.requestMoney(allUsers,allTransactions); continue;
			case 4: activeUser.transactionHistory(); continue;
			case 5: activeUser.pendingRequests(allUsers,allTransactions);
			case 6: activeUser.setUserPinMenu(activeUser); continue;
			case 7: return;
			default: cout << "Please enter number from the list."; break;
			}
		}
}

void Menu::adminMenu(unordered_map<string, User>& allUsers, stack<Transaction>& allTransactions)
{
	cout << "Welcome admin!"
		<< "(1) Log in\n"
		<< "(2) Register\n"
		<< "(3) Forget Password\n"
		<< "(4) Quit\n";
}
