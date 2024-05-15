#pragma once
#include <string>
#include <set>
#include <unordered_map>
#include <stack>
#include <QString>
class Transaction;

class User{
	std::string username;
	std::string password;
	float balance;
	std::stack<Transaction> userTransactions;
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
	
	std::stack<Transaction> getPendingRequests();
	
	void setTransactions(std::stack <Transaction> UTrans);
	
	void setTransaction(Transaction);
	
	bool getActive(void);
	
	void setActive(bool activity);
	
	void setPassword(std::string pass);

	void changepassword(const std::string&);

    QString sendMoney(std::unordered_map<std::string, User>* allUsers, std::stack<Transaction>* allTransactions,std::string sender, std::string recipient, float amount);

    QString requestMoney(std::unordered_map<std::string, User>* allUsers, std::stack<Transaction>* allTransactions,std::string sender, std::string recName, float amount);
	
	void acceptRequest(Transaction tr_pend, std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions);
	
	void changePassword(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions);
	
	static bool validPassword(std::string);
	
	void changeUsername(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions);
	
	void pendingRequests(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions);
	
    QString transactionHistory();
	
	static User searchUser(std::string uname, std::set <User> users);
	
	static User searchUser(std::string uname, std::unordered_map <std::string, User> users);
	
	static void removeUser(std::string uname, std::set <User> users);
	
	static void setUserPinMenu(User activeUser);

};


