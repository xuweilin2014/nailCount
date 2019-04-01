/********************************************************************************
** Form generated from reading UI file 'informatiodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATIODIALOG_H
#define UI_INFORMATIODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_InformatioDialog
{
public:
    QLabel *infoLabel;
    QPushButton *buttonOK;
    QPushButton *buttonCancel;

    void setupUi(QDialog *InformatioDialog)
    {
        if (InformatioDialog->objectName().isEmpty())
            InformatioDialog->setObjectName(QStringLiteral("InformatioDialog"));
        InformatioDialog->resize(252, 150);
        infoLabel = new QLabel(InformatioDialog);
        infoLabel->setObjectName(QStringLiteral("infoLabel"));
        infoLabel->setGeometry(QRect(40, 30, 161, 41));
        infoLabel->setAlignment(Qt::AlignCenter);
        buttonOK = new QPushButton(InformatioDialog);
        buttonOK->setObjectName(QStringLiteral("buttonOK"));
        buttonOK->setGeometry(QRect(30, 100, 61, 31));
        buttonCancel = new QPushButton(InformatioDialog);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        buttonCancel->setGeometry(QRect(150, 100, 61, 31));

        retranslateUi(InformatioDialog);
        QObject::connect(buttonOK, SIGNAL(clicked()), InformatioDialog, SLOT(accept()));
        QObject::connect(buttonCancel, SIGNAL(clicked()), InformatioDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(InformatioDialog);
    } // setupUi

    void retranslateUi(QDialog *InformatioDialog)
    {
        InformatioDialog->setWindowTitle(QApplication::translate("InformatioDialog", "Dialog", Q_NULLPTR));
        infoLabel->setText(QString());
        buttonOK->setText(QApplication::translate("InformatioDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        buttonCancel->setText(QApplication::translate("InformatioDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InformatioDialog: public Ui_InformatioDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMATIODIALOG_H
