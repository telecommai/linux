#pragma once

#include <QWidget>
#include <qpainter.h>
#include <qmath.h>
#include <qevent.h>
#include <QCryptographicHash>
#include "stdafx.h"
#include "opdatamanager.h"
#include "messagebox.h"
#include "inputbox.h"
#include "oprequestsharelib.h"
namespace Ui { class TransAccWidget; };

class TransAccWidget : public QWidget
{
	Q_OBJECT

public:
	TransAccWidget(QWidget *parent = Q_NULLPTR);
	~TransAccWidget();

	void setInfo(QString unit, double balance, QString wallet,QString address);//设置单位，余额，钱包，付款地址
private:
	Ui::TransAccWidget *ui;

	bool		mMoveing;
	QPoint	    mMovePosition;

signals:
	void sigClose();
	void sigHostingCharge(int, QString, QString, QString);

private:
	void paintEvent(QPaintEvent * event);

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
private slots:
	void slotSetValue(int);
	void slotClose();//点击关闭按钮
	void slotConfirm();//点击确定按钮
	void slotConfirmPassword(QString);
};
