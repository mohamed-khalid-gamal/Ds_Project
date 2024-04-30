#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "User.h"
#include "Transaction.h"
class SaveLoad
{
public:
	std::unordered_map<std::string, User> loadUsers();
	void saveUsers();
	std::vector<Transaction> loadTransactions();
	void saveTransactions();

};

