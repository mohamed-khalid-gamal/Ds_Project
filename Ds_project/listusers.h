#ifndef LISTUSERS_H
#define LISTUSERS_H

#include <QDialog>
#include <unordered_map>
#include <string>
#include "Transaction.h"
#include "User.h"

namespace Ui {
class listUsers;
}

class listUsers : public QDialog
{
    Q_OBJECT

public:
    explicit listUsers(QWidget *parent = nullptr);
    explicit listUsers(std::unordered_map<std::string,User> *allU,QWidget *parent = nullptr);
    QString getUsers();
    std::unordered_map<std::string,User>* allUsers;
    ~listUsers();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::listUsers *ui;
};

#endif // LISTUSERS_H
