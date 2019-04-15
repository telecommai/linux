#ifndef MESSAGELISTDISPATCHER_H
#define MESSAGELISTDISPATCHER_H

#include <QObject>
#include <QVariant>
#include <QMap>
#include <QKeyEvent>
#include "imbuddy.h"
#include "imusermessage.h"

class MessageListStore;

class MessageListDispatcher : public QObject
{
    Q_OBJECT
private:
	static MessageListDispatcher* s_instance;
	MessageListStore* m_store;	
public:
    explicit MessageListDispatcher(QObject *parent = nullptr);
	static MessageListDispatcher* instance();
	void init();

signals:
	void sigSetMsgRead(QString strUserId);//发送设置消息已读的信号
	void sigDealTrayIocnFlash(QString strUserId);//任务栏图标处理
	void sigMessageUnreadNumChanged(int num);//全部的未读消息数量变化


	void sigUpdateMessage(bool isGroup, QVariant var);//消息列表条目内容更新消息(如头像，昵称等变化)


	void sigClickIndex(int idx);//最近消息条目单击指定index
	void sigClickItem(QString strUserId);//最近消息条目单击指定userid的条目
	void sigRightClickItem(QString strUserId);//最近消息条目右击指定userid的条目

	
	void sigInsertSelfMessage(bool isGroup, QVariant var, QString msg, bool bNeedOpen, QMap<QString, QVariant> params);//自己在电脑端发送聊天消息时触发
	void sigInsertPerToPerMessage(MessageInfo messageinfo, BuddyInfo buddyInfo, bool bChangeNum);//新的个人聊天消息到来(手机端发给个人的也会走)
	void sigInsertPerToGroupMessage(MessageInfo messageinfo, GroupInfo groupInfo, bool bChangeNum);//新的群聊天消息到来(手机端发给群的也会走)

	void sigDealPerMessageType(MessageInfo msgTmp, BuddyInfo buddyInfo);//双击打开新的个人聊天窗口时触发
	void sigDealGroupMessageType(MessageInfo msgTmp, GroupInfo groupInfo);//双击打开新的群聊天窗口时触发

	

	void sigViewKeyPressEvent(QKeyEvent *event);//VIEW里触发了key press
	void sigKeyUpDown(QKeyEvent *event);//在聊天发送窗等外部窗体触发的上下键信号


	void sigSetDraft(QString strUserId, QString strMsg);//设置草稿

	void sigCloseChat(QString strUserId);//关闭指定的聊天窗口
	void sigCloseAllChat();//关闭所有的聊天窗口
	void sigCloseChatQuery(QString strUserId);//询问是否关闭正在下载文件的
	void sigCloseAllChatQuery();
	void sigViewDetails(QString strUserId,bool isPer);//查看资料
	void sigCancleMessageTop(QString strUserId);//取消置顶
	void sigMessageTop(QString strUserId);//设置置顶
	void sigMessagePrompt(QString strUserId);//允许提示（禁用免打扰）
	void sigMessageNoPrompt(QString strUserId);//禁止提示（启用免打扰）
	void sigDissolveGroup(QString strUserId);//解散群
	void sigUserQuitGroup(QString strUserId);//退出群

	void sigCheckHttp(bool bResult, QString strResult);//解散或退出群时的HTTP请求状态检查
public slots:
	void slotClickIndex(int idx);
	void slotClickItem(QString strUserId);
	void slotRightClickItem(QString strUserId);

	void slotCloseChat(QString strUserId);
	void slotCloseAllChat();

	void slotInsertPerToPerMessage(MessageInfo messageinfo, BuddyInfo buddyInfo, bool bChangeNum);
	void slotInsertPerToGroupMessage(MessageInfo messageinfo, GroupInfo groupInfo, bool bChangeNum);

	void slotDealPerMessageType(MessageInfo msgTmp, BuddyInfo buddyInfo);
	void slotDealGroupMessageType(MessageInfo msgTmp, GroupInfo groupInfo);
	void slotUpdateMessage(bool isGroup, QVariant var);

	void slotKeyUpDown(QKeyEvent *event);
	void slotInsertSelfMessage(bool isGroup, QVariant var, QString msg, bool bNeedOpen, QMap<QString, QVariant> params);

	void slotSetDraft(QString strUserId, QString strMsg);

	void slotViewDetails(QString strUserId, bool isPer);
	void slotCancleMessageTop(QString strUserId);
	void slotMessageTop(QString strUserId);
	void slotMessagePrompt(QString strUserId);
	void slotMessageNoPrompt(QString strUserId);
	void slotDissolveGroup(QString strUserId);
	void slotUserQuitGroup(QString strUserId);

	void slotCheckHttp(bool bResult, QString strResult);
};

#endif // MESSAGELISTDISPATCHER_H