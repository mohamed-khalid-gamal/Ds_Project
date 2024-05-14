#ifndef USERWINDOW_H
#define USERWINDOW_H
#include "Transaction.h"
#include "User.h"

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

private:
    Ui::userwindow *ui;
};

#endif // USERWINDOW_H
