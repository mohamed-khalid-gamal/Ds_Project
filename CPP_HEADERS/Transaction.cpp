#include "User.h"
#include "Transaction.h"
#include <fstream>


Transaction::Transaction(User sendUser, User recieveUser)
{
	sender = sendUser.getUsername();
	recipient = recieveUser.getUsername();
	datePlaceHolder = "Today";
	isAccepted = false;
}

void Transaction::listTransactions(std::vector<Transaction>)
{
}

Transaction::Transaction()
{
	sender = User("test","test").getUsername();
	recipient = User("test","test").getUsername();
	datePlaceHolder = "Today";
	isAccepted = false;
}

void Transaction::setid(string nid)
{
	id = nid;
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
string Transaction::getid()
{
	return id;
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

bool Transaction::getisAccepted()
{
	return isAccepted;
}