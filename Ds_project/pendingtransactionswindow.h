#ifndef PENDINGTRANSACTIONSWINDOW_H
#define PENDINGTRANSACTIONSWINDOW_H

#include <QDialog>

namespace Ui {
class pendingTransactionsWindow;
}

class pendingTransactionsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit pendingTransactionsWindow(QWidget *parent = nullptr);
    ~pendingTransactionsWindow();

private:
    Ui::pendingTransactionsWindow *ui;
};

#endif // PENDINGTRANSACTIONSWINDOW_H
