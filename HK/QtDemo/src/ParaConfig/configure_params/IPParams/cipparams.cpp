#include "cipparams.h"
#include "publicfuc.h"
#include <QMessageBox>

CIPParams::CIPParams(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);
	m_lUserID = -1;
	m_iIPParamIndex = -1;
	m_iCurrentRow = -1;

    ui.hLayout->addWidget(ui.widgetCamora);
    ui.widgetCamora->hide();
    ui.btnSave->hide();

    //click table
    connect(ui.tableChannelInfo, SIGNAL(cellClicked(int,int)), this, SLOT(clickTabChannel(int)));
}

CIPParams::~CIPParams()
{

}

int CIPParams::setUserID(long lUserID)
{
	if(lUserID < 0)
	{
		return HPR_ERROR;
	}
	m_lUserID = lUserID;
	return HPR_OK;
}

//��ȡͨ����Ϣ��д�������
int CIPParams::getIPInfo()
{
	if(m_lUserID < 0)
	{
        return HPR_ERROR;
	}

	//��ȡ�豸��IP������Ϣ
	NET_DVR_IPPARACFG struIPParams;
	memset(&struIPParams, 0 , sizeof(NET_DVR_IPPARACFG));
	if(getIPConInfo(&struIPParams) < 0)
	{
		return HPR_ERROR;
	}

    //����������
    int iRow;
    ui.tableChannelInfo->clear();
    for(iRow = 0; iRow < ui.tableChannelInfo->rowCount(); iRow++)
    {
    	ui.tableChannelInfo->removeRow(iRow);
    }

    //��ȡ�������ͨ����ģ��ͨ����
    NET_DVR_DEVICECFG struDeviceInfo;
    memset(&struDeviceInfo, 0 , sizeof(NET_DVR_DEVICECFG));
    if(getDeviceInfo(&struDeviceInfo) < 0)
    {
    	return HPR_ERROR;
    }

    //����������������ͷ
    ui.tableChannelInfo->setRowCount(struDeviceInfo.byChanNum + struDeviceInfo.byIPChanNum);
    ui.tableChannelInfo->setColumnCount(5);

    //����ͷ��
    QStringList list;
    list<<"Channel No."<<"IP address"<<"Port"<<"IP channel No."<<"Whether online";
    ui.tableChannelInfo->setHorizontalHeaderLabels(list);

    //���óߴ�����Ӧ
    ui.tableChannelInfo->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui.tableChannelInfo->setSelectionBehavior(QAbstractItemView::SelectRows);   //��������ѡ��
    //ui.tableChannelInfo->setSelectionMode(QAbstractItemView::SingleSelection);  //���õ���ѡ��

    //��������
    int i;
    int dwIPChanIndex;
    int dwID;
    iRow = 0;
    char strChannelName[100] = {0};
    for(i = 0; i < MAX_CHANNUM_V30; i++)
    {
    	//ģ��ͨ��
    	if(i < struDeviceInfo.byChanNum )
    	{
    		memset(strChannelName, 0, 100);
    		sprintf(strChannelName,"Camora%d", i + struDeviceInfo.byStartChan);
    		ui.tableChannelInfo->setItem(iRow, 0, new QTableWidgetItem(strChannelName));
    		ui.tableChannelInfo->setItem(iRow, 1, new QTableWidgetItem("Local"));
    		ui.tableChannelInfo->setItem(iRow, 2, new QTableWidgetItem("0"));
    		ui.tableChannelInfo->setItem(iRow, 3, new QTableWidgetItem("0"));
    		if(struIPParams.byAnalogChanEnable[i])
    		{
    		    ui.tableChannelInfo->setItem(iRow, 4, new QTableWidgetItem("Yes"));
    		}
    		else
    		{
    			ui.tableChannelInfo->setItem(iRow, 4, new QTableWidgetItem("No"));
    		}
    		iRow++;
    	}
    	//����ͨ��
    	if((i >= MAX_ANALOG_CHANNUM) && (i < MAX_ANALOG_CHANNUM + struDeviceInfo.byIPChanNum))
    	{
    		dwIPChanIndex = i  - MAX_ANALOG_CHANNUM;
    		memset(strChannelName, 0, 100);
    		sprintf(strChannelName,"IPCamora%d", dwIPChanIndex + struDeviceInfo.byStartChan);
    		ui.tableChannelInfo->setItem(iRow, 0, new QTableWidgetItem(strChannelName));
    		dwID = struIPParams.struIPChanInfo[dwIPChanIndex].byIPID;
            if(struIPParams.struIPChanInfo[dwIPChanIndex].byIPID != 0)
            {
            	//IP
            	ui.tableChannelInfo->setItem(iRow, 1, new QTableWidgetItem(struIPParams.struIPDevInfo[dwID-1].struIP.sIpV4));
                //�˿�
            	memset(strChannelName, 0, 100);
            	sprintf(strChannelName, "%d", struIPParams.struIPDevInfo[dwID-1].wDVRPort);
            	ui.tableChannelInfo->setItem(iRow, 2, new QTableWidgetItem(strChannelName));
            	//IPͨ����
            	memset(strChannelName, 0, 100);
            	sprintf(strChannelName, "%d", struIPParams.struIPChanInfo[dwIPChanIndex].byChannel);
            	ui.tableChannelInfo->setItem(iRow, 3, new QTableWidgetItem(strChannelName));
            	//�Ƿ�����
            	if (struIPParams.struIPChanInfo[dwIPChanIndex].byEnable)
            	{
            		ui.tableChannelInfo->setItem(iRow, 4, new QTableWidgetItem("online"));
            	}
            	else
            	{
            		ui.tableChannelInfo->setItem(iRow, 4, new QTableWidgetItem("offline"));
            	}
            }
            else
            {
            	ui.tableChannelInfo->setItem(iRow, 1, new QTableWidgetItem("0.0.0.0"));
            	ui.tableChannelInfo->setItem(iRow, 2, new QTableWidgetItem("0"));
            	ui.tableChannelInfo->setItem(iRow, 3, new QTableWidgetItem("0"));
            	ui.tableChannelInfo->setItem(iRow, 4, new QTableWidgetItem("no"));
            }
    		iRow++;
    	}
    }

    //table�����Ա��༭
    ui.tableChannelInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
    return HPR_OK;
}
//�ӱ����еõ����ݣ�д���豸
int CIPParams::saveIPInfo()
{

	return HPR_OK;
}

//������������¼�
int CIPParams::clickTabChannel(int iRow)
{
	m_iIPParamIndex = -1;

	//ͨ�����е�camoraXX��Ϣ����ȡȥID��Ϣ
	int iChannelIndex = 0;
	if(getIPChannnelIndex(iRow, &iChannelIndex) < 0)
	{
		return HPR_ERROR;
	}

	//�����޸Ŀؼ��е�ֵ
	NET_DVR_IPPARACFG struIPParams;
	memset(&struIPParams, 0 , sizeof(NET_DVR_IPPARACFG));
	//��ȡ�豸�е�IP������Ϣ
	if(getIPConInfo(&struIPParams) < 0)
	{
		return HPR_ERROR;
	}

	m_iIPParamIndex = iChannelIndex; //��¼�µ�ǰ��ͨ�����
	if(iChannelIndex < MAX_ANALOG_CHANNUM)//ģ��ͨ��
	{
		ui.widgetIPCamora->hide();
		ui.widgetCamora->show();
		if(struIPParams.byAnalogChanEnable[iChannelIndex])
		{
			ui.btnEnable->setEnabled(FALSE);
			ui.btnDisenable->setEnabled(TRUE);
		}
		else
		{
			ui.btnEnable->setEnabled(TRUE);
			ui.btnDisenable->setEnabled(FALSE);
		}
	}
	else//����ͨ��
	{
		int iIPChannelIndex;
		iIPChannelIndex = iChannelIndex - MAX_ANALOG_CHANNUM;
		ui.widgetIPCamora->show();
		ui.widgetCamora->hide();
		if(struIPParams.struIPChanInfo[iIPChannelIndex].byIPID > 0)//�ж�Ӧ��IP�豸ID
		{
			int iIPID;
			iIPID = struIPParams.struIPChanInfo[iIPChannelIndex].byIPID -1;
			ui.btnEdit->setText("�޸�");
			ui.btnDelete->setEnabled(TRUE);
			//���ÿؼ���ֵ
			ui.editIP->setText(struIPParams.struIPDevInfo[iIPID].struIP.sIpV4);
                        ui.editUsername->setText((char *)struIPParams.struIPDevInfo[iIPID].sUserName);
                        ui.editPassword->setText((char *)struIPParams.struIPDevInfo[iIPID].sPassword);
			unsigned int uiPort;
			uiPort = struIPParams.struIPDevInfo[iIPID].wDVRPort;
			KIT_unintToEdit(ui.editPort, uiPort);
			unsigned int uiChannelNO;
			uiChannelNO = struIPParams.struIPChanInfo[iIPChannelIndex].byChannel;
			KIT_unintToEdit(ui.editChannelNO, uiChannelNO);
		}
		else//û�ж�Ӧ��IP�豸ID
		{
			ui.btnEdit->setText("����");
			ui.btnDelete->setEnabled(FALSE);
		}
	}

    m_iCurrentRow = iRow;
	//QMessageBox::information(this, "Please check!", tr("The error is \"%1\"").arg(iChannelIndex));
	return HPR_OK;
}

//����IPC�����"�༭"��ť
void CIPParams::on_btnEdit_clicked()
{
	//��ȡ��ǰ������Ϣ
	if(m_iIPParamIndex  >= MAX_ANALOG_CHANNUM)
	{
		int iIPChannelIndex;
		int iTemp;
		NET_DVR_IPPARACFG struIPParams; //= {0};
		memset(&struIPParams, 0, sizeof(NET_DVR_IPPARACFG));
		//��ȡ�豸�е�IP������Ϣ
		if(getIPConInfo(&struIPParams) < 0)
		{
			return;
		}

		iIPChannelIndex = m_iIPParamIndex - MAX_ANALOG_CHANNUM;
		int iIPID = 0;
		if(struIPParams.struIPChanInfo[iIPChannelIndex].byIPID <= 0)//�������豸
		{
			//��һ������IP�豸ID��
			int i;
			for(i = 0; i< MAX_IP_DEVICE; i++)
			{
				if (!struIPParams.struIPDevInfo[i].dwEnable)
				{
					iIPID = i+1;//find the first empty node
					break;
				}
			}

			//�޸�IPͨ����Ϣ
			KIT_editToInt(ui.editChannelNO, &iTemp);
			struIPParams.struIPChanInfo[iIPChannelIndex].byChannel = (BYTE)iTemp;
			struIPParams.struIPChanInfo[iIPChannelIndex].byIPID = (BYTE)iIPID;

			//�޸�iIPID��Ӧ���豸
                        KIT_editToIP(ui.editIP, (BYTE *)(struIPParams.struIPDevInfo[iIPID-1].struIP.sIpV4), IP_LEN);
			struIPParams.struIPDevInfo[iIPID-1].dwEnable = TRUE;
			KIT_editToInt(ui.editPort, &iTemp);
			struIPParams.struIPDevInfo[iIPID-1].wDVRPort = iTemp;//port
			KIT_editToStr(ui.editUsername, struIPParams.struIPDevInfo[iIPID-1].sUserName, NAME_LEN);
			KIT_editToStr(ui.editPassword, struIPParams.struIPDevInfo[iIPID-1].sPassword, PASSWD_LEN);
		}
		else //�޸�IPͨ����Ϣ
		{
			iIPID =  struIPParams.struIPChanInfo[iIPChannelIndex].byIPID;
			KIT_editToInt(ui.editChannelNO, &iTemp);
			struIPParams.struIPChanInfo[iIPChannelIndex].byChannel = (BYTE)iTemp;

			//�޸�iIPID��Ӧ���豸
                        KIT_editToIP(ui.editIP, (BYTE *)(struIPParams.struIPDevInfo[iIPID-1].struIP.sIpV4), IP_LEN);
			KIT_editToInt(ui.editPort, &iTemp);
			struIPParams.struIPDevInfo[iIPID-1].wDVRPort = iTemp;//port
			KIT_editToStr(ui.editUsername, struIPParams.struIPDevInfo[iIPID-1].sUserName, NAME_LEN);
			KIT_editToStr(ui.editPassword, struIPParams.struIPDevInfo[iIPID-1].sPassword, PASSWD_LEN);
		}

		//���豸���Ͳ���������Ϣ, ���浽�豸
		int iRet = NET_DVR_SetDVRConfig(m_lUserID, NET_DVR_SET_IPPARACFG, -1, &struIPParams, sizeof(NET_DVR_IPPARACFG));
	    if(0 == iRet)
	    {
		    iRet = NET_DVR_GetLastError();
		    QMessageBox::information(this, tr("Please check!"), tr("Set User parameters error! \"%1\"").arg(iRet));
		    return ;
	    }
	}//IPͨ�������޸Ļ����ӽ���

	if(m_iIPParamIndex < 0)
	{
		QMessageBox::information(this, tr("Please check!"), tr("Please choose a row of table!"));
	}

	getIPInfo(); //ˢ��Table
	if(m_iCurrentRow >= 0)
	{
		ui.tableChannelInfo->setCurrentCell(m_iCurrentRow, 0);
		clickTabChannel(m_iCurrentRow);
	}
}

//ɾ��IPͨ��������Ϣ
void CIPParams::on_btnDelete_clicked()
{
	//��ȡ��ǰTable�е���һ�б�ѡ�У�m_iIPParamIndex��ʾ��ѡ����һ�е�ͨ�����(start no.�����ͨ����)
	if(m_iIPParamIndex  >= MAX_ANALOG_CHANNUM)
	{
		int iIPChannelIndex;
		NET_DVR_IPPARACFG struIPParams; //= {0};
		memset(&struIPParams, 0, sizeof(NET_DVR_IPPARACFG));
		//��ȡ�豸�е�IP������Ϣ
		if(getIPConInfo(&struIPParams) < 0)
		{
			return;
		}
		iIPChannelIndex = m_iIPParamIndex - MAX_ANALOG_CHANNUM;//IP�����������

		int iIPID = 0;
		//��ȡIP�豸�������
		iIPID = struIPParams.struIPChanInfo[iIPChannelIndex].byIPID;
		if (iIPID <= 0) //��ЧIP�豸��ţ�ɾ��ʧ�ܣ�ֱ�ӷ���
		{
			QMessageBox::information(this, tr("Please check!"), tr("Please ip device ID is error!"));
			return;
		}

		//�ж�һ���Ƿ���IPͨ�������ø��豸
		int i;
		bool bDeleteDev = TRUE;
		for (i = 0; i < MAX_IP_CHANNEL; i++)
		{
			if (iIPChannelIndex != i)
			{
				if (iIPID == struIPParams.struIPChanInfo[i].byIPID)
				{
					//����IPͨ��ʹ�ø��豸,
					//QMessageBox::information(this, tr("Please check!"), tr("Some IP channel has used this Device!"));
					bDeleteDev = FALSE;
					break;
				}
			}
		}

		//���ip�豸����Ϣ/clear current ip device
		if (bDeleteDev)
		{
			memset(&(struIPParams.struIPDevInfo[iIPID-1]), 0, sizeof(NET_DVR_IPDEVINFO));
		}

		//��յ�ǰipͨ������Ϣ/clear current ip chan
		memset(&(struIPParams.struIPChanInfo[iIPChannelIndex]), 0, sizeof(NET_DVR_IPCHANINFO));
		//���豸���Ͳ���������Ϣ, ���浽�豸
		int iRet = NET_DVR_SetDVRConfig(m_lUserID, NET_DVR_SET_IPPARACFG, -1, &struIPParams, sizeof(NET_DVR_IPPARACFG));
	    if(0 == iRet)
	    {
		    iRet = NET_DVR_GetLastError();
		    QMessageBox::information(this, tr("Please check!"), tr("Set User parameters error! \"%1\"").arg(iRet));
		    return ;
	    }
	}
	if(m_iIPParamIndex < 0)
	{
		QMessageBox::information(this, tr("Please check!"), tr("Please choose a row of table!"));
	}

	getIPInfo(); //ˢ��Table
	if(m_iCurrentRow >= 0)
	{
		ui.tableChannelInfo->setCurrentCell(m_iCurrentRow, 0);
		clickTabChannel(m_iCurrentRow);
	}
}

//����ģ��ͨ��
void CIPParams::on_btnEnable_clicked()
{
	if(m_iIPParamIndex < 0)
	{
		QMessageBox::information(this, tr("Please check!"), tr("Please choose a row of table!"));
		return;
	}

	if(m_iIPParamIndex < MAX_ANALOG_CHANNUM)//ģ��ͨ��
	{
		NET_DVR_IPPARACFG struIPParams; //= {0};
		memset(&struIPParams, 0, sizeof(NET_DVR_IPPARACFG));
		//��ȡ�豸�е�IP������Ϣ
		if(getIPConInfo(&struIPParams) < 0)
		{
			return;
		}

		struIPParams.byAnalogChanEnable[m_iIPParamIndex] = TRUE;//ģ��ͨ�������������
		//���豸���Ͳ���������Ϣ, ���浽�豸
		int iRet = NET_DVR_SetDVRConfig(m_lUserID, NET_DVR_SET_IPPARACFG, -1, &struIPParams, sizeof(NET_DVR_IPPARACFG));
	    if(!iRet)
	    {
		    iRet = NET_DVR_GetLastError();
		    QMessageBox::information(this, tr("Please check!"), tr("Set User parameters error! \"%1\"").arg(iRet));
		    return ;
	    }

    	ui.btnEnable->setEnabled(FALSE);
    	ui.btnDisenable->setEnabled(TRUE);
	    if(getIPInfo() == HPR_OK) //ˢ��Table
	    {
	    }
	}
}

//����ģ��ͨ��
void CIPParams::on_btnDisenable_clicked()
{
	if(m_iIPParamIndex < 0)
	{
		QMessageBox::information(this, tr("Please check!"), tr("Please choose a row of table!"));
		return;
	}

	if(m_iIPParamIndex < MAX_ANALOG_CHANNUM)//ģ��ͨ��
	{
		NET_DVR_IPPARACFG struIPParams; //= {0};
		memset(&struIPParams, 0, sizeof(NET_DVR_IPPARACFG));
		//��ȡ�豸�е�IP������Ϣ
		if(getIPConInfo(&struIPParams) < 0)
		{
			return;
		}

		struIPParams.byAnalogChanEnable[m_iIPParamIndex] = FALSE;//ģ��ͨ�������������
		//���豸���Ͳ���������Ϣ, ���浽�豸
		int iRet = NET_DVR_SetDVRConfig(m_lUserID, NET_DVR_SET_IPPARACFG, -1, &struIPParams, sizeof(NET_DVR_IPPARACFG));
	    if(!iRet)
	    {
		    iRet = NET_DVR_GetLastError();
		    QMessageBox::information(this, tr("Please check!"), tr("Set User parameters error! \"%1\"").arg(iRet));
		    return ;
	    }

		ui.btnEnable->setEnabled(TRUE);
	    ui.btnDisenable->setEnabled(FALSE);
	    getIPInfo(); //ˢ��Table
	}
}

//��ȡ�豸��Ϣ: ��ʼͨ���ţ�������table����ʾ��
int CIPParams::getDeviceInfo(LPNET_DVR_DEVICECFG pDeviceInfo)
{
	if(m_lUserID < 0 && pDeviceInfo ==NULL)
	{
		return HPR_ERROR;
	}

	int iRet;
	DWORD uiReturnLen;
	iRet = NET_DVR_GetDVRConfig(m_lUserID, NET_DVR_GET_DEVICECFG, 0, pDeviceInfo, sizeof(NET_DVR_DEVICECFG), &uiReturnLen);
    if(0 == iRet)
    {
    	iRet = NET_DVR_GetLastError();
        QMessageBox::information(this, "Please check!", tr("The error is \"%1\"").arg(iRet));
        return HPR_ERROR;
    }

	return HPR_OK;
}

//��ȡIP������Ϣ
int CIPParams::getIPConInfo(LPNET_DVR_IPPARACFG pIPConInfo)
{
	if(m_lUserID < 0 && pIPConInfo ==NULL)
	{
		return HPR_ERROR;
	}

	int iRet;
	DWORD uiReturnLen;
	iRet = NET_DVR_GetDVRConfig(m_lUserID, NET_DVR_GET_IPPARACFG, 0, pIPConInfo, sizeof(NET_DVR_IPPARACFG), &uiReturnLen);
    if(0 == iRet)
    {
    	iRet = NET_DVR_GetLastError();
        QMessageBox::information(this, "Please check!", tr("The error is \"%1\"").arg(iRet));
        return HPR_ERROR;
    }

    return HPR_OK;
}

//�����кţ���ȡͨ�����
int CIPParams::getIPChannnelIndex(int iRow, int *piChannelIndex)
{
	if(NULL == piChannelIndex)
	{
		return HPR_ERROR;
	}

	//�Ȼ�ȡ�����е�Ԫ��
	QTableWidgetItem *pChannelName = NULL;
	pChannelName = ui.tableChannelInfo->item(iRow, 0);

	//ȡ��Ԫ���е�text
	if(NULL ==pChannelName)
	{
		return HPR_ERROR;
	}
	char strChannelName[20] = {0};
	QString qstrChannelName;
	qstrChannelName = pChannelName->text();
        KIT_qstringToStr(&qstrChannelName, (BYTE *)strChannelName, 20);

	//��ȡ�豸��Ϣ
	NET_DVR_DEVICECFG struDeviceInfo;
	memset(&struDeviceInfo, 0, sizeof(NET_DVR_DEVICECFG));
	if(getDeviceInfo(&struDeviceInfo) < 0)
	{
		return HPR_ERROR;
	}

	//����
	int iIndex = 0;
	if('C' == strChannelName[0])//ģ��ͨ������
	{
		iIndex = atoi(&(strChannelName[6]));
	}
	if('I' == strChannelName[0])//IPͨ��
	{
		iIndex =  atoi(&(strChannelName[8]));
		iIndex += MAX_ANALOG_CHANNUM;
	}

	iIndex -= struDeviceInfo.byStartChan;
	*piChannelIndex = iIndex;

	return HPR_OK;
}

void CIPParams::showEvent ( QShowEvent * event )
{
	if(event == NULL)
	{
	}
	getIPInfo();
}
