#include "SaveLoad.h"
#include <unordered_map>


std::unordered_map<std::string, User> SaveLoad::loadUsers()
{
	return std::unordered_map<std::string, User>();
}

void SaveLoad::saveUsers()
{
}

std::vector<Transaction> SaveLoad::loadTransactions()
{
	return std::vector<Transaction>();
}


void SaveLoad::saveTransactions()
{
}
