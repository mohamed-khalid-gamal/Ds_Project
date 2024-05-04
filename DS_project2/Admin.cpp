#include "Admin.h"
#include <iostream>
#include "User.h"
#include "Menu.h"
#include "SaveLoad.h"
void Admin::EditUser(unordered_map<string, User>& allUsers) {
	cout << "Enter the username of Account you want to edit :";
	string usernamesearched; getline(cin, usernamesearched);
	User choosen = User::searchUser(usernamesearched, allUsers);
	cout << "(1) change username" << endl;
	cout << "(2) change password" << endl;
	cout << "(3) return to Admin Menu" << endl;
	cout << ">> ";
	int x; cin >> x;
	cin.ignore();
	if (x == 1) {
		choosen.changeUsername(allUsers, true);
	}
	else if (x == 2) {
		choosen.changePassword(allUsers, true);
	}
	else {
		Menu::adminMenu();
	}
	 
}

void ListUsers(unordered_map<string, User>& allUsers){
    for (auto& pair : allUsers){
        cout<< "Username : "<< pair.second.getUsername()<<endl;
        cout<< "current balance : "<< pair.second.getBalance()<<endl;
        cout<< "Transaction History : "<< pair.second.transactionHistory()<<endl;
    }

}
