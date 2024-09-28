/*
 * Copyright(C) 2009,Hikvision Digital Technology Co., Ltd 
 * 
 * �ļ����ƣ�cshelter.cpp
 * ��    ����
 * ��ǰ�汾��1.0
 * ��    �ߣ����Ƕ�
 * �������ڣ�2009��11��24��
 * �޸ļ�¼��
 */


#include "cshelter.h"
#include "publicfuc.h"


/*******************************************************************
      Function:   CShelter::CShelter
     Parameter:  
           (IN)     QWidget *parent  
   Description:   ���캯��
**********************************************************************/
CShelter::CShelter(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);

	QStringList list;
	list<<"X"<<"Y"<<"Width"<<"Height";

	ui.tableShelter->setRowCount(MAX_SHELTERNUM);
	ui.tableShelter->setColumnCount(4);
	ui.tableShelter->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableShelter->setHorizontalHeaderLabels(list);

	m_pShelter =NULL;
}

/*******************************************************************
      Function:   CShelter::~CShelter
     Parameter:  
           (IN)     �޲���  
   Description:   ��������
**********************************************************************/
CShelter::~CShelter()
{
}


/*******************************************************************
      Function:   CShelter::setShelter
     Parameter:  
           (IN)     NET_DVR_SHELTER *pShelter  �ڵ�����ָ��
        Return:   HPR_OK--�ɹ���HPR_ERROR--ʧ�ܡ�
   Description:   �����ڵ������ַ
**********************************************************************/
int CShelter::setShelter(NET_DVR_SHELTER *pShelter)
{
	if(NULL == pShelter)
	{
		return HPR_ERROR;
	}

	m_pShelter = pShelter;
    return HPR_OK;
}


/*******************************************************************
      Function:   CShelter::setEachWidgetValue
     Parameter:  
           (IN)     �޲���  
        Return:   HPR_OK--�ɹ���HPR_ERROR--ʧ�ܡ�
   Description:   ���öԻ���ؼ��е�ֵ
**********************************************************************/
int CShelter::setEachWidgetValue()
{
	if(NULL == m_pShelter)
	{
		return HPR_ERROR;
	}
	int i;
	char strTemp[100] = {0};
	for(i = 0; i < MAX_SHELTERNUM; i++)
	{
		//X����
		sprintf(strTemp, "%d", m_pShelter[i].wHideAreaTopLeftX);//����ת�ַ���
		m_itemShelter[i][0].setText(strTemp);                                      //���뵽Item��
		ui.tableShelter->setItem(i, 0, &(m_itemShelter[i][0]));               //���뵽Table��ȥ

		//Y����
		memset(strTemp, 0, 100);
		sprintf(strTemp, "%d", m_pShelter[i].wHideAreaTopLeftY);
		m_itemShelter[i][1].setText(strTemp);
		ui.tableShelter->setItem(i, 1, &(m_itemShelter[i][1]));

		//����
		memset(strTemp, 0, 100);
		sprintf(strTemp, "%d", m_pShelter[i].wHideAreaWidth);
		m_itemShelter[i][2].setText(strTemp);
		ui.tableShelter->setItem(i, 2, &(m_itemShelter[i][2]));

		//�߶�
		memset(strTemp, 0, 100);
		sprintf(strTemp, "%d", m_pShelter[i].wHideAreaHeight);
		m_itemShelter[i][3].setText(strTemp);
		ui.tableShelter->setItem(i, 3, &(m_itemShelter[i][3]));
	}

	return HPR_OK;
}

/*******************************************************************
      Function:   CShelter::getEachWidgetValue
     Parameter:  
           (IN)     �޲���  
        Return:   HPR_OK--�ɹ���HPR_ERROR--ʧ�ܡ�
   Description:   ��ȡ�Ի����еĿؼ�ֵ
**********************************************************************/
int CShelter::getEachWidgetValue()
{
	if(NULL == m_pShelter)
	{
		return HPR_ERROR;
	}

	int iTemp;
	int i;
	QString qstrTemp;
	for(i = 0; i < MAX_SHELTERNUM; i++)
	{
		qstrTemp = m_itemShelter[i][0].text();  //�������ã�ֱ����kit����ȡ��ַ����waring
		KIT_qstringToInt(&(qstrTemp), &iTemp);
		m_pShelter[i].wHideAreaTopLeftX = iTemp;

		qstrTemp = m_itemShelter[i][1].text();
		KIT_qstringToInt(&(qstrTemp), &iTemp);
		m_pShelter[i].wHideAreaTopLeftY = iTemp;

		qstrTemp = m_itemShelter[i][2].text();
		KIT_qstringToInt(&(qstrTemp), &iTemp);
		m_pShelter[i].wHideAreaWidth = iTemp;

		qstrTemp = m_itemShelter[i][3].text();
		KIT_qstringToInt(&(qstrTemp), &iTemp);
		m_pShelter[i].wHideAreaHeight = iTemp;
	}

	return HPR_OK;
}

/*******************************************************************
      Function:   CShelter::on_btnSave_clicked
     Parameter:  
           (IN)     �޲���  
        Return:   ��
   Description:   ��ȷ������ť����Ӧ���������ڱ������
**********************************************************************/
void CShelter::on_btnSave_clicked()
{
	getEachWidgetValue();//�������
    close();
}

/*******************************************************************
      Function:   CShelter::showEvent
     Parameter:  
           (IN)     QShowEvent * event  ������ʾ�¼�
        Return:   ��
   Description:   �Ի�����ʾʱ���������е�ֵд��ؼ�����ʾ����
**********************************************************************/
void CShelter::showEvent ( QShowEvent * event )
{
	if(event ==NULL)
	{
	}
	//��ȡ��ʾ����
	setEachWidgetValue();
}
