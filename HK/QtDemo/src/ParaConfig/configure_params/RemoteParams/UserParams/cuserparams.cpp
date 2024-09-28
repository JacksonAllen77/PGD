#include "cuserparams.h"
#include "publicfuc.h"

#include <QMessageBox>

CUserParams::CUserParams(QWidget *parent)
    : QDialog(parent)
{
	ui.setupUi(this);

	m_lUserID = -1;
	m_iStartChan = 0;
	m_iSimChannelNum = 0;

	int i;
	for (i = 0; i < MAX_CHANNUM_V30; i++)
	{
		m_iArryChannel[i] = -1;
		m_pcheckLocalChannel[i] = NULL;
		m_pcheckRemoteChannel[i] = NULL;
	}

	for (i = 0; i < MAX_RIGHT; i++)
	{
		m_pcheckLocalRight[i] = NULL;
		m_pcheckRemoteRight[i] = NULL;
	}
	ui.checkRemoteRight11->hide();

	QStringList strings;
	strings<<"Local playback"<<"Local record"<<"PTZ local control"<<"Local backup";
	ui.comboLocalRight->addItems(strings);

	strings.clear();
	strings<<"Remote preview"<<"Remote playback"<<"Remote record"<<"PTZ remote control";
	ui.comboNetRight->addItems(strings);

	//�û�
	strings.clear();
	strings<<"Administrator";
	strings<<"User1"<<"User2"<<"User3"<<"User4"<<"User5"<<"User6"<<"User7";
	strings<<"User8"<<"User9"<<"User10"<<"User11"<<"User12"<<"User13"<<"User14";
	strings<<"User15"<<"User16"<<"User17"<<"User18"<<"User19"<<"User20"<<"User21";
	strings<<"User22"<<"User23"<<"User24"<<"User25"<<"User26"<<"User27"<<"User28";
	strings<<"User29"<<"User30"<<"User31";
	ui.comboUserNo->addItems(strings);

	ui.tableLocalChannel->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableLocalChannel->setColumnCount(1);
	ui.tableRemoteChannel->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui.tableRemoteChannel->setColumnCount(1);

	connect(ui.comboUserNo, SIGNAL(activated(int)), this, SLOT( userIDChanged(int )));
    connect(ui.comboLocalRight, SIGNAL(activated(int)), this, SLOT(localRightTypeChanged(int)));
    connect(ui.comboNetRight, SIGNAL(activated(int)), this, SLOT(remoteRightTypeChanged(int)));
	//���ȼ�
    connectArrayAndWidget();
}

CUserParams::~CUserParams()
{

}

//�û�ID�仯
void CUserParams::userIDChanged(int iUserID)
{
	if(m_lUserID < 0)
	{
		return ;
	}

	NET_DVR_USER_V30 struUser;
	int iRet;
	DWORD uiReturnLen;

	//��ȡ�豸�Ĳ���ֵ
	iRet = NET_DVR_GetDVRConfig(m_lUserID, NET_DVR_GET_USERCFG_V30, -1, &struUser, sizeof(NET_DVR_USER_V30), &uiReturnLen);
	if(iRet == 0)
	{
	    iRet = NET_DVR_GetLastError();
	    QMessageBox::information(this, tr("Please check!"), tr("Get User parameters error! \"%1\"").arg(iRet));
	    return ;
	}

	//�����û��������ؼ���ȥ
        ui.editUserName->setText((char*)struUser.struUser[iUserID].sUserName);
        ui.editPassword->setText((char*)struUser.struUser[iUserID].sPassword);
        ui.editPassword2->setText((char*)struUser.struUser[iUserID].sPassword);

	//���ȼ�
	QStringList strings;
	if(struUser.struUser[iUserID].byPriority == (BYTE)0xff)
	{
		ui.comboPriority->setEnabled(FALSE);
	}
	else
	{
		ui.comboPriority->setEnabled(TRUE);
		ui.comboPriority->clear();
		if(struUser.struUser[iUserID].byPriority == 2)
		{
			strings<<"Administrator";
			ui.comboPriority->addItems(strings);
			ui.comboPriority->setCurrentIndex(0);
		}
		else
		{
			strings<<"Normal user"<<"Operator";
			ui.comboPriority->addItems(strings);
			ui.comboPriority->setCurrentIndex((int)(unsigned int)(struUser.struUser[iUserID].byPriority));
		}
	 }

	//���غ�Զ�̲���Ȩ��
	int i;
	for(i = 0; i < MAX_RIGHT; i++)
	{
		if(m_pcheckLocalRight[i] != NULL)
		{
			m_pcheckLocalRight[i]->setChecked(struUser.struUser[iUserID].byLocalRight[i]);
		}
		if(m_pcheckRemoteRight[i] != NULL)
		{
			m_pcheckRemoteRight[i]->setChecked(struUser.struUser[iUserID].byRemoteRight[i]);
		}
	}

	//���غ�Զ��ͨ��Ȩ��
	localRightTypeChanged(0);
	remoteRightTypeChanged(0);

	//IP��ַ
	ui.editUserIP->setText(struUser.struUser[iUserID].struUserIP.sIpV4);
	//MAC��ַ
	char strMAC[100] = {0};
	for(i = 0; i < MACADDR_LEN; i++)
	{
		sprintf(strMAC, "%02x", struUser.struUser[iUserID].byMACAddr[i]);
		m_pEditMAC[i]->setText(strMAC);
	}
}

//����ͨ��Ȩ�޷�ʽ�ı�
void CUserParams::localRightTypeChanged(int iLocalRightType)
{
	if(m_lUserID < 0)
	{
		return ;
	}
	//QMessageBox::information(this, tr("Please check!"), tr("Changed error!"));

	int iUserNo;//�û������
	iUserNo = ui.comboUserNo->currentIndex();

	NET_DVR_USER_V30 struUser;
	int iRet;
	DWORD uiReturnLen;

	//��ȡ�豸�Ĳ���ֵ
	iRet = NET_DVR_GetDVRConfig(m_lUserID, NET_DVR_GET_USERCFG_V30, -1, &struUser, sizeof(NET_DVR_USER_V30), &uiReturnLen);
	if(iRet == 0)
	{
	    iRet = NET_DVR_GetLastError();
	    QMessageBox::information(this, tr("Please check!"), tr("Get User parameters error! \"%1\"").arg(iRet));
	    return ;
	}

	//����Ȩ�޵�ͨ��
	int i;
	BYTE *pRight;
	//����Ȩ�޲����ڽṹ����λ��ƫ��
	pRight = struUser.struUser[iUserNo].byLocalPlaybackRight + iLocalRightType*2*MAX_CHANNUM_V30;
	for(i = 0; i < MAX_CHANNUM_V30; i++)
	{
		if(m_pcheckLocalChannel[i] != NULL)
		{
			if(pRight[i] == (BYTE)0xff) //�Ͱ汾�豸��֧�ָò���()����ֵSDK��Ϊ-1
			{
				m_pcheckLocalChannel[i]->setChecked(FALSE);
			}
			else //���������λ0��1
			{
				m_pcheckLocalChannel[i]->setChecked(pRight[i]);
			}
		}
	}
}

//����ͨ��Ȩ�޷�ʽ�ı�
void CUserParams::remoteRightTypeChanged(int iRemoteRightType)
{
	if(m_lUserID < 0)
	{
		return ;
	}
	//QMessageBox::information(this, tr("Please check!"), tr("Changed error!"));

	int iUserNo;//�û������
	iUserNo = ui.comboUserNo->currentIndex();

	NET_DVR_USER_V30 struUser;
	int iRet;
	DWORD uiReturnLen;

	//��ȡ�豸�Ĳ���ֵ
	iRet = NET_DVR_GetDVRConfig(m_lUserID, NET_DVR_GET_USERCFG_V30, -1, &struUser, sizeof(NET_DVR_USER_V30), &uiReturnLen);
	if(iRet == 0)
	{
	    iRet = NET_DVR_GetLastError();
	    QMessageBox::information(this, tr("Please check!"), tr("Get User parameters error! \"%1\"").arg(iRet));
	    return ;
	}

	//����Ȩ�޵�ͨ��
	int i;
	BYTE *pRight;
	//����Ȩ�޲����ڽṹ����λ��ƫ��
	pRight = struUser.struUser[iUserNo].byNetPreviewRight + iRemoteRightType*2*MAX_CHANNUM_V30;
	for(i = 0; i < MAX_CHANNUM_V30; i++)
	{
		if(m_pcheckRemoteChannel[i] != NULL)
		{
			if(pRight[i] == (BYTE)0xff) //�Ͱ汾�豸��֧�ָò���()����ֵSDK��Ϊ-1
			{
				m_pcheckRemoteChannel[i]->setChecked(FALSE);
			}
			else //���������λ0��1
			{
				m_pcheckRemoteChannel[i]->setChecked(pRight[i]);
			}
		}
	}

}

//��ȡʵ�ʿ���ͨ���б�����д��tablewidget��
int CUserParams::getChannelNum()
{
	if(m_lUserID < 0)
	{
		return HPR_ERROR;
	}

	NET_DVR_DEVICECFG struDeviceParams;
	DWORD paramsLen;
	int iRet;

	//***1.Get the channel number and IP channel number.***//
	iRet = NET_DVR_GetDVRConfig(m_lUserID, NET_DVR_GET_DEVICECFG, -1,
			&struDeviceParams, sizeof(NET_DVR_DEVICECFG), &paramsLen);
	if (iRet == 0) {
		iRet = NET_DVR_GetLastError();
		QMessageBox::information(this, tr("Please check!"), tr("Get device parameters error!"));
		return HPR_ERROR;
	}
	m_iStartChan = (int) (struDeviceParams.byStartChan);

	//***2.Get the channel which is enabled.***//
	//iRet��ֵ�����ж��Ƿ�֧��IPͨ��
	NET_DVR_IPPARACFG struIPParams;
	iRet = NET_DVR_GetDVRConfig(m_lUserID, NET_DVR_GET_IPPARACFG, -1, &struIPParams, sizeof(NET_DVR_IPPARACFG), &paramsLen);

	int i, j;
	j = 0;
	if (iRet != 0)//if support ip channel
	{
		//ģ��ͨ��
		for (i = 0; i < MAX_ANALOG_CHANNUM; i++)
		{
			if (struIPParams.byAnalogChanEnable[i])
			{
				m_iArryChannel[j] = i + m_iStartChan;
				j++;
			}
		}
		m_iSimChannelNum = j;

		//IPͨ��
		for (i = 0; i < MAX_IP_CHANNEL; i++)
		{
			if (struIPParams.struIPChanInfo[i].byIPID != 0)
			{
				m_iArryChannel[j] = i + m_iStartChan + MAX_ANALOG_CHANNUM;
				j++;
			}
		}
	}
	else//if not support ip channel
	{
		//simulate channel
		for (i = 0; (i < MAX_ANALOG_CHANNUM)
				&& (i < struDeviceParams.byChanNum); i++)
		{
			m_iArryChannel[j] = i + m_iStartChan;
			j++;
		}
		m_iSimChannelNum = j;
	}

	//ʵ�ʿ��õ����ͨ����Ŀ
	int iMaxChannelNo;
	for(i = 0; i < MAX_CHANNUM_V30; i++)
	{
		if(m_iArryChannel[i] < 0)
		{
			break;
		}
	}
	iMaxChannelNo = i;

	int iRow = 0; //�������
	//ɾ���ϴε�����
	iRow = ui.tableLocalChannel->rowCount();
	for(i = 0; i < iRow; i++)
	{
		ui.tableLocalChannel->removeRow(i);
		ui.tableRemoteChannel->removeRow(i);
	}

	//����ϴμ�������ݣ�ע��tablewidget���Լ��ͷŵ��ڴ棬��ʹ����new������
	ui.tableLocalChannel->clear();
	ui.tableRemoteChannel->clear();
	for (i = 0; i < MAX_CHANNUM_V30; i++)
	{
		m_pcheckLocalChannel[i] = NULL;
		m_pcheckRemoteChannel[i] = NULL;
	}

	//�����µĺ�����tableͷ
	ui.tableLocalChannel->setRowCount(iMaxChannelNo);
	ui.tableRemoteChannel->setRowCount(iMaxChannelNo);
    QStringList strings;
    strings<<"Local channel";
    ui.tableLocalChannel->setHorizontalHeaderLabels(strings);
    strings.clear();
    strings<<"Remote channel";
    ui.tableRemoteChannel->setHorizontalHeaderLabels(strings);

	//***3. Add check items to table.***//
	char strTemp[100] = { 0 };
	iRow = 0;
	for (i = 0; i < MAX_CHANNUM_V30; i++)
	{
		if (m_iArryChannel[i] >= 0)//����һ��ͨ��
		{
			if (m_iArryChannel[i] < MAX_ANALOG_CHANNUM) //ģ��ͨ��
			{
				sprintf(strTemp, "Camora%d", m_iArryChannel[i]);
			}
			else//IP channel
			{
				if (iRet != 0)//supprot IP channel
				{
					sprintf(strTemp, "IPCamora%d", (m_iArryChannel[i] - MAX_ANALOG_CHANNUM));
				}
			}
			//new����һ���µı���
			m_pcheckLocalChannel[m_iArryChannel[i] - m_iStartChan] = new QCheckBox();
			m_pcheckRemoteChannel[m_iArryChannel[i] - m_iStartChan] = new QCheckBox();

			m_pcheckLocalChannel[m_iArryChannel[i] - m_iStartChan]->setText(strTemp);
			m_pcheckRemoteChannel[m_iArryChannel[i] - m_iStartChan]->setText(strTemp);

			ui.tableLocalChannel->setCellWidget(iRow, 0, (m_pcheckLocalChannel[m_iArryChannel[i] - m_iStartChan]));
			ui.tableRemoteChannel->setCellWidget(iRow, 0, (m_pcheckRemoteChannel[m_iArryChannel[i] - m_iStartChan]));
		    iRow++;
		}
	}

	return HPR_OK;
}

//���þ��ֵ
int CUserParams::setUserID(long lUserID)
{
	if(lUserID < 0)
	{
		return HPR_ERROR;
	}
	m_lUserID = lUserID;

	return HPR_OK;
}

//��ȡ������д��ؼ���ȥ
int CUserParams::getAllInfo()
{
	if(m_lUserID < 0)
	{
		return HPR_ERROR;
	}
	//���õ�ǰ���û�ΪNOΪ0
	ui.comboUserNo->setCurrentIndex(0);
	//�����û��������ؼ���ȥ
	userIDChanged(0);

	return HPR_OK;
}

int CUserParams::setAllInfo()
{
	if(m_lUserID < 0)
	{
		return HPR_ERROR;
	}

	NET_DVR_USER_V30 struUser;
	int iRet;
	DWORD uiReturnLen;

	//��ȡ�û��Ĳ���ֵ
	iRet = NET_DVR_GetDVRConfig(m_lUserID, NET_DVR_GET_USERCFG_V30, -1, &struUser, sizeof(NET_DVR_USER_V30), &uiReturnLen);
	if(iRet == 0)
	{
	    iRet = NET_DVR_GetLastError();
	    QMessageBox::information(this, tr("Please check!"), tr("Get User parameters error! \"%1\"").arg(iRet));
	    return HPR_ERROR;
	}

	//�����û���:�ȱȽ������Ƿ���ͬ
	if(ui.editPassword->text() != ui.editPassword2->text())
	{
		QMessageBox::information(this, tr("Please check!"), tr("password is not equal error! "));
	    return HPR_ERROR;
	}
	//��ȡ��ǰ�û���
	int iUserNo;
	iUserNo = ui.comboUserNo->currentIndex();


	//IP��ַ
        iRet = KIT_editToIP(ui.editUserIP, (BYTE *)struUser.struUser[iUserNo].struUserIP.sIpV4, 16);
	if(iRet == HPR_ERROR)
	{
		QMessageBox::information(this, tr("Please check!"), tr("ip is error! "));
	    return HPR_ERROR;
	}
	//MAC��ַ
	char strMAC[100] = {0};
	int iMAC;
	int i;
	for(i = 0; i < MACADDR_LEN; i++)
	{
		memset(strMAC, 0, 100);
                KIT_editToStr(m_pEditMAC[i], (BYTE *)strMAC, 3);
		sscanf(strMAC, "%02x", &iMAC);
		struUser.struUser[iUserNo].byMACAddr[i] = (BYTE)iMAC;
	}

	KIT_editToStr(ui.editUserName, struUser.struUser[iUserNo].sUserName, NAME_LEN);
    //��������
	KIT_editToStr(ui.editPassword, struUser.struUser[iUserNo].sPassword, PASSWD_LEN);

	//����Զ�̺ͱ���Ȩ��
	for(i = 0; i < MAX_RIGHT; i++)
	{
		if(m_pcheckLocalRight[i] != NULL)//����Ȩ��
		{
			struUser.struUser[iUserNo].byLocalRight[i] = (BYTE)m_pcheckLocalRight[i]->isChecked();
		}
		if(m_pcheckRemoteRight[i] != NULL)
		{
			struUser.struUser[iUserNo].byRemoteRight[i] = (BYTE)m_pcheckRemoteRight[i]->isChecked();
		}
	}

	//���ȼ�
	if(ui.comboPriority->isEnabled())
	{
		if(ui.comboPriority->count() == 2)
		{
			struUser.struUser[iUserNo].byPriority = ui.comboPriority->currentIndex();
		}
		else
		{
			struUser.struUser[iUserNo].byPriority = 2;
		}
	}
	else
	{
		struUser.struUser[iUserNo].byPriority = (BYTE)0xff;
	}

	//ͨ��Ȩ��
	//�õ���ǰͨ��Ȩ������
	int iLocalRightType;
	int iRemoteRightType;
	iLocalRightType = ui.comboLocalRight->currentIndex();
	iRemoteRightType = ui.comboNetRight->currentIndex();
	BYTE *pLocalRight;
	BYTE *pRemoteRight;
	//����Ȩ�޲����ڽṹ����λ��ƫ��
	pLocalRight = struUser.struUser[iUserNo].byLocalPlaybackRight + iLocalRightType*2*MAX_CHANNUM_V30;
	pRemoteRight = struUser.struUser[iUserNo].byNetPreviewRight + iRemoteRightType*2*MAX_CHANNUM_V30;
	for(i = 0; i < MAX_CHANNUM_V30; i++)
	{
		//����ͨ��
		if(m_pcheckLocalChannel[i] != NULL)
		{
			if(pLocalRight[i] != (BYTE)0xff) //���豸�汾����ʱ
			{
				pLocalRight[i] = m_pcheckLocalChannel[i]->isChecked();
			}
		}
		//Զ��ͨ��
		if(m_pcheckRemoteChannel[i] != NULL)//���豸�汾����ʱ
		{
			if(pRemoteRight[i] != (BYTE)0xff)
			{
				pRemoteRight[i] = m_pcheckRemoteChannel[i]->isChecked();
			}
		}
	}

	//���浽�豸
	iRet = NET_DVR_SetDVRConfig(m_lUserID, NET_DVR_SET_USERCFG_V30, -1, &struUser, sizeof(NET_DVR_USER_V30));
    if(0 == iRet)
    {
	    iRet = NET_DVR_GetLastError();
	    QMessageBox::information(this, tr("Please check!"), tr("Set User parameters error! \"%1\"").arg(iRet));
	    return HPR_ERROR;
    }

	return HPR_OK;
}

void CUserParams::connectArrayAndWidget()
{
	//����Ȩ��
	m_pcheckLocalRight[0] = ui.checkLocalRight0;
	m_pcheckLocalRight[1] = ui.checkLocalRight1;
	m_pcheckLocalRight[2] = ui.checkLocalRight2;
	m_pcheckLocalRight[3] = ui.checkLocalRight3;
	m_pcheckLocalRight[4] = ui.checkLocalRight4;
	m_pcheckLocalRight[5] = ui.checkLocalRight5;
	m_pcheckLocalRight[6] = ui.checkLocalRight6;
	m_pcheckLocalRight[7] = ui.checkLocalRight7;
	m_pcheckLocalRight[8] = ui.checkLocalRight8;
	m_pcheckLocalRight[9] = ui.checkLocalRight9;

	//Զ��Ȩ��
	m_pcheckRemoteRight[0] = ui.checkRemoteRight0;
	m_pcheckRemoteRight[1] = ui.checkRemoteRight1;
	m_pcheckRemoteRight[2] = ui.checkRemoteRight2;
	m_pcheckRemoteRight[3] = ui.checkRemoteRight3;
	m_pcheckRemoteRight[4] = ui.checkRemoteRight4;
	m_pcheckRemoteRight[5] = ui.checkRemoteRight5;
	m_pcheckRemoteRight[6] = ui.checkRemoteRight6;
	m_pcheckRemoteRight[7] = ui.checkRemoteRight7;
	m_pcheckRemoteRight[8] = ui.checkRemoteRight8;
	m_pcheckRemoteRight[9] = ui.checkRemoteRight9;
	m_pcheckRemoteRight[10] = ui.checkRemoteRight10;
	m_pcheckRemoteRight[11] = ui.checkRemoteRight11;
	m_pcheckRemoteRight[12] = ui.checkRemoteRight12;
	m_pcheckRemoteRight[13] = ui.checkRemoteRight13;

	//MAC��ַ
	m_pEditMAC[0] = ui.editMACAddr1;
	m_pEditMAC[1] = ui.editMACAddr2;
	m_pEditMAC[2] = ui.editMACAddr3;
	m_pEditMAC[3] = ui.editMACAddr4;
	m_pEditMAC[4] = ui.editMACAddr5;
	m_pEditMAC[5] = ui.editMACAddr6;
}

//event
void CUserParams::showEvent ( QShowEvent * event )
{
	if(NULL == event)
	{
	}

	getChannelNum(); //��ȡͨ����
	getAllInfo();

}
