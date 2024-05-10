#pragma once
#include <string>
#include <stack>
class Transaction{
	int id;
	float tran_amount;
	std::string sender;
	std::string recipient;
	std::string datePlaceHolder; //Placeholder for the person who works on transactions class
	bool isAccepted; //If accepted transaction will appear on the user's transactions instead of user's requests (less space than having several arrays for requests and transactions
public:
	Transaction();
	Transaction(std::string sendUser, std::string recieveUser);
	void setid(int i);
	void setsender(std::string nsender);
	void setrecipient(std::string nrecipient);
	void setdatePlaceHolder(std::string ndatePlaceHolder);
	void setisAccepted(bool nisAccepted);
	void setAmount(float);
	Transaction(std::string sendUser, std::string recieveUser, std::stack<Transaction>& allTransactions);
	void listTransactions(std::stack<Transaction> transactions); //Displays a list of all transactions
	std::string getsender();
	std::string getrecipient();
	std::string getdatePlaceHolder();
	int getId();
	float getAmount();
	bool getisAccepted();
	std::string get_time();
};
