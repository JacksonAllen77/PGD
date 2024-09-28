/********************************************************************************
** Form generated from reading UI file 'cserialparams.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSERIALPARAMS_H
#define UI_CSERIALPARAMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CSerialParams
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *comboBox232BAUD;
    QComboBox *comboBox232DATABIT;
    QComboBox *comboBox232STOPBIT;
    QComboBox *comboBox232CHECKBIT;
    QComboBox *comboBox232FLOW;
    QComboBox *comboBox232workstate;
    QPushButton *pushButtonPPPSETUP;
    QGroupBox *groupBox_2;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QComboBox *comboBox485STOPBIT;
    QComboBox *comboBox485CHECKBIT;
    QComboBox *comboBox485FLOW;
    QComboBox *comboBox485BAUD;
    QComboBox *comboBox485DATABIT;
    QLabel *label_13;
    QLabel *label_14;
    QComboBox *comboBoxDECODETYPE;
    QLineEdit *lineEditDECODEADDRESS;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QComboBox *comboBoxChanIndex;
    QPushButton *pushButton232refresh;
    QPushButton *pushButtonsave;

    void setupUi(QWidget *CSerialParams)
    {
        if (CSerialParams->objectName().isEmpty())
            CSerialParams->setObjectName(QString::fromUtf8("CSerialParams"));
        CSerialParams->resize(586, 503);
        groupBox = new QGroupBox(CSerialParams);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 551, 181));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 30, 61, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(133, 30, 71, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(243, 30, 71, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(353, 30, 71, 21));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(453, 30, 71, 21));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 100, 91, 21));
        comboBox232BAUD = new QComboBox(groupBox);
        comboBox232BAUD->addItem(QString());
        comboBox232BAUD->addItem(QString());
        comboBox232BAUD->addItem(QString());
        comboBox232BAUD->addItem(QString());
        comboBox232BAUD->addItem(QString());
        comboBox232BAUD->addItem(QString());
        comboBox232BAUD->addItem(QString());
        comboBox232BAUD->addItem(QString());
        comboBox232BAUD->addItem(QString());
        comboBox232BAUD->addItem(QString());
        comboBox232BAUD->addItem(QString());
        comboBox232BAUD->addItem(QString());
        comboBox232BAUD->addItem(QString());
        comboBox232BAUD->addItem(QString());
        comboBox232BAUD->addItem(QString());
        comboBox232BAUD->setObjectName(QString::fromUtf8("comboBox232BAUD"));
        comboBox232BAUD->setGeometry(QRect(20, 60, 81, 22));
        comboBox232BAUD->setIconSize(QSize(16, 16));
        comboBox232DATABIT = new QComboBox(groupBox);
        comboBox232DATABIT->addItem(QString());
        comboBox232DATABIT->addItem(QString());
        comboBox232DATABIT->addItem(QString());
        comboBox232DATABIT->addItem(QString());
        comboBox232DATABIT->setObjectName(QString::fromUtf8("comboBox232DATABIT"));
        comboBox232DATABIT->setGeometry(QRect(130, 60, 81, 25));
        comboBox232STOPBIT = new QComboBox(groupBox);
        comboBox232STOPBIT->addItem(QString());
        comboBox232STOPBIT->addItem(QString());
        comboBox232STOPBIT->setObjectName(QString::fromUtf8("comboBox232STOPBIT"));
        comboBox232STOPBIT->setGeometry(QRect(230, 60, 91, 25));
        comboBox232CHECKBIT = new QComboBox(groupBox);
        comboBox232CHECKBIT->addItem(QString());
        comboBox232CHECKBIT->addItem(QString());
        comboBox232CHECKBIT->addItem(QString());
        comboBox232CHECKBIT->setObjectName(QString::fromUtf8("comboBox232CHECKBIT"));
        comboBox232CHECKBIT->setGeometry(QRect(340, 60, 91, 25));
        comboBox232FLOW = new QComboBox(groupBox);
        comboBox232FLOW->addItem(QString());
        comboBox232FLOW->addItem(QString());
        comboBox232FLOW->addItem(QString());
        comboBox232FLOW->setObjectName(QString::fromUtf8("comboBox232FLOW"));
        comboBox232FLOW->setGeometry(QRect(450, 60, 81, 25));
        comboBox232workstate = new QComboBox(groupBox);
        comboBox232workstate->addItem(QString());
        comboBox232workstate->addItem(QString());
        comboBox232workstate->addItem(QString());
        comboBox232workstate->setObjectName(QString::fromUtf8("comboBox232workstate"));
        comboBox232workstate->setGeometry(QRect(110, 100, 171, 25));
        pushButtonPPPSETUP = new QPushButton(groupBox);
        pushButtonPPPSETUP->setObjectName(QString::fromUtf8("pushButtonPPPSETUP"));
        pushButtonPPPSETUP->setEnabled(false);
        pushButtonPPPSETUP->setGeometry(QRect(40, 140, 211, 23));
        groupBox_2 = new QGroupBox(CSerialParams);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 210, 551, 231));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(450, 60, 71, 21));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(240, 60, 71, 21));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(350, 60, 71, 21));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(27, 60, 61, 21));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(130, 60, 71, 21));
        comboBox485STOPBIT = new QComboBox(groupBox_2);
        comboBox485STOPBIT->addItem(QString());
        comboBox485STOPBIT->addItem(QString());
        comboBox485STOPBIT->setObjectName(QString::fromUtf8("comboBox485STOPBIT"));
        comboBox485STOPBIT->setGeometry(QRect(240, 90, 81, 25));
        comboBox485CHECKBIT = new QComboBox(groupBox_2);
        comboBox485CHECKBIT->addItem(QString());
        comboBox485CHECKBIT->addItem(QString());
        comboBox485CHECKBIT->addItem(QString());
        comboBox485CHECKBIT->setObjectName(QString::fromUtf8("comboBox485CHECKBIT"));
        comboBox485CHECKBIT->setGeometry(QRect(340, 90, 91, 25));
        comboBox485FLOW = new QComboBox(groupBox_2);
        comboBox485FLOW->addItem(QString());
        comboBox485FLOW->addItem(QString());
        comboBox485FLOW->addItem(QString());
        comboBox485FLOW->setObjectName(QString::fromUtf8("comboBox485FLOW"));
        comboBox485FLOW->setGeometry(QRect(450, 90, 81, 25));
        comboBox485BAUD = new QComboBox(groupBox_2);
        comboBox485BAUD->addItem(QString());
        comboBox485BAUD->addItem(QString());
        comboBox485BAUD->addItem(QString());
        comboBox485BAUD->addItem(QString());
        comboBox485BAUD->addItem(QString());
        comboBox485BAUD->addItem(QString());
        comboBox485BAUD->addItem(QString());
        comboBox485BAUD->addItem(QString());
        comboBox485BAUD->addItem(QString());
        comboBox485BAUD->addItem(QString());
        comboBox485BAUD->addItem(QString());
        comboBox485BAUD->addItem(QString());
        comboBox485BAUD->addItem(QString());
        comboBox485BAUD->addItem(QString());
        comboBox485BAUD->addItem(QString());
        comboBox485BAUD->setObjectName(QString::fromUtf8("comboBox485BAUD"));
        comboBox485BAUD->setGeometry(QRect(10, 90, 91, 25));
        comboBox485DATABIT = new QComboBox(groupBox_2);
        comboBox485DATABIT->addItem(QString());
        comboBox485DATABIT->addItem(QString());
        comboBox485DATABIT->addItem(QString());
        comboBox485DATABIT->addItem(QString());
        comboBox485DATABIT->setObjectName(QString::fromUtf8("comboBox485DATABIT"));
        comboBox485DATABIT->setGeometry(QRect(130, 90, 81, 25));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 150, 101, 21));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(270, 150, 101, 21));
        comboBoxDECODETYPE = new QComboBox(groupBox_2);
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->addItem(QString());
        comboBoxDECODETYPE->setObjectName(QString::fromUtf8("comboBoxDECODETYPE"));
        comboBoxDECODETYPE->setGeometry(QRect(120, 150, 101, 25));
        lineEditDECODEADDRESS = new QLineEdit(groupBox_2);
        lineEditDECODEADDRESS->setObjectName(QString::fromUtf8("lineEditDECODEADDRESS"));
        lineEditDECODEADDRESS->setGeometry(QRect(390, 150, 113, 25));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 181, 23));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout->addWidget(label_7);

        comboBoxChanIndex = new QComboBox(layoutWidget);
        comboBoxChanIndex->setObjectName(QString::fromUtf8("comboBoxChanIndex"));

        horizontalLayout->addWidget(comboBoxChanIndex);

        pushButton232refresh = new QPushButton(CSerialParams);
        pushButton232refresh->setObjectName(QString::fromUtf8("pushButton232refresh"));
        pushButton232refresh->setGeometry(QRect(100, 460, 75, 25));
        pushButtonsave = new QPushButton(CSerialParams);
        pushButtonsave->setObjectName(QString::fromUtf8("pushButtonsave"));
        pushButtonsave->setGeometry(QRect(330, 460, 75, 25));

        retranslateUi(CSerialParams);

        QMetaObject::connectSlotsByName(CSerialParams);
    } // setupUi

    void retranslateUi(QWidget *CSerialParams)
    {
        CSerialParams->setWindowTitle(QApplication::translate("CSerialParams", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("CSerialParams", "232 setup", nullptr));
        label->setText(QApplication::translate("CSerialParams", "Port speed", nullptr));
        label_2->setText(QApplication::translate("CSerialParams", "Data bit", nullptr));
        label_3->setText(QApplication::translate("CSerialParams", "Stop bit", nullptr));
        label_4->setText(QApplication::translate("CSerialParams", "Parity", nullptr));
        label_5->setText(QApplication::translate("CSerialParams", "Flow control", nullptr));
        label_6->setText(QApplication::translate("CSerialParams", "Operation mode", nullptr));
        comboBox232BAUD->setItemText(0, QApplication::translate("CSerialParams", "50", nullptr));
        comboBox232BAUD->setItemText(1, QApplication::translate("CSerialParams", "75", nullptr));
        comboBox232BAUD->setItemText(2, QApplication::translate("CSerialParams", "110", nullptr));
        comboBox232BAUD->setItemText(3, QApplication::translate("CSerialParams", "150", nullptr));
        comboBox232BAUD->setItemText(4, QApplication::translate("CSerialParams", "300", nullptr));
        comboBox232BAUD->setItemText(5, QApplication::translate("CSerialParams", "600", nullptr));
        comboBox232BAUD->setItemText(6, QApplication::translate("CSerialParams", "1200", nullptr));
        comboBox232BAUD->setItemText(7, QApplication::translate("CSerialParams", "2400", nullptr));
        comboBox232BAUD->setItemText(8, QApplication::translate("CSerialParams", "4800", nullptr));
        comboBox232BAUD->setItemText(9, QApplication::translate("CSerialParams", "9600", nullptr));
        comboBox232BAUD->setItemText(10, QApplication::translate("CSerialParams", "19200", nullptr));
        comboBox232BAUD->setItemText(11, QApplication::translate("CSerialParams", "38400", nullptr));
        comboBox232BAUD->setItemText(12, QApplication::translate("CSerialParams", "57600", nullptr));
        comboBox232BAUD->setItemText(13, QApplication::translate("CSerialParams", "76800", nullptr));
        comboBox232BAUD->setItemText(14, QApplication::translate("CSerialParams", "115.2k", nullptr));

        comboBox232DATABIT->setItemText(0, QApplication::translate("CSerialParams", "5", nullptr));
        comboBox232DATABIT->setItemText(1, QApplication::translate("CSerialParams", "6", nullptr));
        comboBox232DATABIT->setItemText(2, QApplication::translate("CSerialParams", "7", nullptr));
        comboBox232DATABIT->setItemText(3, QApplication::translate("CSerialParams", "8", nullptr));

        comboBox232STOPBIT->setItemText(0, QApplication::translate("CSerialParams", "1", nullptr));
        comboBox232STOPBIT->setItemText(1, QApplication::translate("CSerialParams", "2", nullptr));

        comboBox232CHECKBIT->setItemText(0, QApplication::translate("CSerialParams", "None", nullptr));
        comboBox232CHECKBIT->setItemText(1, QApplication::translate("CSerialParams", "Odd", nullptr));
        comboBox232CHECKBIT->setItemText(2, QApplication::translate("CSerialParams", "Even", nullptr));

        comboBox232FLOW->setItemText(0, QApplication::translate("CSerialParams", "None", nullptr));
        comboBox232FLOW->setItemText(1, QApplication::translate("CSerialParams", "Software", nullptr));
        comboBox232FLOW->setItemText(2, QApplication::translate("CSerialParams", "Hardware", nullptr));

        comboBox232workstate->setItemText(0, QApplication::translate("CSerialParams", "Narrow-band transmission", nullptr));
        comboBox232workstate->setItemText(1, QApplication::translate("CSerialParams", "Console", nullptr));
        comboBox232workstate->setItemText(2, QApplication::translate("CSerialParams", "Transpsrent channel", nullptr));

        pushButtonPPPSETUP->setText(QApplication::translate("CSerialParams", "Narrowband transparent setup", nullptr));
        groupBox_2->setTitle(QApplication::translate("CSerialParams", "RS485 setup", nullptr));
        label_8->setText(QApplication::translate("CSerialParams", "Flow control", nullptr));
        label_9->setText(QApplication::translate("CSerialParams", "Stop bit", nullptr));
        label_10->setText(QApplication::translate("CSerialParams", "Parity", nullptr));
        label_11->setText(QApplication::translate("CSerialParams", "Port speed", nullptr));
        label_12->setText(QApplication::translate("CSerialParams", "Data bit", nullptr));
        comboBox485STOPBIT->setItemText(0, QApplication::translate("CSerialParams", "1", nullptr));
        comboBox485STOPBIT->setItemText(1, QApplication::translate("CSerialParams", "2", nullptr));

        comboBox485CHECKBIT->setItemText(0, QApplication::translate("CSerialParams", "None", nullptr));
        comboBox485CHECKBIT->setItemText(1, QApplication::translate("CSerialParams", "Odd", nullptr));
        comboBox485CHECKBIT->setItemText(2, QApplication::translate("CSerialParams", "Even", nullptr));

        comboBox485FLOW->setItemText(0, QApplication::translate("CSerialParams", "None", nullptr));
        comboBox485FLOW->setItemText(1, QApplication::translate("CSerialParams", "Software", nullptr));
        comboBox485FLOW->setItemText(2, QApplication::translate("CSerialParams", "Hardware", nullptr));

        comboBox485BAUD->setItemText(0, QApplication::translate("CSerialParams", "50", nullptr));
        comboBox485BAUD->setItemText(1, QApplication::translate("CSerialParams", "75", nullptr));
        comboBox485BAUD->setItemText(2, QApplication::translate("CSerialParams", "110", nullptr));
        comboBox485BAUD->setItemText(3, QApplication::translate("CSerialParams", "150", nullptr));
        comboBox485BAUD->setItemText(4, QApplication::translate("CSerialParams", "300", nullptr));
        comboBox485BAUD->setItemText(5, QApplication::translate("CSerialParams", "600", nullptr));
        comboBox485BAUD->setItemText(6, QApplication::translate("CSerialParams", "1200", nullptr));
        comboBox485BAUD->setItemText(7, QApplication::translate("CSerialParams", "2400", nullptr));
        comboBox485BAUD->setItemText(8, QApplication::translate("CSerialParams", "4800", nullptr));
        comboBox485BAUD->setItemText(9, QApplication::translate("CSerialParams", "9600", nullptr));
        comboBox485BAUD->setItemText(10, QApplication::translate("CSerialParams", "19200", nullptr));
        comboBox485BAUD->setItemText(11, QApplication::translate("CSerialParams", "38400", nullptr));
        comboBox485BAUD->setItemText(12, QApplication::translate("CSerialParams", "57600", nullptr));
        comboBox485BAUD->setItemText(13, QApplication::translate("CSerialParams", "76800", nullptr));
        comboBox485BAUD->setItemText(14, QApplication::translate("CSerialParams", "115.2k", nullptr));

        comboBox485DATABIT->setItemText(0, QApplication::translate("CSerialParams", "5", nullptr));
        comboBox485DATABIT->setItemText(1, QApplication::translate("CSerialParams", "6", nullptr));
        comboBox485DATABIT->setItemText(2, QApplication::translate("CSerialParams", "7", nullptr));
        comboBox485DATABIT->setItemText(3, QApplication::translate("CSerialParams", "8", nullptr));

        label_13->setText(QApplication::translate("CSerialParams", "Decoder model", nullptr));
        label_14->setText(QApplication::translate("CSerialParams", "Decoder IP", nullptr));
        comboBoxDECODETYPE->setItemText(0, QApplication::translate("CSerialParams", "YouLi", nullptr));
        comboBoxDECODETYPE->setItemText(1, QApplication::translate("CSerialParams", "LiLin-1016", nullptr));
        comboBoxDECODETYPE->setItemText(2, QApplication::translate("CSerialParams", "LiLin-820", nullptr));
        comboBoxDECODETYPE->setItemText(3, QApplication::translate("CSerialParams", "Pelco-p", nullptr));
        comboBoxDECODETYPE->setItemText(4, QApplication::translate("CSerialParams", "DM DynaColor", nullptr));
        comboBoxDECODETYPE->setItemText(5, QApplication::translate("CSerialParams", "HD600", nullptr));
        comboBoxDECODETYPE->setItemText(6, QApplication::translate("CSerialParams", "JC-4116", nullptr));
        comboBoxDECODETYPE->setItemText(7, QApplication::translate("CSerialParams", "Pelco-d WX", nullptr));
        comboBoxDECODETYPE->setItemText(8, QApplication::translate("CSerialParams", "Pelco-d PICO", nullptr));
        comboBoxDECODETYPE->setItemText(9, QApplication::translate("CSerialParams", "VCOM_VC_2000", nullptr));
        comboBoxDECODETYPE->setItemText(10, QApplication::translate("CSerialParams", "NETSTREAMER", nullptr));
        comboBoxDECODETYPE->setItemText(11, QApplication::translate("CSerialParams", "SAE", nullptr));
        comboBoxDECODETYPE->setItemText(12, QApplication::translate("CSerialParams", "SAMSUNG", nullptr));
        comboBoxDECODETYPE->setItemText(13, QApplication::translate("CSerialParams", "KALATEL_KTD_312", nullptr));
        comboBoxDECODETYPE->setItemText(14, QApplication::translate("CSerialParams", "CELOTEX", nullptr));
        comboBoxDECODETYPE->setItemText(15, QApplication::translate("CSerialParams", "TLPELCO_P", nullptr));
        comboBoxDECODETYPE->setItemText(16, QApplication::translate("CSerialParams", "TL_HHX2000", nullptr));
        comboBoxDECODETYPE->setItemText(17, QApplication::translate("CSerialParams", "BBV", nullptr));
        comboBoxDECODETYPE->setItemText(18, QApplication::translate("CSerialParams", "RM110", nullptr));
        comboBoxDECODETYPE->setItemText(19, QApplication::translate("CSerialParams", "KC3360S", nullptr));
        comboBoxDECODETYPE->setItemText(20, QApplication::translate("CSerialParams", "ACES", nullptr));
        comboBoxDECODETYPE->setItemText(21, QApplication::translate("CSerialParams", "ALSON", nullptr));
        comboBoxDECODETYPE->setItemText(22, QApplication::translate("CSerialParams", "INV3609HD", nullptr));
        comboBoxDECODETYPE->setItemText(23, QApplication::translate("CSerialParams", "HOWELL", nullptr));
        comboBoxDECODETYPE->setItemText(24, QApplication::translate("CSerialParams", "TC_PELCO_P", nullptr));
        comboBoxDECODETYPE->setItemText(25, QApplication::translate("CSerialParams", "TC_PELCO_D", nullptr));
        comboBoxDECODETYPE->setItemText(26, QApplication::translate("CSerialParams", "AUTO_M", nullptr));
        comboBoxDECODETYPE->setItemText(27, QApplication::translate("CSerialParams", "AUTO_H", nullptr));
        comboBoxDECODETYPE->setItemText(28, QApplication::translate("CSerialParams", "ANTEN", nullptr));
        comboBoxDECODETYPE->setItemText(29, QApplication::translate("CSerialParams", "CHANGLIN", nullptr));
        comboBoxDECODETYPE->setItemText(30, QApplication::translate("CSerialParams", "DELTADOME", nullptr));
        comboBoxDECODETYPE->setItemText(31, QApplication::translate("CSerialParams", "XYM_12", nullptr));
        comboBoxDECODETYPE->setItemText(32, QApplication::translate("CSerialParams", "ADR8060", nullptr));
        comboBoxDECODETYPE->setItemText(33, QApplication::translate("CSerialParams", "EVI", nullptr));
        comboBoxDECODETYPE->setItemText(34, QApplication::translate("CSerialParams", "Demo_Speed", nullptr));
        comboBoxDECODETYPE->setItemText(35, QApplication::translate("CSerialParams", "DM_PELCO_D", nullptr));
        comboBoxDECODETYPE->setItemText(36, QApplication::translate("CSerialParams", "ST_832", nullptr));
        comboBoxDECODETYPE->setItemText(37, QApplication::translate("CSerialParams", "LC_D2104", nullptr));
        comboBoxDECODETYPE->setItemText(38, QApplication::translate("CSerialParams", "HUNTER", nullptr));
        comboBoxDECODETYPE->setItemText(39, QApplication::translate("CSerialParams", "A01", nullptr));
        comboBoxDECODETYPE->setItemText(40, QApplication::translate("CSerialParams", "TECHWIN", nullptr));
        comboBoxDECODETYPE->setItemText(41, QApplication::translate("CSerialParams", "WEIHAN", nullptr));
        comboBoxDECODETYPE->setItemText(42, QApplication::translate("CSerialParams", "LG", nullptr));
        comboBoxDECODETYPE->setItemText(43, QApplication::translate("CSerialParams", "D_MAX", nullptr));
        comboBoxDECODETYPE->setItemText(44, QApplication::translate("CSerialParams", "PANASONIC", nullptr));
        comboBoxDECODETYPE->setItemText(45, QApplication::translate("CSerialParams", "KTD_348", nullptr));
        comboBoxDECODETYPE->setItemText(46, QApplication::translate("CSerialParams", "INFINOVA", nullptr));
        comboBoxDECODETYPE->setItemText(47, QApplication::translate("CSerialParams", "PIH-7625", nullptr));
        comboBoxDECODETYPE->setItemText(48, QApplication::translate("CSerialParams", "IDOME/IVIEW/LCU", nullptr));
        comboBoxDECODETYPE->setItemText(49, QApplication::translate("CSerialParams", "Dennar_dDome", nullptr));
        comboBoxDECODETYPE->setItemText(50, QApplication::translate("CSerialParams", "Philips", nullptr));
        comboBoxDECODETYPE->setItemText(51, QApplication::translate("CSerialParams", "SAMPLE", nullptr));
        comboBoxDECODETYPE->setItemText(52, QApplication::translate("CSerialParams", "PLD", nullptr));
        comboBoxDECODETYPE->setItemText(53, QApplication::translate("CSerialParams", "PARCO", nullptr));
        comboBoxDECODETYPE->setItemText(54, QApplication::translate("CSerialParams", "HY", nullptr));
        comboBoxDECODETYPE->setItemText(55, QApplication::translate("CSerialParams", "NAIJIE", nullptr));
        comboBoxDECODETYPE->setItemText(56, QApplication::translate("CSerialParams", "YH_06", nullptr));
        comboBoxDECODETYPE->setItemText(57, QApplication::translate("CSerialParams", "SP9096X", nullptr));
        comboBoxDECODETYPE->setItemText(58, QApplication::translate("CSerialParams", "M_PANEL", nullptr));
        comboBoxDECODETYPE->setItemText(59, QApplication::translate("CSerialParams", "M_MV2050", nullptr));
        comboBoxDECODETYPE->setItemText(60, QApplication::translate("CSerialParams", "SAE_QUICK", nullptr));
        comboBoxDECODETYPE->setItemText(61, QApplication::translate("CSerialParams", "RED_APPLE", nullptr));
        comboBoxDECODETYPE->setItemText(62, QApplication::translate("CSerialParams", "NKO8G", nullptr));
        comboBoxDECODETYPE->setItemText(63, QApplication::translate("CSerialParams", "DH_CC440", nullptr));
        comboBoxDECODETYPE->setItemText(64, QApplication::translate("CSerialParams", "TX_CONTROL_232", nullptr));
        comboBoxDECODETYPE->setItemText(65, QApplication::translate("CSerialParams", "VCL_SPEED_DOME", nullptr));
        comboBoxDECODETYPE->setItemText(66, QApplication::translate("CSerialParams", "ST_2C160", nullptr));
        comboBoxDECODETYPE->setItemText(67, QApplication::translate("CSerialParams", "TDWY", nullptr));
        comboBoxDECODETYPE->setItemText(68, QApplication::translate("CSerialParams", "TWHC", nullptr));
        comboBoxDECODETYPE->setItemText(69, QApplication::translate("CSerialParams", "USNT", nullptr));
        comboBoxDECODETYPE->setItemText(70, QApplication::translate("CSerialParams", "KLT_NVD2200PS", nullptr));
        comboBoxDECODETYPE->setItemText(71, QApplication::translate("CSerialParams", "VIDO_B01", nullptr));
        comboBoxDECODETYPE->setItemText(72, QApplication::translate("CSerialParams", "LG_MULTIX", nullptr));
        comboBoxDECODETYPE->setItemText(73, QApplication::translate("CSerialParams", "ENKEL", nullptr));
        comboBoxDECODETYPE->setItemText(74, QApplication::translate("CSerialParams", "YT_PELCOD", nullptr));
        comboBoxDECODETYPE->setItemText(75, QApplication::translate("CSerialParams", "HIKVISION", nullptr));
        comboBoxDECODETYPE->setItemText(76, QApplication::translate("CSerialParams", "PE60", nullptr));
        comboBoxDECODETYPE->setItemText(77, QApplication::translate("CSerialParams", "LiAo", nullptr));
        comboBoxDECODETYPE->setItemText(78, QApplication::translate("CSerialParams", "NK16", nullptr));
        comboBoxDECODETYPE->setItemText(79, QApplication::translate("CSerialParams", "DaLi", nullptr));
        comboBoxDECODETYPE->setItemText(80, QApplication::translate("CSerialParams", "HN_4304", nullptr));
        comboBoxDECODETYPE->setItemText(81, QApplication::translate("CSerialParams", "VIDEOTEC", nullptr));
        comboBoxDECODETYPE->setItemText(82, QApplication::translate("CSerialParams", "HNDCB", nullptr));
        comboBoxDECODETYPE->setItemText(83, QApplication::translate("CSerialParams", "Lion_2007", nullptr));
        comboBoxDECODETYPE->setItemText(84, QApplication::translate("CSerialParams", "LG_LVC_C372", nullptr));
        comboBoxDECODETYPE->setItemText(85, QApplication::translate("CSerialParams", "Gold_Video", nullptr));
        comboBoxDECODETYPE->setItemText(86, QApplication::translate("CSerialParams", "NVD1600PS", nullptr));

        label_7->setText(QApplication::translate("CSerialParams", "Channel No.", nullptr));
        pushButton232refresh->setText(QApplication::translate("CSerialParams", "Update", nullptr));
        pushButtonsave->setText(QApplication::translate("CSerialParams", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CSerialParams: public Ui_CSerialParams {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSERIALPARAMS_H
