QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Account.cpp \
    Admin.cpp \
    Menu.cpp \
    SaveLoad.cpp \
    Transaction.cpp \
    User.cpp \
    main.cpp \
    mainwindow.cpp
    Account.cpp
    Admin.cpp
    DS_project2.cpp
    LogIn.cpp
    Menu.cpp
    SaveLoad.cpp
    Transaction.cpp
    User.cpp
HEADERS += \
    Account.h \
    Admin.h \
    Menu.h \
    SaveLoad.h \
    Transaction.h \
    User.h \
    mainwindow.h
    Account.h
    Admin.h
    DS_project2.h
    LogIn.h
    Menu.h
    SaveLoad.h
    Transaction.h
    User.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
