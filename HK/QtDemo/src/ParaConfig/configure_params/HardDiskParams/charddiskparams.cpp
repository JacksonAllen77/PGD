#include "charddiskparams.h"
#include "publicfuc.h"
#include <QMessageBox>

CHardDiskParams::CHardDiskParams(QWidget *parent)
    : QWidget(parent)
{
	ui.setupUi(this);

	m_lUserID = -1;
	memset(m_struHDTableWidget, 0, sizeof(KIT_HD_WIDGET)*MAX_DISKNUM_V30);

	int i;
	for(i = 0; i < MAX_CHAN_NUM; i++ )
	{
		m_pCheckChan[i] = NULL;//�ͷ���Qtableȥ���
	}

	ui.tableHDGroup->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

	connect(ui.comboDGroup, SIGNAL(activated(int)), this, SLOT(comboHDGroupChanged(int)));
}

CHardDiskParams::~CHardDiskParams()
{

}

int CHardDiskParams::setUserID(long lUserID)
{
	if(lUserID < 0)
	{
		return HPR_ERROR;
	}
	m_lUserID = lUserID;
	return HPR_OK;
}

//��ȡӲ����Ϣ, �������ñ�����Ϣ�Ĳ���
int  CHardDiskParams::getHardDiskInfo()
{
	//���豸��ȡӲ����Ϣ
	if(m_lUserID < 0)
	{
		return HPR_ERROR;
	}
	NET_DVR_HDCFG struHDParams;
	memset(&struHDParams, 0 , sizeof(NET_DVR_HDCFG));
	int iRet;
	DWORD uiReturnLen;
	iRet = NET_DVR_GetDVRConfig(m_lUserID, NET_DVR_GET_HDCFG, 0, &struHDParams, sizeof(NET_DVR_HDCFG), &uiReturnLen);
    if(0 == iRet)
    {
    	iRet = NET_DVR_GetLastError();
        QMessageBox::information(this, "Please check!", tr("The error is \"%1\"").arg(iRet));
        return HPR_ERROR;
    }

    //1.��ձ���
    int iRow;
    ui.tableHardDisk->clear();
    for(iRow = 0; iRow < ui.tableHardDisk->rowCount(); iRow++)
    {
    	ui.tableHardDisk->removeRow(iRow);
    }

    //����������������ͷ
    ui.tableHardDisk->setRowCount((int)struHDParams.dwHDCount);
    ui.tableHardDisk->setColumnCount(7);

    //����ͷ��
    QStringList list;
    list<<"HD name"<<"Capacity"<<"Last capacity"<<"State"<<"Type"<<"Attribute"<<"Group";
    ui.tableHardDisk->setHorizontalHeaderLabels(list);

    QStringList listHdStatus; //HD״̬
    listHdStatus<<"Normal"<<"Not format"<<"Error"<<"S.M.A.R.T"<<"Not match"<<"Sleep"<<"Not connect";
    QStringList listHDAttr; //HD����
    listHDAttr<<"Default"<<"Redundancy"<<"Read";
    QStringList listHDType; //HD����
    listHDType<<"Local"<<"ESATA"<<"NFS";
    QStringList listHdGroup; //�����
    listHdGroup<<"0"<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7";
    listHdGroup<<"8"<<"9"<<"10"<<"11"<<"12"<<"13"<<"14"<<"15";

    //2.��������д������
    ui.tableHardDisk->setEditTriggers(QAbstractItemView::NoEditTriggers); //���񲻿ɱ༭
    int i;
    char strTemp[100];
    for(i = 0; i < (int)struHDParams.dwHDCount; i++ )
    {
    	//Ӳ�̺�
    	memset(strTemp, 0, 100);
    	sprintf(strTemp, "%d", struHDParams.struHDInfo[i].dwHDNo);
    	m_struHDTableWidget[i].pTableItem[0] = new QTableWidgetItem(strTemp);
    	//iTableItemFlags = m_struHDTableWidget[i].pTableItem[0]->flags();
    	//m_struHDTableWidget[i].pTableItem[0]->setFlags(iTableItemFlags&0xfd);
    	ui.tableHardDisk->setItem(i, 0, m_struHDTableWidget[i].pTableItem[0]);
    	//Ӳ������
    	memset(strTemp, 0, 100);
        sprintf(strTemp, "%d", struHDParams.struHDInfo[i].dwCapacity);
        m_struHDTableWidget[i].pTableItem[1] = new QTableWidgetItem(strTemp);
        ui.tableHardDisk->setItem(i, 1, m_struHDTableWidget[i].pTableItem[1]);
        //ʣ������
        memset(strTemp, 0, 100);
        sprintf(strTemp, "%d", struHDParams.struHDInfo[i].dwFreeSpace);
        m_struHDTableWidget[i].pTableItem[2] = new QTableWidgetItem(strTemp);
        ui.tableHardDisk->setItem(i, 2, m_struHDTableWidget[i].pTableItem[2]);

        //״̬
		m_struHDTableWidget[i].pTableCombo[0] = new QComboBox();
		m_struHDTableWidget[i].pTableCombo[0]->addItems(listHdStatus);
		m_struHDTableWidget[i].pTableCombo[0]->setCurrentIndex((int)struHDParams.struHDInfo[i].dwHdStatus);
		ui.tableHardDisk->setCellWidget(i, 3, m_struHDTableWidget[i].pTableCombo[0]);
		//m_struHDTableWidget[i].pTableCombo[0]->setEditable(FALSE);
		m_struHDTableWidget[i].pTableCombo[0]->setEnabled(FALSE);
		//����
        m_struHDTableWidget[i].pTableCombo[1] = new QComboBox();
        m_struHDTableWidget[i].pTableCombo[1]->addItems(listHDAttr);
        m_struHDTableWidget[i].pTableCombo[1]->setCurrentIndex((int)struHDParams.struHDInfo[i].byHDAttr);
        ui.tableHardDisk->setCellWidget(i, 4, m_struHDTableWidget[i].pTableCombo[1]);

        //����
		m_struHDTableWidget[i].pTableCombo[2] = new QComboBox();
		m_struHDTableWidget[i].pTableCombo[2]->addItems(listHDType);
		m_struHDTableWidget[i].pTableCombo[2]->setCurrentIndex((int)struHDParams.struHDInfo[i].byHDType);
		ui.tableHardDisk->setCellWidget(i, 5, m_struHDTableWidget[i].pTableCombo[2]);
		m_struHDTableWidget[i].pTableCombo[2]->setEnabled(FALSE);

		//����
		m_struHDTableWidget[i].pTableCombo[3] = new QComboBox();
		m_struHDTableWidget[i].pTableCombo[3]->addItems(listHdGroup);
		m_struHDTableWidget[i].pTableCombo[3]->setCurrentIndex((int)struHDParams.struHDInfo[i].dwHdGroup);
		ui.tableHardDisk->setCellWidget(i, 6, m_struHDTableWidget[i].pTableCombo[3]);
    }

    return HPR_ERROR;
}

//����Ӳ�̲���
int CHardDiskParams::setHardDiskInfo()
{
	//QMessageBox::information(this, tr("Please check!"), tr("Please table widget is NULL!"));
	//���豸��ȡӲ����Ϣ
	if(m_lUserID < 0)
	{
		return HPR_ERROR;
	}
	NET_DVR_HDCFG struHDParams;
	memset(&struHDParams, 0 , sizeof(NET_DVR_HDCFG));
	int iRet;
	DWORD uiReturnLen;
	iRet = NET_DVR_GetDVRConfig(m_lUserID, NET_DVR_GET_HDCFG, 0, &struHDParams, sizeof(NET_DVR_HDCFG), &uiReturnLen);
    if(0 == iRet)
    {
    	iRet = NET_DVR_GetLastError();
        QMessageBox::information(this, "Please check!", tr("The error is \"%1\"").arg(iRet));
        return HPR_ERROR;
    }

    //�ӵ�ǰ��table�����л�ȡ����
    int i;
    for(i = 0; i < (int)struHDParams.dwHDCount; i++ )
    {
    	if(NULL == m_struHDTableWidget[i].pTableCombo[1] || NULL == m_struHDTableWidget[i].pTableCombo[3])
    	{
    		QMessageBox::information(this, tr("Please check!"), tr("Please table widget is NULL!"));
    		return HPR_ERROR;
    	}
    	struHDParams.struHDInfo[i].byHDAttr = m_struHDTableWidget[i].pTableCombo[1]->currentIndex();
    	struHDParams.struHDInfo[i].dwHdGroup = m_struHDTableWidget[i].pTableCombo[3]->currentIndex();
    }

    //�������豸��ȥ
	iRet = NET_DVR_SetDVRConfig(m_lUserID, NET_DVR_SET_HDCFG, 0, &struHDParams, sizeof(NET_DVR_HDCFG));
    if(0 == iRet)
    {
    	iRet = NET_DVR_GetLastError();
        QMessageBox::information(this, "Please check!", tr("The error is \"%1\"").arg(iRet));
        return HPR_ERROR;
    }

    return HPR_OK;
}

//��ȡӲ������Ϣ
int CHardDiskParams::getHDGroupInfo()
{
	//���豸��ȡӲ������Ϣ
	if(m_lUserID < 0)
	{
		return HPR_ERROR;
	}
	NET_DVR_HDGROUP_CFG struHDGroupParams;
	memset(&struHDGroupParams, 0 , sizeof(NET_DVR_HDGROUP_CFG));
	int iRet;
	DWORD uiReturnLen;
	iRet = NET_DVR_GetDVRConfig(m_lUserID, NET_DVR_GET_HDGROUP_CFG, 0, &struHDGroupParams, sizeof(NET_DVR_HDGROUP_CFG), &uiReturnLen);
    if(0 == iRet)
    {
    	iRet = NET_DVR_GetLastError();
        QMessageBox::information(this, "Please check!", tr("The error is \"%1\"").arg(iRet));
        return HPR_ERROR;
    }

    if(GetChanInfoToTable() == HPR_ERROR) //�Ȼ�ȡͨ����Ϣ
    {
    	return HPR_ERROR;
    }

    //����Ӳ������Ϣ
    //Ӳ�̺�
    char strTemp[100];
    int i;
    QStringList listHDGroup;
    for(i = 0; i < ((int)struHDGroupParams.dwHDGroupCount ); i++)
    {
    	//QMessageBox::information(this, "Please check!", tr("dwHDGroupCount i is \"%1\"").arg(i));
    	memset(strTemp, 0, 100);
    	sprintf(strTemp, "%d", i + 1);
    	listHDGroup<<strTemp;
    }
    ui.comboDGroup->clear();
    ui.comboDGroup->addItems(listHDGroup);
    comboHDGroupChanged(0);//���õ�1�������ͨ����Ϣ

	 return HPR_OK;
}

//����Ӳ�������
int CHardDiskParams::setHDGroupInfo()
{
	//���豸��ȡӲ������Ϣ
	if(m_lUserID < 0)
	{
		return HPR_ERROR;
	}
	NET_DVR_HDGROUP_CFG struHDGroupParams;
	memset(&struHDGroupParams, 0 , sizeof(NET_DVR_HDGROUP_CFG));
	int iRet;
	DWORD uiReturnLen;
	iRet = NET_DVR_GetDVRConfig(m_lUserID, NET_DVR_GET_HDGROUP_CFG, 0, &struHDGroupParams, sizeof(NET_DVR_HDGROUP_CFG), &uiReturnLen);
    if(0 == iRet)
    {
    	iRet = NET_DVR_GetLastError();
        QMessageBox::information(this, "Please check!", tr("The error is \"%1\"").arg(iRet));
        return HPR_ERROR;
    }

    //��ȡ���������������
    //��ǰѡ�����
    int iCurrentComboIndex;
    iCurrentComboIndex = ui.comboDGroup->currentIndex();
    if(iCurrentComboIndex < 0)
    {
    	return HPR_ERROR;
    }
    int i;
    for(i=0; i < MAX_CHAN_NUM; i++)
    {
    	if(m_pCheckChan[i] != NULL)
    	{
    		struHDGroupParams.struHDGroupAttr[iCurrentComboIndex].byHDGroupChans[i]
    		                                                                     = m_pCheckChan[i]->isChecked();
    	}
    }

    //���õ��豸��
	iRet = NET_DVR_SetDVRConfig(m_lUserID, NET_DVR_SET_HDGROUP_CFG, 0, &struHDGroupParams, sizeof(NET_DVR_HDGROUP_CFG ));
    if(0 == iRet)
    {
    	iRet = NET_DVR_GetLastError();
        QMessageBox::information(this, "Please check!", tr("The error is \"%1\"").arg(iRet));
        return HPR_ERROR;
    }
	 return HPR_OK;
}

//ˢ��Ӳ�̲���
void CHardDiskParams::on_btnHDUpdate_clicked()
{
	getHardDiskInfo();
}

//�������
void CHardDiskParams::on_btnHDSave_clicked()
{
	setHardDiskInfo();
	getHardDiskInfo();//�����꣬ˢ����
}

//ˢ��Ӳ�����������
void CHardDiskParams::on_btnHDGroupUpdate_clicked()
{
	getHDGroupInfo();
}

//����Ӳ�����������
void CHardDiskParams::on_btnHDGroupSave_clicked()
{
	setHDGroupInfo();
	getHDGroupInfo();//ˢ����
}

//comboxBoxѡ��
void CHardDiskParams::comboHDGroupChanged(int iHDGroupIndex)
{
	//���豸��ȡӲ������Ϣ
	if(m_lUserID < 0)
	{
		return ;
	}
	NET_DVR_HDGROUP_CFG struHDGroupParams;
	memset(&struHDGroupParams, 0 , sizeof(NET_DVR_HDGROUP_CFG));
	int iRet;
	DWORD uiReturnLen;
	iRet = NET_DVR_GetDVRConfig(m_lUserID, NET_DVR_GET_HDGROUP_CFG, 0, &struHDGroupParams, sizeof(NET_DVR_HDGROUP_CFG), &uiReturnLen);
    if(0 == iRet)
    {
    	iRet = NET_DVR_GetLastError();
        QMessageBox::information(this, "Please check!", tr("The error is \"%1\"").arg(iRet));
        return ;
    }

    //���������Ӧ��ͨ����Ϣ
    int i;
    for(i=0; i < MAX_CHAN_NUM; i++)
    {
    	if(m_pCheckChan[i] != NULL)
    	{
    		if(struHDGroupParams.struHDGroupAttr[iHDGroupIndex].byHDGroupChans[i])
    		{
    			m_pCheckChan[i]->setChecked(TRUE);
    		}
    		else
    		{
    			m_pCheckChan[i]->setChecked(FALSE);
    		}
    	}
    }
}

void CHardDiskParams::on_checkAllChan_clicked()
{
	int bState;
	if(ui.checkAllChan->isChecked())
	{
		//ui.checkAllChan->setChecked(FALSE);
		bState = TRUE;
	}
	else
	{
		//ui.checkAllChan->setChecked(TRUE);
		bState = FALSE;
	}

    //��������ͨ��״̬
    int i;
    for(i=0; i < MAX_CHAN_NUM; i++)
    {
    	if(m_pCheckChan[i] != NULL)
    	{
    		m_pCheckChan[i]->setChecked(bState);
    	}
    }
}

void CHardDiskParams::showEvent ( QShowEvent * event )
{
	if(event == NULL)
	{
	}
	getHardDiskInfo();         //�ٻ�ȡӲ��
	getHDGroupInfo();
}

//��ȡͨ����Ϣ
int CHardDiskParams::GetChanInfoToTable()
{
    //1.�����豸���ص���Ϣ������checkbox��
    //new������checkboxҪ�Լ��ͷţ�������Qtable���
    int iTotalNum;
    if(KIT_CreateCheckboxChanArr(m_lUserID, m_pCheckChan, &iTotalNum) == HPR_ERROR)
    {
    	return HPR_ERROR;
    }

    //2.��ձ���
    int iRow;
    ui.tableHDGroup->clear();
    for(iRow = 0; iRow < ui.tableHDGroup->rowCount(); iRow++)
    {
    	ui.tableHDGroup->removeRow(iRow);
    }

    //��������������: 3��
    int iRowCount; //������ܺ���
    iRowCount = (iTotalNum)/3;
    if((iTotalNum + 1)%3 > 0)
    {
    	iRowCount++;
    }
	ui.tableHDGroup->setRowCount(iRowCount);
    ui.tableHDGroup->setColumnCount(3);

    //3.������д��table��
    //ui.tableHDGroup->setCellWidget(0, 0, m_pCheckChanAll);
    int iColumn = 0;
    iRow = 0;
    int i;
    for(i = 0; i < MAX_CHANNUM_V30; i++)
    {
    	//�ҵ�һ���Ѿ�������checkbox
    	if(m_pCheckChan[i] != NULL)
    	{
    		//��˳�����μ���table��
    		ui.tableHDGroup->setCellWidget(iRow, iColumn, m_pCheckChan[i]);
    		//�Ѿ�����һ�е���ĩ������
    		if(iColumn == 2)
    		{
    			++iRow;
    			iColumn = 0;
    		}
    		else//�¸�tableλ��
    		{
    			++iColumn;
    		}
    	}
    }

	return HPR_OK;
}









