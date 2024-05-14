#include "mainwindow.h"
#include "SaveLoad.h"

#include <QApplication>
int main(int argc, char *argv[])
{
    std::unordered_map<std::string,User> *allU = new std::unordered_map<std::string,User>;
    std::stack<Transaction> *allT = new std::stack<Transaction>;
    SaveLoad file;
    *allT = file.loadTransactions();
    *allU = file.loadUsers(*allT);
    QApplication a(argc, argv);
    MainWindow w(allU,allT, NULL);
    w.show();
    file.saveUsers(*allU);
    file.saveTransactions(*allT);
    allU = NULL;
    allT = NULL;
    delete allU;
    delete allT;
    return a.exec();
}
