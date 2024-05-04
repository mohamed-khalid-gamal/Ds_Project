#include "User.h"
#include "Account.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include <set>
#include <unordered_map>
#include <stack>
#include "SaveLoad.cpp"
using namespace std;

User::User(string name, string pass)
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



string User::getUsername(void)
{
	return username;
}
void User::setUsername(string uname)
{
    username = uname;
}
string User::getPassword(void)
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
string User::getPin(void)
{
    return pin;
}
void User::setPin(string pinum)
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

stack<Transaction> User::getTransactions(void)
{
    return userTransactions;
}
void User::setTransactions(stack <Transaction> UTrans)
{
    userTransactions = UTrans;
}
void User::setTransaction(Transaction tra)
{
    userTransactions.push(tra);
}

void User::setPendingTransaction(Transaction tr)
{
    user_pending_Transactions.insert(make_pair(tr.getId(),tr));
}

void User::setPassword(string pass)
{
	password = pass;
}
void User::sendMoney()
{
    string recipient;
    float amount;

    cout << "Enter the user name you want to receive the money ";
    cin >> recipient;
    cout << "Enter the amount you want to send ";
    cin >> amount;
    SaveLoad X = SaveLoad();
    auto user = searchUser(recipient, X.loadUsers());
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
               auto transs =  X.loadTransactions();
               transs.push(trans);
               X.saveTransactions(transs);
            }
            else {
                cout << "you  or the recepient are panned  call the admin";
                Menu men = Menu();
                User actUser = searchUser(this->username, X.loadUsers());
                auto users = &X.loadUsers();
                men.userMenu(actUser, *users);
            }
        }
        else {
            cout << "invalid amount";
            char x;
            cout << "\n do you want try again ? (Y / N)";
            cin >> x;
            if (x == 'y' || x == 'Y')
            {
                sendMoney();
            }
            else {
                Menu men = Menu();
                User actUser = searchUser(this->username, X.loadUsers());
                auto users = &X.loadUsers();
                men.userMenu(actUser, *users);
            }
        }
        
    }
    else
    {
        char x;
        cout << "\n do you want try again ? (Y / N)";
        cin >> x;
        if (x=='y' ||x=='Y')
        {
            sendMoney();
        }
        else {
            Menu men = Menu();
            User actUser = searchUser(this->username, X.loadUsers());
            auto users = &X.loadUsers();
                men.userMenu(actUser,*users );
        }
    }
}

void User::requestMoney()
{
    string sender;
    float amount;
    cout << "Enter the user name you want to receive the request ";
    cin >> sender;
    cout << "Enter the amount you want to request ";
    cin >> amount;
    SaveLoad files = SaveLoad();
    auto user = searchUser(sender, files.loadUsers());
    if (user.getUsername() == sender)
    {     
            
                Transaction trans = Transaction( sender, this->getUsername());
                trans.setAmount(amount);
                user.setPendingTransaction(trans);
    }
    else
    {
        char x;
        cout << "\n do you want try again ? (Y / N)";
        cin >> x;
        if (x == 'y' || x == 'Y')
        {
            requestMoney();
        }
        else {
            Menu men = Menu();
            User actUser = searchUser(this->username, files.loadUsers());
            auto users = &files.loadUsers();
            men.userMenu(actUser, *users);
        }
    }

}

void User::acceptRequest(Transaction tr_pend)
{

    SaveLoad files = SaveLoad();
    user_pending_Transactions.erase(tr_pend.getId());
    tr_pend.setisAccepted(true);
    this->balance -= tr_pend.getAmount();
    this->setTransaction(tr_pend);
    User recepient = searchUser(tr_pend.getrecipient(), files.loadUsers());
    recepient.balance += tr_pend.getAmount();
    recepient.setTransaction(tr_pend);
    stack<Transaction> trs = files.loadTransactions();
    trs.push(tr_pend);
    files.saveTransactions(trs);
}

void User::changePassword(unordered_map<string, User>& allUsers, bool admin = false) {
    if (admin == true) {
        cout << endl << "Enter new password : ";
        string newPassword; getline(cin, newPassword);
        if (!validPassword(newPassword)) {
            system("pause"); system("cls");
            cout << endl << "             (1) reEnter your new password                   ";
            cout << endl << "             other to return to admin menu                     ";
            int x; cin >> x;
            cin.ignore();
            if (x == 1) {
                system("pause"); system("cls");
                changePassword(allUsers, true);
            }
            else {
                system("pause"); system("cls");
                Menu::adminMenu();
                //Menu::userMenu(allUsers[this->username], allUsers);
                //both are correct
            }

        }
        else {
            this->password = newPassword;
            cout << "password has been changed ! " << endl;
            system("pause"); system("cls");
            Menu::adminMenu();
            //Menu::userMenu(allUsers[this->username], allUsers);
        }
    }
    else {
        cout << "Enter current password : ";
        string password; getline(cin, password);
        if (this->password == password) {
            cout << endl << "Enter new password : ";
            string newPassword; getline(cin, newPassword);
            if (!validPassword(newPassword)) {
                system("pause"); system("cls");
                cout << endl << "             (1) reEnter your new password                    ";
                cout << endl << "             other to return to user menu                     ";
                int x; cin >> x;
                cin.ignore();
                if (x == 1) {
                    system("pause"); system("cls");
                    changePassword(allUsers);
                }
                else {
                    system("pause"); system("cls");
                    Menu::userMenu(*this, allUsers);
                    //Menu::userMenu(allUsers[this->username], allUsers);
                    //both are correct
                }

            }
            else {
                this->password = newPassword;
                cout << "password has been changed ! " << endl;
                system("pause"); system("cls");
                Menu::userMenu(*this, allUsers);
                //Menu::userMenu(allUsers[this->username], allUsers);
            }
        }
        else {
            cout << "Wrong password !" << endl;
            system("pause"); system("cls");
            cout << endl << "             (1) reEnter your password                   ";
            cout << endl << "             other to return to user menu                     ";
            int x; cin >> x;
            cin.ignore();
            if (x == 1) {
                system("pause"); system("cls");
                changePassword(allUsers);
            }
            else {
                system("pause"); system("cls");
                Menu::userMenu(*this, allUsers);
                //Menu::userMenu(allUsers[this->username], allUsers);
                //both are correct
            }
        }

    }
}
bool User::validPassword(string password) {
    if (password.length() < 8) {
        cout << "Password must be at least 8 characters long." << endl;
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
        cout << "Password must contain at least one uppercase letter." << endl;
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
        cout << "Password must contain at least one lowercase letter." << endl;
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
        cout << "Password must contain at least one digit." << endl;
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
        cout << "Password must contain at least one special character." << endl;
        return false;
    }
    return true;
}
void User::changeUsername(unordered_map<string, User>& allUsers,bool admin = false) {
    if (admin == false) {
        system("pause"); system("cls");
        cout << "Enter new Username : ";
        string username; getline(cin, username);
        auto it = allUsers.find(username);
        if (it != allUsers.end()) {
            this->username = username;
        }
        else {
            cout << "This username is taken !" << endl << "Try another one" << endl;
            system("pause"); system("cls");
            cout << endl << "             (1) reEnter new username                   ";
            cout << endl << "             other to return to user menu                     ";
            int x; cin >> x;
            cin.ignore();
            if (x == 1) {
                system("pause"); system("cls");
                changePassword(allUsers);
            }
            else {
                system("pause"); system("cls");
                Menu::userMenu(*this, allUsers);
                //Menu::userMenu(allUsers[this->username], allUsers);
                //both are correct
            }
        }
        system("pause");
    }
    else if (admin == true) {
        system("pause"); system("cls");
        cout << "Enter new Username : ";
        string username; getline(cin, username);
        auto it = allUsers.find(username);
        if (it != allUsers.end()) {
            this->username = username;
        }
        else {
            cout << "This username is taken !" << endl << "Try another one" << endl;
            system("pause"); system("cls");
            cout << endl << "             (1) reEnter new username                   ";
            cout << endl << "             other to return to admin menu                     ";
            int x; cin >> x;
            cin.ignore();
            if (x == 1) {
                system("pause"); system("cls");
                changeUsername(allUsers,true);
            }
            else {
                system("pause"); system("cls");
                Menu::adminMenu();
                //Menu::userMenu(allUsers[this->username], allUsers);
                //both are correct
            }
        }
        system("pause");
    }
}

void User::pendingRequests()
{
    for (auto it: user_pending_Transactions)
    {
        cout << "id : " << it.first << "amount : " << it.second.getAmount()<<"recepient :"<<it.second.getrecipient();
    }
    int id;
    cout << "Enter the id of request you want to proceed \n";
    cin >> id;
    Transaction tr_pend = user_pending_Transactions.at(id);
    if (tr_pend.getAmount()<=this->balance && this->getActive())
    {
        char ch;
        cout << "Do you want to accept the request (Y / N)\n";
        cin >> ch;
        if (ch == 'y'|| ch =='Y')
        {
            acceptRequest(tr_pend);
        }
        else
        {
            user_pending_Transactions.erase(tr_pend.getId());
        }
    }
    else
    {
        char ch;
        cout << "you can`t accept this request do you want to reject it ? (Y / N)\n";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            user_pending_Transactions.erase(tr_pend.getId());
        }
        else
        {
            SaveLoad X = SaveLoad();
            Menu men = Menu();
            User actUser = searchUser(this->username, X.loadUsers());
            auto users = &X.loadUsers();
            men.userMenu(actUser, *users);
        }
    }
}

void User::transactionHistory(stack<Transaction> userTransactions)
{
    stack<Transaction> tempStack = userTransactions;
    bool flag = false;

    while (!tempStack.empty()){

        flag = true;
        cout<<"Transaction ID : ";
        cout<<tempStack.top().getId()<<endl;
        cout<<"Transaction amount : ";
        cout<<tempStack.top().getAmount()<<endl;
        cout<<"Sender : ";
        cout<<tempStack.top().getsender()<<endl;
        cout<<"Recipient : ";
        cout<<tempStack.top().getrecipient()<<endl;
        cout<<"Date : ";
        cout<<tempStack.top().getdatePlaceHolder()<<endl;
        tempStack.pop();

    }
    if(!flag){
        cout<<"No Transactions found";
    }

}


User User::searchUser(string uname, set <User> users)
{
	set <User> ::iterator it;
	it = users.begin();
	while (it != users.end())
	{
		if (uname == it->username)
			return *it;
		it++;
	}
	cout << "User not found\n";
	return User();
}

User User::searchUser(string uname, unordered_map <string, User> users)
{
	auto it = users.find(uname);
	if (it != users.end())
		return it->second;
	else
	{
		cout << "User not found\n";
		return User();
	}
}

void User::removeUser(string uname, set <User> users)
{
	set <User> ::iterator it;
	while (it != users.end())
	{
		if (uname == it->username)
		{
			users.erase(it);
			return;
		}
		it++;
	}
	cout << "User not found\n";
	return;
}
