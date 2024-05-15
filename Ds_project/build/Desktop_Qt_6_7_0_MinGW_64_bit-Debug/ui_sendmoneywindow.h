/********************************************************************************
** Form generated from reading UI file 'sendmoneywindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENDMONEYWINDOW_H
#define UI_SENDMONEYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_sendMoneyWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_4;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *sendMoneyWindow)
    {
        if (sendMoneyWindow->objectName().isEmpty())
            sendMoneyWindow->setObjectName("sendMoneyWindow");
        sendMoneyWindow->resize(1280, 720);
        verticalLayout_2 = new QVBoxLayout(sendMoneyWindow);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(sendMoneyWindow);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(33);
        label->setFont(font);

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        label_4 = new QLabel(sendMoneyWindow);
        label_4->setObjectName("label_4");
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: darkgreen"));

        verticalLayout->addWidget(label_4, 0, Qt::AlignLeft|Qt::AlignVCenter);


        verticalLayout_2->addLayout(verticalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_2 = new QLabel(sendMoneyWindow);
        label_2->setObjectName("label_2");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit = new QLineEdit(sendMoneyWindow);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_3 = new QLabel(sendMoneyWindow);
        label_3->setObjectName("label_3");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineEdit_2 = new QLineEdit(sendMoneyWindow);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_5 = new QLabel(sendMoneyWindow);
        label_5->setObjectName("label_5");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        lineEdit_3 = new QLineEdit(sendMoneyWindow);
        lineEdit_3->setObjectName("lineEdit_3");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_3);


        verticalLayout_2->addLayout(formLayout);

        pushButton_2 = new QPushButton(sendMoneyWindow);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(sendMoneyWindow);
        pushButton->setObjectName("pushButton");

        verticalLayout_2->addWidget(pushButton);


        retranslateUi(sendMoneyWindow);

        QMetaObject::connectSlotsByName(sendMoneyWindow);
    } // setupUi

    void retranslateUi(QDialog *sendMoneyWindow)
    {
        sendMoneyWindow->setWindowTitle(QCoreApplication::translate("sendMoneyWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("sendMoneyWindow", "Send Money", nullptr));
        label_4->setText(QCoreApplication::translate("sendMoneyWindow", "Message: No Errors", nullptr));
        label_2->setText(QCoreApplication::translate("sendMoneyWindow", "Username:", nullptr));
        label_3->setText(QCoreApplication::translate("sendMoneyWindow", "Amount: ", nullptr));
        label_5->setText(QCoreApplication::translate("sendMoneyWindow", "Pin:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("sendMoneyWindow", "Send Money", nullptr));
        pushButton->setText(QCoreApplication::translate("sendMoneyWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sendMoneyWindow: public Ui_sendMoneyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENDMONEYWINDOW_H
