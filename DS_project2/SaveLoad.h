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
	static stack <Transaction> loadTransactions();
	static void saveTransactions(stack <Transaction> transactions);
};
