#include "SaveLoad.h"
#include <unordered_map>
#include <fstream>
using namespace std;

unordered_map<string, User> SaveLoad::loadUsers()
{
	return unordered_map<string, User>();
}

void SaveLoad::saveUsers()
{
}

stack <Transaction> SaveLoad::loadTransactions()
{
	string text;
	stack <Transaction> temp;
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
		temp.push(tmp);
	}
	stack <Transaction> transactions;
	while (!temp.empty())
	{
		transactions.push(temp.top());
		temp.pop();
	}
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
	return;
}