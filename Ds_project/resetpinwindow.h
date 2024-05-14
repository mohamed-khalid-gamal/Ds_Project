#ifndef RESETPINWINDOW_H
#define RESETPINWINDOW_H

#include <QDialog>

namespace Ui {
class resetPinWindow;
}

class resetPinWindow : public QDialog
{
    Q_OBJECT

public:
    explicit resetPinWindow(QWidget *parent = nullptr);
    ~resetPinWindow();

private:
    Ui::resetPinWindow *ui;
};

#endif // RESETPINWINDOW_H
