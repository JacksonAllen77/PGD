#ifndef CALARMPARAMSDLG_H
#define CALARMPARAMSDLG_H

#include <QtWidgets/QDialog>
#include <QCheckBox>
#include <QMessageBox>
#include "DemoPublic.h"

namespace Ui {
    class CAlarmParamsDlg;
}

class CAlarmParamsDlg : public QDialog {
    Q_OBJECT
public:

    CAlarmParamsDlg(QWidget *parent = 0);
    ~CAlarmParamsDlg();
    int setUserID(long lUserID);

    //��ȡ������ز���
   int getAlarmInfo();
   //���ñ���������ز���
   int setAlarmInInfo();
   //���ñ����������
   int setAlarmoutInfo();

public slots:
	//����������Ÿı�
    void changeAlarmInIndex(int index);
    //�Ƿ񱨾����봦����ʽ
    void on_checkBoxAlarmInHandle_clicked();
    //�������봦����ʽ
    void on_pushButtonAlarmInHandle_clicked();
    //PTZ
    void on_pushButtonPTZ_clicked();

    //���ñ����������button
    void on_pushButtonAlarmInSave_clicked();
    //���ñ����������button
    void on_pushButtonAlarmOutSave_clicked();

    //�������
    void changeAlarmOutIndex(int index);
    void changeAlarmOutDateIndex(int index);

protected:
    void changeEvent(QEvent *e);
    void showEvent(QShowEvent * event);

private:
    Ui::CAlarmParamsDlg *m_ui;
    long m_lUserID;

    BOOL m_bGetAlarmInInfo;
    BOOL m_bGetAlarmOutInfo;
    int m_iAlarmInIndex;
    int m_iAlarmOutIndex;
    BOOL m_bGetAlarmIn[MAX_ALARMIN_V30];
    BOOL m_bGetAlarmOut[MAX_ALARMOUT_V30];
    NET_DVR_IPALARMINCFG m_struIPAlarmInCfg;
    NET_DVR_IPALARMOUTCFG m_struIPAlarmOutCfg;
    NET_DVR_ALARMINCFG_V30 m_struAlarmInCfg[MAX_ALARMIN_V30];
    NET_DVR_ALARMINCFG_V30 m_struCurrAlarmInCfg; //��ǰ�����������
    NET_DVR_ALARMOUTCFG_V30 m_struAlarmOutCfg[MAX_ALARMOUT_V30];
    NET_DVR_ALARMOUTCFG_V30 m_struCurrAlarmOutCfg; //��ǰ�����������
    NET_DVR_IPPARACFG m_struIpAccessCfg;

    //���ݱ����������ƣ���ȡ�����������
    int getAlarmInIndexByName(char * strName);
    int getAlarmOutIndexByName(char * strName);

};

#endif // CALARMPARAMSDLG_H
