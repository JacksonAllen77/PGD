#ifndef CMOTION_H
#define CMOTION_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include "ui_cmotion.h"
#include "DemoPublic.h"

#define KIT_MOTION_WIDTH 22  //�ƶ������22*18��С���
#define KIT_MOTION_HEIGHT 18

class CMotion : public QDialog
{
    Q_OBJECT

public:
    CMotion(QWidget *parent = 0);
    ~CMotion();

    int setAlarmOutNum(int iAlarmOutNum);
    //���ÿ���ͨ��ID
    int setChannelID(int *piChannelID);
    //�����ƶ���ⱨ������
    int setStruMotion(NET_DVR_MOTION_V30 *pstruMotion);
    //������ʼͨ����
    int setStartChannelNo(int iStartChannelNo);
    //�����û�ID
    int setUserID(long lUserID);

    //event
    void showEvent ( QShowEvent * event );

public slots:
     //���ڱ��ı�
     void comboWeekDayChanged(int iWeekDay);
     //�Ƿ񴥷��������
     void checkAlarmOut();
     //�������
     void on_btnSave_clicked();

private:
    Ui::CMotionClass ui;
    long m_lUserID;   //��½ʱ��ȡ��IDֵ
    //�ƶ��������
    QCheckBox m_checkMotionScope[KIT_MOTION_HEIGHT][KIT_MOTION_WIDTH];
    QCheckBox *m_pcheckAlarmOut[MAX_ALARMOUT_V30]; //�����ı������
    //������¼��ͨ��, �����Ŵ�����ͨ��ID - ��ʼͨ����
    QCheckBox m_checkChannel[MAX_CHANNUM_V30];
    QLineEdit m_editStartHour[MAX_TIMESEGMENT_V30]; //������ʼʱ��(Сʱ)
    QLineEdit m_editStartMin[MAX_TIMESEGMENT_V30];   //������ʼʱ��(����)
    QLineEdit m_editEndHour[MAX_TIMESEGMENT_V30];  //��������ʱ��(Сʱ)
    QLineEdit m_editEndMin[MAX_TIMESEGMENT_V30];    //��������ʱ��(����)

    //�ƶ�������ָ��
    NET_DVR_MOTION_V30 *m_pstruMotion;
    int *m_iArryChannel;                                       //����ͨ��ID����
    int m_iAlarmOutNum;                                      //�����������
    int m_iStartChannelNo;                                    //��ʼͨ����

    //���ݿ���ID��,��������¼��ͨ����
    int createChannelCheck();
    //�����������check
    int createAlarmOutCheck();
    int getAlarmOutInfo(int iAlarmOut, QCheckBox *pQCheckAlarmOut);

    int setEachWidgetValue(); //���ý��������пؼ��е�ֵ
    int getEachWidgetValue(); //��ȡ���������пؼ��е�ֵ

    int setMotionAlarmTypeWidget();//���ñ���������ʽ
    int getMotionAlarmTypeWidget();//��ȡ����������ʽ
};

#endif // CMOTION_H
