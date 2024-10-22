#pragma once
#include <unordered_map>
#include <fstream>
#include "Transaction.h"
#include "User.h"
#include "SaveLoad.h"
template <typename T>
std::stack <T> SaveLoad::reverseStack(std::stack <T> orig)
{
	std::stack <T> reversed;
	while (!orig.empty())
	{
		reversed.push(orig.top());
		orig.pop();
	}
	return reversed;
}

std::unordered_map<std::string, User> SaveLoad::loadUsers(std::stack<Transaction> allTransaction)
{
	std::unordered_map<std::string, User> users;
	User temp;
	std::stack <Transaction> userTrans;
	Transaction tmp;
	int size;
	std::ifstream ifile("users.txt");
	if (!ifile.is_open())
	{
		ifile.close();
		std::ofstream ofile("users.txt");
		ofile.close();
		return users;
	}
	std::string text;
	while (getline(ifile, text))
	{
		std::stack <Transaction> tempTrans = allTransaction;
		temp.setUsername(text);
		getline(ifile, text);
		temp.setPassword(text);
		getline(ifile, text);
		temp.setBalance(stof(text));
		getline(ifile, text);
		temp.setPin(text);
		getline(ifile, text);
		temp.setActive((bool)stoi(text));
		if (!allTransaction.empty()) {
			for (int i = 0; i < allTransaction.size(); i++)
			{
				if (tempTrans.top().getsender() == temp.getUsername() || tempTrans.top().getrecipient() == temp.getUsername()) {
					userTrans.push(tempTrans.top());
				}
				tempTrans.pop();
			}
			userTrans = reverseStack(userTrans);
			temp.setTransactions(userTrans);
		}
		users.insert(make_pair(temp.getUsername(), temp));
	}
	ifile.close();
	return users;
}

void SaveLoad::saveUsers(std::unordered_map<std::string, User> users)
{
	std::ofstream ofile("users.txt");
	for (auto i = users.begin(); i != users.end(); i++)
	{
		// std::stack<Transaction> userTrans = i->second.getTransactions();
		ofile << i->first << std::endl << i->second.getPassword() << std::endl << i->second.getBalance() << std::endl
			<< i->second.getPin() << std::endl << i->second.getActive() << std::endl; /* << userTrans.size() << std::endl;
	while (!userTrans.empty())
		{
			ofile << userTrans.top().getId() << std::endl;
			userTrans.pop();
			ofile << userTrans.top().getsender() << std::endl;
			userTrans.pop();
			ofile << userTrans.top().getrecipient() << std::endl;
			userTrans.pop();
			ofile << userTrans.top().getdatePlaceHolder() << std::endl;
			userTrans.pop();
			ofile << userTrans.top().getisAccepted() << std::endl;
			userTrans.pop();
		}
*/
	}
	ofile.close();
}

std::stack <Transaction> SaveLoad::loadTransactions()
{
	std::string text;
	std::stack <Transaction> transactions;
	std::ifstream ifile("transactions.txt");
	if (!ifile.is_open())
	{
		ifile.close();
		std::ofstream ofile("transactions.txt");
		ofile.close();
		return transactions;
	}
	while (getline(ifile, text))
	{
		Transaction tmp;
		tmp.setid(stoi(text));
		getline(ifile, text);
		tmp.setAmount(stoi(text));
		getline(ifile, text);
		tmp.setsender(text);
		getline(ifile, text);
		tmp.setrecipient(text);
		getline(ifile, text);
		tmp.setdatePlaceHolder(text);
		getline(ifile, text);
		bool bol = (bool)stoi(text);
		tmp.setisAccepted(bol);
		transactions.push(tmp);
	}
	transactions = reverseStack(transactions);
	ifile.close();
	return transactions;
}

void SaveLoad::saveTransactions(std::stack <Transaction> transactions)
{
	std::ofstream ofile("transactions.txt");
	std::stack <Transaction> temp = transactions;
	while (!temp.empty())
	{
		Transaction tmp = temp.top();
		ofile << tmp.getId() << std::endl << tmp.getAmount() << std::endl << tmp.getsender() << std::endl << tmp.getrecipient() << std::endl
			<< tmp.getdatePlaceHolder() << std::endl << tmp.getisAccepted() << std::endl;
		temp.pop();
	}
	ofile.close();
}
