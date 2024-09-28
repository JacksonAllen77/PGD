#ifndef CVILOST_H
#define CVILOST_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QCheckBox>
#include "DemoPublic.h"
#include "ui_cvilost.h"

using namespace Ui;

class CVILost : public QDialog
{
    Q_OBJECT

public:
    CVILost(QDialog *parent = 0);
    ~CVILost();

    //�����źŶ�ʧ��������
    int setStruVILost(NET_DVR_VILOST_V30 *pstruVILost);
    //���ñ����������
    int setAlarmOutNum(int iAlarmOutNum);
    //�����û�ID
    int setUserID(long lUserID);

    //event
    void showEvent ( QShowEvent * event );

public slots:
    //�������
    void on_btnSave_clicked();
    //���ڱ��ı�
    void comboWeekDayChanged(int iWeekDay);
    //�Ƿ񴥷��������
    void checkAlarmOut();

private:
    Ui::CVILostClass ui;
    long m_lUserID;   //��½ʱ��ȡ��IDֵ
    NET_DVR_VILOST_V30 *m_pstruVILost; //��Ƶ�źŶ�ʧ��������ָ��
    int m_iAlarmOutNum;                                   //�����������
    QLineEdit m_editStartHour[MAX_TIMESEGMENT_V30]; //������ʼʱ��(Сʱ)
    QLineEdit m_editStartMin[MAX_TIMESEGMENT_V30];   //������ʼʱ��(����)
    QLineEdit m_editEndHour[MAX_TIMESEGMENT_V30];  //��������ʱ��(Сʱ)
    QLineEdit m_editEndMin[MAX_TIMESEGMENT_V30];    //��������ʱ��(����)

    QCheckBox *m_pcheckAlarmOut[MAX_ALARMOUT_V30]; //�����ı������

    //��table�в���iAlarmOutNum���������checkbo
    int createAlarmOutCheck();
    int getAlarmOutInfo(int iAlarmOut, QCheckBox *pQCheckAlarmOut);

    //����ÿ���ؼ���ֵ
    int setEachWidgetValue();
    //��ȡÿ���ؼ���ֵ
    int getEachWidgetValue();
};

#endif // CVILOST_H
