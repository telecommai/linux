#ifndef SCANQRWIDGET_H
#define SCANQRWIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include "scanshowqrwidget.h"
#include "scanloginwidget.h"
#include "scannetworksetwidget.h"
#include "threadpoll.h"
#include "common.h"

namespace Ui {
	class ScanQRWidget;
}

class ScanQRWidget : public QWidget
{
	Q_OBJECT

public:
	ScanQRWidget(QWidget *parent = 0);
	~ScanQRWidget();

	/*显示二维码窗口*/
	void showQrWidget();

	void showErro(QString strMsg);

	void setProxy(NetWorkProxyInfo);

	/*显示用户窗口*/
	//void showUserWidget(UserInfo userInfo);
    void setLinuxCenter();
private:
	// Qualifier: 初始化样式表
	void OnInitStyleSheet();
	// Qualifier: 初始化
	void OnInit();

private slots:
	void slotCloseTip();

protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
	virtual void closeEvent(QCloseEvent *event);
public slots:
	//设置用户
	void slotClickSetUser();
	//设置
	void slotClickSet();
	//关闭
	void slotClickClose();
	//获取二维码失败
	void slotLoginFailed();
	//创建二维码
	void slotCreateQR(QString);
signals:
	void sigCloseLoginWidget();
//	void sigClickedLogin();
	void sigQRLoginSuccess(QVariantMap);
	void sigProxy(NetWorkProxyInfo);
private:
	Ui::ScanQRWidget *ui;
	/*实现无边框可拖拽*/
	bool        mMoveing;
	QPoint      mMovePosition;
	ScanShowQRWidget *pShowQRWidget;
	ScanLoginWidget  *pScanLoginWidget;
	ScanNetWorkSetWidget *pScanNetWorkSetWidget;

	IMessageBox *messageBox;
};

#endif // SCANQRWIDGET_H
