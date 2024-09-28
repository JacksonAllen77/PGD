#include "cmotion.h"
#include "publicfuc.h"
#include <QMessageBox>
#include <new>

CMotion::CMotion(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);

	m_lUserID = -1;
	//***����table***//
	//���õ�Ԫ�����
	ui.tableMotion->setRowCount(KIT_MOTION_HEIGHT);
	ui.tableMotion->setColumnCount(KIT_MOTION_WIDTH);
	//���õ�Ԫ������
	int i, j;
	for(i = 0; i < KIT_MOTION_HEIGHT; i++)
	{
		for(j = 0; j < KIT_MOTION_WIDTH; j++)
		{
			ui.tableMotion->setCellWidget(i, j, &(m_checkMotionScope[i][j]));
		}
	}
	//���õ�Ԫ���С
	for(j = 0; j < KIT_MOTION_HEIGHT; j++)
	{
		ui.tableMotion->setColumnWidth(j, 30);
	}

	//����ʱ��༭��
	for(i = 0; i < MAX_TIMESEGMENT_V30; i++)
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

	ui.tableChannel->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableAlarmOut->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	m_pstruMotion = NULL;
	m_iAlarmOutNum = 0;
	m_iArryChannel = NULL;
	m_iStartChannelNo = 0;

	//������
	QStringList list;
	list <<"0"<<"1"<<"2"<<"3"<<"4"<<"5"<<"close";
	ui.comboMotionSensitive->addItems(list);

	//����
	list.clear();
	list<<"16*16"<<"32*32"<<"64*64";
	ui.comboPrecision->addItems(list);

	//����
	list.clear();
	list<<"Monday"<<"Tuesday"<<"Wednesday"<<"Thursday"<<"Friday"<<"Saturday"<<"Sunday";
    ui.comboWeekDay->addItems(list);

	connect(ui.comboWeekDay, SIGNAL(activated(int)), this, SLOT(comboWeekDayChanged(int)));
	connect(ui.checkbo08, SIGNAL(clicked()), this, SLOT(checkAlarmOut()));
}

CMotion::~CMotion()
{

}

//���ÿؼ��е�ֵ
int CMotion::setEachWidgetValue()
{
    //��ע��//
    /*
	if(NULL == m_pstruMotion || NULL == m_iArryChannel)
	{
		return HPR_ERROR;
	}
	createChannelCheck(); //ͨ�������и���ʵ��ͨ��������checkbox
	createAlarmOutCheck(); //�ڱ�����������м���checkbox

	//չʾ�����ƶ��������
	int i, j;
	for(i = 0; i < KIT_MOTION_HEIGHT; i++)
	{
		for(j = 0; j < KIT_MOTION_WIDTH; j++)
		{
			if(m_pstruMotion->byMotionScope[i][j] == 0)
			{
				m_checkMotionScope[i][j].setChecked(FALSE);
			}
			else
			{
				m_checkMotionScope[i][j].setChecked(TRUE);
			}
		}
	}

	//�ƶ����������
        if(m_pstruMotion->byMotionSensitive <= 5 //*&& m_pstruMotion->byMotionSensitive >= 0//)
	{
		ui.comboMotionSensitive->setCurrentIndex(m_pstruMotion->byMotionSensitive);
	}
	else
	{
		ui.comboMotionSensitive->setCurrentIndex(6);//�ر�
	}

	//�㷨����
        if(m_pstruMotion->byPrecision <= 2 )
	{
		ui.comboPrecision->setCurrentIndex(m_pstruMotion->byPrecision);
	}

	//����������ʽ
	setMotionAlarmTypeWidget();
	//����ʱ��
	comboWeekDayChanged(0);
	//����������¼��ͨ��
	for(i = 0; i < MAX_CHANNUM_V30; i++)
	{
		if(m_pstruMotion->byRelRecordChan[i] == 1)
		{
			m_checkChannel[i].setChecked(TRUE);
		}
		else
		{
			m_checkChannel[i].setChecked(FALSE);
		}
	}

    */
	return HPR_OK;
}

//��ȡ���������пؼ��е�ֵ
int CMotion::getEachWidgetValue()
{
	if(NULL == m_pstruMotion || NULL == m_iArryChannel)
	{
		return HPR_ERROR;
	}

	//��ȡ�ƶ��������
	int i, j;
	for(i = 0; i < KIT_MOTION_HEIGHT; i++)
	{
		for(j = 0; j < KIT_MOTION_WIDTH; j++)
		{
			if(m_checkMotionScope[i][j].isChecked())
			{
				m_pstruMotion->byMotionScope[i][j] = 1;
			}
			else
			{
				m_pstruMotion->byMotionScope[i][j] = 0;
			}
		}
	}

	//��ȡ������
	if(ui.comboMotionSensitive->currentIndex() <= 5)
	{
		m_pstruMotion->byMotionSensitive = ui.comboMotionSensitive->currentIndex();
	}
	else
	{
		m_pstruMotion->byMotionSensitive = 0xff;
	}

	//����
    //��ע��//
	//m_pstruMotion->byPrecision = ui.comboPrecision->currentIndex();

	//���ñ�����ʽ
	getMotionAlarmTypeWidget();
	//��ȡ����ʱ��
	int iTime;
	int iWeekDay;
	iWeekDay = ui.comboWeekDay->currentIndex();
	for(i = 0; i < MAX_TIMESEGMENT_V30; i++)
	{
	    //��ʼСʱ
		KIT_editToInt(&(m_editStartHour[i]), &iTime);
		m_pstruMotion->struAlarmTime[iWeekDay][i].byStartHour = iTime;
		//��ʼ����
		KIT_editToInt(&(m_editStartMin[i]), &iTime);
		m_pstruMotion->struAlarmTime[iWeekDay][i].byStartMin = iTime;
		//����Сʱ
		KIT_editToInt(&(m_editEndHour[i]), &iTime);
		m_pstruMotion->struAlarmTime[iWeekDay][i].byStopHour = iTime;
		//��������
		KIT_editToInt(&(m_editEndMin[i]), &iTime);
		m_pstruMotion->struAlarmTime[iWeekDay][i].byStopMin = iTime;
	}

	//����������ͨ��
	for(i = 0; i < MAX_CHANNUM_V30; i++)
	{
		if(m_checkChannel[i].isChecked())
		{
			m_pstruMotion->byRelRecordChan[i] = 1;
		}
		else
		{
			m_pstruMotion->byRelRecordChan[i] = 0;
		}
	}

    return HPR_OK;
}

//���ñ���������ʽ
int  CMotion::setMotionAlarmTypeWidget()
{
	if(m_pstruMotion->struMotionHandleType.dwHandleType == 0)//����Ӧ
	{
		return HPR_OK;
	}
	//�������ϱ���
    if((m_pstruMotion->struMotionHandleType.dwHandleType & 0x01) == 0x01)
    {
    	ui.checkbo01->setChecked(TRUE);
    }
    else
    {
    	ui.checkbo01->setChecked(FALSE);
    }
    //��������
    if((m_pstruMotion->struMotionHandleType.dwHandleType & 0x02) == 0x02)
    {
    	ui.checkbo02->setChecked(TRUE);
    }
    else
    {
    	ui.checkbo02->setChecked(FALSE);
    }
    //�ϴ�����
    if((m_pstruMotion->struMotionHandleType.dwHandleType & 0x04) == 0x04)
    {
    	ui.checkbo04->setChecked(TRUE);
    }
    else
    {
    	ui.checkbo04->setChecked(FALSE);
    }
    //�����������
    if((m_pstruMotion->struMotionHandleType.dwHandleType & 0x08) == 0x08)
    {
    	ui.checkbo08->setChecked(TRUE);
    	ui.tableAlarmOut->setEnabled(TRUE);
    	int i;
    	for(i = 0; i < MAX_ALARMOUT_V30; i++)//�������
    	{
    		if(m_pcheckAlarmOut[i] != NULL)//�������checkbox��Ϊ��
    		{
        	    if(m_pstruMotion->struMotionHandleType.byRelAlarmOut[i] == 0)
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
    if((m_pstruMotion->struMotionHandleType.dwHandleType & 0x10) == 0x10)
    {
    	ui.checkbo10->setChecked(TRUE);
    }
    else
    {
    	ui.checkbo10->setChecked(FALSE);
    }

	return HPR_OK;
}

//��ȡ����������ʽ
int CMotion::getMotionAlarmTypeWidget()
{
	if(NULL == m_pstruMotion)
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
					m_pstruMotion->struMotionHandleType.byRelAlarmOut[i] = 1;
				}
				else
				{
					m_pstruMotion->struMotionHandleType.byRelAlarmOut[i] = 0;
				}
			}
		}
	}
	if(ui.checkbo10->isChecked())
	{
		dwHandleType += 16;
	}
	m_pstruMotion->struMotionHandleType.dwHandleType = dwHandleType;

	return HPR_OK;
}

//���ݿ���ID��,��������¼��ͨ����
int CMotion::createChannelCheck()
{
	//�Ȼ�ȡ����ͨ������Ŀ
	int iChannelNum;
	int i;
	for(i = 0; i < MAX_CHANNUM_V30; i++)
	{
		if(m_iArryChannel[i] < 0 )
		{
			break;
		}
	}
	iChannelNum = i;

	//��channnel checkbox ���뵽channel table��ȥ
    ui.tableChannel->setRowCount(iChannelNum);
    ui.tableChannel->setColumnCount(1);
    QStringList list;
    list<<"����ͨ��";
    ui.tableChannel->setHorizontalHeaderLabels(list);
    int iRow = 0; //��ʾ�ڼ���
    char strChannelID[100] = {0};
	for(i = 0; i < MAX_CHANNUM_V30; i++)
	{
		if(m_iArryChannel[i] < 0 )
		{
			break;
		}
		else
		{
            memset(strChannelID, 0, sizeof(strChannelID));
            if(m_iArryChannel[i] < MAX_ANALOG_CHANNUM)
            {
            	sprintf(strChannelID, "Camera%d", m_iArryChannel[i]);
            }
            else
            {
            	sprintf(strChannelID, "IPCamera%d", m_iArryChannel[i]);
            }
            m_checkChannel[m_iArryChannel[i] - m_iStartChannelNo].setText(strChannelID);
			ui.tableChannel->setCellWidget(iRow, 0, &(m_checkChannel[m_iArryChannel[i] - m_iStartChannelNo]));
			iRow++;
		}
	}

	return HPR_OK;
}

int CMotion::setUserID(long lUserID)
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

//���ݱ���������������������;
int CMotion::createAlarmOutCheck()
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
    	//��֧��IP�������
    	memset(&struIPAlarmOut, 0, sizeof(struIPAlarmOut));
		iRet = NET_DVR_GetLastError();
		//QMessageBox::information(this, tr("Please check!"), tr("Get device parameters error! \"%1\"").arg(iRet));
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
int CMotion::getAlarmOutInfo(int iAlarmOut, QCheckBox *pQCheckAlarmOut)
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

//���ñ��������Ա����
int CMotion::setAlarmOutNum(int iAlarmOutNum)
{
	if(iAlarmOutNum < 0 || iAlarmOutNum > 64)
	{
		return HPR_ERROR;
	}
	m_iAlarmOutNum = iAlarmOutNum;
	return HPR_OK;
}

//����ͨ����Ŀ
int CMotion::setChannelID(int *piChannelID)
{
	if(NULL == piChannelID)
	{
		return HPR_ERROR;
	}
	m_iArryChannel = piChannelID;
	return HPR_OK;
}

//�����ƶ���ⱨ������
int CMotion::setStruMotion(NET_DVR_MOTION_V30 *pstruMotion)
{
	if(NULL == pstruMotion)
	{
		return HPR_ERROR;
	}
	m_pstruMotion = pstruMotion;
	return HPR_OK;
}

//������ʼͨ����
int CMotion::setStartChannelNo(int iStartChannelNo)
{
	if(iStartChannelNo < 0 || iStartChannelNo > 64)
	{
		return HPR_ERROR;
	}

	m_iStartChannelNo = iStartChannelNo;
	return HPR_OK;
}

void CMotion::comboWeekDayChanged(int iWeekDay)
{
	if(m_pstruMotion == NULL)
	{
		return;
	}
    int i;
    int iTemp;
	for(i = 0; i < MAX_TIMESEGMENT_V30; i++)
	{
	   	//ʱ��
	   	iTemp = m_pstruMotion->struAlarmTime[iWeekDay][i].byStartHour;
   	    KIT_intToEdit(&(m_editStartHour[i]), iTemp);
   	    iTemp = m_pstruMotion->struAlarmTime[iWeekDay][i].byStartMin;
	   	KIT_intToEdit(&(m_editStartMin[i]), iTemp);
	   	iTemp = m_pstruMotion->struAlarmTime[iWeekDay][i].byStopHour;
	    KIT_intToEdit(&(m_editEndHour[i]), iTemp);
        iTemp = m_pstruMotion->struAlarmTime[iWeekDay][i].byStopMin;
        KIT_intToEdit(&(m_editEndMin[i]), iTemp);
	 }
}

//ѡ�б������
void CMotion::checkAlarmOut()
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

void CMotion::on_btnSave_clicked()
{
	getEachWidgetValue();
}

//event
void CMotion::showEvent ( QShowEvent * event )
{
	if(event ==NULL)
	{
	}

	//��ȡ��ʾ����
	setEachWidgetValue();
}
