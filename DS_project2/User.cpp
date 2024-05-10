#pragma once
#include "Transaction.h"
#include "User.h"
#include <iostream>
#include "Account.h"
#include "Menu.h"

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
void User::setTransactions(std::stack <Transaction> UTrans)
{
    userTransactions = UTrans;
}
void User::setTransaction(Transaction tra)
{
    userTransactions.push(tra);
}

void User::setPendingTransaction(Transaction tr)
{
    user_pending_Transactions.insert(std::make_pair(tr.getId(),tr));
}

void User::setPassword(std::string pass)
{
	password = pass;
}
void User::sendMoney(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions)
{
    std::string recipient;
    float amount;

    std::cout << "Enter the user name you want to receive the money ";
    std::cin >> recipient;
    std::cout << "Enter the amount you want to send ";
    std::cin >> amount;
    auto user = searchUser(recipient, allUsers);
    if ( user.getUsername() == recipient)
    {
        if (amount <= this->balance)
        {
            if (this->getActive()==true && user.getActive())
            {
                Transaction trans = Transaction(this->getUsername(), recipient);
                trans.setisAccepted(true);
                trans.setAmount(amount);
                this->setTransaction(trans);
                user.setTransaction(trans);
                this->balance -= amount;
                user.balance += amount;
                allTransactions.push(trans);
            }
            else {
                std::cout << "you  or the recepient are panned  call the admin";
                Menu men = Menu();
                User actUser = searchUser(this->username, allUsers);
                men.userMenu(actUser, allUsers,allTransactions);
            }
        }
        else {
            std::cout << "invalid amount";
            char x;
            std::cout << "\n do you want try again ? (Y / N)";
            std::cin >> x;
            if (x == 'y' || x == 'Y')
            {
                sendMoney(allUsers,allTransactions);
            }
            else {
                Menu men = Menu();
                User actUser = searchUser(this->username, allUsers);
                men.userMenu(actUser, allUsers, allTransactions);
            }
        }
        
    }
    else
    {
        char x;
        std::cout << "\n do you want try again ? (Y / N)";
        std::cin >> x;
        if (x=='y' ||x=='Y')
        {
            sendMoney(allUsers,allTransactions);
        }
        else {
            Menu men = Menu();
            User actUser = searchUser(this->username, allUsers);
            men.userMenu(actUser,allUsers,allTransactions);
        }
    }
}

void User::requestMoney(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions)
{
    std::string sender;
    float amount;
    std::cout << "Enter the user name you want to receive the request ";
    std::cin >> sender;
    std::cout << "Enter the amount you want to request ";
    std::cin >> amount;
    auto user = searchUser(sender, allUsers);
    if (user.getUsername() == sender)
    {     
            
                Transaction trans = Transaction( sender, this->getUsername());
                trans.setAmount(amount);
                user.setPendingTransaction(trans);
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
            Menu men = Menu();
            User actUser = searchUser(this->username, allUsers);
            men.userMenu(actUser, allUsers,allTransactions);
        }
    }

}

void User::acceptRequest(Transaction tr_pend, std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions)
{
    user_pending_Transactions.erase(tr_pend.getId());
    tr_pend.setisAccepted(true);
    this->balance -= tr_pend.getAmount();
    this->setTransaction(tr_pend);
    User recepient = searchUser(tr_pend.getrecipient(), allUsers);
    recepient.balance += tr_pend.getAmount();
    recepient.setTransaction(tr_pend);
    allTransactions.push(tr_pend);
}

void User::changePassword(std::unordered_map<std::string, User>& allUsers, bool admin, std::stack<Transaction>& allTransactions) {
    Menu men = Menu();
    if (admin == true) {
        std::cout << std::endl << "Enter new password : ";
        std::string newPassword; getline(std::cin, newPassword);
        if (!validPassword(newPassword)) {
            getchar();
            std::cout << std::endl << "             (1) Re-Enter your new password                   ";
            std::cout << std::endl << "             (Else) Return to admin menu                     ";
            int x; std::cin >> x;
            std::cin.ignore();
            if (x == 1) {
                getchar();
                changePassword(allUsers, true,allTransactions);
            }
            else {
                getchar();
                men.adminMenu(allUsers, allTransactions);
                //Menu::userMenu(allUsers[this->username], allUsers);
                //both are correct
            }

        }
        else {
            this->password = newPassword;
            std::cout << "password has been changed ! " << std::endl;
            getchar();
            men.adminMenu(allUsers, allTransactions);
            //Menu::userMenu(allUsers[this->username], allUsers);
        }
    }
    else {
        std::cout << "Enter current password : ";
        std::string password; getline(std::cin, password);
        if (this->password == password) {
            std::cout << std::endl << "Enter new password : ";
            std::string newPassword; getline(std::cin, newPassword);
            if (!validPassword(newPassword)) {
                std::cout << std::endl << "             (1) reEnter your new password                    ";
                std::cout << std::endl << "             other to return to user menu                     ";
                int x; std::cin >> x;
                std::cin.ignore();
                if (x == 1) {
                    getchar();
                    changePassword(allUsers, false, allTransactions);
                }
                else {
                    getchar();
                    men.userMenu(*this, allUsers, allTransactions);
                    //Menu::userMenu(allUsers[this->username], allUsers);
                    //both are correct
                }

            }
            else {
                this->password = newPassword;
                std::cout << "password has been changed ! " << std::endl;
                getchar();
                men.userMenu(*this, allUsers,allTransactions);
                //Menu::userMenu(allUsers[this->username], allUsers);
            }
        }
        else {
            std::cout << "Wrong password !" << std::endl;
            std::cout << std::endl << "             (1) reEnter your password                   ";
            std::cout << std::endl << "             other to return to user menu                     ";
            int x; std::cin >> x;
            std::cin.ignore();
            if (x == 1) {
                getchar();
                changePassword(allUsers,false, allTransactions);
            }
            else {
                getchar();
                men.userMenu(*this, allUsers, allTransactions);
                //Menu::userMenu(allUsers[this->username], allUsers);
                //both are correct
            }
        }

    }
}
bool User::validPassword(std::string password) {
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
        std::cout << "Password must contain at least one uppercase letter." << std::endl;
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
        std::cout << "Password must contain at least one lowercase letter." << std::endl;
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
        std::cout << "Password must contain at least one digit." << std::endl;
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
        std::cout << "Password must contain at least one special character." << std::endl;
        return false;
    }
    return true;
}
void User::changeUsername(std::unordered_map<std::string, User>& allUsers,bool admin, std::stack<Transaction>& allTransactions) {
    Menu men = Menu();
    if (admin == false) {
        std::cout << "Enter new Username : ";
        std::string username; getline(std::cin, username);
        auto it = allUsers.find(username);
        if (it != allUsers.end()) {
            this->username = username;
        }
        else {
            std::cout << "This username is taken !" << std::endl << "Try another one" << std::endl;
            getchar();
            std::cout << std::endl << "             (1) reEnter new username                   ";
            std::cout << std::endl << "             other to return to user menu                     ";
            int x; std::cin >> x;
            std::cin.ignore();
            if (x == 1) {
                getchar();
                changePassword(allUsers,false, allTransactions);
            }
            else {
                getchar();
                men.userMenu(*this, allUsers,allTransactions);
                //Menu::userMenu(allUsers[this->username], allUsers);
                //both are correct
            }
        }
        system("pause");
    }
    else if (admin == true) {
        std::cout << "Enter new Username : ";
        std::string username; getline(std::cin, username);
        auto it = allUsers.find(username);
        if (it != allUsers.end()) {
            this->username = username;
        }
        else {
            std::cout << "This username is taken !" << std::endl << "Try another one" << std::endl;
            getchar();
            std::cout << std::endl << "             (1) reEnter new username                   ";
            std::cout << std::endl << "             other to return to admin menu                     ";
            int x; std::cin >> x;
            std::cin.ignore();
            if (x == 1) {
                getchar();
                changeUsername(allUsers,true,allTransactions);
            }
            else {
                getchar();
                men.adminMenu(allUsers,allTransactions);
                //Menu::userMenu(allUsers[this->username], allUsers);
                //both are correct
            }
        }
        system("pause");
    }
}

void User::pendingRequests(std::unordered_map<std::string, User>& allUsers, std::stack<Transaction>& allTransactions)
{
    for (auto it: user_pending_Transactions)
    {
        std::cout << "id : " << it.first << "amount : " << it.second.getAmount()<<"recepient :"<<it.second.getrecipient();
    }
    int id;
    std::cout << "Enter the id of request you want to proceed \n";
    std::cin >> id;
    Transaction tr_pend = user_pending_Transactions.at(id);
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
            user_pending_Transactions.erase(tr_pend.getId());
        }
    }
    else
    {
        char ch;
        std::cout << "you can`t accept this request do you want to reject it ? (Y / N)\n";
        std::cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            user_pending_Transactions.erase(tr_pend.getId());
        }
        else
        {
            Menu men = Menu();
            User actUser = searchUser(this->username, allUsers);
            men.userMenu(actUser, allUsers,allTransactions);
        }
    }
}

void User::transactionHistory()
{
    std::stack<Transaction> tempStack = this->userTransactions;
    bool flag = false;

    while (!tempStack.empty()){

        flag = true;
        std::cout<<"Transaction ID : ";
        std::cout<<tempStack.top().getId()<< std::endl;
        std::cout<<"Transaction amount : ";
        std::cout<<tempStack.top().getAmount()<< std::endl;
        std::cout<<"Sender : ";
        std::cout<<tempStack.top().getsender()<< std::endl;
        std::cout<<"Recipient : ";
        std::cout<<tempStack.top().getrecipient()<< std::endl;
        std::cout<<"Date : ";
        std::cout<<tempStack.top().getdatePlaceHolder()<< std::endl;
        tempStack.pop();

    }
    if(!flag){
        std::cout<<"No Transactions found";
    }

}


User User::searchUser(std::string uname, std::set <User> users)
{
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
