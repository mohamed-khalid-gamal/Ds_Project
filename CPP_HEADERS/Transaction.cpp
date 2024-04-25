#include "User.h"
#include "Transaction.h"


Transaction::Transaction(User sendUser, User recieveUser)
{
	*sender = sendUser;
	*recipient = recieveUser;
	datePlaceHolder = "Today";
	isAccepted = false;
}

void Transaction::listTransactions(std::vector<Transaction>)
{
}

Transaction::Transaction()
{
	*sender = User("test","test");
	*recipient = User("test","test");
	datePlaceHolder = "Today";
	isAccepted = false;
}
