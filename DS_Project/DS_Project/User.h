#pragma once
#include <string>
#include <vector>
using namespace std;
class Transcation;
class User
{
	string username;
	string password;
	int balance;
	vector<Transcation>* userTransactions;
	string pin;
	bool is_active;
public:
	User(string name, string pass);
	User();
	string getUsername(void);
	string getPassword(void);
	void setPassword(string pass);
	void sendMoney(void);
	void requestMoney(void);
	void changePassword(void);
	void pendingRequests(void);
	void transactionHistory(void);
};

