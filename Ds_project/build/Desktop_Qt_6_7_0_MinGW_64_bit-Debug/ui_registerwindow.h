/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_registerwindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;

    void setupUi(QDialog *registerwindow)
    {
        if (registerwindow->objectName().isEmpty())
            registerwindow->setObjectName("registerwindow");
        registerwindow->resize(1280, 720);
        verticalLayout_2 = new QVBoxLayout(registerwindow);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(registerwindow);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(55);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(label, 0, Qt::AlignHCenter);

        label_4 = new QLabel(registerwindow);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(689, 135));
        QFont font1;
        font1.setPointSize(33);
        label_4->setFont(font1);

        verticalLayout_2->addWidget(label_4, 0, Qt::AlignHCenter);

        label_5 = new QLabel(registerwindow);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(56, 136));
        QFont font2;
        font2.setPointSize(22);
        label_5->setFont(font2);
        label_5->setStyleSheet(QString::fromUtf8("color: darkred"));

        verticalLayout_2->addWidget(label_5, 0, Qt::AlignHCenter);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_2 = new QLabel(registerwindow);
        label_2->setObjectName("label_2");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit = new QLineEdit(registerwindow);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_3 = new QLabel(registerwindow);
        label_3->setObjectName("label_3");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineEdit_2 = new QLineEdit(registerwindow);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);


        verticalLayout_2->addLayout(formLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushButton_2 = new QPushButton(registerwindow);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton_4 = new QPushButton(registerwindow);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout->addWidget(pushButton_4);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(registerwindow);

        QMetaObject::connectSlotsByName(registerwindow);
    } // setupUi

    void retranslateUi(QDialog *registerwindow)
    {
        registerwindow->setWindowTitle(QCoreApplication::translate("registerwindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("registerwindow", "Digital Wallet", nullptr));
        label_4->setText(QCoreApplication::translate("registerwindow", "Username must be between 5 and 16 letters in length.\n"
"Password must be between 8 and 16 letters length", nullptr));
        label_5->setText(QCoreApplication::translate("registerwindow", "Message: No Errors", nullptr));
        label_2->setText(QCoreApplication::translate("registerwindow", "User Name", nullptr));
        label_3->setText(QCoreApplication::translate("registerwindow", "Password", nullptr));
        pushButton_2->setText(QCoreApplication::translate("registerwindow", "Register", nullptr));
        pushButton_4->setText(QCoreApplication::translate("registerwindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registerwindow: public Ui_registerwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
