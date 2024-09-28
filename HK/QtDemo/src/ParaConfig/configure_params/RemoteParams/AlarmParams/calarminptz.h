/*
 * Copyright(C) 2010,Hikvision Digital Technology Co., Ltd 
 * 
 * �ļ����ƣ�calarminptz.h
 * ��    ����
 * ��ǰ�汾��1.0
 * ��    �ߣ����Ƕ�
 * �������ڣ�2010��1��15��
 * �޸ļ�¼��
 */

#ifndef CALARMINPTZ_H
#define CALARMINPTZ_H

#include <QtWidgets/QDialog>
#include "ui_calarminptz.h"
#include "DemoPublic.h"

class CAlarmInPTZ : public QDialog
{
    Q_OBJECT

public:
    CAlarmInPTZ(QWidget *parent = 0);
    ~CAlarmInPTZ();

    int setUserID(long lUserID);
    int setAlarmInInfo(LPNET_DVR_ALARMINCFG_V30 pAlarmInInfo);

    //�������ݵ�����
    int getAlarmInPTZInfo();
    //�������ݵ��豸��
    int setAlarmInPTZInfo();

public slots:
    void changeChanIndex(int index);
    void showEvent(QShowEvent * event);

    void on_rBtnPreset_clicked();
    void on_rBtnCruise_clicked();
    void on_rBtnPtzTrack_clicked();

    void on_btnSave_clicked();
    void on_btnExit_clicked();

private:
    Ui::CAlarmInPTZClass ui;
    long m_lUserID;

    LPNET_DVR_ALARMINCFG_V30 m_pAlarmInInfo;
};

#endif // CALARMINPTZ_H
