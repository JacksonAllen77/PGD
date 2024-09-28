#ifndef CHARDDISKPARAMS_H
#define CHARDDISKPARAMS_H

#include <QtWidgets/QWidget>
#include <QtWidgets/QCheckBox>
#include "ui_charddiskparams.h"
#include "DemoPublic.h"

#define MAX_CHAN_NUM 64

//��HD table��д��Ŀؼ�
typedef struct
{
	//0:�̺�; 1:����; 2:ʣ��ռ�;
	QTableWidgetItem *pTableItem[3];
	//0:״̬; 1:����; 2:����; 3:����
	QComboBox *pTableCombo[4];
}KIT_HD_WIDGET;

class CHardDiskParams : public QWidget
{
    Q_OBJECT

public:
    CHardDiskParams(QWidget *parent = 0);
    ~CHardDiskParams();

    //set userID
    int setUserID(long lUserID);

    //��ȡӲ����Ϣ
    int getHardDiskInfo();
    //����Ӳ�̲���
    int setHardDiskInfo();

    //��ȡӲ������Ϣ
    int getHDGroupInfo();
    //����Ӳ�������
    int setHDGroupInfo();

public slots:
    //ˢ��Ӳ�̹�������
    void on_btnHDUpdate_clicked();
    //����Ӳ�̹�������
    void on_btnHDSave_clicked();

    //ˢ��Ӳ�����������
    void on_btnHDGroupUpdate_clicked();
    //����Ӳ�����������
    void on_btnHDGroupSave_clicked();

    //comboxBoxѡ��
    void comboHDGroupChanged(int iHDGroupIndex);
    //���ѡ������ͨ��
    void on_checkAllChan_clicked();

private:
    Ui::CHardDiskParamsClass ui;
    long m_lUserID;
    KIT_HD_WIDGET m_struHDTableWidget[MAX_DISKNUM_V30];
    //QCheckBox *m_pCheckChanAll; //HDGroup table�����е�checkbo
    QCheckBox *m_pCheckChan[MAX_CHAN_NUM];

    //������ʾʱ����
    void showEvent ( QShowEvent * event );
    //��ȡtable�е�ͨ����Ϣ
    int GetChanInfoToTable();
    //����table��ֵ
};

#endif // CHARDDISKPARAMS_H
