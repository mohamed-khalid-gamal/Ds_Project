#ifndef LISTUSERS_H
#define LISTUSERS_H

#include <QDialog>

namespace Ui {
class listUsers;
}

class listUsers : public QDialog
{
    Q_OBJECT

public:
    explicit listUsers(QWidget *parent = nullptr);
    ~listUsers();

private:
    Ui::listUsers *ui;
};

#endif // LISTUSERS_H
