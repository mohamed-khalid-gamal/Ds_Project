#ifndef ACCOUNTUTIL_H
#define ACCOUNTUTIL_H
#include <string>
#include <QString>

class AccountUtil
{
public:
    AccountUtil();
    std::string hashText(std::string);
    QString validPassword(std::string password);
};

#endif // ACCOUNTUTIL_H
