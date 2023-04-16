/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLCDNumber *lcd;
    QPushButton *prebtn;
    QPushButton *pushButton_2;
    QPushButton *openbtn;
    QLabel *label;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *openBtn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *cutBtn;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *closebtn;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(831, 604);
        lcd = new QLCDNumber(Widget);
        lcd->setObjectName(QString::fromUtf8("lcd"));
        lcd->setGeometry(QRect(10, 10, 800, 50));
        lcd->setMinimumSize(QSize(800, 50));
        lcd->setMaximumSize(QSize(800, 50));
        lcd->setDigitCount(20);
        prebtn = new QPushButton(Widget);
        prebtn->setObjectName(QString::fromUtf8("prebtn"));
        prebtn->setGeometry(QRect(200, 550, 93, 28));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 550, 93, 28));
        openbtn = new QPushButton(Widget);
        openbtn->setObjectName(QString::fromUtf8("openbtn"));
        openbtn->setGeometry(QRect(40, 550, 93, 28));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 90, 441, 441));
        label->setFrameShape(QFrame::Box);
        label->setScaledContents(true);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(530, 90, 281, 441));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        openBtn = new QPushButton(widget);
        openBtn->setObjectName(QString::fromUtf8("openBtn"));

        gridLayout->addWidget(openBtn, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 0, 1, 1);

        cutBtn = new QPushButton(widget);
        cutBtn->setObjectName(QString::fromUtf8("cutBtn"));

        gridLayout->addWidget(cutBtn, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 2, 0, 1, 1);

        closebtn = new QPushButton(widget);
        closebtn->setObjectName(QString::fromUtf8("closebtn"));

        gridLayout->addWidget(closebtn, 2, 1, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 2, 2, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        prebtn->setText(QCoreApplication::translate("Widget", "\344\270\212\344\270\200\345\274\240", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\344\270\213\344\270\200\345\274\240", nullptr));
        openbtn->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\347\233\270\345\206\214", nullptr));
        label->setText(QString());
        openBtn->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200", nullptr));
        cutBtn->setText(QCoreApplication::translate("Widget", "\346\210\252\345\233\276", nullptr));
        closebtn->setText(QCoreApplication::translate("Widget", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
