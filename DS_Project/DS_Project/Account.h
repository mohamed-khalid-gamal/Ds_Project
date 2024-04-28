#pragma once
#include <unordered_map>
#include <string>
#include "Transaction.h"
#include "User.h"

class Account
{
public:
	void logIn(std::unordered_map<std::string, User>& allUsers, std::vector<Transaction>& allTransactions);
	void registerAccount(std::unordered_map<std::string, User>& allUsers);
	void forgetPassword(std::unordered_map<std::string, User>& allUsers);
	void hashPassword();
};

