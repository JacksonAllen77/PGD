/********************************************************************************
** Form generated from reading UI file 'logsearch.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGSEARCH_H
#define UI_LOGSEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogSearchClass
{
public:
    QFrame *line_10;
    QLabel *label_deviceIP;
    QLineEdit *lineEdit_nodename;
    QFrame *line_9;
    QLabel *label_nodename;
    QFrame *line_11;
    QLineEdit *lineEdit_deviceIP;
    QFrame *line_12;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QComboBox *comboBox_logtype;
    QComboBox *comboBox_maintype;
    QComboBox *comboBox_subtype;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QCheckBox *checkBox_smart;
    QTableWidget *logtableWidget;
    QPushButton *pushButton_searchlog;
    QPushButton *pushButton_exit;
    QLabel *label_6;
    QDateTimeEdit *dateTimeEdit_start;
    QDateTimeEdit *dateTimeEdit_stop;

    void setupUi(QWidget *LogSearchClass)
    {
        if (LogSearchClass->objectName().isEmpty())
            LogSearchClass->setObjectName(QString::fromUtf8("LogSearchClass"));
        LogSearchClass->resize(827, 604);
        line_10 = new QFrame(LogSearchClass);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setGeometry(QRect(0, 20, 20, 571));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);
        label_deviceIP = new QLabel(LogSearchClass);
        label_deviceIP->setObjectName(QString::fromUtf8("label_deviceIP"));
        label_deviceIP->setGeometry(QRect(300, 30, 71, 20));
        lineEdit_nodename = new QLineEdit(LogSearchClass);
        lineEdit_nodename->setObjectName(QString::fromUtf8("lineEdit_nodename"));
        lineEdit_nodename->setGeometry(QRect(110, 30, 141, 20));
        line_9 = new QFrame(LogSearchClass);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(10, 10, 801, 20));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        label_nodename = new QLabel(LogSearchClass);
        label_nodename->setObjectName(QString::fromUtf8("label_nodename"));
        label_nodename->setGeometry(QRect(30, 30, 81, 20));
        line_11 = new QFrame(LogSearchClass);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setGeometry(QRect(800, 20, 20, 571));
        line_11->setFrameShape(QFrame::VLine);
        line_11->setFrameShadow(QFrame::Sunken);
        lineEdit_deviceIP = new QLineEdit(LogSearchClass);
        lineEdit_deviceIP->setObjectName(QString::fromUtf8("lineEdit_deviceIP"));
        lineEdit_deviceIP->setGeometry(QRect(380, 30, 131, 20));
        line_12 = new QFrame(LogSearchClass);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setGeometry(QRect(10, 590, 801, 16));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);
        line = new QFrame(LogSearchClass);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(20, 60, 16, 81));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(LogSearchClass);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(780, 60, 20, 81));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(LogSearchClass);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(30, 50, 761, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(LogSearchClass);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(30, 130, 761, 16));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        comboBox_logtype = new QComboBox(LogSearchClass);
        comboBox_logtype->addItem(QString());
        comboBox_logtype->addItem(QString());
        comboBox_logtype->addItem(QString());
        comboBox_logtype->addItem(QString());
        comboBox_logtype->setObjectName(QString::fromUtf8("comboBox_logtype"));
        comboBox_logtype->setGeometry(QRect(90, 81, 111, 21));
        comboBox_maintype = new QComboBox(LogSearchClass);
        comboBox_maintype->addItem(QString());
        comboBox_maintype->addItem(QString());
        comboBox_maintype->addItem(QString());
        comboBox_maintype->addItem(QString());
        comboBox_maintype->addItem(QString());
        comboBox_maintype->setObjectName(QString::fromUtf8("comboBox_maintype"));
        comboBox_maintype->setGeometry(QRect(270, 80, 101, 20));
        comboBox_subtype = new QComboBox(LogSearchClass);
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->addItem(QString());
        comboBox_subtype->setObjectName(QString::fromUtf8("comboBox_subtype"));
        comboBox_subtype->setGeometry(QRect(430, 80, 111, 22));
        label = new QLabel(LogSearchClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 80, 61, 20));
        label_2 = new QLabel(LogSearchClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 80, 61, 21));
        label_3 = new QLabel(LogSearchClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(380, 81, 51, 20));
        label_4 = new QLabel(LogSearchClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 120, 54, 13));
        label_5 = new QLabel(LogSearchClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(250, 110, 54, 20));
        checkBox_smart = new QCheckBox(LogSearchClass);
        checkBox_smart->setObjectName(QString::fromUtf8("checkBox_smart"));
        checkBox_smart->setGeometry(QRect(540, 110, 111, 17));
        logtableWidget = new QTableWidget(LogSearchClass);
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
        logtableWidget->setGeometry(QRect(30, 150, 761, 381));
        pushButton_searchlog = new QPushButton(LogSearchClass);
        pushButton_searchlog->setObjectName(QString::fromUtf8("pushButton_searchlog"));
        pushButton_searchlog->setGeometry(QRect(540, 550, 75, 23));
        pushButton_exit = new QPushButton(LogSearchClass);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));
        pushButton_exit->setGeometry(QRect(660, 550, 75, 23));
        label_6 = new QLabel(LogSearchClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 550, 141, 16));
        dateTimeEdit_start = new QDateTimeEdit(LogSearchClass);
        dateTimeEdit_start->setObjectName(QString::fromUtf8("dateTimeEdit_start"));
        dateTimeEdit_start->setGeometry(QRect(90, 110, 151, 22));
        dateTimeEdit_stop = new QDateTimeEdit(LogSearchClass);
        dateTimeEdit_stop->setObjectName(QString::fromUtf8("dateTimeEdit_stop"));
        dateTimeEdit_stop->setGeometry(QRect(310, 110, 151, 22));

        retranslateUi(LogSearchClass);

        QMetaObject::connectSlotsByName(LogSearchClass);
    } // setupUi

    void retranslateUi(QWidget *LogSearchClass)
    {
        LogSearchClass->setWindowTitle(QApplication::translate("LogSearchClass", "LogSearch", nullptr));
        label_deviceIP->setText(QApplication::translate("LogSearchClass", "Device IP", nullptr));
        label_nodename->setText(QApplication::translate("LogSearchClass", "Device name", nullptr));
        comboBox_logtype->setItemText(0, QApplication::translate("LogSearchClass", "All", nullptr));
        comboBox_logtype->setItemText(1, QApplication::translate("LogSearchClass", "By type", nullptr));
        comboBox_logtype->setItemText(2, QApplication::translate("LogSearchClass", "By time", nullptr));
        comboBox_logtype->setItemText(3, QApplication::translate("LogSearchClass", "By type and name", nullptr));

        comboBox_maintype->setItemText(0, QApplication::translate("LogSearchClass", "All", nullptr));
        comboBox_maintype->setItemText(1, QApplication::translate("LogSearchClass", "Alarm", nullptr));
        comboBox_maintype->setItemText(2, QApplication::translate("LogSearchClass", "Abnormal", nullptr));
        comboBox_maintype->setItemText(3, QApplication::translate("LogSearchClass", "Operation", nullptr));
        comboBox_maintype->setItemText(4, QApplication::translate("LogSearchClass", "Information", nullptr));

        comboBox_subtype->setItemText(0, QApplication::translate("LogSearchClass", "ALL", nullptr));
        comboBox_subtype->setItemText(1, QApplication::translate("LogSearchClass", "MINOR_ALARM_IN", nullptr));
        comboBox_subtype->setItemText(2, QApplication::translate("LogSearchClass", "MINOR_ALARM_OUT", nullptr));
        comboBox_subtype->setItemText(3, QApplication::translate("LogSearchClass", "MINOR_MOTDET_START", nullptr));
        comboBox_subtype->setItemText(4, QApplication::translate("LogSearchClass", "MINOR_MOTDET_STOP", nullptr));
        comboBox_subtype->setItemText(5, QApplication::translate("LogSearchClass", "MINOR_HIDE_ALARM_START", nullptr));
        comboBox_subtype->setItemText(6, QApplication::translate("LogSearchClass", "MINOR_HIDE_ALARM_STOP", nullptr));
        comboBox_subtype->setItemText(7, QApplication::translate("LogSearchClass", "MINOR_VCA_ALARM_START", nullptr));
        comboBox_subtype->setItemText(8, QApplication::translate("LogSearchClass", "MINOR_VCA_ALARM_STOP", nullptr));
        comboBox_subtype->setItemText(9, QApplication::translate("LogSearchClass", "---Excp-------", nullptr));
        comboBox_subtype->setItemText(10, QApplication::translate("LogSearchClass", "MINOR_VI_LOST", nullptr));
        comboBox_subtype->setItemText(11, QApplication::translate("LogSearchClass", "MINOR_ILLEGAL_ACCESS", nullptr));
        comboBox_subtype->setItemText(12, QApplication::translate("LogSearchClass", "MINOR_HD_FULL", nullptr));
        comboBox_subtype->setItemText(13, QApplication::translate("LogSearchClass", "MINOR_HD_ERROR", nullptr));
        comboBox_subtype->setItemText(14, QApplication::translate("LogSearchClass", "MINOR_DCD_LOST", nullptr));
        comboBox_subtype->setItemText(15, QApplication::translate("LogSearchClass", "MINOR_IP_CONFLICT", nullptr));
        comboBox_subtype->setItemText(16, QApplication::translate("LogSearchClass", "MINOR_NET_BROKEN", nullptr));
        comboBox_subtype->setItemText(17, QApplication::translate("LogSearchClass", "MINOR_REC_ERROR", nullptr));
        comboBox_subtype->setItemText(18, QApplication::translate("LogSearchClass", "MINOR_IPC_NO_LINK", nullptr));
        comboBox_subtype->setItemText(19, QApplication::translate("LogSearchClass", "MINOR_VI_EXCEPTION", nullptr));
        comboBox_subtype->setItemText(20, QApplication::translate("LogSearchClass", "MINOR_IPC_IP_CONFLICT", nullptr));
        comboBox_subtype->setItemText(21, QApplication::translate("LogSearchClass", "----Oper-----", nullptr));
        comboBox_subtype->setItemText(22, QApplication::translate("LogSearchClass", "MINOR_START_DVR", nullptr));
        comboBox_subtype->setItemText(23, QApplication::translate("LogSearchClass", "MINOR_STOP_DVR", nullptr));
        comboBox_subtype->setItemText(24, QApplication::translate("LogSearchClass", "MINOR_STOP_ABNORMAL", nullptr));
        comboBox_subtype->setItemText(25, QApplication::translate("LogSearchClass", "MINOR_REBOOT_DVR", nullptr));
        comboBox_subtype->setItemText(26, QApplication::translate("LogSearchClass", "MINOR_LOCAL_LOGIN", nullptr));
        comboBox_subtype->setItemText(27, QApplication::translate("LogSearchClass", "MINOR_LOCAL_LOGOUT", nullptr));
        comboBox_subtype->setItemText(28, QApplication::translate("LogSearchClass", "MINOR_LOCAL_CFG_PARM", nullptr));
        comboBox_subtype->setItemText(29, QApplication::translate("LogSearchClass", "MINOR_LOCAL_PLAYBYFILE", nullptr));
        comboBox_subtype->setItemText(30, QApplication::translate("LogSearchClass", "MINOR_LOCAL_PLAYBYTIME", nullptr));
        comboBox_subtype->setItemText(31, QApplication::translate("LogSearchClass", "MINOR_LOCAL_START_REC", nullptr));
        comboBox_subtype->setItemText(32, QApplication::translate("LogSearchClass", "MINOR_LOCAL_STOP_REC", nullptr));
        comboBox_subtype->setItemText(33, QApplication::translate("LogSearchClass", "MINOR_LOCAL_PTZCTRL", nullptr));
        comboBox_subtype->setItemText(34, QApplication::translate("LogSearchClass", "MINOR_LOCAL_PREVIEW", nullptr));
        comboBox_subtype->setItemText(35, QApplication::translate("LogSearchClass", "MINOR_LOCAL_MODIFY_TIME", nullptr));
        comboBox_subtype->setItemText(36, QApplication::translate("LogSearchClass", "MINOR_LOCAL_UPGRADE", nullptr));
        comboBox_subtype->setItemText(37, QApplication::translate("LogSearchClass", "MINOR_LOCAL_RECFILE_OUTPUT", nullptr));
        comboBox_subtype->setItemText(38, QApplication::translate("LogSearchClass", "MINOR_LOCAL_FORMAT_HDD", nullptr));
        comboBox_subtype->setItemText(39, QApplication::translate("LogSearchClass", "MINOR_LOCAL_CFGFILE_OUTPUT", nullptr));
        comboBox_subtype->setItemText(40, QApplication::translate("LogSearchClass", "MINOR_LOCAL_CFGFILE_INPUT", nullptr));
        comboBox_subtype->setItemText(41, QApplication::translate("LogSearchClass", "----MINOR_LOCAL_COPYFILE", nullptr));
        comboBox_subtype->setItemText(42, QApplication::translate("LogSearchClass", "MINOR_LOCAL_LOCKFILE", nullptr));
        comboBox_subtype->setItemText(43, QApplication::translate("LogSearchClass", "MINOR_LOCAL_UNLOCKFILE", nullptr));
        comboBox_subtype->setItemText(44, QApplication::translate("LogSearchClass", "MINOR_LOCAL_DVR_ALARM", nullptr));
        comboBox_subtype->setItemText(45, QApplication::translate("LogSearchClass", "MINOR_IPC_ADD", nullptr));
        comboBox_subtype->setItemText(46, QApplication::translate("LogSearchClass", "MINOR_IPC_DEL", nullptr));
        comboBox_subtype->setItemText(47, QApplication::translate("LogSearchClass", "MINOR_IPC_SET", nullptr));
        comboBox_subtype->setItemText(48, QApplication::translate("LogSearchClass", "MINOR_LOCAL_START_BACKUP", nullptr));
        comboBox_subtype->setItemText(49, QApplication::translate("LogSearchClass", "MINOR_LOCAL_STOP_BACKUP", nullptr));
        comboBox_subtype->setItemText(50, QApplication::translate("LogSearchClass", "MINOR_LOCAL_COPYFILE_START_TIME", nullptr));
        comboBox_subtype->setItemText(51, QApplication::translate("LogSearchClass", "MINOR_LOCAL_COPYFILE_END_TIME", nullptr));
        comboBox_subtype->setItemText(52, QApplication::translate("LogSearchClass", "MINOR_LOCAL_ADD_NAS", nullptr));
        comboBox_subtype->setItemText(53, QApplication::translate("LogSearchClass", "MINOR_LOCAL_DEL_NAS", nullptr));
        comboBox_subtype->setItemText(54, QApplication::translate("LogSearchClass", "MINOR_LOCAL_SET_NAS", nullptr));
        comboBox_subtype->setItemText(55, QApplication::translate("LogSearchClass", "MINOR_REMOTE_LOGIN", nullptr));
        comboBox_subtype->setItemText(56, QApplication::translate("LogSearchClass", "MINOR_REMOTE_LOGOUT", nullptr));
        comboBox_subtype->setItemText(57, QApplication::translate("LogSearchClass", "MINOR_REMOTE_START_REC", nullptr));
        comboBox_subtype->setItemText(58, QApplication::translate("LogSearchClass", "MINOR_REMOTE_STOP_REC", nullptr));
        comboBox_subtype->setItemText(59, QApplication::translate("LogSearchClass", "MINOR_START_TRANS_CHAN", nullptr));
        comboBox_subtype->setItemText(60, QApplication::translate("LogSearchClass", "MINOR_STOP_TRANS_CHAN", nullptr));
        comboBox_subtype->setItemText(61, QApplication::translate("LogSearchClass", "MINOR_REMOTE_GET_PARM", nullptr));
        comboBox_subtype->setItemText(62, QApplication::translate("LogSearchClass", "MINOR_REMOTE_CFG_PARM", nullptr));
        comboBox_subtype->setItemText(63, QApplication::translate("LogSearchClass", "MINOR_REMOTE_GET_STATUS", nullptr));
        comboBox_subtype->setItemText(64, QApplication::translate("LogSearchClass", "MINOR_REMOTE_ARM", nullptr));
        comboBox_subtype->setItemText(65, QApplication::translate("LogSearchClass", "MINOR_REMOTE_DISARM", nullptr));
        comboBox_subtype->setItemText(66, QApplication::translate("LogSearchClass", "MINOR_REMOTE_REBOOT", nullptr));
        comboBox_subtype->setItemText(67, QApplication::translate("LogSearchClass", "MINOR_START_VT", nullptr));
        comboBox_subtype->setItemText(68, QApplication::translate("LogSearchClass", "MINOR_STOP_VT", nullptr));
        comboBox_subtype->setItemText(69, QApplication::translate("LogSearchClass", "MINOR_REMOTE_UPGRADE", nullptr));
        comboBox_subtype->setItemText(70, QApplication::translate("LogSearchClass", "MINOR_REMOTE_PLAYBYFILE", nullptr));
        comboBox_subtype->setItemText(71, QApplication::translate("LogSearchClass", "MINOR_REMOTE_PLAYBYTIME", nullptr));
        comboBox_subtype->setItemText(72, QApplication::translate("LogSearchClass", "MINOR_REMOTE_PTZCTRL", nullptr));
        comboBox_subtype->setItemText(73, QApplication::translate("LogSearchClass", "MINOR_REMOTE_FORMAT_HDD", nullptr));
        comboBox_subtype->setItemText(74, QApplication::translate("LogSearchClass", "MINOR_REMOTE_STOP", nullptr));
        comboBox_subtype->setItemText(75, QApplication::translate("LogSearchClass", "MINOR_REMOTE_LOCKFILE", nullptr));
        comboBox_subtype->setItemText(76, QApplication::translate("LogSearchClass", "MINOR_REMOTE_UNLOCKFILE", nullptr));
        comboBox_subtype->setItemText(77, QApplication::translate("LogSearchClass", "MINOR_REMOTE_CFGFILE_OUTPUT", nullptr));
        comboBox_subtype->setItemText(78, QApplication::translate("LogSearchClass", "MINOR_REMOTE_CFGFILE_INTPUT", nullptr));
        comboBox_subtype->setItemText(79, QApplication::translate("LogSearchClass", "MINOR_REMOTE_RECFILE_OUTPUT", nullptr));
        comboBox_subtype->setItemText(80, QApplication::translate("LogSearchClass", "MINOR_REMOTE_IPC_ADD", nullptr));
        comboBox_subtype->setItemText(81, QApplication::translate("LogSearchClass", "MINOR_REMOTE_IPC_DEL", nullptr));
        comboBox_subtype->setItemText(82, QApplication::translate("LogSearchClass", "MINOR_REMOTE_IPC_SET", nullptr));
        comboBox_subtype->setItemText(83, QApplication::translate("LogSearchClass", "MINOR_REBOOT_VCA_LIB", nullptr));
        comboBox_subtype->setItemText(84, QApplication::translate("LogSearchClass", "MINOR_REMOTE_ADD_NAS", nullptr));
        comboBox_subtype->setItemText(85, QApplication::translate("LogSearchClass", "MINOR_REMOTE_DEL_NAS", nullptr));
        comboBox_subtype->setItemText(86, QApplication::translate("LogSearchClass", "MINOR_REMOTE_SET_NAS", nullptr));
        comboBox_subtype->setItemText(87, QApplication::translate("LogSearchClass", "-----Info----", nullptr));
        comboBox_subtype->setItemText(88, QApplication::translate("LogSearchClass", "MINOR_HDD_INFO", nullptr));
        comboBox_subtype->setItemText(89, QApplication::translate("LogSearchClass", "MINOR_SMART_INFO", nullptr));
        comboBox_subtype->setItemText(90, QApplication::translate("LogSearchClass", "MINOR_REC_START", nullptr));
        comboBox_subtype->setItemText(91, QApplication::translate("LogSearchClass", "MINOR_REC_STOP", nullptr));
        comboBox_subtype->setItemText(92, QApplication::translate("LogSearchClass", "MINOR_REC_OVERDUE", nullptr));
        comboBox_subtype->setItemText(93, QApplication::translate("LogSearchClass", "MINOR_LINK_START", nullptr));
        comboBox_subtype->setItemText(94, QApplication::translate("LogSearchClass", "MINOR_LINK_STOP", nullptr));
        comboBox_subtype->setItemText(95, QApplication::translate("LogSearchClass", "MINOR_NET_DISK_INFO", nullptr));

        label->setText(QApplication::translate("LogSearchClass", "Query", nullptr));
        label_2->setText(QApplication::translate("LogSearchClass", "Main type", nullptr));
        label_3->setText(QApplication::translate("LogSearchClass", "Sub type", nullptr));
        label_4->setText(QApplication::translate("LogSearchClass", "Start", nullptr));
        label_5->setText(QApplication::translate("LogSearchClass", "End", nullptr));
        checkBox_smart->setText(QApplication::translate("LogSearchClass", "HDD smart info", nullptr));
        QTableWidgetItem *___qtablewidgetitem = logtableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("LogSearchClass", "Log time", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = logtableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("LogSearchClass", "Main type", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = logtableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("LogSearchClass", "Sub type", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = logtableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("LogSearchClass", "Remote host", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = logtableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("LogSearchClass", "Describtion", nullptr));
        pushButton_searchlog->setText(QApplication::translate("LogSearchClass", "Search log", nullptr));
        pushButton_exit->setText(QApplication::translate("LogSearchClass", "Exit", nullptr));
        label_6->setText(QApplication::translate("LogSearchClass", "Searching.......", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LogSearchClass: public Ui_LogSearchClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGSEARCH_H
