#include "Transaction.h"
#include "User.h"
#include "Account.h"
#include <unordered_map>
#include <string>

User::User(std::string name, std::string pass)
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

std::string User::getUsername(void)
{
	return username;
}
std::string User::getPassword(void)
{
	return password;
}
void User::setPassword(std::string pass)
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
