#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "User.h"
#include "Transaction.h"
using namespace std;
class SaveLoad
{
public:
	template <typename T>
	static stack <T> reverseStack(stack <T>);
	unordered_map<string, User> loadUsers();
	void saveUsers(unordered_map<string, User> users);
	static stack <Transaction> loadTransactions();
	static void saveTransactions(stack <Transaction> transactions);
};
