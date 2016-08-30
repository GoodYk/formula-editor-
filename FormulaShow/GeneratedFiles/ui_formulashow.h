/********************************************************************************
** Form generated from reading UI file 'formulashow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMULASHOW_H
#define UI_FORMULASHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormulaShowClass
{
public:
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit2;
    QWidget *widget;

    void setupUi(QWidget *FormulaShowClass)
    {
        if (FormulaShowClass->objectName().isEmpty())
            FormulaShowClass->setObjectName(QStringLiteral("FormulaShowClass"));
        FormulaShowClass->resize(946, 569);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FormulaShowClass->sizePolicy().hasHeightForWidth());
        FormulaShowClass->setSizePolicy(sizePolicy);
        FormulaShowClass->setMaximumSize(QSize(946, 16777215));
        plainTextEdit = new QPlainTextEdit(FormulaShowClass);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(10, 20, 321, 541));
        plainTextEdit2 = new QPlainTextEdit(FormulaShowClass);
        plainTextEdit2->setObjectName(QStringLiteral("plainTextEdit2"));
        plainTextEdit2->setGeometry(QRect(360, 20, 571, 271));
        widget = new QWidget(FormulaShowClass);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(360, 300, 571, 261));

        retranslateUi(FormulaShowClass);

        QMetaObject::connectSlotsByName(FormulaShowClass);
    } // setupUi

    void retranslateUi(QWidget *FormulaShowClass)
    {
        FormulaShowClass->setWindowTitle(QApplication::translate("FormulaShowClass", "FormulaShow", 0));
    } // retranslateUi

};

namespace Ui {
    class FormulaShowClass: public Ui_FormulaShowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMULASHOW_H
