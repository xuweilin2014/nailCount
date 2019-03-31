/********************************************************************************
** Form generated from reading UI file 'polyxdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POLYXDIALOG_H
#define UI_POLYXDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_PolyxDialog
{
public:

    void setupUi(QDialog *PolyxDialog)
    {
        if (PolyxDialog->objectName().isEmpty())
            PolyxDialog->setObjectName(QStringLiteral("PolyxDialog"));
        PolyxDialog->resize(400, 300);

        retranslateUi(PolyxDialog);

        QMetaObject::connectSlotsByName(PolyxDialog);
    } // setupUi

    void retranslateUi(QDialog *PolyxDialog)
    {
        PolyxDialog->setWindowTitle(QApplication::translate("PolyxDialog", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PolyxDialog: public Ui_PolyxDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POLYXDIALOG_H
