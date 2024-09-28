/********************************************************************************
** Form generated from reading UI file 'alarmtable.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALARMTABLE_H
#define UI_ALARMTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AlarmTableClass
{
public:
    QTableWidget *tableWidget;

    void setupUi(QWidget *AlarmTableClass)
    {
        if (AlarmTableClass->objectName().isEmpty())
            AlarmTableClass->setObjectName(QString::fromUtf8("AlarmTableClass"));
        AlarmTableClass->resize(699, 87);
        tableWidget = new QTableWidget(AlarmTableClass);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 701, 89));

        retranslateUi(AlarmTableClass);

        QMetaObject::connectSlotsByName(AlarmTableClass);
    } // setupUi

    void retranslateUi(QWidget *AlarmTableClass)
    {
        AlarmTableClass->setWindowTitle(QApplication::translate("AlarmTableClass", "AlarmTable", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("AlarmTableClass", "Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("AlarmTableClass", "Alarm info", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("AlarmTableClass", "Device info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AlarmTableClass: public Ui_AlarmTableClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALARMTABLE_H
