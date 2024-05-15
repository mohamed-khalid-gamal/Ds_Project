#include "accountutil.h"
#include <ostream>

AccountUtil::AccountUtil() {

}

std::string AccountUtil::hashText(std::string pendingText){
    int temp = 0;
    std::string hashedText;
    for (int i = 0; i < (int) pendingText.length(); i++) {
        temp += pendingText[i];
    }
    hashedText = std::to_string(temp);
    return hashedText;
}

QString AccountUtil::validPassword(std::string password) {
    QString message;
    for (char ch : password) {
        if (ch == ' ') {
            message = "Password must not contains a space";
            return message;
        }
    }
    if (password.length() < 8) {
        message = "Password must be at least 8 characters long.";
        return message;
    }
    bool hasUpperCase = false;
    for (char c : password) {
        if (isupper(c)) {
            hasUpperCase = true;
            break;
        }
    }
    if (!hasUpperCase) {
        message = "Password must contain at least one uppercase and lowercase letters, digit, special character.";
        return message;
    }
    bool hasLowerCase = false;
    for (char c : password) {
        if (islower(c)) {
            hasLowerCase = true;
            break;
        }
    }
    if (!hasLowerCase) {
        message =  "Password must contain at least one uppercase and lowercase letters, digit, special character.";
        return message;
    }
    bool hasDigit = false;
    for (char c : password) {
        if (isdigit(c)) {
            hasDigit = true;
            break;
        }
    }
    if (!hasDigit) {
        message = "Password must contain at least one uppercase and lowercase letters, digit, special character.";
        return message;
    }
    bool hasSpecialChar = false;
    for (char c : password) {
        if (!isalnum(c)) {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) {
        message = "Password must contain at least one uppercase and lowercase letters, digit, special character.";
        return message;
    }
    message = "Success";
    return message;
}
