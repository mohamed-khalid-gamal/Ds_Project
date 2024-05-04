#include "User.h"
#include "Transaction.h"
#include <fstream>
#include <chrono>
#include <ctime>
#include"SaveLoad.cpp"
Transaction::Transaction(string sendUser, string recieveUser)
{
	SaveLoad files = SaveLoad();
	auto all_tr = files.loadTransactions();
	if (all_tr.empty())
	{
		this->id = 0;
	}
	else
	{
		this->id = all_tr.top().id++;
	}
	sender = sendUser;
	recipient = recieveUser;
	datePlaceHolder = get_time();
	isAccepted = false;
}
void Transaction::listTransactions(std::stack<Transaction>)
{
    bool flag = false;
    while (!transaction.empty()){
        
        flag = true;
        cout<<"Transaction ID : ";
        cout<<transaction.top().getId()<<endl;
        cout<<"Transaction amount : ";
        cout<<transaction.top().getAmount()<<endl;
        cout<<"Sender : ";
        cout<<transaction.top().getsender()<<endl;
        cout<<"Recipient : ";
        cout<<transaction.top().getrecipient()<<endl;
        cout<<"Date : ";
        cout<<transaction.top().getdatePlaceHolder()<<endl;
    }
    if(!flag){
        cout<<"No Transactions yet";
    }
}

Transaction::Transaction()
{
	sender = User("test", "test").getUsername();
	recipient = User("test", "test").getUsername();
	datePlaceHolder = "Today";
	isAccepted = false;
}
void Transaction::setid(int i)
{
	id = i;
}
void Transaction::setsender(string nsender)
{
	sender = nsender;
}
void Transaction::setrecipient(string nrecipient)
{
	recipient = nrecipient;
}
void Transaction::setdatePlaceHolder(string ndatePlaceHolder)
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


string Transaction::getsender()
{
	return sender;
}

string Transaction::getrecipient()
{
	return recipient;
}

string Transaction::getdatePlaceHolder()
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

string Transaction::get_time()
{
	auto now = chrono::system_clock::now();
	time_t current_time = chrono::system_clock::to_time_t(now);
	tm* local_time = localtime(&current_time);
	char date_buffer[80];
	strftime(date_buffer, sizeof(date_buffer), "%Y-%m-%d", local_time);
	string current_date = date_buffer;
	char time_buffer[80];
	strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", local_time);
	string current_time_str = time_buffer;
	return  current_date + " " + current_time_str;
}

