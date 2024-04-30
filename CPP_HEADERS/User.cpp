#include "Transaction.h"
#include "User.h"
#include "Account.h"
#include <unordered_map>
#include <string>
using namespace std;
User::User( string name,  string pass)
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
User User::searchUser(string uname, set<User> users)
{
	return User();
}
static User searchUser(string uname, set <User> users)
{
	set <User> ::iterator it;
	it = users.begin();
	while (it != users.end())
	{
		if (strcmp(uname, it->username) == 0)
			return *it;
	}
	cout << "User not found\n";
	return null;
}

sataic User searchUser(string uname, unordered_map <User> users)
{
	User* ptr = users.find(unmae);
	if (ptr != users.end())
		return *ptr;
	else
	{
		cout << "User not found\n";
		return null;
	}
}