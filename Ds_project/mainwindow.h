#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <string>
#include <stack>
#include <unordered_map>
#include "Transaction.h"
#include "User.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(std::unordered_map<std::string,User> *allU,std::stack<Transaction> *allT,QWidget *parent);
    ~MainWindow();
    std::stack<Transaction> *allTransactions = new std::stack<Transaction>;
    std::unordered_map<std::string,User> *allUsers = new std::unordered_map<std::string,User>;
    void logIn(QString name);

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
