/********************************************************************************
** Form generated from reading UI file 'forgetpasswordwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORGETPASSWORDWINDOW_H
#define UI_FORGETPASSWORDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_forgetPasswordWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QFormLayout *formLayout_2;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QDialog *forgetPasswordWindow)
    {
        if (forgetPasswordWindow->objectName().isEmpty())
            forgetPasswordWindow->setObjectName("forgetPasswordWindow");
        forgetPasswordWindow->resize(1280, 720);
        verticalLayout_3 = new QVBoxLayout(forgetPasswordWindow);
        verticalLayout_3->setObjectName("verticalLayout_3");
        label = new QLabel(forgetPasswordWindow);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(55);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(label);

        label_4 = new QLabel(forgetPasswordWindow);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(689, 135));
        QFont font1;
        font1.setPointSize(33);
        label_4->setFont(font1);

        verticalLayout_3->addWidget(label_4);

        label_5 = new QLabel(forgetPasswordWindow);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(56, 136));
        QFont font2;
        font2.setPointSize(22);
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("color: darkred"));

        verticalLayout_3->addWidget(label_5);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        label_6 = new QLabel(forgetPasswordWindow);
        label_6->setObjectName("label_6");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_6);

        lineEdit_3 = new QLineEdit(forgetPasswordWindow);
        lineEdit_3->setObjectName("lineEdit_3");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit_3);

        label_7 = new QLabel(forgetPasswordWindow);
        label_7->setObjectName("label_7");

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_7);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit_4 = new QLineEdit(forgetPasswordWindow);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_4);

        pushButton_3 = new QPushButton(forgetPasswordWindow);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_2->addWidget(pushButton_3);


        formLayout_2->setLayout(1, QFormLayout::FieldRole, horizontalLayout_2);


        verticalLayout_3->addLayout(formLayout_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        pushButton_5 = new QPushButton(forgetPasswordWindow);
        pushButton_5->setObjectName("pushButton_5");

        verticalLayout_2->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(forgetPasswordWindow);
        pushButton_6->setObjectName("pushButton_6");

        verticalLayout_2->addWidget(pushButton_6);


        verticalLayout_3->addLayout(verticalLayout_2);


        retranslateUi(forgetPasswordWindow);

        QMetaObject::connectSlotsByName(forgetPasswordWindow);
    } // setupUi

    void retranslateUi(QDialog *forgetPasswordWindow)
    {
        forgetPasswordWindow->setWindowTitle(QCoreApplication::translate("forgetPasswordWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("forgetPasswordWindow", "Digital Wallet", nullptr));
        label_4->setText(QCoreApplication::translate("forgetPasswordWindow", "Enter Username and new Password.\n"
"Password must be between 8 and 16 letters", nullptr));
        label_5->setText(QCoreApplication::translate("forgetPasswordWindow", "Message: No Errors", nullptr));
        label_6->setText(QCoreApplication::translate("forgetPasswordWindow", "User Name", nullptr));
        label_7->setText(QCoreApplication::translate("forgetPasswordWindow", "Password", nullptr));
        pushButton_3->setText(QCoreApplication::translate("forgetPasswordWindow", "Show Pass", nullptr));
        pushButton_5->setText(QCoreApplication::translate("forgetPasswordWindow", "Change Password", nullptr));
        pushButton_6->setText(QCoreApplication::translate("forgetPasswordWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class forgetPasswordWindow: public Ui_forgetPasswordWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORGETPASSWORDWINDOW_H
