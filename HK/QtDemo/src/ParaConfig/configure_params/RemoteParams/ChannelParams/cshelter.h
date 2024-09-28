/*
 * Copyright(C) 2009,Hikvision Digital Technology Co., Ltd 
 * 
 * �ļ����ƣ�cshelter.h
 * ��    ����
 * ��ǰ�汾��1.0
 * ��    �ߣ����Ƕ�
 * �������ڣ�2009��11��24��
 * �޸ļ�¼��
 */


#ifndef CSHELTER_H
#define CSHELTER_H

#include <QtWidgets/QDialog>
#include "ui_cshelter.h"
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QCheckBox>
#include "DemoPublic.h"

class CShelter : public QDialog
{
    Q_OBJECT

public:
    CShelter(QWidget *parent = 0);
    ~CShelter();

    //�ڵ�����
    int setShelter(NET_DVR_SHELTER *pShelter);

    //��������

    //event
    void showEvent ( QShowEvent * event );

public slots:
    //��������
    void on_btnSave_clicked();

private:
    Ui::CShelterClass ui;
    NET_DVR_SHELTER *m_pShelter;
    QTableWidgetItem m_itemShelter[MAX_SHELTERNUM][4];//�ڵ�����

    //���ñ�ʾ�ڵ������table�е�ֵ
    int setEachWidgetValue();
    //��ȡ��ʾ�ڵ������table�е�ֵ
    int getEachWidgetValue();
};

#endif // CSHELTER_H
