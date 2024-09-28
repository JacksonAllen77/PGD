/***************************************************************************************
 *      Copyright 2009-2011 Hikvision Digital Technology Co., Ltd.
 *      FileName        :       channelattr.h
 *      Description     :       ͨ������ͷ�ļ�
 *      Modification    :       ��
 *      Version         :       V1.0.0
 *      Time            :       2009-10,11
 *      Author          :       wanggp@hikvision.com
 **************************************************************************************/
#ifndef CHANNELATTR_H
#define CHANNELATTR_H

#include <QtWidgets/QDialog>
#include "ui_channelattr.h"

class ChannelAttr : public QDialog
{
    Q_OBJECT

public:
    friend class QtClientDemo;
    ChannelAttr(QWidget *parent = 0);
    ~ChannelAttr();

private:
    Ui::ChannelAttrClass ui;
};

#endif // CHANNELATTR_H

