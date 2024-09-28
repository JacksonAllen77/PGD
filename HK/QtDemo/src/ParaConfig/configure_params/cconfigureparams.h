/*
 * Copyright(C) 2010,Hikvision Digital Technology Co., Ltd 
 * 
 * �ļ����ƣ�cconfigureparams.h
 * ��    ����
 * ��ǰ�汾��1.0
 * ��    �ߣ����Ƕ�
 * �������ڣ�2010��2��1��
 * �޸ļ�¼��
 */


#ifndef CCONFIGUREPARAMS_H
#define CCONFIGUREPARAMS_H

#include <QtWidgets/QWidget>
#include <QMessageBox>
#include "cremoteparams.h"
#include "cipparams.h"
#include "charddiskparams.h"
#include "DemoPublic.h"


#ifndef HPR_OK
#define HPR_OK 0
#endif

#ifndef HPR_ERROR
#define HPR_ERROR 1
#endif

namespace Ui
{
    class CConfigureParams;
}

class CConfigureParams : public QWidget
{
    Q_OBJECT

public:
    CConfigureParams(QWidget *parent = 0);
    ~CConfigureParams();

    //event
    void showEvent ( QShowEvent * event );

public slots:
    void loadRemoteParams();          //Զ�̲���
    void on_btnIPParams_clicked();             //IP��������
    void on_btnHardDiskParams_clicked(); //Ӳ������
    void GetDVRUserID();
    void SetDVRUserID(long lUserID);

    void showLoginBtn();

private:
    Ui::CConfigureParams *ui;
    QMessageBox m_MessageBox;

    QWidget *m_pCurrentWidget;
    CRemoteParams *m_pRemoteparams;
    CIPParams *m_pIPParams;
    CHardDiskParams *m_pHardDiskParams;

    long m_lUserID;  //user ID
};

#endif // CCONFIGUREPARAMS_H
