#include "Account.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include "User.h"
#include "Menu.h"
using namespace std;
void Account::logIn(unordered_map<string, User>& allUsers, vector<Transaction>& allTransactions)
{
	Menu menu;
	string name;
	string pass;
	cout << "~Log In (-1 at any point to go back to main menu)~\n";
	while (true)
	{
		cout << "Enter Username:\n";
		cin >> name;

		if (name == "-1") return;
		else if (name.length() < 5 || name.length() > 16) {
			cout << "Wrong length please try again.";
			continue;
		}
		break;
	}
	int passwordFailTries = 0;
	while (true)
	{
		cout << "Enter Password:\n";
		cin >> pass;
		cin.ignore();
		if (pass == "-1") return;
		else if (name == "admin" && pass == "admin") {
				menu.adminMenu();
				return;
			}
		else if (pass != allUsers[name].getPassword()) {
			cout << "Wrong password! Please try again.\n" + allUsers[name].getPassword();
			if (++passwordFailTries > 3) {
				cout << "Inputed wrong password too many times";
				return;
			}
			continue;
		}
		break;
	}
	menu.userMenu(allUsers.at(name), allUsers);
}

void Account::registerAccount(unordered_map<string, User>& allUsers)
{
	string name;
	string pass;
	cout << "~Register Account (-1 at any point to go back to main menu)~\n";
	while (true)
	{
		cout << "Enter Username(must between 5 and 16 letters length):\n";
		cin >> name;
		
		if (name == "-1") return;
		else if (name.length() < 5 || name.length() > 16) {
			cout << "Wrong length please try again.";
			continue;
		}
		else if (name == allUsers[name].getUsername()) {
			cout << "Username is already taken please try again.";
			continue;
		}
		break;
	}
	while (true)
	{
		cout << "Enter Password(must between 8 and 16 letters length):\n";
		cin >> pass;
		if (pass.length() < 8 || pass.length() > 16) {
			cout << "Wrong length please try again.";
			continue;
		}
		else if (pass == "-1") return;
		break;
	}
	User newUser = User(name, pass);
	allUsers[name] = newUser;
}

void Account::forgetPassword(unordered_map<string, User>& allUsers)
{
	string name;
	string pass;
	cout << "~Forget Password (-1 at any point to go back to main menu)~\n";
	while (true)
	{
		cout << "Enter Username(must between 5 and 16 letters length):\n";
		cin >> name;

		if (name == "-1") return;
		else if (name == allUsers[name].getUsername()) {
			break;
		}
		cout << "Username not found, try again!\n";
	}
	while (true)
	{
		cout << "Enter Password(must between 8 and 16 letters length):\n";
		cin >> pass;
		if (pass == "-1") return;
		else if (pass.length() < 8 || pass.length() > 16) {
			cout << "Wrong length please try again.";
			continue;
		}
		break;
	}
	allUsers[name].setPassword(pass);
}

void Account::hashPassword()
{
}
