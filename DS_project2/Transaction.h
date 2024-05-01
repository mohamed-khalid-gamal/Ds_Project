#pragma once
#include <string>
#include <vector>
#include <stack>
#include "User.h"
using namespace std;

class Transaction
{
	string id;
	string sender;
	string recipient;
	string datePlaceHolder; //Placeholder for the person who works on transactions class
	bool isAccepted; //If accepted transaction will appear on the user's transactions instead of user's requests (less space than having several arrays for requests and transactions
public:
	Transaction();
	Transaction(User sendUser, User recieveUser);
	void setid(string nid);
	void setsender(string nsender);
	void setrecipient(string nrecipient);
	void setdatePlaceHolder(string ndatePlaceHolder);
	void setisAccepted(bool nisAccepted);
	void saveTransactions(stack<Transaction> transactions);
	void listTransactions(vector<Transaction> transactionArr); //Displays a list of all transactions
	string getid();
	string getsender();
	string getrecipient();
	string getdatePlaceHolder();
	bool getisAccepted();
};

