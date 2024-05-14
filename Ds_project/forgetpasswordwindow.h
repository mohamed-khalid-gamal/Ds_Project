#ifndef FORGETPASSWORDWINDOW_H
#define FORGETPASSWORDWINDOW_H

#include <QDialog>
#include <unordered_map>
#include <string>
#include "Transaction.h"
#include "User.h"

namespace Ui {
class forgetPasswordWindow;
}

class forgetPasswordWindow : public QDialog
{
    Q_OBJECT

public:
    explicit forgetPasswordWindow(QWidget *parent = nullptr);
    explicit forgetPasswordWindow(std::unordered_map<std::string,User> *allU,QWidget *parent = nullptr);
    std::unordered_map<std::string,User>* allUsers;
    ~forgetPasswordWindow();

private:
    Ui::forgetPasswordWindow *ui;
};

#endif // FORGETPASSWORDWINDOW_H
