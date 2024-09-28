#include "chidealarm.h"
#include "publicfuc.h"
#include <QMessageBox>

CHideAlarm::CHideAlarm(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);

	m_lUserID = -1;
	m_pstruHideAlarm = NULL;
	m_iAlarmOutNum = 0;

	ui.tableAlarmOut->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui.tableAlarmOut->setColumnCount(1);
    ui.tableAlarmOut->setEnabled(FALSE);

	int i;
	for(i=0; i < MAX_TIMESEGMENT_V30; i++)
	{
		ui.vLayStartHour->addWidget(&(m_editStartHour[i]));
		ui.vLayStartMin->addWidget(&(m_editStartMin[i]));
		ui.vLayEndHour->addWidget(&(m_editEndHour[i]));
		ui.vLayEndMin->addWidget(&(m_editEndMin[i]));
	}

	for(i = 0; i < MAX_ALARMOUT_V30; i++)
	{
		m_pcheckAlarmOut[i] = NULL;
	}

	QStringList strings;
	strings<<"Monday"<<"Tuesday"<<"Wednesday"<<"Thursday"<<"Friday"<<"Saturday"<<"Sunday";
	ui.comboWeekDay->addItems(strings);

	connect(ui.comboWeekDay, SIGNAL(activated(int)), this, SLOT(comboWeekDayChanged(int)));
    connect(ui.checkbo08, SIGNAL(clicked()), this, SLOT(checkAlarmOut()));
}

CHideAlarm::~CHideAlarm()
{

}

//��������Ի���ǰ��Ҫ���õ���������
int CHideAlarm::setStruHideAlarm(NET_DVR_HIDEALARM_V30 *pstruHideAlarm)
{
	if(NULL == pstruHideAlarm)
	{
		return HPR_ERROR;
	}

	m_pstruHideAlarm = pstruHideAlarm;
	return HPR_OK;
}

//��������Ի���ǰ��Ҫ���õ���������
int CHideAlarm::setAlarmOutNum(int iAlarmOutNum)
{
	if(iAlarmOutNum < 0)
	{
		return HPR_ERROR;
	}
	else
	{
		m_iAlarmOutNum = iAlarmOutNum;
	}

	return HPR_OK;
}

//
int CHideAlarm::setUserID(long lUserID)
{
	if(lUserID < 0)
	{
		return HPR_ERROR;
	}
	else
	{
		m_lUserID = lUserID;
	}

	return HPR_OK;
}

//����ÿ���ؼ���ֵ
int CHideAlarm::setEachWidgetValue()
{
	if(m_pstruHideAlarm == NULL)
	{
		return HPR_ERROR;
	}

	createAlarmOutCheck();//�����������


    //����ʱ��
    comboWeekDayChanged(0);

	//�ڵ�����
	unsigned int uiTemp;
	uiTemp = m_pstruHideAlarm->wHideAlarmAreaTopLeftX;
	KIT_intToEdit(ui.editHideAlarmAreaTopLeftX, uiTemp);
	uiTemp = m_pstruHideAlarm->wHideAlarmAreaTopLeftY;
	KIT_intToEdit(ui.editHideAlarmAreaTopLeftY, uiTemp);
	uiTemp = m_pstruHideAlarm->wHideAlarmAreaWidth;
	KIT_intToEdit(ui.editHideAlarmAreaWidth, uiTemp);
	uiTemp = m_pstruHideAlarm->wHideAlarmAreaHeight;
	KIT_intToEdit(ui.editHideAlarmAreaHeight, uiTemp);

	if(m_pstruHideAlarm->strHideAlarmHandleType.dwHandleType == 0)//����Ӧ
	{
		return HPR_OK;
	}
	//�������ϱ���
    if((m_pstruHideAlarm->strHideAlarmHandleType.dwHandleType & 0x01) == 0x01)
    {
    	ui.checkbo01->setChecked(TRUE);
    }
    else
    {
    	ui.checkbo01->setChecked(FALSE);
    }
    //��������
    if((m_pstruHideAlarm->strHideAlarmHandleType.dwHandleType & 0x02) == 0x02)
    {
    	ui.checkbo02->setChecked(TRUE);
    }
    else
    {
    	ui.checkbo02->setChecked(FALSE);
    }
    //�ϴ�����
    if((m_pstruHideAlarm->strHideAlarmHandleType.dwHandleType & 0x04) == 0x04)
    {
    	ui.checkbo04->setChecked(TRUE);
    }
    else
    {
    	ui.checkbo04->setChecked(FALSE);
    }
    //�����������
    if((m_pstruHideAlarm->strHideAlarmHandleType.dwHandleType & 0x08) == 0x08)
    {
    	ui.checkbo08->setChecked(TRUE);
    	ui.tableAlarmOut->setEnabled(TRUE);
    	int i;
    	for(i = 0; i < MAX_ALARMOUT_V30; i++)//�������
    	{
    		if(m_pcheckAlarmOut[i] != NULL)
    		{
        	    if(m_pstruHideAlarm->strHideAlarmHandleType.byRelAlarmOut[i] == 0)
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
    if((m_pstruHideAlarm->strHideAlarmHandleType.dwHandleType & 0x10) == 0x10)
    {
    	ui.checkbo10->setChecked(TRUE);
    }
    else
    {
    	ui.checkbo10->setChecked(FALSE);
    }


	return HPR_OK;
}
   //��ȡÿ���ؼ���ֵ
int CHideAlarm::getEachWidgetValue()
{
	if(m_pstruHideAlarm == NULL)
	{
		return HPR_ERROR;
	}

	//�����ڵ�����
	int iTemp;
	KIT_editToInt(ui.editHideAlarmAreaTopLeftX, &iTemp);
	m_pstruHideAlarm->wHideAlarmAreaTopLeftX = (unsigned short)iTemp;
	KIT_editToInt(ui.editHideAlarmAreaTopLeftY, &iTemp);
	m_pstruHideAlarm->wHideAlarmAreaTopLeftY = (unsigned short)iTemp;
	KIT_editToInt(ui.editHideAlarmAreaWidth, &iTemp);
	m_pstruHideAlarm->wHideAlarmAreaWidth = (unsigned short)iTemp;
	KIT_editToInt(ui.editHideAlarmAreaHeight, &iTemp);
	m_pstruHideAlarm->wHideAlarmAreaHeight = (unsigned short)iTemp;

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
			if(m_pcheckAlarmOut[i] == NULL)
			{
				continue;
			}
			if(m_pcheckAlarmOut[i]->isChecked())
			{
				m_pstruHideAlarm->strHideAlarmHandleType.byRelAlarmOut[i] = 1;
			}
			else
			{
				m_pstruHideAlarm->strHideAlarmHandleType.byRelAlarmOut[i] = 0;
			}
		}
	}
	if(ui.checkbo10->isChecked())
	{
		dwHandleType += 16;
	}
	m_pstruHideAlarm->strHideAlarmHandleType.dwHandleType = dwHandleType;

	//ʱ��ֵ
	int iTime;
	int iWeekDay;
	iWeekDay = ui.comboWeekDay->currentIndex();
	for(i = 0; i < MAX_TIMESEGMENT_V30; i++)
	{
	    //��ʼСʱ
		KIT_editToInt(&(m_editStartHour[i]), &iTime);
		m_pstruHideAlarm->struAlarmTime[iWeekDay][i].byStartHour = iTime;
		//��ʼ����
		KIT_editToInt(&(m_editStartMin[i]), &iTime);
		m_pstruHideAlarm->struAlarmTime[iWeekDay][i].byStartMin = iTime;
		//����Сʱ
		KIT_editToInt(&(m_editEndHour[i]), &iTime);
		m_pstruHideAlarm->struAlarmTime[iWeekDay][i].byStopHour = iTime;
		//��������
		KIT_editToInt(&(m_editEndMin[i]), &iTime);
		m_pstruHideAlarm->struAlarmTime[iWeekDay][i].byStopMin = iTime;
	}

	return HPR_OK;
}

int CHideAlarm::createAlarmOutCheck()
{
	if(m_lUserID < 0)
	{
		return HPR_ERROR;
	}

	int iRet;
	DWORD uiReturnLen;
	NET_DVR_IPALARMOUTCFG  struIPAlarmOut;
	iRet = NET_DVR_GetDVRConfig(m_lUserID, NET_DVR_GET_IPALARMOUTCFG, -1, &struIPAlarmOut, sizeof(NET_DVR_IPALARMOUTCFG), &uiReturnLen);
    if(iRet == 0)
    {
    	memset(&struIPAlarmOut, 0, sizeof(struIPAlarmOut));
		iRet = NET_DVR_GetLastError();
		//QMessageBox::information(this, tr("Please check!"), tr("Get device parameters error! \"%1\"").arg(iRet));
		//return HPR_ERROR;
    }

	//��ȡIP��������ĸ����������ñ��������
	int i;
	int iRow = 0;
	for(i = 0; i < MAX_IP_ALARMOUT; i++ )
	{
		if(struIPAlarmOut.struIPAlarmOutInfo[i].byIPID > 0)
		{
			iRow++;
		}
	}
	iRow += m_iAlarmOutNum;
    ui.tableAlarmOut->setRowCount(iRow);
    ui.tableAlarmOut->setColumnCount(1);
    QStringList list;
    list<<"�������";
    ui.tableAlarmOut->setHorizontalHeaderLabels(list);

    //�����ǰ����������
    ui.tableAlarmOut->clear();
	for(i = 0; i < MAX_ALARMOUT_V30; i++)
	{
		m_pcheckAlarmOut[i] = NULL;
	}


    //�������м���ģ�ⱨ�����
	for(i = 0; i < m_iAlarmOutNum; i++)
	{
		//new һ���µ�checkbox
		m_pcheckAlarmOut[i] = new(std::nothrow) QCheckBox;
		//��ȡ���������
		getAlarmOutInfo(i, m_pcheckAlarmOut[i]);
		//���뵽table��ȥ
		ui.tableAlarmOut->setCellWidget(i, 0, (m_pcheckAlarmOut[i]));
	}

	//IP�������
	for(i = 0; i < MAX_IP_ALARMOUT; i++)
	{
		//�ж�IP��������Ƿ����
		if(struIPAlarmOut.struIPAlarmOutInfo[i].byIPID > 0)
		{
			//new����һ���µ�checkbox
			m_pcheckAlarmOut[i + MAX_ANALOG_ALARMOUT] = new(std::nothrow) QCheckBox;
		    //��ȡ�����������
			getAlarmOutInfo(i + MAX_ANALOG_ALARMOUT, m_pcheckAlarmOut[i + MAX_ANALOG_ALARMOUT]);
		    //���뵽table��ȥ
			ui.tableAlarmOut->setCellWidget(i + m_iAlarmOutNum, 0, (m_pcheckAlarmOut[i + MAX_ANALOG_ALARMOUT]));
		}
	}

	return HPR_OK;
}

//���ݱ��������ţ���ȡ�����������
int CHideAlarm::getAlarmOutInfo(int iAlarmOut, QCheckBox *pQCheckAlarmOut)
{
	char strTemp[100] = {0};
	if(iAlarmOut < MAX_ANALOG_ALARMOUT)
	{
		sprintf(strTemp, "AlarmOut%d", iAlarmOut + 1);
	}
	else
	{
		sprintf(strTemp, "IPAlarmOut%d", iAlarmOut - MAX_ANALOG_ALARMOUT + 1);
	}
    pQCheckAlarmOut->setText(strTemp);

	return HPR_OK;
}

void CHideAlarm::on_btnSave_clicked()
{
	getEachWidgetValue();
}

//ѡ�б������
void CHideAlarm::checkAlarmOut()
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

void CHideAlarm::comboWeekDayChanged(int iWeekDay)
{
	if(m_pstruHideAlarm == NULL)
	{
		return;
	}
    int i;
    int iTemp;
	for(i = 0; i < MAX_TIMESEGMENT_V30; i++)
	{
	   	//ʱ��
	   	iTemp = m_pstruHideAlarm->struAlarmTime[iWeekDay][i].byStartHour;
   	    KIT_intToEdit(&(m_editStartHour[i]), iTemp);
   	    iTemp = m_pstruHideAlarm->struAlarmTime[iWeekDay][i].byStartMin;
	   	KIT_intToEdit(&(m_editStartMin[i]), iTemp);
	   	iTemp = m_pstruHideAlarm->struAlarmTime[iWeekDay][i].byStopHour;
	    KIT_intToEdit(&(m_editEndHour[i]), iTemp);
        iTemp = m_pstruHideAlarm->struAlarmTime[iWeekDay][i].byStopMin;
        KIT_intToEdit(&(m_editEndMin[i]), iTemp);
	 }
}

//event
void CHideAlarm::showEvent ( QShowEvent * event )
{
	if(event ==NULL)
	{
	}
	//��ȡ��ʾ����
	setEachWidgetValue();
}

