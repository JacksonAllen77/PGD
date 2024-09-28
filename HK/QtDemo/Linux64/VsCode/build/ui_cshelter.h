/********************************************************************************
** Form generated from reading UI file 'cshelter.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSHELTER_H
#define UI_CSHELTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_CShelterClass
{
public:
    QTableWidget *tableShelter;
    QPushButton *btnSave;
    QLabel *label;

    void setupUi(QDialog *CShelterClass)
    {
        if (CShelterClass->objectName().isEmpty())
            CShelterClass->setObjectName(QString::fromUtf8("CShelterClass"));
        CShelterClass->resize(534, 318);
        tableShelter = new QTableWidget(CShelterClass);
        tableShelter->setObjectName(QString::fromUtf8("tableShelter"));
        tableShelter->setGeometry(QRect(20, 20, 491, 231));
        btnSave = new QPushButton(CShelterClass);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(430, 270, 75, 23));
        label = new QLabel(CShelterClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 270, 114, 13));

        retranslateUi(CShelterClass);

        QMetaObject::connectSlotsByName(CShelterClass);
    } // setupUi

    void retranslateUi(QDialog *CShelterClass)
    {
        CShelterClass->setWindowTitle(QApplication::translate("CShelterClass", "CShelter", nullptr));
        btnSave->setText(QApplication::translate("CShelterClass", "confirm", nullptr));
        label->setText(QApplication::translate("CShelterClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ff0000;\">(size\357\274\232704*576)</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CShelterClass: public Ui_CShelterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSHELTER_H
