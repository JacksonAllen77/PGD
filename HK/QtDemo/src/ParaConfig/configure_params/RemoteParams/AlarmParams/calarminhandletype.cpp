/*
 * Copyright(C) 2010,Hikvision Digital Technology Co., Ltd 
 * 
 * �ļ����ƣ�calarminhandletype.cpp
 * ��    ����
 * ��ǰ�汾��1.0
 * ��    �ߣ����Ƕ�
 * �������ڣ�2010��1��15��
 * �޸ļ�¼��
 */


#include "calarminhandletype.h"
#include "publicfuc.h"

CAlarmInHandleType::CAlarmInHandleType(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);
	ui.tableChannel->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableAlarmOut->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	m_lUserID = -1;
	m_pAlarmInInfo = NULL; //�ⲿ���룬�ⲿ�ͷ�

	int i;
	//����ʱ��༭��
	for(i = 0; i < MAX_TIMESEGMENT_V30; i++)
	{
		ui.vLayStartHour->addWidget(&(m_editStartHour[i]));
		ui.vLayStartMin->addWidget(&(m_editStartMin[i]));
		ui.vLayEndHour->addWidget(&(m_editEndHour[i]));
		ui.vLayEndMin->addWidget(&(m_editEndMin[i]));
	}
	QStringList list;
	list<<"Monday"<<"Tuesday"<<"Wednesday"<<"Thursday"<<"Friday"<<"Saturday"<<"Sunday";
    ui.comboWeekDay->addItems(list);

	connect(ui.comboWeekDay, SIGNAL(activated(int)), this, SLOT(comboWeekDayChanged(int)));
}

CAlarmInHandleType::~CAlarmInHandleType()
{

}

int CAlarmInHandleType::setUserID(long lUserID)
 {
     if(lUserID >= 0)
     {
         m_lUserID = lUserID;
         return HPR_OK;
     }
     else
     {
         return HPR_ERROR;
     }
 }

int CAlarmInHandleType::setAlarmInInfo(LPNET_DVR_ALARMINCFG_V30 pAlarmInInfo)
{
	if(pAlarmInInfo == NULL)
	{
		return HPR_ERROR;
	}

	//���豸����д�����
	m_pAlarmInInfo = pAlarmInInfo;
	return HPR_OK;
}

//�������ݵ�����
int CAlarmInHandleType::getAlarmInHandleInfo()
{
	if(m_pAlarmInInfo == NULL || m_lUserID < 0)
	{
		return HPR_ERROR;
	}

	//��ȡ����¼��ͨ��
	int iTotalChanNum;
	if(KIT_CreateCheckboxChanArr(m_lUserID, m_pCheckChannel, &iTotalChanNum)==HPR_ERROR)
	{
		return HPR_ERROR;
	}
	//����Щ������checkbox���뵽ͨ��table��ȥ
	//����ͨ�����
    //1.��ձ���
	int iRow;
	ui.tableChannel->clear();
	for(iRow = 0; iRow < ui.tableChannel->rowCount(); iRow++)
	{
		ui.tableChannel->removeRow(iRow);
	}
	//2.�������м�������
    ui.tableChannel->setRowCount(iTotalChanNum);
    ui.tableChannel->setColumnCount(1);
    int i;
    iRow = 0;
    for(i = 0; i < MAX_CHANNUM_V30; i++)
    {
    	if(m_pCheckChannel[i] != NULL)
    	{
    		ui.tableChannel->setCellWidget(iRow, 0, m_pCheckChannel[i]);
    		if(m_pAlarmInInfo->byRelRecordChan[i] == 1)
    		{
    			m_pCheckChannel[i]->setChecked(TRUE);
    		}
    		else
    		{
    			m_pCheckChannel[i]->setChecked(FALSE);
    		}
    		iRow++;
    	}
    }

    //**�������**//
    int iTotalAlarmOutNum;
    if(KIT_CreateCheckboxAlarmOut(m_lUserID, m_pcheckAlarmOut, &iTotalAlarmOutNum) == HPR_ERROR)
    {
    	return HPR_ERROR;
    }
    //1.��ձ����������
	ui.tableAlarmOut->clear();
	for(iRow = 0; iRow < ui.tableAlarmOut->rowCount(); iRow++)
	{
		ui.tableAlarmOut->removeRow(iRow);
	}
	//2.�������м�������
    ui.tableAlarmOut->setRowCount(iTotalAlarmOutNum);
    ui.tableAlarmOut->setColumnCount(1);
    iRow = 0;
    for(i = 0; i < MAX_ALARMOUT_V30; i++)
    {
    	if(m_pcheckAlarmOut[i] != NULL)
    	{
    		ui.tableAlarmOut->setCellWidget(iRow, 0, m_pcheckAlarmOut[i]);
    		if(m_pAlarmInInfo->struAlarmHandleType.byRelAlarmOut[i] == 1)
    		{
    			m_pcheckAlarmOut[i]->setChecked(TRUE);
    		}
    		else
    		{
    			m_pcheckAlarmOut[i]->setChecked(FALSE);
    		}
    		iRow++;
    	}
    }

    //����ʱ��
    comboWeekDayChanged(0);
    //����������ʽ
    setAlarmTypeWidget();

    return HPR_OK;
}

//�ӽ����ȡ������д���豸
int CAlarmInHandleType::setAlarmInHandleInfo()
{
	if(m_pAlarmInInfo == NULL)
	{
		return HPR_ERROR;
	}

	//����¼��ͨ��
    int i;
    for(i = 0; i < MAX_CHANNUM_V30; i++)
    {
    	if(m_pCheckChannel[i] != NULL)
    	{
    		if(m_pCheckChannel[i]->isChecked())
    		{
    			m_pAlarmInInfo->byRelRecordChan[i] = 1;
    		}
    		else
    		{
    			m_pAlarmInInfo->byRelRecordChan[i] =0;
    		}
    	}
    }

    //���ñ������
    for(i = 0; i < MAX_ALARMOUT_V30; i++)
    {
    	if(m_pcheckAlarmOut[i] != NULL)
    	{
    		if(m_pcheckAlarmOut[i]->isChecked())
    		{
    			m_pAlarmInInfo->struAlarmHandleType.byRelAlarmOut[i] = 1;
    		}
    		else
    		{
    			m_pAlarmInInfo->struAlarmHandleType.byRelAlarmOut[i] = 0;
    		}
    	}
    }

    //ʱ��
	//��ȡ����ʱ��
	int iTime;
	int iWeekDay;
	iWeekDay = ui.comboWeekDay->currentIndex();
	for(i = 0; i < MAX_TIMESEGMENT_V30; i++)
	{
	    //��ʼСʱ
		KIT_editToInt(&(m_editStartHour[i]), &iTime);
		m_pAlarmInInfo->struAlarmTime[iWeekDay][i].byStartHour = iTime;
		//��ʼ����
		KIT_editToInt(&(m_editStartMin[i]), &iTime);
		m_pAlarmInInfo->struAlarmTime[iWeekDay][i].byStartMin = iTime;
		//����Сʱ
		KIT_editToInt(&(m_editEndHour[i]), &iTime);
		m_pAlarmInInfo->struAlarmTime[iWeekDay][i].byStopHour = iTime;
		//��������
		KIT_editToInt(&(m_editEndMin[i]), &iTime);
		m_pAlarmInInfo->struAlarmTime[iWeekDay][i].byStopMin = iTime;
	}

	//������ʽ
	getAlarmTypeWidget();
	return HPR_OK;
}

//��ȡ����������ʽ
int CAlarmInHandleType::getAlarmTypeWidget()
{
	if(NULL == m_pAlarmInInfo)
	{
		return HPR_ERROR;
	}

	//������ʽ����
	int dwHandleType;
	int i;
	dwHandleType = 0;
	if(ui.checkbo01->isChecked())
	{
		dwHandleType += 1;
	}
	if(ui.checkbo02->isChecked())
	{
		dwHandleType += 2;
	}
	if(ui.checkbo04->isChecked())
	{
		dwHandleType += 4;
	}
	if(ui.checkbo08->isChecked())
	{
		dwHandleType += 8;
		for(i = 0; i < MAX_ALARMOUT_V30; i++)
		{
			if(m_pcheckAlarmOut[i] != NULL)
			{
				if(m_pcheckAlarmOut[i]->isChecked())
				{
					m_pAlarmInInfo->struAlarmHandleType.byRelAlarmOut[i] = 1;
				}
				else
				{
					m_pAlarmInInfo->struAlarmHandleType.byRelAlarmOut[i] = 0;
				}
			}
		}
	}
	if(ui.checkbo10->isChecked())
	{
		dwHandleType += 16;
	}
	m_pAlarmInInfo->struAlarmHandleType.dwHandleType = dwHandleType;

	return HPR_OK;
}

//���ñ���������ʽ
int CAlarmInHandleType::setAlarmTypeWidget()
{
	if(m_pAlarmInInfo == NULL)
	{
		return HPR_ERROR;
	}

	//�������ϱ���
    if((m_pAlarmInInfo->struAlarmHandleType.dwHandleType & 0x01) == 0x01)
    {
    	ui.checkbo01->setChecked(TRUE);
    }
    else
    {
    	ui.checkbo01->setChecked(FALSE);
    }
    //��������
    if((m_pAlarmInInfo->struAlarmHandleType.dwHandleType & 0x02) == 0x02)
    {
    	ui.checkbo02->setChecked(TRUE);
    }
    else
    {
    	ui.checkbo02->setChecked(FALSE);
    }
    //�ϴ�����
    if((m_pAlarmInInfo->struAlarmHandleType.dwHandleType & 0x04) == 0x04)
    {
    	ui.checkbo04->setChecked(TRUE);
    }
    else
    {
    	ui.checkbo04->setChecked(FALSE);
    }
    //�����������
    if((m_pAlarmInInfo->struAlarmHandleType.dwHandleType & 0x08) == 0x08)
    {
    	ui.checkbo08->setChecked(TRUE);
    	ui.tableAlarmOut->setEnabled(TRUE);
    	int i;
    	for(i = 0; i < MAX_ALARMOUT_V30; i++)//�������
    	{
    		if(m_pcheckAlarmOut[i] != NULL)//�������checkbox��Ϊ��
    		{
        	    if(m_pAlarmInInfo->struAlarmHandleType.byRelAlarmOut[i] == 0)
        	    {
        	    	m_pcheckAlarmOut[i]->setChecked(FALSE);
        	    }
        	    else
        	    {
        	    	m_pcheckAlarmOut[i]->setChecked(TRUE);
        	    }
    		}
    	}
    }
    else
    {
    	ui.checkbo08->setChecked(FALSE);
    	ui.tableAlarmOut->setEnabled(FALSE);
    }
    //JPEGץͼ�����ϴ�����
    if((m_pAlarmInInfo->struAlarmHandleType.dwHandleType & 0x10) == 0x10)
    {
    	ui.checkbo10->setChecked(TRUE);
    }
    else
    {
    	ui.checkbo10->setChecked(FALSE);
    }

	return HPR_OK;

}

void CAlarmInHandleType::comboWeekDayChanged(int iWeekDay)
{
	if(m_pAlarmInInfo == NULL)
	{
		return;
	}
    int i;
    int iTemp;
	for(i = 0; i < MAX_TIMESEGMENT_V30; i++)
	{
	   	//ʱ��
	   	iTemp = m_pAlarmInInfo->struAlarmTime[iWeekDay][i].byStartHour;
   	    KIT_intToEdit(&(m_editStartHour[i]), iTemp);
   	    iTemp = m_pAlarmInInfo->struAlarmTime[iWeekDay][i].byStartMin;
	   	KIT_intToEdit(&(m_editStartMin[i]), iTemp);
	   	iTemp = m_pAlarmInInfo->struAlarmTime[iWeekDay][i].byStopHour;
	    KIT_intToEdit(&(m_editEndHour[i]), iTemp);
        iTemp = m_pAlarmInInfo->struAlarmTime[iWeekDay][i].byStopMin;
        KIT_intToEdit(&(m_editEndMin[i]), iTemp);
	 }
}

void CAlarmInHandleType::on_btnSave_clicked()
{
	setAlarmInHandleInfo();
	//quit();
	close();
}


void CAlarmInHandleType::on_checkbo08_clicked()
{
	if(ui.checkbo08->isChecked())
	{
		ui.tableAlarmOut->setEnabled(TRUE);
	}
	else
	{
		ui.tableAlarmOut->setEnabled(FALSE);
	}
}

void CAlarmInHandleType::showEvent(QShowEvent * event)
{
	if(NULL == event)
	{
	}
	getAlarmInHandleInfo();
}







