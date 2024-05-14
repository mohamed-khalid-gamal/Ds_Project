#ifndef EDITUSERSWINDOW_H
#define EDITUSERSWINDOW_H

#include <QDialog>

namespace Ui {
class editUsersWindow;
}

class editUsersWindow : public QDialog
{
    Q_OBJECT

public:
    explicit editUsersWindow(QWidget *parent = nullptr);
    ~editUsersWindow();

private:
    Ui::editUsersWindow *ui;
};

#endif // EDITUSERSWINDOW_H
