#ifndef TRANSACTIONHISTORY_H
#define TRANSACTIONHISTORY_H

#include <QDialog>

namespace Ui {
class transactionHistory;
}

class transactionHistory : public QDialog
{
    Q_OBJECT

public:
    explicit transactionHistory(QWidget *parent = nullptr);
    ~transactionHistory();

private:
    Ui::transactionHistory *ui;
};

#endif // TRANSACTIONHISTORY_H
