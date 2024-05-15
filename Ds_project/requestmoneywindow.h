#ifndef REQUESTMONEYWINDOW_H
#define REQUESTMONEYWINDOW_H

#include <QDialog>
#include <stack>
#include <unordered_map>
#include <string>
#include "Transaction.h"
#include "User.h"

namespace Ui {
class requestMoneyWindow;
}

class requestMoneyWindow : public QDialog
{
    Q_OBJECT

public:
    explicit requestMoneyWindow(QWidget *parent = nullptr);
    explicit requestMoneyWindow(std::unordered_map<std::string,User> *allU, std::stack<Transaction> *allT,QWidget *parent = nullptr);
    std::stack<Transaction>* allTransactions;
    std::unordered_map<std::string,User>* allUsers;
    ~requestMoneyWindow();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::requestMoneyWindow *ui;
};

#endif // REQUESTMONEYWINDOW_H
