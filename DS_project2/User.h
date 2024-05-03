#pragma once
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
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
	int getBalance(void);
	string getPin(void);
	bool getActive(void);
	void setPassword(string pass);
	void sendMoney(void);
	void requestMoney(void);
	void changePassword(unordered_map<string, User>&, bool);
	bool validPassword(string); 
	void changeUsername(unordered_map<string, User>& allUsers, bool admin);
	void pendingRequests(void);
	void transactionHistory(void);
	static User searchUser(string uname, set <User> users);
	static User searchUser(string uname, unordered_map <string, User> users);
	static void removeUser(string uname, set <User> users);
};
