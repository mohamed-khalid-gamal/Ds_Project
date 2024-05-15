#pragma once
#include "Transaction.h"
#include "User.h"
#include <iostream>
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

QString User::sendMoney(std::unordered_map<std::string, User>* allUsers, std::stack<Transaction>* allTransactions,std::string sender, std::string recipient, float amount)
{
    if ((*allUsers).count(recipient) == 1)
    {
        if (amount <= (*allUsers)[recipient].getBalance())
        {
            if ((*allUsers)[sender].getActive()==true && (*allUsers)[recipient].getActive() == true)
            {
                Transaction trans = Transaction(sender, recipient,*allTransactions);
                trans.setisAccepted(true);
                trans.setAmount(amount);
                (*allUsers)[sender].setTransaction(trans);
                (*allUsers)[recipient].setTransaction(trans);
                (*allUsers)[sender].setBalance((*allUsers)[sender].getBalance() - amount);
                (*allUsers)[recipient].setBalance((*allUsers)[recipient].getBalance() + amount);
                allTransactions->push(trans);
            }
            else {
                return "you or the recepient are banned call the admin";
            }
        }
        else {
            return "invalid amount\n";
        }
        
    }
    else
    {
        return "Username Does not Exist\n";

    }
    return "Successful Transaction";
}

QString User::requestMoney(std::unordered_map<std::string, User>* allUsers, std::stack<Transaction>* allTransactions,std::string sender, std::string recName, float amount)
{
    if ((*allUsers).count(recName) == 1)
    {
        Transaction trans = Transaction(recName, sender, *allTransactions);
        trans.setAmount(amount);
        trans.setisAccepted(false);
        (*allUsers)[recName].setTransaction(trans);
        (*allUsers)[sender].setTransaction(trans);
        (*allTransactions).push(trans);
    }
    else
    {
        return "Username not found.";
    }
    return "Successful Request";
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



