#pragma once

#include <QObject>
#include <QMenu>
#include <QAction>
#include <windows.h>
#include <QLabel>
#include <QAbstractNativeEventFilter>
#include <qrect.h>

class CSysTrayIcon : public QObject, public QAbstractNativeEventFilter
{
	Q_OBJECT

public:
	CSysTrayIcon(QObject *parent=0);
	~CSysTrayIcon();

	void CreateTrayIcon(QIcon icon);
	void setIcon(QIcon icon);
	QPoint getTrayMenuPos();
private:
	void CreateTrayMenu();
	void CreateRightMenu(int x, int y);
	bool nativeEventFilter(const QByteArray & eventType, void * message, long * result);
signals:
	void sigExit();

	void sigabout();

	void sigMouseLBttonDown();

	void sigMouseSuspendIn(QPoint);
	void sigMouseSuspendOut(QPoint, int);
public slots:
	void slotSysTrayExit();
	void slotReceiveBoxRect(QRect);
	void slotGetFlashStatus(bool);
private:
	QMenu *mTrayMenu;        //系统托盘菜单
	QAction *ActionCheckUpdate; //检查更新
	QAction *ActionExit;        //退出
	QLabel *mLabel;
	NOTIFYICONDATA    nid;
	QPoint sysTrayPos;
	QPoint globalPos;
	QPoint localPos;
	QPoint pointBuff;
	bool isMouseInTray = true;//标志：鼠标是否在系统托盘悬停 
	bool isMouseOutTray = true;//标志：鼠标悬停在系统托盘上时 保证只弹窗一次 
	bool outOfTrayFlag = true;
	bool outOfWindowFlag = true;
	bool flag = true;
	int suspendTimes;	//鼠标在系统托盘的悬停秒数
	QRect boxRect;
	bool isFlash = false;
};
