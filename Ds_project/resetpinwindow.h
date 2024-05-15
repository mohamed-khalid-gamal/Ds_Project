#ifndef RESETPINWINDOW_H
#define RESETPINWINDOW_H
#include "User.h"
#include <unordered_map>
#include <QDialog>

namespace Ui {
class resetPinWindow;
}

class resetPinWindow : public QDialog
{
    Q_OBJECT

public:
    explicit resetPinWindow(QWidget *parent = nullptr);
    resetPinWindow(QString actUser, std::unordered_map<std::string,User> *allU,QWidget *parent);
    std::unordered_map<std::string,User> *allUsers;
    QString activeUser;
    ~resetPinWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::resetPinWindow *ui;
};

#endif // RESETPINWINDOW_H
