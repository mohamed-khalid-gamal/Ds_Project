#ifndef SENDMONEYWINDOW_H
#define SENDMONEYWINDOW_H

#include <QDialog>
#include <stack>
#include <unordered_map>
#include <string>
#include "Transaction.h"
#include "User.h"

namespace Ui {
class sendMoneyWindow;
}

class sendMoneyWindow : public QDialog
{
    Q_OBJECT

public:
    explicit sendMoneyWindow(QWidget *parent = nullptr);
    explicit sendMoneyWindow(QString sender,std::unordered_map<std::string,User> *allU, std::stack<Transaction> *allT,QWidget *parent = nullptr);
    std::stack<Transaction>* allTransactions;
    std::unordered_map<std::string,User>* allUsers;
    QString sendUser;
    ~sendMoneyWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::sendMoneyWindow *ui;
};

#endif // SENDMONEYWINDOW_H
