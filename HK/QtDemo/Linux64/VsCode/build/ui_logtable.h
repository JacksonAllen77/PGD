/********************************************************************************
** Form generated from reading UI file 'logtable.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGTABLE_H
#define UI_LOGTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogTableClass
{
public:
    QTableWidget *logtableWidget;

    void setupUi(QWidget *LogTableClass)
    {
        if (LogTableClass->objectName().isEmpty())
            LogTableClass->setObjectName(QString::fromUtf8("LogTableClass"));
        LogTableClass->resize(701, 87);
        logtableWidget = new QTableWidget(LogTableClass);
        if (logtableWidget->columnCount() < 5)
            logtableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        logtableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        logtableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        logtableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        logtableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        logtableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        logtableWidget->setObjectName(QString::fromUtf8("logtableWidget"));
        logtableWidget->setGeometry(QRect(0, 0, 701, 89));

        retranslateUi(LogTableClass);

        QMetaObject::connectSlotsByName(LogTableClass);
    } // setupUi

    void retranslateUi(QWidget *LogTableClass)
    {
        LogTableClass->setWindowTitle(QApplication::translate("LogTableClass", "LogTable", nullptr));
        QTableWidgetItem *___qtablewidgetitem = logtableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("LogTableClass", "time", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = logtableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("LogTableClass", "state", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = logtableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("LogTableClass", "operation", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = logtableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("LogTableClass", "devicee info", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = logtableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("LogTableClass", "error info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogTableClass: public Ui_LogTableClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGTABLE_H
