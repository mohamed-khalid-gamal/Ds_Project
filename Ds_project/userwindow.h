#ifndef USERWINDOW_H
#define USERWINDOW_H
#include "Transaction.h"
#include "User.h"
#include "sendMoneyWindow.h"
#include "requestmoneywindow.h"
#include "transactionhistory.h"
#include "pendingtransactionswindow.h"
#include "resetpinwindow.h"

#include <QDialog>

namespace Ui {
class userwindow;
}

class userwindow : public QDialog
{
    Q_OBJECT

public:
    explicit userwindow(QString actUser, std::unordered_map<std::string,User> *allU,std::stack<Transaction> *allT,QWidget *parent = nullptr);
    QString activeUser;
    std::stack<Transaction>* allTransactions;
    std::unordered_map<std::string,User>* allUsers;
    void showBalance();
    ~userwindow();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::userwindow *ui;
    pendingTransactionsWindow* penWin;
    transactionHistory* tranWin;
    requestMoneyWindow* reqWin;
    sendMoneyWindow* sendWin;
    resetPinWindow* resetWin;
};

#endif // USERWINDOW_H
