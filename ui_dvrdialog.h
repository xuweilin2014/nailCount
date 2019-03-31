/********************************************************************************
** Form generated from reading UI file 'dvrdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DVRDIALOG_H
#define UI_DVRDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DVRDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelFP;
    QLineEdit *lineFP;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelSP;
    QLineEdit *lineSP;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelCSL;
    QLineEdit *lineCSL;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelCS;
    QLineEdit *lineCS;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelUCS;
    QLineEdit *lineUCS;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelMDTP;
    QLineEdit *lineMDTP;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelTP;
    QLineEdit *lineTP;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labelP;
    QLineEdit *lineP;
    QPushButton *buttonOK;
    QPushButton *buttonCancel;

    void setupUi(QDialog *DVRDialog)
    {
        if (DVRDialog->objectName().isEmpty())
            DVRDialog->setObjectName(QStringLiteral("DVRDialog"));
        DVRDialog->resize(315, 372);
        layoutWidget = new QWidget(DVRDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 20, 203, 291));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelFP = new QLabel(layoutWidget);
        labelFP->setObjectName(QStringLiteral("labelFP"));

        horizontalLayout->addWidget(labelFP);

        lineFP = new QLineEdit(layoutWidget);
        lineFP->setObjectName(QStringLiteral("lineFP"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineFP->sizePolicy().hasHeightForWidth());
        lineFP->setSizePolicy(sizePolicy);
        lineFP->setMinimumSize(QSize(40, 0));
        lineFP->setMaximumSize(QSize(120, 16777215));
        lineFP->setReadOnly(true);

        horizontalLayout->addWidget(lineFP);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelSP = new QLabel(layoutWidget);
        labelSP->setObjectName(QStringLiteral("labelSP"));

        horizontalLayout_2->addWidget(labelSP);

        lineSP = new QLineEdit(layoutWidget);
        lineSP->setObjectName(QStringLiteral("lineSP"));
        lineSP->setMaximumSize(QSize(120, 16777215));
        lineSP->setReadOnly(true);

        horizontalLayout_2->addWidget(lineSP);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelCSL = new QLabel(layoutWidget);
        labelCSL->setObjectName(QStringLiteral("labelCSL"));

        horizontalLayout_3->addWidget(labelCSL);

        lineCSL = new QLineEdit(layoutWidget);
        lineCSL->setObjectName(QStringLiteral("lineCSL"));
        lineCSL->setMaximumSize(QSize(120, 16777215));
        lineCSL->setReadOnly(true);

        horizontalLayout_3->addWidget(lineCSL);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelCS = new QLabel(layoutWidget);
        labelCS->setObjectName(QStringLiteral("labelCS"));

        horizontalLayout_4->addWidget(labelCS);

        lineCS = new QLineEdit(layoutWidget);
        lineCS->setObjectName(QStringLiteral("lineCS"));
        lineCS->setMaximumSize(QSize(120, 16777215));
        lineCS->setReadOnly(true);

        horizontalLayout_4->addWidget(lineCS);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelUCS = new QLabel(layoutWidget);
        labelUCS->setObjectName(QStringLiteral("labelUCS"));

        horizontalLayout_5->addWidget(labelUCS);

        lineUCS = new QLineEdit(layoutWidget);
        lineUCS->setObjectName(QStringLiteral("lineUCS"));
        lineUCS->setMaximumSize(QSize(120, 16777215));
        lineUCS->setReadOnly(true);

        horizontalLayout_5->addWidget(lineUCS);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        labelMDTP = new QLabel(layoutWidget);
        labelMDTP->setObjectName(QStringLiteral("labelMDTP"));

        horizontalLayout_6->addWidget(labelMDTP);

        lineMDTP = new QLineEdit(layoutWidget);
        lineMDTP->setObjectName(QStringLiteral("lineMDTP"));
        lineMDTP->setMaximumSize(QSize(120, 16777215));
        lineMDTP->setReadOnly(true);

        horizontalLayout_6->addWidget(lineMDTP);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        labelTP = new QLabel(layoutWidget);
        labelTP->setObjectName(QStringLiteral("labelTP"));

        horizontalLayout_7->addWidget(labelTP);

        lineTP = new QLineEdit(layoutWidget);
        lineTP->setObjectName(QStringLiteral("lineTP"));
        lineTP->setMaximumSize(QSize(120, 16777215));
        lineTP->setReadOnly(true);

        horizontalLayout_7->addWidget(lineTP);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        labelP = new QLabel(layoutWidget);
        labelP->setObjectName(QStringLiteral("labelP"));

        horizontalLayout_8->addWidget(labelP);

        lineP = new QLineEdit(layoutWidget);
        lineP->setObjectName(QStringLiteral("lineP"));
        lineP->setMaximumSize(QSize(120, 16777215));
        lineP->setReadOnly(true);

        horizontalLayout_8->addWidget(lineP);


        verticalLayout->addLayout(horizontalLayout_8);

        buttonOK = new QPushButton(DVRDialog);
        buttonOK->setObjectName(QStringLiteral("buttonOK"));
        buttonOK->setGeometry(QRect(40, 330, 61, 31));
        buttonCancel = new QPushButton(DVRDialog);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        buttonCancel->setGeometry(QRect(200, 330, 61, 31));

        retranslateUi(DVRDialog);
        QObject::connect(buttonOK, SIGNAL(clicked()), DVRDialog, SLOT(accept()));
        QObject::connect(buttonCancel, SIGNAL(clicked()), DVRDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DVRDialog);
    } // setupUi

    void retranslateUi(QDialog *DVRDialog)
    {
        DVRDialog->setWindowTitle(QApplication::translate("DVRDialog", "DVR\351\222\211\347\233\222\350\256\241\346\225\260", Q_NULLPTR));
        labelFP->setText(QApplication::translate("DVRDialog", "FP\345\214\272\346\225\260\347\233\256\357\274\232", Q_NULLPTR));
        labelSP->setText(QApplication::translate("DVRDialog", "SP\345\214\272\346\225\260\347\233\256\357\274\232", Q_NULLPTR));
        labelCSL->setText(QApplication::translate("DVRDialog", "CSL\345\214\272\346\225\260\347\233\256\357\274\232", Q_NULLPTR));
        labelCS->setText(QApplication::translate("DVRDialog", "CS\345\214\272\346\225\260\347\233\256\357\274\232", Q_NULLPTR));
        labelUCS->setText(QApplication::translate("DVRDialog", "UCS\345\214\272\346\225\260\347\233\256\357\274\232", Q_NULLPTR));
        labelMDTP->setText(QApplication::translate("DVRDialog", "MDTP\345\214\272\346\225\260\347\233\256\357\274\232", Q_NULLPTR));
        labelTP->setText(QApplication::translate("DVRDialog", "TP\345\214\272\346\225\260\347\233\256\357\274\232", Q_NULLPTR));
        labelP->setText(QApplication::translate("DVRDialog", "P\345\214\272\346\225\260\347\233\256\357\274\232", Q_NULLPTR));
        buttonOK->setText(QApplication::translate("DVRDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        buttonCancel->setText(QApplication::translate("DVRDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DVRDialog: public Ui_DVRDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DVRDIALOG_H
