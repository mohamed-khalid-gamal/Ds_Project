#pragma once
#include <string>
#include <set>
#include <unordered_map>
#include <stack>
class Transaction;

class User{
	std::string username;
	std::string password;
	float balance;
	std::stack<Transaction> userTransactions;
	std::unordered_map<int,Transaction> user_pending_Transactions;
	std::string pin;
	bool is_active;
public:
	User(std::string name, std::string pass);
	User();
	std::string getUsername(void);
	void setUsername(std::string uname);
	std::string getPassword(void);
	float getBalance(void);
	void setBalance(float bal);
	std::string getPin(void);
	void setPin(std::string pinum);
	std::stack<Transaction> getTransactions(void);
	void setTransactions(std::stack <Transaction> UTrans);
	void setTransaction(Transaction);
	void setPendingTransaction(Transaction);
	bool getActive(void);
	void setActive(bool activity);
	void setPassword(std::string pass);
	void sendMoney(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions);
	void requestMoney(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions);
	void acceptRequest(Transaction tr_pend, std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions);
	void changePassword(std::unordered_map<std::string, User>& allUsers, bool admin, std::stack<Transaction>& allTransactions);
	bool validPassword(std::string);
	void changeUsername(std::unordered_map<std::string, User>& allUsers, bool admin, std::stack<Transaction>& allTransactions);
	void pendingRequests(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions);
	void transactionHistory();
	static User searchUser(std::string uname, std::set <User> users);
	static User searchUser(std::string uname, std::unordered_map <std::string, User> users);
	static void removeUser(std::string uname, std::set <User> users);
	static void setUserPinMenu(User activeUser);

};

