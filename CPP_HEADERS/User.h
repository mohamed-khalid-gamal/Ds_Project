#pragma once
#include <string>
#include <vector>
class Transcation;
class User
{
	std::string username;
	std::string password;
	int balance;
	std::vector<Transcation>* userTransactions;
	std::string pin;
	bool is_active;
public:
	User(std::string name, std::string pass);
	User();
	std::string getUsername(void);
	std::string getPassword(void);
	void setPassword(std::string pass);
	void sendMoney(void);
	void requestMoney(void);
	void changePassword(void);
	void pendingRequests(void);
	void transactionHistory(void);
};

