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
    explicit pendingTransactionsWindow(std::unordered_map<std::string,User> *allU,QWidget *parent = nullptr);
    std::unordered_map<std::string,User>* allUsers;
    ~pendingTransactionsWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::pendingTransactionsWindow *ui;
};

#endif // PENDINGTRANSACTIONSWINDOW_H
