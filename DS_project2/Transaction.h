#pragma once
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Transaction
{
	int id;
	float tran_amount;
	string sender;
	string recipient;
	string datePlaceHolder; //Placeholder for the person who works on transactions class
	bool isAccepted; //If accepted transaction will appear on the user's transactions instead of user's requests (less space than having several arrays for requests and transactions
public:
	Transaction();
	Transaction(string sendUser, string recieveUser);
	void setid(int i);
	void setsender(string nsender);
	void setrecipient(string nrecipient);
	void setdatePlaceHolder(string ndatePlaceHolder);
	void setisAccepted(bool nisAccepted);
	void setAmount(float);
	Transaction(string sendUser, string recieveUser, stack<Transaction>& allTransactions);
	void listTransactions(stack<Transaction> transactions); //Displays a list of all transactions
	string getsender();
	string getrecipient();
	string getdatePlaceHolder();
	int getId();
	float getAmount();
	bool getisAccepted();
	string get_time();
};
