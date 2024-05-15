/********************************************************************************
** Form generated from reading UI file 'pendingtransactionswindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PENDINGTRANSACTIONSWINDOW_H
#define UI_PENDINGTRANSACTIONSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pendingTransactionsWindow
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton;

    void setupUi(QDialog *pendingTransactionsWindow)
    {
        if (pendingTransactionsWindow->objectName().isEmpty())
            pendingTransactionsWindow->setObjectName("pendingTransactionsWindow");
        pendingTransactionsWindow->resize(1280, 720);
        verticalLayout = new QVBoxLayout(pendingTransactionsWindow);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(pendingTransactionsWindow);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1260, 588));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName("verticalLayout_2");
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(22);
        label->setFont(font);

        verticalLayout_2->addWidget(label, 0, Qt::AlignLeft|Qt::AlignTop);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(pendingTransactionsWindow);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(pendingTransactionsWindow);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        pushButton_2 = new QPushButton(pendingTransactionsWindow);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        pushButton_4 = new QPushButton(pendingTransactionsWindow);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout->addWidget(pushButton_4);

        pushButton = new QPushButton(pendingTransactionsWindow);
        pushButton->setObjectName("pushButton");

        verticalLayout->addWidget(pushButton);


        retranslateUi(pendingTransactionsWindow);

        QMetaObject::connectSlotsByName(pendingTransactionsWindow);
    } // setupUi

    void retranslateUi(QDialog *pendingTransactionsWindow)
    {
        pendingTransactionsWindow->setWindowTitle(QCoreApplication::translate("pendingTransactionsWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("pendingTransactionsWindow", "Pending Transactions:", nullptr));
        label_2->setText(QCoreApplication::translate("pendingTransactionsWindow", "Transaction ID:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("pendingTransactionsWindow", "Accept", nullptr));
        pushButton_4->setText(QCoreApplication::translate("pendingTransactionsWindow", "Refresh Transactions", nullptr));
        pushButton->setText(QCoreApplication::translate("pendingTransactionsWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pendingTransactionsWindow: public Ui_pendingTransactionsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PENDINGTRANSACTIONSWINDOW_H
