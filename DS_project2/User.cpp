#pragma once
#include "Transaction.h"
#include "User.h"
#include <iostream>
#include "Account.h"
#include "SaveLoad.h"
User::User(std::string name, std::string pass)
{
	username = name;
	password = pass;
	balance = 50;
	pin = "000000";
	is_active = true;
}

User::User()
{
	username = "test";
	password = "test 2";
	pin = "000000";
	balance = 0;
	is_active = false;
}

std::string User::getUsername(void)
{
	return username;
}

void User::setUsername(std::string uname)
{
    username = uname;
}

std::string User::getPassword(void)
{
	return password;
}

float User::getBalance(void)
{
    return balance;
}

void User::setBalance(float bal)
{
    balance = bal;
}

std::string User::getPin(void)
{
    return pin;
}

void User::setPin(std::string pinum)
{
    pin = pinum;
}

bool User::getActive(void)
{
    return is_active;
}

void User::setActive(bool activity)
{
    is_active = activity;
}

std::stack<Transaction> User::getTransactions(void)
{
    return userTransactions;
}

std::stack<Transaction> User::getPendingRequests() {
    std::stack<Transaction> tempTrans = this->getTransactions();
    std::stack<Transaction> pendingTrans;
    int size = tempTrans.size();
    for (int i = 0; i < size; i++) {
        if (tempTrans.top().getisAccepted() == false) {
            pendingTrans.push(tempTrans.top());
        }
        tempTrans.pop();
    }
    return pendingTrans;
}

void User::setTransactions(std::stack <Transaction> UTrans)
{
    userTransactions = UTrans;
}

void User::setTransaction(Transaction tra)
{
    userTransactions.push(tra);
}

void User::setPassword(std::string pass)
{
	password = pass;
}
void User::changepassword(const std::string& newPassword) {
    this->password = newPassword;
}
void User::sendMoney(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions)
{
    std::string recipient;
    float amount;

    std::cout << "Enter the user name you want to receive the money: ";
    std::cin >> recipient;
    std::cin.ignore();
    std::cout << "Enter the amount you want to send: ";
    std::cin >> amount;
    std::cin.ignore();
    if (allUsers[recipient].getUsername() == recipient)
    {
        if (amount <= this->balance)
        {
            if (this->getActive()==true && allUsers[recipient].getActive() == true)
            {
                Transaction trans = Transaction(this->getUsername(), recipient,allTransactions);
                trans.setisAccepted(true);
                trans.setAmount(amount);
                setTransaction(trans);
                allUsers[recipient].setTransaction(trans);
                allUsers[username].setBalance(balance - amount);
                balance -= amount;
                allUsers[recipient].balance += amount;
                allTransactions.push(trans);
            }
            else {
                std::cout << "you or the recepient are banned call the admin";
                User actUser = searchUser(this->username, allUsers);
                return;
            }
        }
        else {
            std::cout << "invalid amount\n";
            char x;
            std::cout << "do you want try again ? (Y / N)\n";
            std::cin >> x;
            if (x == 'y' || x == 'Y')
            {
                sendMoney(allUsers,allTransactions);
            }
            else {
                
                User actUser = searchUser(this->username, allUsers);
                return;
            }
        }
        
    }
    else
    {
        char x;
        std::cout << "Username Does not Exist\ndo you want try again ? (Y / N)\n";
        std::cin >> x;
        if (x=='y' ||x=='Y')
        {
            sendMoney(allUsers,allTransactions);
        }
        else {
            
            User actUser = searchUser(this->username, allUsers);
            return;
        }
    }
}

void User::requestMoney(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions)
{
    std::string recName;
    float amount;
    std::cout << "Enter the user name you want to receive the request ";
    std::cin >> recName;
    std::cout << "Enter the amount you want to request ";
    std::cin >> amount;
    if (allUsers[recName].getUsername() == recName)
    {     
            
                Transaction trans = Transaction(recName, this->getUsername(), allTransactions);
                trans.setAmount(amount);
                trans.setisAccepted(false);
                allUsers[recName].setTransaction(trans);
    }
    else
    {
        char x;
        std::cout << "\n do you want try again ? (Y / N)";
        std::cin >> x;
        if (x == 'y' || x == 'Y')
        {
            requestMoney(allUsers, allTransactions);
        }
        else {
            User actUser = searchUser(this->username, allUsers);
            return;
        }
    }

}

void User::acceptRequest(Transaction tr_pend, std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions)
{
    tr_pend.setisAccepted(true);
    this->balance -= tr_pend.getAmount();
    User recepient = searchUser(tr_pend.getrecipient(), allUsers);
    recepient.balance += tr_pend.getAmount();
    std::stack<Transaction> tempAllTrans = allTransactions;
    std::stack<Transaction> tempUserTrans = this->getTransactions();
    int allSize = tempAllTrans.size();
    int userSize = tempUserTrans.size();
    std::stack<Transaction> newUserTrans;
    std::stack<Transaction> newAllTrans;
    for (int i = 0; i <allSize; i++) { // All Transactions loop
        if (tempAllTrans.top().getId() == tr_pend.getId()) {
            newAllTrans.push(tr_pend);
        }
        else {
            newAllTrans.push(tempAllTrans.top());
        }
        tempAllTrans.pop();
    }
    for (int i = 0; i < userSize; i++) { // User Transactions loop
        if (tempUserTrans.top().getId() == tr_pend.getId()) {
            newUserTrans.push(tr_pend);
        }
        else {
            newUserTrans.push(tempUserTrans.top());
        }
        tempUserTrans.pop();
    }
    SaveLoad file; // Saveload variable so i can use the ReverseStack function
    newAllTrans = file.reverseStack(newAllTrans);
    newUserTrans = file.reverseStack(newUserTrans);
    allTransactions = newAllTrans;
    setTransactions(newUserTrans);
    allUsers[username].setTransactions(newUserTrans);
}

void User::changePassword(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions) {
    Account account;
    std::cout << "~change password (-1 at any point to go back to main menu)~\n";
    while (true) {
        std::cout << std::endl << "Enter new password : ";
        std::string newPassword; getline(std::cin, newPassword);
        if (newPassword == "-1")
            return;
        else if (!validPassword(newPassword)) {
            getchar();
            continue;
        }
        else {
            this->password = newPassword;
            allUsers[this->username].setPassword(account.hashText(newPassword));
            std::cout << "Password changed successfully!" << std::endl;
            break;
        }
    }
}

bool User::validPassword(std::string password) {
    for (char ch : password) {
        if (ch == ' ') {
            std::cout << "Password must not contains a space" << std::endl;
            return false; 
        }
    }
    if (password.length() < 8) {
        std::cout << "Password must be at least 8 characters long." << std::endl;
        return false;
    }
    bool hasUpperCase = false;
    for (char c : password) {
        if (isupper(c)) {
            hasUpperCase = true;
            break;
        }
    }
    if (!hasUpperCase) {
        std::cout << "Password must contain at least one uppercase and lowercase letters, digit, special character." << std::endl;
        return false;
    }
    bool hasLowerCase = false;
    for (char c : password) {
        if (islower(c)) {
            hasLowerCase = true;
            break;
        }
    }
    if (!hasLowerCase) {
        std::cout << "Password must contain at least one uppercase and lowercase letters, digit, special character." << std::endl;
        return false;
    }
    bool hasDigit = false;
    for (char c : password) {
        if (isdigit(c)) {
            hasDigit = true;
            break;
        }
    }
    if (!hasDigit) {
        std::cout << "Password must contain at least one uppercase and lowercase letters, digit, special character." << std::endl;
        return false;
    }
    bool hasSpecialChar = false;
    for (char c : password) {
        if (!isalnum(c)) {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) {
        std::cout << "Password must contain at least one uppercase and lowercase letters, digit, special character." << std::endl;
        return false;
    }
    return true;
}

void User::changeUsername(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions) {
    std::cout << "~change username (-1 at any point to go back to main menu)~\n";
    while (true) {
        std::cout << "Enter new Username : ";
        std::string newUsername;
        getline(std::cin, newUsername);
        if (newUsername == "-1")
            return;
        if (newUsername.length() < 5 || newUsername.length() > 16) {
            std::cout << "Wrong length please try again.\n";
            continue;
        }
        auto it = allUsers.find(this->username);
        if (it != allUsers.end()) {
            User& user = it->second;
            user.setUsername(newUsername);
            allUsers[newUsername] = user;
            allUsers.erase(it);
            std::cout << "Username changed successfully!" << std::endl;
            break;
        }
        else {
            std::cout << "This username is taken !, Try another one" << std::endl;
            getchar();
            continue;
        }
    }
    
}

void User::pendingRequests(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions)
{
    std::stack<Transaction> pendRequests = this->getPendingRequests();
    int pendSize = pendRequests.size();
    for (int i = 0; i < pendSize; i++)
    {
        std::cout << "id : " << pendRequests.top().getId() << "amount : " << pendRequests.top().getAmount() <<"recepient :"<< pendRequests.top().getrecipient();
    }
    int id;
    std::cout << "Enter the id of request you want to proceed \n";
    std::cin >> id;
    pendRequests = this->getPendingRequests();
    Transaction tr_pend;
    bool found = false;
    for (int i = 0; i < pendSize; i++) {
        if (pendRequests.top().getId() == id) {
            tr_pend = pendRequests.top();
            found = true;
        }
        pendRequests.pop();
    }
    if (!found) {
        std::cout << "Please enter a valid id.\n";
        return;
    }
    if (tr_pend.getAmount()<=this->balance && this->getActive())
    {
        char ch;
        std::cout << "Do you want to accept the request (Y / N)\n";
        std::cin >> ch;
        if (ch == 'y'|| ch =='Y')
        {
            acceptRequest(tr_pend,allUsers,allTransactions);
        }
        else
        {
            return;
        }
    }
    else
    {
        std::cout << "Insufficient Funds in Account please try again later.\n";
    }
}

void User::transactionHistory()
{
    bool flag = this->userTransactions.empty();
    if (!flag) {
        std::stack<Transaction> tempStack = this->userTransactions;
        bool flag = false;
        tempStack.top().listallTransactions(tempStack);
    }
    else {
        std::cout << "No Transactions on this account.\n";
    }
}

User User::searchUser(std::string uname, std::set <User> users) {
    std::set <User> ::iterator it;
	it = users.begin();
	while (it != users.end())
	{
		if (uname == it->username)
			return *it;
		it++;
	}
    std::cout << "User not found\n";
	return User();
}

User User::searchUser(std::string uname, std::unordered_map <std::string, User> users)
{
	auto it = users.find(uname);
	if (it != users.end())
		return it->second;
	else
	{
        std::cout << "User not found\n";
		return User();
	}
}

void User::removeUser(std::string uname, std::set <User> users)
{
    std::set <User> ::iterator it;
	while (it != users.end())
	{
		if (uname == it->username)
		{
			users.erase(it);
			return;
		}
		it++;
	}
    std::cout << "User not found\n";
	return;
}

void User::setUserPinMenu(User activeUser)
{
    std::string newPin;
    std::cout << "Enter new pin(Must be 6 numbers in length): ";
    std::cin >> newPin;
    std::cin.ignore();
    if (newPin.length() > 6 || newPin.length() < 6) {
        std::cout << "Wrong format pleaser try again with the correct format\n";
    }
    else {
        activeUser.setPin(newPin);
    }
}


