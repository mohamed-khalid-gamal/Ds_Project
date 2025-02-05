#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <stack>
#include <unordered_map>
#include <string>
#include "Transaction.h"
#include "User.h"
#include "listusers.h"
#include "edituserswindow.h"
#include "transactionhistory.h"

namespace Ui {
class adminwindow;
}

class adminwindow : public QDialog
{
    Q_OBJECT

public:
    explicit adminwindow(QWidget *parent = nullptr);
    explicit adminwindow(std::unordered_map<std::string,User> *allU, std::stack<Transaction> *allT,QWidget *parent = nullptr);
    std::stack<Transaction>* allTransactions;
    std::unordered_map<std::string,User>* allUsers;
    void clearTrans(std::stack<Transaction>& allTrans);
    ~adminwindow();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::adminwindow *ui;
    listUsers *listWin;
    editUsersWindow *editWin;
    transactionHistory *tranWin;
};

#endif // ADMINWINDOW_H
