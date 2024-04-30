#include "Transaction.h"
#include "User.h"
#include "Account.h"
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

void User::changePassword(void)
{
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
