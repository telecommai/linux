#ifndef CHATDATAMANAGER_H
#define CHATDATAMANAGER_H

#include <QObject>
#include "chatwidget.h"
#include "imtranstype.h"
#include "imrequestbuddyinfo.h"
#include "messagelog/messagelog.h"
#include "childWidget/transmitmessagewidget.h"

class IMPerChatView;
class IMGroupView;

class ChatDataManager : public QObject
{
	Q_OBJECT
private:
	static ChatDataManager* pThis;
public:
	bool m_isFirstShowChat;//是否是第一次打开聊天窗口
public:
	ChatDataManager(QObject *parent=NULL);
	~ChatDataManager();

	static ChatDataManager* self();

	ChatWidget *getChatWidget();

    void InsertTextEditPic(QString strPath);

	void updateBuddyHeaderImgPath(int userId,QString path);

	QString m_currentSelectedChatId;

	void RevInputting(MessageInfo);

public slots:
	//************************************
	// Method:    recvChat
	// FullName:  ChatDataManager::recvOpenChat
	// Access:    public 
	// Returns:   void
	// Qualifier: 
	// Parameter: int type
	// Parameter: QVariant message
	// Parameter: QVariant buddy
	//************************************
	void recvChat(int type, QVariant message, QVariant buddy = QVariant());


	//************************************
	// Method:    slotQuickReply
	// FullName:  ChatDataManager::slotQuickReply
	// Access:    public 
	// Returns:   void
	// Qualifier: 快捷回复接口
	// Parameter: int type openPer或者openGroup
	// Parameter: QString contactID 好友或者部落的id
	// Parameter: QString strMsg 仅支持文本信息
	//************************************
	void slotQuickReply(int type, QString contactID, QString strMsg);

	//刷新其他设备信息的槽。
	void slotRefreshDeviceInfo();

private slots:
    void slotClickedChat(QString);
	void slotCloseChat(QString);
	void slotCloseAllChat();

	void slotCloseChatQuery(QString);
	void slotCloseAllChatQuery();
	void slotAskExit();

	void slotSearchText(QString);

	void slotParseGroupBuddyInfo(QString, QList<BuddyInfo>);

	void slotUpdateMessageState(MessageInfo, int);
	void slotShowPerLog(QString buddyID);
	void slotOpenGroupLog(QString groupID);
	void slotRevOtherDeviceMsg(MessageInfo);

	void slotTransmitWidget(QString msgID);
	void slotTransmitMessage(int type, QString contactID);

	void slotShareWidget(int type, QString shareID);
	void slotShareMessage(int type, QString recvID);

	void slotTipMessage(int type, QString recvID, QString strMessage);
	

	void slotLoadGroupLogByID();
	void slotLoadPerLogByID();

	void slotDeviceInfoResult(bool success, QString result);
	//图片浏览
	void slotOpenPic(QString, QList<QString>*,QWidget *);
	void slotClosePic();
	void slotChangePic(int);

	void slotTransferMsg(QString, QString, QString);

	void slotWebEngineViewTermination(QString);

	void slotSetMsgRead(QString);

	void slotUserInputting(int);

	void slotCloseMessagelog();

	void slotContuinueClose();
private:
	IMPerChatView *getPerChat(QString uesrID);
	IMGroupView *getGroupChat(QString groupID);


	//************************************
	// Method:    RecvFileMessage
	// FullName:  ChatDataManager::RecvFileMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 接收到文件消息
	// Parameter: MessageInfo msgInfo
	// Parameter: QString Avatar
	//************************************
	void RecvFileMessage(MessageInfo msgInfo, QString Avatar);

	// Qualifier: 处理接收到的个人消息
	void OnDealPerMessage(QVariant message, QVariant info);

	// Qualifier: 处理接收到的部落消息
	void OnDealGroupMessage(QVariant message, QVariant info);

	// Qualifier: 处理接收到的打开个人消息
	void  OnDealOpenPerMessage(QVariant message);

	// Qualifier: 处理接收到的打开部落消息
	void  OnDealOpenGroupMessage(QVariant message);

	// Qualifier: 处理接收到的更新好友消息
	void  OnDealBuddyUpdateMessage(QVariant message);

	// Qualifier: 处理接收到的更新部落消息
	void OnDealGroupUpdateMessage(QVariant message);

	// Qualifier: 处理接收到的退出部落消息
	void OnDealQuitGroupMessage(QVariant message, QVariant info);

	// Qualifier: 处理接收到的部落添加用户消息
	void OnDealGroupAddUserMessage(QVariant message, QVariant info);

	//Qualifier: 设置群组禁言
	void OnDealGroupNoSpeak(QVariant id, QVariant noSpeak);

	//Qualifier: 处理收到的删除好友消息
	void OnDealBuddyDelete(QVariant message);

	QString decodeURI(QString str);

	void saveDraft(QString);
signals:
	// Qualifier: 窗口最小化
	void sigWidgetMinSize();

	// Qualifier: 还原窗口
	void sigShowNormalWindow();

	void sigDealTrayIocnFlash(QString);
	void sigMakeGroupHeader(QString);
	void sigCountMessageNum(int);

	void sigUpdateSelfMessage(bool, QVariant, QString,bool, QMap<QString, QVariant>);

	void sigShowDeviceWidget();

	void sigAddChatGroup(QString);

	void sigUpdateSelfImage(int, QPixmap);

	void sigTransferRecord(RecordInfo);

    void sigTransferWindow(QString,QString);

	void sigETHWindow(QString, QString);

	void sigBTCWindow(QString, QString);

	void sigEOSWindow(QString, QString);

	void sigHostingCharge(int, QString, QString, QString);

	void sigWebEngineViewTermination(QString);
private:
	ChatWidget *chatWidget;
	MessageListView *messageList;
	SearchList *searchList;
	QStackedWidget *stackedWidget;
	MessageLog *messageLog;

	QString m_strTmpLogId;
	//图片浏览
	PicWidget * m_pPicWidget;
	QList<QString> m_listPic;
	QList<QString>::iterator m_PicIter;
};

#endif // CHATDATAMANAGER_H
