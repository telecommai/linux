#pragma once

#include <QWidget>
#include <qpainter.h>
#include <qlabel.h>
#include <qboxlayout.h>
#include "common.h"
#include "stdafx.h"
#include "oprequestsharelib.h"
namespace Ui { class RedPackHistory; };

class RedPackHistory : public QWidget
{
	Q_OBJECT

public:
	RedPackHistory(QWidget *parent = Q_NULLPTR);
	~RedPackHistory();

	//添加收到红包记录，参数分别为发红包者ID，红包金额，红包单位，日期，时间
	void addReceiveInfo(QString senderID, QString amount, QString unit, QString date, QString time);

	//添加发红包记录，参数分别为红包类型，红包金额，红包单位，日期，时间
	void addSendInfo(QString type, QString amount, QString unit, QString date, QString time);

	//头像路径，昵称，收到的红包总数，发出的红包总数,需要在addReceiveInfo和addSendInfo之后调用
	void setInfo(QString avatarPath, QString nickname);

    void setLinuxCenter();
private:
	Ui::RedPackHistory *ui;

	void setStyle();

	void paintEvent(QPaintEvent *event);
	QPixmap PixmapToRound(const QPixmap & img, int radius);
	void loadImg(QLabel* label, QString avatarPath);//给label设置头像

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

	bool		mMoveing;
	QPoint	    mMovePosition;
	int	mReceivePacks = 0;
	int mSendPacks = 0;
	/*QVector<QBoxLayout *>	layouts;
	QVector<QLabel *>	labels;
	QVector<QWidget *>	widgets;*/
signals:
	void sigClose();

private slots:
	void onCloseClicked();
	void onReceiveClicked();
	void onSendClicked();

	void slotPacketRecordsIn(QList<RecordInfo>);
	void slotPacketRecordsOut(QList<RecordInfo>);
};
