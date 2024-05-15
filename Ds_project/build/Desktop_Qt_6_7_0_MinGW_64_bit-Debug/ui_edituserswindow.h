/********************************************************************************
** Form generated from reading UI file 'edituserswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITUSERSWINDOW_H
#define UI_EDITUSERSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_editUsersWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_5;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_4;

    void setupUi(QDialog *editUsersWindow)
    {
        if (editUsersWindow->objectName().isEmpty())
            editUsersWindow->setObjectName("editUsersWindow");
        editUsersWindow->resize(1280, 720);
        verticalLayout_2 = new QVBoxLayout(editUsersWindow);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(editUsersWindow);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(33);
        label->setFont(font);

        verticalLayout_2->addWidget(label, 0, Qt::AlignHCenter);

        label_5 = new QLabel(editUsersWindow);
        label_5->setObjectName("label_5");
        QFont font1;
        font1.setPointSize(22);
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color: darkred"));

        verticalLayout_2->addWidget(label_5);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_2 = new QLabel(editUsersWindow);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit = new QLineEdit(editUsersWindow);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_3 = new QLabel(editUsersWindow);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineEdit_2 = new QLineEdit(editUsersWindow);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_4 = new QLabel(editUsersWindow);
        label_4->setObjectName("label_4");
        label_4->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        lineEdit_3 = new QLineEdit(editUsersWindow);
        lineEdit_3->setObjectName("lineEdit_3");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);


        verticalLayout_2->addLayout(formLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButton = new QPushButton(editUsersWindow);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(editUsersWindow);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(editUsersWindow);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);

        pushButton_5 = new QPushButton(editUsersWindow);
        pushButton_5->setObjectName("pushButton_5");

        verticalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(editUsersWindow);
        pushButton_6->setObjectName("pushButton_6");

        verticalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(editUsersWindow);
        pushButton_7->setObjectName("pushButton_7");

        verticalLayout->addWidget(pushButton_7);

        pushButton_4 = new QPushButton(editUsersWindow);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout->addWidget(pushButton_4);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(editUsersWindow);

        QMetaObject::connectSlotsByName(editUsersWindow);
    } // setupUi

    void retranslateUi(QDialog *editUsersWindow)
    {
        editUsersWindow->setWindowTitle(QCoreApplication::translate("editUsersWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("editUsersWindow", "Edit User", nullptr));
        label_5->setText(QCoreApplication::translate("editUsersWindow", "Message:", nullptr));
        label_2->setText(QCoreApplication::translate("editUsersWindow", "Current Username:", nullptr));
        label_3->setText(QCoreApplication::translate("editUsersWindow", "New Username:", nullptr));
        label_4->setText(QCoreApplication::translate("editUsersWindow", "New Password:", nullptr));
        pushButton->setText(QCoreApplication::translate("editUsersWindow", "List Users", nullptr));
        pushButton_2->setText(QCoreApplication::translate("editUsersWindow", "Change Username", nullptr));
        pushButton_3->setText(QCoreApplication::translate("editUsersWindow", "Change Password", nullptr));
        pushButton_5->setText(QCoreApplication::translate("editUsersWindow", "Remove User", nullptr));
        pushButton_6->setText(QCoreApplication::translate("editUsersWindow", "Ban User", nullptr));
        pushButton_7->setText(QCoreApplication::translate("editUsersWindow", "Unban User", nullptr));
        pushButton_4->setText(QCoreApplication::translate("editUsersWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editUsersWindow: public Ui_editUsersWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITUSERSWINDOW_H
