#ifndef OPOBJECTMANAGER_H
#define OPOBJECTMANAGER_H

#include <QObject>
#include <qtranslator.h>
#include <qsharedmemory.h>
#include "imrequestbuddyinfo.h"
#include "imsocketmessageinfo.h"
#include "opwindowsmanagersharelib.h"
#include "parsesystemmessage.h"
#include "updatesharelib.h"
#include "getdeviceinfo.h"
#ifdef Q_OS_WIN
#include "qhttpserver.h"
#include "dump.h"
#endif
class OPObjectManager : public QObject
{
	Q_OBJECT
public:
	OPObjectManager(QObject *parent = NULL);
	~OPObjectManager();

	// Qualifier: 更新方法
	void update();

	// Qualifier: 读取配置信息
	AppConfig readAppConf();

	// Qualifier: 启动LoginWidget
	void StartLoginWidget();

	// Qualifier: 初始化程序
	void InitApp();
	
	// Qualifier: 根据程序收到的系统参数分别进行处理。
	int InitMain();
	//Qualifier: 初始化语言（加载翻译文件）
	void initLanguage();
	
private:
	// Qualifier: 设置代理、检测更新,
	void initUpdate(bool doUpdate=true);

	// Qualifier: 注册信号类型
	void RegisterMetaType();

	//Qualifier: 初始化日志信息
	void installTranslator(QString qmPath);

	// Qualifier: 初始化日志信息
	void InitLog();

	// Qualifier: 日志信息
	//void LogInfo(QtMsgType type, const QMessageLogContext &context, const QString &msg);

	// Qualifier: 请求个人信息
	void RequestPersonInfo();

	// Qualifier: 请求好友信息
	void RequestBuddyInfo();

	// Qualifier: 请求部落信息
	void RequestGroupInfo();

	// Qualifier: 连接socket
	void ConnectSocketServer();

	// Qualifier: 判断是否请求好友信息
	void InitBuddyInfo();

	// Qualifier: 判断是否请求部落信息
	void InitGroupInfo();

	// Qualifier: 加载好友信息
	void LoadBuddyInfo();

	// Qualifier: 加载部落信息
	void LoadGroupInfo();

	// Qualifier: 解析从服务器返回给的个人信息
	UserInfo ParseUserInfoFromServer(QVariantMap varMap);

	//发送请求通知服务器下线的方法。
	void requestOffline();

	//加载RCC资源
	void loadRccResource();

private slots:
    // Qualifier: 已启动程序的情况下，重启的槽。
    void slotRestartMain();

	// Qualifier: 启动程序的槽。
	void slotStart();

	// Qualifier: 登陆成功
	void slotLoginSuccess(QVariantMap varMap);

	// Qualifier: 解析个人信息成功
	void slotParsePersonInfo(bool bResult, UserInfo userInfo);

	//Qualifier: 接收到系统消息
	void slotRevSystemMessage(MessageInfo);

	//Qualifier: 接收到消息
	void slotRevMsgInfo(MessageInfo, int);

	//Qualifier: 接收到消息
	//void slotRevUpdateMessageState(MessageInfo, int);

	//Qualifier: 获取socket信息失败
	void slotGetSocketAddressErro(QString);

	//Qualifier: 连接socket成功
	void slotConnectSocketSuccess();

	//Qualifier:重连socket成功
	void slotReConnectSuccess();

	void slotExit();

	//读取基地地址成功后，加载好友和部落信息。
	void slotInitBuddyGroup();

	//处理httpserver的消息。
	void slotGetGroupByKey(QString);

	void slotApplyGroup(bool, QString);

	void slotCancel();//登出

	void slotGlobalScreenShot();//全局截图方法。

	void slotCancelandDelete(QString);

	void slotCheckUpdate();//更新

	void slotInputting(MessageInfo);//正在输入          

	void slotInsertLocalFileTable(QByteArray, QString, QString);//插入文件信息表

	void slotDisConnectServerServer(QString);

	void slotThemeSwitch(QString);

#ifndef Q_OS_WIN
    void slotScreenCanclePixMap();
    void slotSendScreenShotPic();
#endif
signals:
	void sigReConnectServerSuccess(QString msg);

	void sigOpenChat(int, QVariant);

	void sigUpdateBuddyInfo(BuddyInfo buddyInfo);

    void sigClickedDock();

    void sigGlobalMouseMouse();

	void sigRestart();

#ifndef Q_OS_WIN
    void sigSendScreenShotPic();
#endif
private:
	OPWindowsManagerShareLib *mWindowManager;
	ParseSystemMessage *sysMessage;
	bool m_bChecking;
#ifdef Q_OS_WIN
	QHttpServer *mHttpServer;
	QSharedMemory shareMem;
#endif
};

#endif // OPOBJECTMANAGER_H
