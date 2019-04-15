#pragma once

#include <QWidget>
#include <qpainter.h>
#include <QGraphicsObject>
#include <QPropertyAnimation>
#include <QGraphicsRotation>
#include <QParallelAnimationGroup>
namespace Ui { class OpenPacketWidget; };
enum packType
{
	commonPack,groupCommonPack,groupRandomPack
};
class OpenPacketWidget : public QWidget
{
	Q_OBJECT

public:
	OpenPacketWidget(QWidget *parent = Q_NULLPTR);
	~OpenPacketWidget();
	void setInfo(QString avatarPath, QString nickname, QString msgID, QString notice,packType type = commonPack);//设置头像，昵称，红包备注，红包类型

private:
	Ui::OpenPacketWidget *ui;

	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);

	void paintEvent(QPaintEvent *event);
	void setStyle();//设置界面样式

	bool		mMoveing;
	QPoint	    mMovePosition;

	QString msgID;

	int m_angle;
	bool m_change;
	QTimer *m_pTimer;

signals:
	void sigClose();
	void sigOpenPacket(QString msgID);
private slots:
	void onCloseClicked();//用户点击关闭按钮，窗口关闭
	void onOpenClicked();//用户点击打开红包
	void SLO_updatePaint();
};
