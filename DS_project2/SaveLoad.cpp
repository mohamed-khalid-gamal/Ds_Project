#include "SaveLoad.h"
#include <unordered_map>
#include <fstream>
using namespace std;

template <typename T>
stack <T> SaveLoad::reverseStack(stack <T> orig)
{
	stack <T> reversed;
	while (!orig.empty())
	{
		reversed.push(orig.top());
		orig.pop();
	}
	return reversed;
}

unordered_map<string, User> SaveLoad::loadUsers()
{
	unordered_map<string, User> users;
	User temp;
	stack <Transaction> userTrans;
	Transaction tmp;
	int size;
	ifstream ifile("data files/users.txt");
	string text;
	while (getline(ifile, text))
	{
		temp.setUsername(text);
		getline(ifile, text);
		temp.setPassword(text);
		getline(ifile, text);
		temp.setBalance(stoi(text));
		getline(ifile, text);
		temp.setPin(text);
		getline(ifile, text);
		temp.setActive((bool)stoi(text));
		getline(ifile, text);
		size = stoi(text);
		for (int i = 0; i < size; i++)
		{
			getline(ifile, text);
			tmp.setid(text);
			getline(ifile, text);
			tmp.setsender(text);
			getline(ifile, text);
			tmp.setrecipient(text);
			getline(ifile, text);
			tmp.setdatePlaceHolder(text);
			getline(ifile, text);
			tmp.setisAccepted((bool)stoi(text));
			userTrans.push(tmp);
		}
		userTrans = reverseStack(userTrans);
		temp.setTransactions(userTrans);
		users.insert(make_pair(temp.getUsername(), temp));
	}
	ifile.close();
	return users;
}

void SaveLoad::saveUsers(unordered_map<string, User> users)
{
	ofstream ofile("data files/users.txt");
	for (auto i = users.begin(); i != users.end(); i++)
	{
		stack<Transaction> userTrans = i->second.getTransactions();
		ofile << i->first << endl << i->second.getPassword() << endl << i->second.getBalance()<< endl 
			<< i->second.getPin() << endl << i->second.getActive() << endl << userTrans.size() << endl;
		while (!userTrans.empty())
		{
			ofile << userTrans.top().getid() << endl;
			userTrans.pop();
			ofile << userTrans.top().getsender() << endl;
			userTrans.pop();
			ofile << userTrans.top().getrecipient() << endl;
			userTrans.pop();
			ofile << userTrans.top().getdatePlaceHolder() << endl;
			userTrans.pop();
			ofile << userTrans.top().getisAccepted() << endl;
			userTrans.pop();
		}
		
	}
	ofile.close();
}

stack <Transaction> SaveLoad::loadTransactions()
{
	string text;
	stack <Transaction> transactions;
	ifstream ifile("data files/transactions.txt");
	while (getline(ifile, text))
	{
		Transaction tmp;
		tmp.setid(text);
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

void SaveLoad::saveTransactions(stack <Transaction> transactions)
{
	ofstream ofile("data files/transactions.txt");
	stack <Transaction> temp = transactions;
	while (!temp.empty())
	{
		Transaction tmp = transactions.top();
		ofile << tmp.getid() << endl << tmp.getsender() << endl << tmp.getrecipient() << endl
			<< tmp.getdatePlaceHolder() << endl << tmp.getisAccepted() << endl;
		temp.pop();
	}
	ofile.close();
}