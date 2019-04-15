#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QDoubleValidator>
#include <QStyledItemDelegate>
#include "opcommon.h"
#include "messagebox.h"
#include "oprequestsharelib.h"
#include "stdafx.h"
#include "../transferWidget/passwordwidget.h"
namespace Ui { class HostingCoinWidget; };

class HostingCoinWidget : public QWidget
{
	Q_OBJECT

public:
	HostingCoinWidget(QWidget *parent = Q_NULLPTR);
	~HostingCoinWidget();

	void setAsset(AssetInfo);
	void setMainAddress(QString address) { this->mainAddress = address; }

	private slots:
	void slotInsertWallet(QList<ChildrenWallet>);
	
	void slotAllBtn();
	void slotChangeAddress(int);

	void slotEnter();
	void slotCoinValue();
	void slotCoinResult(bool);

public slots:
	void show();

private:
	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动

private:
	Ui::HostingCoinWidget *ui;

	QPoint mouse;

	QString mainAddress;
	AssetInfo asset;
};
