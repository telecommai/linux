#pragma once

#include <QWidget>
#include <qpainter.h>
#include <qlabel.h>
#include <qlabel.h>
#include <qboxlayout.h>
#include "RedPackHistory.h"
namespace Ui { class RedPackDetail; };

class RedPackDetail : public QWidget
{
	Q_OBJECT

public:
	RedPackDetail(QWidget *parent = Q_NULLPTR);
	~RedPackDetail();

	//设置头像，昵称,我获得的金额
	void setMyInfo(QString avatarPath, QString nickname,QString myAmount);

	//设置红包备注，红包总金额，红包金额单位，红包总数，已领取红包数量
	void setPackInfo(QString notice, QString totalAmount, QString unit,int numOfPacks,int committedPacks);

	//添加红包领取人,参数分别为头像路径，昵称，日期，时间，领取金额，红包金额单位,是否为手气最佳
	void addPerson(QString avatarPath, QString nickname, QString date, QString time, QString amount, QString unit,bool isMostLucky=false);
private:
	Ui::RedPackDetail *ui;
	void setStyle();

	void paintEvent(QPaintEvent *event);
	void loadImg(QLabel* label, QString avatarPath);//给label设置头像
	QPixmap PixmapToRound(const QPixmap & img, int radius);

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

	RedPackHistory *historyWidget;

	bool		mMoveing;
	QPoint	    mMovePosition;
	/*QVector<QBoxLayout *>layouts;
	QVector<QLabel *>labels;
	QVector<QWidget *> widgets;*/
private slots:
	void onCloseClicked();
	void onCheckClicked();//点击查看红包记录

	void slotCloseHistoryWidget();
signals:
	void sigClose();
};
