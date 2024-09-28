/*
 * Copyright(C) 2010,Hikvision Digital Technology Co., Ltd 
 * 
 * �ļ����ƣ�calarminhandletype.h
 * ��    ����
 * ��ǰ�汾��1.0
 * ��    �ߣ����Ƕ�
 * �������ڣ�2010��1��15��
 * �޸ļ�¼��
 */

#ifndef CALARMINHANDLETYPE_H
#define CALARMINHANDLETYPE_H

#include <QtWidgets/QDialog>
#include "ui_calarminhandletype.h"
#include "DemoPublic.h"
#include <QtWidgets/QLineEdit>

class CAlarmInHandleType : public QDialog
{
    Q_OBJECT

public:
    CAlarmInHandleType(QWidget *parent = 0);
    ~CAlarmInHandleType();

    int setUserID(long lUserID);
    int setAlarmInInfo(LPNET_DVR_ALARMINCFG_V30 pAlarmInInfo);

    //�������ݵ�����
    int getAlarmInHandleInfo();
    //�������ݵ��豸��
    int setAlarmInHandleInfo();

public slots:
    void showEvent(QShowEvent * event);
    //���ڱ��ı�
    void comboWeekDayChanged(int iWeekDay);
    void on_checkbo08_clicked();

    //�������
    void on_btnSave_clicked();


private:
    Ui::CAlarmInHandleTypeClass ui;
    long m_lUserID;

    LPNET_DVR_ALARMINCFG_V30 m_pAlarmInInfo;
    //������¼��ͨ��, �����Ŵ�����ͨ��ID - ��ʼͨ����
    QCheckBox *m_pCheckChannel[MAX_CHANNUM_V30];
    //�����ı������
    QCheckBox *m_pcheckAlarmOut[MAX_ALARMOUT_V30];

    QLineEdit m_editStartHour[MAX_TIMESEGMENT_V30]; //������ʼʱ��(Сʱ)
    QLineEdit m_editStartMin[MAX_TIMESEGMENT_V30];   //������ʼʱ��(����)
    QLineEdit m_editEndHour[MAX_TIMESEGMENT_V30];  //��������ʱ��(Сʱ)
    QLineEdit m_editEndMin[MAX_TIMESEGMENT_V30];    //��������ʱ��(����)

    int setAlarmTypeWidget();
    int getAlarmTypeWidget();//��ȡ����������ʽ
};

#endif // CALARMINHANDLETYPE_H
