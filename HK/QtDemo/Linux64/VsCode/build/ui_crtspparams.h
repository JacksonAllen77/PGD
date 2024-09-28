/********************************************************************************
** Form generated from reading UI file 'crtspparams.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRTSPPARAMS_H
#define UI_CRTSPPARAMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CRtspParamsClass
{
public:
    QPushButton *btnRefresh;
    QPushButton *btnSave;
    QPushButton *btnExit;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *editPort;

    void setupUi(QDialog *CRtspParamsClass)
    {
        if (CRtspParamsClass->objectName().isEmpty())
            CRtspParamsClass->setObjectName(QString::fromUtf8("CRtspParamsClass"));
        CRtspParamsClass->resize(319, 181);
        btnRefresh = new QPushButton(CRtspParamsClass);
        btnRefresh->setObjectName(QString::fromUtf8("btnRefresh"));
        btnRefresh->setGeometry(QRect(10, 120, 75, 23));
        btnSave = new QPushButton(CRtspParamsClass);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(150, 120, 75, 23));
        btnExit = new QPushButton(CRtspParamsClass);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        btnExit->setGeometry(QRect(240, 120, 75, 23));
        layoutWidget = new QWidget(CRtspParamsClass);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 50, 231, 23));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        editPort = new QLineEdit(layoutWidget);
        editPort->setObjectName(QString::fromUtf8("editPort"));

        gridLayout->addWidget(editPort, 0, 1, 1, 1);


        retranslateUi(CRtspParamsClass);

        QMetaObject::connectSlotsByName(CRtspParamsClass);
    } // setupUi

    void retranslateUi(QDialog *CRtspParamsClass)
    {
        CRtspParamsClass->setWindowTitle(QApplication::translate("CRtspParamsClass", "CRtspParams", nullptr));
        btnRefresh->setText(QApplication::translate("CRtspParamsClass", "Update", nullptr));
        btnSave->setText(QApplication::translate("CRtspParamsClass", "Confirm", nullptr));
        btnExit->setText(QApplication::translate("CRtspParamsClass", "Cancel", nullptr));
        label->setText(QApplication::translate("CRtspParamsClass", "RTSP port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CRtspParamsClass: public Ui_CRtspParamsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRTSPPARAMS_H
