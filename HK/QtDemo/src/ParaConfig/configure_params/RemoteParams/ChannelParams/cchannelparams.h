#ifndef CCHANNELPARAMS_H
#define CCHANNELPARAMS_H

#include <QtWidgets/QWidget>
#include "ui_cchannelparams.h"
#include "DemoPublic.h"

#define KIT_SHOWSTRING_LEN 44
//using namespace Ui;

class CChannelParams : public QWidget
{
    Q_OBJECT

public:
    CChannelParams(QWidget *parent = 0);
    ~CChannelParams();

    //event
    void showEvent ( QShowEvent * event );

    int setUserID(long lUserID);
    int getChannelNum();   //get the channel and IP channel. (Used by myself.)

    //get all information
    int getAllInfo();
    int setAllInfo();

    int getCompressInfo(int iCompIndex); //Get compress parameters.
    int setCompressInfo(); //Set compress parameters.

    int getRecordInfo(); //Get record parameter.
    int setRecordInfo(); //Set record parameter.

    int getPictureInfo();  //��ȡͼ�����
    int setPictureInfo();  //����ͼ�����

    int getShowStringInfo();//��ȡ�ַ����Ӳ���
    int setShowStringInfo();//�����ַ����Ӳ���

public slots:
    //(combox changed)
    void comboChNoChanged ( int iChannelIndex );
    void comboCompChanged(int iCompIndex);
    void comboVideoBitChanged(int iVideoBitIndex);
    void comboStringNoChanged(int iStringNo);

    //(btn)
    void clickBtnRemoteRecord();  //����¼��ʱ��ƻ�.
    void clickBtnVILost();              //��Ƶ�źŶ�ʧ������������
    void clickBtnShelter();               //�ڵ�����
    void on_btnMotion_clicked();   //�ƶ����
    void on_btnHide_clicked();       //�ڵ�����

    //(click check)�Ƿ�ʱ¼��
    void clickCheckVideoRecord();
    //(click check)�Ƿ�����Ļ����ʾͨ������
    void clickCheckShowChanName();
    //(click check)�Ƿ������źŶ�ʧ��������
    void clickCheckVILost();
    //(click check)�Ƿ������ڵ�
    void clickCheckShelter();
    //(click check)�Ƿ������ƶ����
    void clickCheckMotion();
    //(click check)�Ƿ������ڵ�
    void clickCheckHide();
    //(click check)�Ƿ���ʾOSD
    void clickCheckOSD();
    //�Ƿ���ʾ�ַ�����
    void clickCheckShowString();

private:
    Ui::CChannelParamsClass ui;
    long m_lUserID;
    long m_lChannel;
    int m_iArryChannel[MAX_CHANNUM_V30];//the index is  combox index, the value is channel ID
    int m_iStartChan;            // start channel NO.
    int m_iSimChannelNum;  //ʵ�ʿ���ģ��ͨ������

    NET_DVR_RECORD_V30 m_struRecord;//¼�������ʱ¼���ʱ����趨
    BOOL m_bSetRecord; //��ʾ¼������С����á���ť��û�б��������ѡ"��ʱ¼��"ʱ����ֵ������Ϊ��

    NET_DVR_VILOST_V30 m_struVILost; //ͼ�����->�źŶ�ʧ����
    BOOL m_bVILost;                                   //�źŶ�ʧ�����С����á���ť����û�б����

    NET_DVR_SHELTER  m_struShelter[MAX_SHELTERNUM]; //�ڵ�����
    BOOL m_bShelter;  //�ڵ�����ť�Ƿ񱻵����

    NET_DVR_MOTION_V30  m_struMotion; //�ƶ����
    BOOL m_bMotion; //�ƶ���ⰴť�Ƿ񱻵��

    NET_DVR_HIDEALARM_V30   m_struHide; //�ڵ�����
    BOOL m_bHide; //�ڵ������İ�ť�Ƿ񱻵��

    //��ʾ�ַ�

    //set the value of each compress widget.ѹ������
    int setEachCompWidget(LPNET_DVR_COMPRESSION_INFO_V30 pCompressInfo);
    //get the value of each compress widget.
    int getEachCompWidget(LPNET_DVR_COMPRESSION_INFO_V30 pCompressInfo);
};

#endif // CCHANNELPARAMS_H
