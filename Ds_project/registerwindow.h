#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include <string>
#include <unordered_map>
#include "Transaction.h"
#include "User.h"

namespace Ui {
class registerwindow;
}

class registerwindow : public QDialog
{
    Q_OBJECT

public:
    explicit registerwindow(QWidget *parent = nullptr);
    explicit registerwindow(std::unordered_map<std::string,User> *allU,QWidget *parent = nullptr);
    std::unordered_map<std::string,User>* allUsers;
    ~registerwindow();
    void registerUser(QString name,QString pass);

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::registerwindow *ui;
};

#endif // REGISTERWINDOW_H
