#ifndef REQUESTMONEYWINDOW_H
#define REQUESTMONEYWINDOW_H

#include <QDialog>

namespace Ui {
class requestMoneyWindow;
}

class requestMoneyWindow : public QDialog
{
    Q_OBJECT

public:
    explicit requestMoneyWindow(QWidget *parent = nullptr);
    ~requestMoneyWindow();

private:
    Ui::requestMoneyWindow *ui;
};

#endif // REQUESTMONEYWINDOW_H
