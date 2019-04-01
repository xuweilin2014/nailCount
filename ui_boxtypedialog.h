/********************************************************************************
** Form generated from reading UI file 'boxtypedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOXTYPEDIALOG_H
#define UI_BOXTYPEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BoxTypeDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBoxType;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *comboBoxNailColor;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonOK;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *buttonCancel;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *BoxTypeDialog)
    {
        if (BoxTypeDialog->objectName().isEmpty())
            BoxTypeDialog->setObjectName(QStringLiteral("BoxTypeDialog"));
        BoxTypeDialog->resize(326, 168);
        layoutWidget = new QWidget(BoxTypeDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 20, 221, 81));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBoxType = new QComboBox(layoutWidget);
        comboBoxType->setObjectName(QStringLiteral("comboBoxType"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxType->sizePolicy().hasHeightForWidth());
        comboBoxType->setSizePolicy(sizePolicy);
        comboBoxType->setMinimumSize(QSize(140, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        comboBoxType->setFont(font);

        horizontalLayout->addWidget(comboBoxType);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        comboBoxNailColor = new QComboBox(layoutWidget);
        comboBoxNailColor->setObjectName(QStringLiteral("comboBoxNailColor"));
        sizePolicy.setHeightForWidth(comboBoxNailColor->sizePolicy().hasHeightForWidth());
        comboBoxNailColor->setSizePolicy(sizePolicy);
        comboBoxNailColor->setMinimumSize(QSize(140, 0));
        comboBoxNailColor->setFont(font);

        horizontalLayout_2->addWidget(comboBoxNailColor);


        verticalLayout->addLayout(horizontalLayout_2);

        layoutWidget1 = new QWidget(BoxTypeDialog);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 120, 321, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        buttonOK = new QPushButton(layoutWidget1);
        buttonOK->setObjectName(QStringLiteral("buttonOK"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(buttonOK->sizePolicy().hasHeightForWidth());
        buttonOK->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(buttonOK);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        buttonCancel = new QPushButton(layoutWidget1);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        sizePolicy1.setHeightForWidth(buttonCancel->sizePolicy().hasHeightForWidth());
        buttonCancel->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(buttonCancel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        retranslateUi(BoxTypeDialog);
        QObject::connect(buttonOK, SIGNAL(clicked()), BoxTypeDialog, SLOT(accept()));
        QObject::connect(buttonCancel, SIGNAL(clicked()), BoxTypeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(BoxTypeDialog);
    } // setupUi

    void retranslateUi(QDialog *BoxTypeDialog)
    {
        BoxTypeDialog->setWindowTitle(QApplication::translate("BoxTypeDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("BoxTypeDialog", "\351\222\211\347\233\222\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        comboBoxType->clear();
        comboBoxType->insertItems(0, QStringList()
         << QApplication::translate("BoxTypeDialog", "DVR", Q_NULLPTR)
         << QApplication::translate("BoxTypeDialog", "POLYX", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("BoxTypeDialog", "\351\222\211\345\255\220\351\242\234\350\211\262\357\274\232", Q_NULLPTR));
        comboBoxNailColor->clear();
        comboBoxNailColor->insertItems(0, QStringList()
         << QApplication::translate("BoxTypeDialog", "\347\273\277\350\211\262", Q_NULLPTR)
         << QApplication::translate("BoxTypeDialog", "\351\273\204\350\211\262", Q_NULLPTR)
        );
        buttonOK->setText(QApplication::translate("BoxTypeDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        buttonCancel->setText(QApplication::translate("BoxTypeDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class BoxTypeDialog: public Ui_BoxTypeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOXTYPEDIALOG_H
