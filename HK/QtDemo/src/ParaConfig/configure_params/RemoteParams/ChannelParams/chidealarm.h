#ifndef CHIDEALARM_H
#define CHIDEALARM_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLineEdit>
#include "ui_chidealarm.h"
#include "DemoPublic.h"

class CHideAlarm : public QDialog
{
    Q_OBJECT

public:
    CHideAlarm(QWidget *parent = 0);
    ~CHideAlarm();

    //�����źŶ�ʧ��������
    int setStruHideAlarm(NET_DVR_HIDEALARM_V30 *pstruHideAlarm);
    //���ñ����������
    int setAlarmOutNum(int iAlarmOutNum);
    //�����û�ID
    int setUserID(long lUserID);

public slots:
    //�������
    void on_btnSave_clicked();
    //���ڱ��ı�
    void comboWeekDayChanged(int iWeekDay);
    //�Ƿ񴥷��������
    void checkAlarmOut();

private:
    Ui::CHideAlarmClass ui;

    long m_lUserID;                    //��½ʱ��ȡ��IDֵ
    int m_iAlarmOutNum;            //�����������

    NET_DVR_HIDEALARM_V30 *m_pstruHideAlarm; //�ڵ���������

    QLineEdit m_editStartHour[MAX_TIMESEGMENT_V30]; //������ʼʱ��(Сʱ)
    QLineEdit m_editStartMin[MAX_TIMESEGMENT_V30];   //������ʼʱ��(����)
    QLineEdit m_editEndHour[MAX_TIMESEGMENT_V30];  //��������ʱ��(Сʱ)
    QLineEdit m_editEndMin[MAX_TIMESEGMENT_V30];    //��������ʱ��(����)
    QCheckBox *m_pcheckAlarmOut[MAX_ALARMOUT_V30]; //�����ı������

    //event
    void showEvent ( QShowEvent * event );
    //��table�в���iAlarmOutNum���������checkbo
    int createAlarmOutCheck();
    int getAlarmOutInfo(int iAlarmOut, QCheckBox *pQCheckAlarmOut);

    //����ÿ���ؼ���ֵ
    int setEachWidgetValue();
    //��ȡÿ���ؼ���ֵ
    int getEachWidgetValue();
};

#endif // CHIDEALARM_H
