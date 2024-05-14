#ifndef SENDMONEYWINDOW_H
#define SENDMONEYWINDOW_H

#include <QDialog>

namespace Ui {
class sendMoneyWindow;
}

class sendMoneyWindow : public QDialog
{
    Q_OBJECT

public:
    explicit sendMoneyWindow(QWidget *parent = nullptr);
    ~sendMoneyWindow();

private:
    Ui::sendMoneyWindow *ui;
};

#endif // SENDMONEYWINDOW_H
