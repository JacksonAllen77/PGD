#ifndef CIPPARAMS_H
#define CIPPARAMS_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include "ui_cipparams.h"
#include "DemoPublic.h"

class CIPParams : public QWidget
{
    Q_OBJECT

public:
    CIPParams(QWidget *parent = 0);
    ~CIPParams();

    //set userID
    int setUserID(long lUserID);

    //��ȡͨ����Ϣ��д�������
    int getIPInfo();
    //�ӱ����еõ����ݣ�д���豸
    int saveIPInfo();

public slots:

    //(click table)��Ӧ���񵥻��¼�
    int clickTabChannel(int iRow);
    //IPͨ����������
    void on_btnEdit_clicked();
    //ɾ��IPͨ������
    void on_btnDelete_clicked();
    //����ģ��ͨ��
    void on_btnEnable_clicked();
    //����ģ��ͨ��
    void on_btnDisenable_clicked();

private:
    Ui::CIPParamsClass ui;
    long m_lUserID;
    int m_iIPParamIndex;
    int m_iCurrentRow;

    //��ȡ�豸��Ϣ
    int getDeviceInfo(LPNET_DVR_DEVICECFG pDeviceInfo);
    //��ȡIP������Ϣ
    int getIPConInfo(LPNET_DVR_IPPARACFG pIPConInfo);
    //��ȡ����IP�������������ֵ
    int getIPChannnelIndex(int iRow, int *piChannelIndex);
    //ͼ����ʾʱ����
    void showEvent ( QShowEvent * event );
};

#endif // CIPPARAMS_H
