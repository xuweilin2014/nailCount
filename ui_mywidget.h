/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QFrame *line;
    QGraphicsView *graphicsView;
    QFrame *line_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *uploadImage;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QPushButton *film;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *genExcel;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_4;
    QPushButton *nailCount;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_5;
    QPushButton *boxType;
    QLabel *label_5;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QStringLiteral("MyWidget"));
        MyWidget->resize(537, 379);
        line = new QFrame(MyWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 80, 511, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        graphicsView = new QGraphicsView(MyWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 110, 511, 251));
        line_2 = new QFrame(MyWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 370, 511, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(MyWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(34, 10, 401, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        uploadImage = new QPushButton(layoutWidget);
        uploadImage->setObjectName(QStringLiteral("uploadImage"));

        verticalLayout->addWidget(uploadImage);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        film = new QPushButton(layoutWidget);
        film->setObjectName(QStringLiteral("film"));

        verticalLayout_2->addWidget(film);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        genExcel = new QPushButton(layoutWidget);
        genExcel->setObjectName(QStringLiteral("genExcel"));

        verticalLayout_3->addWidget(genExcel);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_3->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        nailCount = new QPushButton(layoutWidget);
        nailCount->setObjectName(QStringLiteral("nailCount"));

        verticalLayout_4->addWidget(nailCount);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_4->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        boxType = new QPushButton(layoutWidget);
        boxType->setObjectName(QStringLiteral("boxType"));

        verticalLayout_5->addWidget(boxType);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_5->addWidget(label_5);


        horizontalLayout->addLayout(verticalLayout_5);


        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "\351\222\211\345\255\220\350\256\241\346\225\260", Q_NULLPTR));
        uploadImage->setText(QString());
        label->setText(QApplication::translate("MyWidget", "  \344\270\212\344\274\240\345\233\276\347\211\207", Q_NULLPTR));
        film->setText(QString());
        label_2->setText(QApplication::translate("MyWidget", "    \346\221\204\345\203\217", Q_NULLPTR));
        genExcel->setText(QString());
        label_3->setText(QApplication::translate("MyWidget", "  \347\224\237\346\210\220Excel", Q_NULLPTR));
        nailCount->setText(QString());
        label_4->setText(QApplication::translate("MyWidget", "    \350\256\241\346\225\260", Q_NULLPTR));
        boxType->setText(QString());
        label_5->setText(QApplication::translate("MyWidget", "  \347\233\222\345\255\220\347\261\273\345\236\213", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
