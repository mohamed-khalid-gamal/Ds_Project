QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    SaveLoad.cpp \
    Transaction.cpp \
    User.cpp \
    accountutil.cpp \
    adminwindow.cpp \
    edituserswindow.cpp \
    forgetpasswordwindow.cpp \
    listusers.cpp \
    main.cpp \
    mainwindow.cpp \
    pendingtransactionswindow.cpp \
    registerwindow.cpp \
    requestmoneywindow.cpp \
    resetpinwindow.cpp \
    sendmoneywindow.cpp \
    transactionhistory.cpp \
    userwindow.cpp
HEADERS += \
    SaveLoad.h \
    Transaction.h \
    User.h \
    accountutil.h \
    adminwindow.h \
    edituserswindow.h \
    forgetpasswordwindow.h \
    listusers.h \
    mainwindow.h \
    pendingtransactionswindow.h \
    registerwindow.h \
    requestmoneywindow.h \
    resetpinwindow.h \
    sendmoneywindow.h \
    transactionhistory.h \
    userwindow.h

FORMS += \
    adminwindow.ui \
    edituserswindow.ui \
    forgetpasswordwindow.ui \
    listusers.ui \
    mainwindow.ui \
    pendingtransactionswindow.ui \
    registerwindow.ui \
    requestmoneywindow.ui \
    resetpinwindow.ui \
    sendmoneywindow.ui \
    transactionhistory.ui \
    userwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
