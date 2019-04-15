#pragma once

#include <QWidget>
#include <qpainter.h>
#include <qmath.h>
#include <qevent.h>
#include "opcommon.h"
#include "stdafx.h"
#include "inputbox.h"
#include "messagebox.h"
#include "oprequestsharelib.h"
#include "RedPackHistory.h"
#include "TransAccWidget.h"
namespace Ui { class GroupPackWidget; };

class GroupPackWidget : public QWidget
{
	Q_OBJECT

private:
	void getHostingAccount();

	void paintEvent(QPaintEvent * event);

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
public:
	GroupPackWidget(QWidget *parent = Q_NULLPTR);
	~GroupPackWidget();

	void setGroup(QString groupID);

public slots:
	void show();

private:
	Ui::GroupPackWidget *ui;

	bool		mMoveing;
	QPoint	    mMovePosition;

	RedPackHistory *historyWidget;
	TransAccWidget *transWidget;
	QList<AssetInfo> assetsList;

	bool isRandom;//是否为拼手气红包

	int numOfGroup;

signals:
	void sigHostingCharge(int, QString, QString, QString);
	void sigGivePacketData(QString);
	void sigClose();

private slots:
    void slotClickTurnInBtn();

	void onRandomClicked();//点击选择随机红包按钮
	void onCommonClicked();//点击选择普通红包按钮
	void onGiveClicked();
	void slotConfirmPassword(QString);
	void slotCreatePacket(QString packetID);

	void onRecordClicked();//点击查看红包历史记录按钮
	void onTextChanged(QString);
	void onNumChanged(QString);

	void slotHostingAccount(QList<AssetInfo> assetList);

	void slotCloseHistoryWidget();
	void slotCloseTransWidget();
};
