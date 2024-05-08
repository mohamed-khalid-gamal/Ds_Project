
#define USER_H
#include <string>
#include <stack>
#include <set>
#include <unordered_map>
#include "Transaction.h"

using namespace std;
class User
{
    string username;
    string password;
    float balance;
    stack<Transaction> userTransactions;
    unordered_map<int,Transaction> user_pending_Transactions;
    string pin;
    bool is_active;
public:
    User(string name, string pass);
    User();
    string getUsername(void);
    void setUsername(string uname);
    string getPassword(void);
    float getBalance(void);
    void setBalance(float bal);
    string getPin(void);
    void setPin(string pinum);
    stack <Transaction> getTransactions(void);
    void setTransactions(stack <Transaction> UTrans);
    void setTransaction(Transaction);
    void setPendingTransaction(Transaction);
    bool getActive(void);
    void setActive(bool activity);
    void setPassword(string pass);
    void sendMoney( );
    void requestMoney(void);
    void acceptRequest(Transaction);
    void changePassword(unordered_map<string, User>&, bool);
    bool validPassword(string);
    void changeUsername(unordered_map<string, User>& allUsers, bool admin);
    void pendingRequests();
    void transactionHistory();
    static User searchUser(string uname, set <User> users);
    static User searchUser(string uname, unordered_map <string, User> users);
    static void removeUser(string uname, set <User> users);

};

