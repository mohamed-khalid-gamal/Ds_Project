#include "Transaction.h"
#include "User.h"
#include "Account.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
using namespace std;

User::User(string name, string pass)
{
	username = name;
	password = pass;
	balance = 50;
	pin = "000000";
	is_active = true;
}

User::User()
{
	username = "test";
	password = "test 2";
	pin = "000000";
	balance = 0;
	is_active = false;
}



string User::getUsername(void)
{
	return username;
}
string User::getPassword(void)
{
	return password;
}
void User::setPassword(string pass)
{
	password = pass;
}
void User::sendMoney(void)
{
}

void User::requestMoney(void)
{
}

void User::changePassword(unordered_map<string, User>& allUsers, bool admin = false) {
    if (admin == true) {
        cout << endl << "Enter new password : ";
        string newPassword; getline(cin, newPassword);
        if (!validPassword(newPassword)) {
            system("pause"); system("cls");
            cout << endl << "             (1) reEnter your new password                   ";
            cout << endl << "             other to return to admin menu                     ";
            int x; cin >> x;
            cin.ignore();
            if (x == 1) {
                system("pause"); system("cls");
                changePassword(allUsers, true);
            }
            else {
                system("pause"); system("cls");
                Menu::adminMenu();
                //Menu::userMenu(allUsers[this->username], allUsers);
                //both are correct
            }

        }
        else {
            this->password = newPassword;
            cout << "password has been changed ! " << endl;
            system("pause"); system("cls");
            Menu::adminMenu();
            //Menu::userMenu(allUsers[this->username], allUsers);
        }
    }
    else {
        cout << "Enter current password : ";
        string password; getline(cin, password);
        if (this->password == password) {
            cout << endl << "Enter new password : ";
            string newPassword; getline(cin, newPassword);
            if (!validPassword(newPassword)) {
                system("pause"); system("cls");
                cout << endl << "             (1) reEnter your new password                    ";
                cout << endl << "             other to return to user menu                     ";
                int x; cin >> x;
                cin.ignore();
                if (x == 1) {
                    system("pause"); system("cls");
                    changePassword(allUsers);
                }
                else {
                    system("pause"); system("cls");
                    Menu::userMenu(*this, allUsers);
                    //Menu::userMenu(allUsers[this->username], allUsers);
                    //both are correct
                }

            }
            else {
                this->password = newPassword;
                cout << "password has been changed ! " << endl;
                system("pause"); system("cls");
                Menu::userMenu(*this, allUsers);
                //Menu::userMenu(allUsers[this->username], allUsers);
            }
        }
        else {
            cout << "Wrong password !" << endl;
            system("pause"); system("cls");
            cout << endl << "             (1) reEnter your password                   ";
            cout << endl << "             other to return to user menu                     ";
            int x; cin >> x;
            cin.ignore();
            if (x == 1) {
                system("pause"); system("cls");
                changePassword(allUsers);
            }
            else {
                system("pause"); system("cls");
                Menu::userMenu(*this, allUsers);
                //Menu::userMenu(allUsers[this->username], allUsers);
                //both are correct
            }
        }

    }
}
bool User::validPassword(string password) {
    if (password.length() < 8) {
        cout << "Password must be at least 8 characters long." << endl;
        return false;
    }
    bool hasUpperCase = false;
    for (char c : password) {
        if (isupper(c)) {
            hasUpperCase = true;
            break;
        }
    }
    if (!hasUpperCase) {
        cout << "Password must contain at least one uppercase letter." << endl;
        return false;
    }
    bool hasLowerCase = false;
    for (char c : password) {
        if (islower(c)) {
            hasLowerCase = true;
            break;
        }
    }
    if (!hasLowerCase) {
        cout << "Password must contain at least one lowercase letter." << endl;
        return false;
    }
    bool hasDigit = false;
    for (char c : password) {
        if (isdigit(c)) {
            hasDigit = true;
            break;
        }
    }
    if (!hasDigit) {
        cout << "Password must contain at least one digit." << endl;
        return false;
    }
    bool hasSpecialChar = false;
    for (char c : password) {
        if (!isalnum(c)) {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) {
        cout << "Password must contain at least one special character." << endl;
        return false;
    }
    return true;
}
void User::changeUsername(unordered_map<string, User>& allUsers,bool admin = false) {
    if (admin == false) {
        system("pause"); system("cls");
        cout << "Enter new Username : ";
        string username; getline(cin, username);
        auto it = allUsers.find(username);
        if (it != allUsers.end()) {
            this->username = username;
        }
        else {
            cout << "This username is taken !" << endl << "Try another one" << endl;
            system("pause"); system("cls");
            cout << endl << "             (1) reEnter new username                   ";
            cout << endl << "             other to return to user menu                     ";
            int x; cin >> x;
            cin.ignore();
            if (x == 1) {
                system("pause"); system("cls");
                changePassword(allUsers);
            }
            else {
                system("pause"); system("cls");
                Menu::userMenu(*this, allUsers);
                //Menu::userMenu(allUsers[this->username], allUsers);
                //both are correct
            }
        }
        system("pause");
    }
    else if (admin == true) {
        system("pause"); system("cls");
        cout << "Enter new Username : ";
        string username; getline(cin, username);
        auto it = allUsers.find(username);
        if (it != allUsers.end()) {
            this->username = username;
        }
        else {
            cout << "This username is taken !" << endl << "Try another one" << endl;
            system("pause"); system("cls");
            cout << endl << "             (1) reEnter new username                   ";
            cout << endl << "             other to return to admin menu                     ";
            int x; cin >> x;
            cin.ignore();
            if (x == 1) {
                system("pause"); system("cls");
                changeUsername(allUsers,true);
            }
            else {
                system("pause"); system("cls");
                Menu::adminMenu();
                //Menu::userMenu(allUsers[this->username], allUsers);
                //both are correct
            }
        }
        system("pause");
    }
}

void User::pendingRequests(void)
{
}

void User::transactionHistory(void)
{
}



User User::searchUser(string uname, set <User> users)
{
	set <User> ::iterator it;
	it = users.begin();
	while (it != users.end())
	{
		if (uname == it->username)
			return *it;
		it++;
	}
	cout << "User not found\n";
	return User();
}

User User::searchUser(string uname, unordered_map <string, User> users)
{
	auto it = users.find(uname);
	if (it != users.end())
		return it->second;
	else
	{
		cout << "User not found\n";
		return User();
	}
}

void User::removeUser(string uname, set <User> users)
{
	set <User> ::iterator it;
	while (it != users.end())
	{
		if (uname == it->username)
		{
			users.erase(it);
			return;
		}
		it++;
	}
	cout << "User not found\n";
	return;
}
