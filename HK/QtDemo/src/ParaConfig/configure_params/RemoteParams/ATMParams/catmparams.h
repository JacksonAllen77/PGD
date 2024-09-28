/*
 * Copyright(C) 2010,Hikvision Digital Technology Co., Ltd 
 * 
 * �ļ����ƣ�catmparams.h
 * ��    ����
 * ��ǰ�汾��1.0
 * ��    �ߣ����Ƕ�
 * �������ڣ�2010��1��11��
 * �޸ļ�¼��
 */


#ifndef CATMPARAMS_H
#define CATMPARAMS_H

#include <QtWidgets/QWidget>
#include "ui_catmparams.h"
#include "catmnetparams.h"

class CATMParams : public QWidget
{
    Q_OBJECT

public:
    CATMParams(QWidget *parent = 0);
    ~CATMParams();

    int getATMInfo();
    int setATMInfo();

    int setUserID(long lUserID);

 public slots:
	 void comboInputTypeChanged(int iType);


private:
    long m_lUserID;
    CATMNetParams *m_pNetListen;
    Ui::CATMParamsClass ui;


    //event
    void showEvent ( QShowEvent * event );

    //�ж�ϵͳ�Ƿ�֧��ATM���� �����֧�֣����治����
    int isATMDevice();
};

#endif // CATMPARAMS_H
