#pragma once
#include <fstream>
#include <chrono>
#include <ctime>
#include <iostream>
#include "Transaction.h"
#include "User.h"
#pragma warning(disable : 4996)
Transaction::Transaction(std::string sendUser, std::string recieveUser, std::stack<Transaction>& allTransactions)
{
	if (allTransactions.empty())
	{
		this->id = 0;
	}
	else
	{
		this->id = allTransactions.top().id++;
	}
	sender = sendUser;
	recipient = recieveUser;
	datePlaceHolder = get_time();
	isAccepted = false;
}
void Transaction::listTransactions(std::stack<Transaction> transaction)
{
    bool flag = false;
    while (!transaction.empty()){
        
        flag = true;
		std::cout<<"Transaction ID : ";
		std::cout<<transaction.top().getId()<< std::endl;
		std::cout<<"Transaction amount : ";
		std::cout<<transaction.top().getAmount()<< std::endl;
		std::cout<<"Sender : ";
		std::cout<<transaction.top().getsender()<< std::endl;
		std::cout<<"Recipient : ";
		std::cout<<transaction.top().getrecipient()<< std::endl;
		std::cout<<"Date : ";
		std::cout<<transaction.top().getdatePlaceHolder()<< std::endl;
	    transaction.pop();
    }
    if(!flag){
		std::cout<<"No Transactions yet";
    }
}

Transaction::Transaction(){
	sender = User("test", "test").getUsername();
	recipient = User("test", "test").getUsername();
	datePlaceHolder = "Today";
	isAccepted = false;
	id = 0;
	tran_amount = 50;
}
Transaction::Transaction(std::string sendUser, std::string recieveUser)
{
}
void Transaction::setid(int i)
{
	id = i;
}
void Transaction::setsender(std::string nsender)
{
	sender = nsender;
}
void Transaction::setrecipient(std::string nrecipient)
{
	recipient = nrecipient;
}
void Transaction::setdatePlaceHolder(std::string ndatePlaceHolder)
{
	datePlaceHolder = ndatePlaceHolder;
}
void Transaction::setisAccepted(bool nisAccepted)
{
	isAccepted = nisAccepted;
}
void Transaction::setAmount(float trans_amount)
{
	this->tran_amount = trans_amount;
}


std::string Transaction::getsender()
{
	return sender;
}

std::string Transaction::getrecipient()
{
	return recipient;
}

std::string Transaction::getdatePlaceHolder()
{
	return datePlaceHolder;
}

int Transaction::getId()
{
	return id;
}

float Transaction::getAmount()
{
	return tran_amount;
}

bool Transaction::getisAccepted()
{
	return isAccepted;
}

std::string Transaction::get_time()
{
	auto now = std::chrono::system_clock::now();
	time_t current_time = std::chrono::system_clock::to_time_t(now);
	tm* local_time = localtime(&current_time);
	char date_buffer[80];
	strftime(date_buffer, sizeof(date_buffer), "%Y-%m-%d", local_time);
	std::string current_date = date_buffer;
	char time_buffer[80];
	strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", local_time);
	std::string current_time_str = time_buffer;
	return  current_date + " " + current_time_str;
}

