/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_adminwindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;

    void setupUi(QDialog *adminwindow)
    {
        if (adminwindow->objectName().isEmpty())
            adminwindow->setObjectName("adminwindow");
        adminwindow->resize(1280, 720);
        verticalLayout_2 = new QVBoxLayout(adminwindow);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(adminwindow);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(44);
        label->setFont(font);

        verticalLayout_2->addWidget(label, 0, Qt::AlignHCenter);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(adminwindow);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(adminwindow);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(adminwindow);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(adminwindow);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(adminwindow);

        QMetaObject::connectSlotsByName(adminwindow);
    } // setupUi

    void retranslateUi(QDialog *adminwindow)
    {
        adminwindow->setWindowTitle(QCoreApplication::translate("adminwindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("adminwindow", "Admin", nullptr));
        pushButton->setText(QCoreApplication::translate("adminwindow", "List Users", nullptr));
        pushButton_2->setText(QCoreApplication::translate("adminwindow", "Edit Users", nullptr));
        pushButton_4->setText(QCoreApplication::translate("adminwindow", "List All Transactions", nullptr));
        pushButton_3->setText(QCoreApplication::translate("adminwindow", "Log out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminwindow: public Ui_adminwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
