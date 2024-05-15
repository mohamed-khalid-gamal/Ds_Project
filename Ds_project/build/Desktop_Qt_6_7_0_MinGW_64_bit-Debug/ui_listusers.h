/********************************************************************************
** Form generated from reading UI file 'listusers.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTUSERS_H
#define UI_LISTUSERS_H

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

class Ui_listUsers
{
public:
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *listUsers)
    {
        if (listUsers->objectName().isEmpty())
            listUsers->setObjectName("listUsers");
        listUsers->resize(1280, 720);
        verticalLayout_2 = new QVBoxLayout(listUsers);
        verticalLayout_2->setObjectName("verticalLayout_2");
        scrollArea = new QScrollArea(listUsers);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1260, 588));
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

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_2 = new QLabel(listUsers);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(listUsers);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        pushButton_3 = new QPushButton(listUsers);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout_2->addLayout(horizontalLayout);

        pushButton_2 = new QPushButton(listUsers);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(listUsers);
        pushButton->setObjectName("pushButton");

        verticalLayout_2->addWidget(pushButton);


        retranslateUi(listUsers);

        QMetaObject::connectSlotsByName(listUsers);
    } // setupUi

    void retranslateUi(QDialog *listUsers)
    {
        listUsers->setWindowTitle(QCoreApplication::translate("listUsers", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("listUsers", "Users:", nullptr));
        label_2->setText(QCoreApplication::translate("listUsers", "Username:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("listUsers", "Check Transactions", nullptr));
        pushButton_2->setText(QCoreApplication::translate("listUsers", "Refresh User List", nullptr));
        pushButton->setText(QCoreApplication::translate("listUsers", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class listUsers: public Ui_listUsers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTUSERS_H
