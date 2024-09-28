/*
 * Copyright(C) 2010,Hikvision Digital Technology Co., Ltd 
 * 
 * �ļ����ƣ�catmnetparams.h
 * ��    ����
 * ��ǰ�汾��1.0
 * ��    �ߣ����Ƕ�
 * �������ڣ�2010��1��11��
 * �޸ļ�¼��
 */

#ifndef CATMNETPARAMS_H
#define CATMNETPARAMS_H

#include <QtWidgets/QWidget>
#include "ui_catmnetparams.h"
#include "DemoPublic.h"

//using namespace Ui;

class CATMNetParams : public QWidget
{
    Q_OBJECT

public:
    CATMNetParams(QWidget *parent = 0);
    ~CATMNetParams();

    //���豸�е�����д��ؼ���
    int getATMInfo(LPNET_DVR_FRAMEFORMAT pstruATMInfo);
    //���ؼ��е�����д���豸��
    int setATMInfo(LPNET_DVR_FRAMEFORMAT pstruATMInfo);

public slots:
	void comboCodeTypeChanged(int iType);

private:
    Ui::CATMNetParamsClass ui;
    int m_bCode; //�Ƿ��д���
    NET_DVR_FRAMETYPECODE    m_frameTypeCode[10]; //ATM ������Ϣ
};

#endif // CATMNETPARAMS_H
