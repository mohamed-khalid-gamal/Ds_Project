#pragma once
#include "Transaction.h"
#include "User.h"
#include "SaveLoad.h"
User::User(std::string name, std::string pass)
{
	username = name;
	password = pass;
	balance = 50;
	pin = "000000";
	is_active = true;
    userTransactions = std::stack<Transaction>();
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


QString User::requestMoney(std::unordered_map<std::string, User>* allUsers, std::stack<Transaction>* allTransactions,std::string sender, std::string recName, float amount)
{
    Transaction trans = Transaction(recName, sender, *allTransactions);
    trans.setAmount(amount);
    trans.setisAccepted(false);
    (*allUsers)[recName].setTransaction(trans);
    (*allUsers)[sender].setTransaction(trans);
    (*allTransactions).push(trans);
    return "Successful Request";
}



