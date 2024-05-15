#ifndef TRANSACTIONHISTORY_H
#define TRANSACTIONHISTORY_H

#include <QDialog>

#include <stack>
#include "Transaction.h"
#include "User.h"

namespace Ui {
class transactionHistory;
}

class transactionHistory : public QDialog
{
    Q_OBJECT

public:
    explicit transactionHistory(QWidget *parent = nullptr);
    explicit transactionHistory(std::stack<Transaction> allT,QWidget *parent = nullptr);
    std::stack<Transaction> allTransactions;
    QString getTransactions();
    ~transactionHistory();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::transactionHistory *ui;
};

#endif // TRANSACTIONHISTORY_H
