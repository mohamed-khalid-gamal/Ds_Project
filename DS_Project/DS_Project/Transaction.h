#pragma once
#include <string>
#include <vector>
#include "User.h"

class Transaction
{
	std::string id;
	User* sender;
	User* recipient;
	std::string datePlaceHolder; //Placeholder for the person who works on transactions class
	bool isAccepted; //If accepted transaction will appear on the user's transactions instead of user's requests (less space than having several arrays for requests and transactions
public:
	Transaction();
	Transaction(User sendUser, User recieveUser);
	void listTransactions(std::vector<Transaction> transactionArr); //Displays a list of all transactions
};

