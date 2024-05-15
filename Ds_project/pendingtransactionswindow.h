#ifndef PENDINGTRANSACTIONSWINDOW_H
#define PENDINGTRANSACTIONSWINDOW_H

#include <QDialog>
#include <string>
#include <unordered_map>
#include "Transaction.h"
#include "User.h"

namespace Ui {
class pendingTransactionsWindow;
}

class pendingTransactionsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit pendingTransactionsWindow(QWidget *parent = nullptr);
    explicit pendingTransactionsWindow(QString activeU,std::unordered_map<std::string,User>* allU,std::stack<Transaction>* allTP,QWidget *parent);
    QString getPendingTransactions();
    std::stack<Transaction>* allTransactionsPointer;
    QString activeUser;
    std::unordered_map<std::string,User>* allUsers;
    void acceptRequest(std::stack<Transaction>& allTransactions,QString id,QString actUser);
    ~pendingTransactionsWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::pendingTransactionsWindow *ui;
};

#endif // PENDINGTRANSACTIONSWINDOW_H
