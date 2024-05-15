/********************************************************************************
** Form generated from reading UI file 'transactionhistory.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSACTIONHISTORY_H
#define UI_TRANSACTIONHISTORY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_transactionHistory
{
public:
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *transactionHistory)
    {
        if (transactionHistory->objectName().isEmpty())
            transactionHistory->setObjectName("transactionHistory");
        transactionHistory->resize(1280, 720);
        verticalLayout_2 = new QVBoxLayout(transactionHistory);
        verticalLayout_2->setObjectName("verticalLayout_2");
        scrollArea = new QScrollArea(transactionHistory);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1260, 634));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(22);
        label->setFont(font);

        verticalLayout->addWidget(label, 0, Qt::AlignTop);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        pushButton_2 = new QPushButton(transactionHistory);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(transactionHistory);
        pushButton->setObjectName("pushButton");

        verticalLayout_2->addWidget(pushButton);


        retranslateUi(transactionHistory);

        QMetaObject::connectSlotsByName(transactionHistory);
    } // setupUi

    void retranslateUi(QDialog *transactionHistory)
    {
        transactionHistory->setWindowTitle(QCoreApplication::translate("transactionHistory", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("transactionHistory", "Transactions:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("transactionHistory", "Refresh Transactions", nullptr));
        pushButton->setText(QCoreApplication::translate("transactionHistory", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class transactionHistory: public Ui_transactionHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSACTIONHISTORY_H
