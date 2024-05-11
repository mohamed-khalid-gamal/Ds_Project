#pragma once
#include <unordered_map>
#include <string>
#include <stack>
class User;
class Transaction;
class Account
{
public:
	void logIn(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions);
	void registerAccount(std::unordered_map<std::string, User>& allUsers);
	void forgetPassword(std::unordered_map<std::string, User>& allUsers);
	std::string hashText(std::string);
};

