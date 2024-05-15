/********************************************************************************
** Form generated from reading UI file 'userwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_userwindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QPushButton *pushButton_7;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QDialog *userwindow)
    {
        if (userwindow->objectName().isEmpty())
            userwindow->setObjectName("userwindow");
        userwindow->resize(1280, 720);
        verticalLayout_2 = new QVBoxLayout(userwindow);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(userwindow);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(44);
        label->setFont(font);

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(userwindow);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        pushButton_7 = new QPushButton(userwindow);
        pushButton_7->setObjectName("pushButton_7");

        horizontalLayout->addWidget(pushButton_7);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton = new QPushButton(userwindow);
        pushButton->setObjectName("pushButton");

        verticalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(userwindow);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(userwindow);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(userwindow);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout_2->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(userwindow);
        pushButton_5->setObjectName("pushButton_5");

        verticalLayout_2->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(userwindow);
        pushButton_6->setObjectName("pushButton_6");

        verticalLayout_2->addWidget(pushButton_6);


        retranslateUi(userwindow);

        QMetaObject::connectSlotsByName(userwindow);
    } // setupUi

    void retranslateUi(QDialog *userwindow)
    {
        userwindow->setWindowTitle(QCoreApplication::translate("userwindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("userwindow", "User: ", nullptr));
        label_2->setText(QCoreApplication::translate("userwindow", "Balance:", nullptr));
        pushButton_7->setText(QCoreApplication::translate("userwindow", "Refresh Balance Data", nullptr));
        pushButton->setText(QCoreApplication::translate("userwindow", "Send Money", nullptr));
        pushButton_2->setText(QCoreApplication::translate("userwindow", "Request Money", nullptr));
        pushButton_3->setText(QCoreApplication::translate("userwindow", "Transaction History", nullptr));
        pushButton_4->setText(QCoreApplication::translate("userwindow", "Pending Transactions", nullptr));
        pushButton_5->setText(QCoreApplication::translate("userwindow", "Reset Pin", nullptr));
        pushButton_6->setText(QCoreApplication::translate("userwindow", "Log out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userwindow: public Ui_userwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
