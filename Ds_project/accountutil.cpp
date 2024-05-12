#include "accountutil.h"

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
