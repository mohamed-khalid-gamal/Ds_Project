#ifndef FORGETPASSWORDWINDOW_H
#define FORGETPASSWORDWINDOW_H

#include <QDialog>

namespace Ui {
class forgetPasswordWindow;
}

class forgetPasswordWindow : public QDialog
{
    Q_OBJECT

public:
    explicit forgetPasswordWindow(QWidget *parent = nullptr);
    ~forgetPasswordWindow();

private:
    Ui::forgetPasswordWindow *ui;
};

#endif // FORGETPASSWORDWINDOW_H
