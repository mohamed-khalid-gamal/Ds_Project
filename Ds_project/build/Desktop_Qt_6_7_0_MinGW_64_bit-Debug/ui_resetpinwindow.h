/********************************************************************************
** Form generated from reading UI file 'resetpinwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETPINWINDOW_H
#define UI_RESETPINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_resetPinWindow
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
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *resetPinWindow)
    {
        if (resetPinWindow->objectName().isEmpty())
            resetPinWindow->setObjectName("resetPinWindow");
        resetPinWindow->resize(1280, 720);
        verticalLayout_2 = new QVBoxLayout(resetPinWindow);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(resetPinWindow);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(33);
        label->setFont(font);

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        label_4 = new QLabel(resetPinWindow);
        label_4->setObjectName("label_4");
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: darkred"));

        verticalLayout->addWidget(label_4, 0, Qt::AlignLeft|Qt::AlignVCenter);


        verticalLayout_2->addLayout(verticalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_2 = new QLabel(resetPinWindow);
        label_2->setObjectName("label_2");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        lineEdit = new QLineEdit(resetPinWindow);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_3 = new QLabel(resetPinWindow);
        label_3->setObjectName("label_3");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        lineEdit_2 = new QLineEdit(resetPinWindow);
        lineEdit_2->setObjectName("lineEdit_2");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_2);


        verticalLayout_2->addLayout(formLayout);

        pushButton_2 = new QPushButton(resetPinWindow);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(resetPinWindow);
        pushButton->setObjectName("pushButton");

        verticalLayout_2->addWidget(pushButton);


        retranslateUi(resetPinWindow);

        QMetaObject::connectSlotsByName(resetPinWindow);
    } // setupUi

    void retranslateUi(QDialog *resetPinWindow)
    {
        resetPinWindow->setWindowTitle(QCoreApplication::translate("resetPinWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("resetPinWindow", "Reset Pin\n"
"Note: Default pin is 000000", nullptr));
        label_4->setText(QCoreApplication::translate("resetPinWindow", "Message:", nullptr));
        label_2->setText(QCoreApplication::translate("resetPinWindow", "Old Pin:", nullptr));
        label_3->setText(QCoreApplication::translate("resetPinWindow", "New Pin", nullptr));
        pushButton_2->setText(QCoreApplication::translate("resetPinWindow", "Reset Pin", nullptr));
        pushButton->setText(QCoreApplication::translate("resetPinWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class resetPinWindow: public Ui_resetPinWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETPINWINDOW_H
