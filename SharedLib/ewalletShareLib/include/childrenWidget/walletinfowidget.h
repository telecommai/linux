﻿#pragma once

#include <QWidget>
#include <QFileDialog>
#include <QJsonDocument>
#include "stdafx.h"
#include "messagebox.h"
#include "httpnetworksharelib.h"

namespace Ui { class WalletInfoWidget; };

class WalletInfoWidget : public QWidget
{
	Q_OBJECT

public:
	WalletInfoWidget(QWidget *parent = Q_NULLPTR);
	~WalletInfoWidget();

private slots:
	void slotEnter();

	void slotSelectIcon();
	void slotUploadImage(bool, QByteArray);

#ifdef Q_OS_LINUX
    void setLinuxCenter();
#endif
protected:
	bool eventFilter(QObject *, QEvent *);


signals:
	void sigSendWalletInfo(QString name, QString iconID);

private:
	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动

private:
	Ui::WalletInfoWidget *ui;

	QPoint mouse;

	QString iconPath;
	QString iconId;
	QString walletName;

	bool send;
};
