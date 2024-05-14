#pragma once
#include <string>
#include <unordered_map>
#include <stack>
class User;
class Transaction;
class SaveLoad
{
public:
	template <typename T>
	static std::stack <T> reverseStack(std::stack <T>);
	std::unordered_map<std::string, User> loadUsers(std::stack<Transaction> allTransaction);
    void saveUsers(std::unordered_map<std::string, User> users);
	static std::stack <Transaction> loadTransactions();
	static void saveTransactions(std::stack <Transaction> transactions);
};
