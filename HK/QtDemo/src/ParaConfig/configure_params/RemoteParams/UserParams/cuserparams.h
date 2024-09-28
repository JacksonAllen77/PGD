#ifndef CUSERPARAMS_H
#define CUSERPARAMS_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include "ui_cuserparams.h"
#include "DemoPublic.h"

class CUserParams : public QDialog
{
    Q_OBJECT

public:
    CUserParams(QWidget *parent = 0);
    ~CUserParams();

    int setUserID(long lUserID);

    int getAllInfo();
    int setAllInfo();

public slots:
    void userIDChanged(int iUserID);
    void localRightTypeChanged(int iLocalRightType);       //����ͨ��
    void remoteRightTypeChanged(int iRemoteRightType); //Զ��ͨ��

private:
    Ui::CUserParamsClass ui;
    long m_lUserID;
    QCheckBox *m_pcheckLocalRight[MAX_RIGHT];    //����Ȩ��
    QCheckBox *m_pcheckRemoteRight[MAX_RIGHT]; //Զ��Ȩ��
    int m_iArryChannel[MAX_CHANNUM_V30];//the index is  combox index, the value is channel ID
    QCheckBox *m_pcheckLocalChannel[MAX_CHANNUM_V30];    //����ͨ��Ȩ��
    QCheckBox *m_pcheckRemoteChannel[MAX_CHANNUM_V30]; //Զ��ͨ��Ȩ��
    QPushButton  *m_ptest;
    int m_iStartChan;            // ��ʼͨ����.
    int m_iSimChannelNum;  //ʵ�ʿ���ģ��ͨ������
    QLineEdit *m_pEditMAC[MACADDR_LEN]; //������ַ

    //event
    void showEvent ( QShowEvent * event );
    //����checkȨ����check����֮��Ķ�Ӧ��ϵ
    void connectArrayAndWidget();
    //get the channel and IP channel. (Used by myself.)
    int getChannelNum();
};

#endif // CUSERPARAMS_H
