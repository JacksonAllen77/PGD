#ifndef CDLGREMOTERECORDSCHEDULE_H
#define CDLGREMOTERECORDSCHEDULE_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QComboBox>
#include "ui_cdlgremoterecordschedule.h"
#include "DemoPublic.h"

/**
 * �������û�в����豸��ֻ������ʱ�䰲��ֵ
 * **/

class CDlgRemoteRecordSchedule : public QDialog
{
    Q_OBJECT

public:
    CDlgRemoteRecordSchedule(QWidget *parent = 0);
    ~CDlgRemoteRecordSchedule();

    //���ṹ�帳ֵ����ַ
    int SetStruRecord(NET_DVR_RECORD_V30 *pstruRecord);

    //event
    void showEvent ( QShowEvent * event );

public slots:
    void on_btnCopyDay_clicked();
    void on_btnSave_clicked();

    int comboWeekDayChanged(int iWeekDay);

    int clickRecordAllDay();


private:
    Ui::CDlgRemoteRecordScheduleClass ui;

    QLineEdit m_editStartHour[MAX_TIMESEGMENT_V30];
    QLineEdit m_editStartMin[MAX_TIMESEGMENT_V30];
    QLineEdit m_editEndHour[MAX_TIMESEGMENT_V30];
    QLineEdit m_editEndMin[MAX_TIMESEGMENT_V30];
    QComboBox m_comboRecordType[MAX_TIMESEGMENT_V30]; //¼������

    //¼�������Ϣ
    NET_DVR_RECORD_V30 *m_pstruRecord;

    //������ǰ���õ�ĳһ��
    int copyDaySetting(int iWeekNo);
    int setEachWidget(int iWeekDay);

};

#endif // CDLGREMOTERECORDSCHEDULE_H
