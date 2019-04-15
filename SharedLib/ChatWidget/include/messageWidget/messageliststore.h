#ifndef MESSAGELISTSTORE_H
#define MESSAGELISTSTORE_H

#include <QObject>
#include <QMap>
#include <QTimer>
#include "imusermessage.h"
#include "imbuddy.h"

class MessageListViewModel;
class MessageListDispatcher;

class MessageListStore : public QObject
{
	Q_OBJECT
private:
	static MessageListStore* s_instance;
	MessageListViewModel* m_vm;
	MessageListDispatcher* m_dispatcher;

	QTimer *m_menuTimer;

	bool backToCurrentFlag;
	QString backToCurrentID; //当前对话框进入消息标志

	QMap<QString, QString> m_lastMsgIdInfoMap;//UserId or GroupId => 最后一条消息的MsgId
	QMap<QString, QString> m_msgIdInfoMap;//MsgId=>MsgDesc
	QMap<QString, bool> m_lastMsgIdFailureInfoMap;//最后一条消息是否发送失败
private:
	QString OnDealMessageType(MessageInfo StInfo, QString& strJson, QString& strPlainText);
	void OnInsertMessage(QString strUserID, QString strPicPath, QString strNickName, QString strMsgContent, int MessageTime, QString strMessageNum, int msgTopOrder, int nType = 0, bool bHasDraft = false);
	void SetSendStatusFailure(QString buddyOrGroupId, int idx);
	QString getValidImagePath(QString imgPath, bool isPer, QString headProvider = QString());
	QString getHumanReadableChatTime(int MessageTime);
	void emitMessageUnreadNum();
	QString UpdateMsgJsonText(QString& strJson, const QString& strPlainText);
	QString UpdateMsgJsonText(const QJsonArray& jsonArr, const QString& strPlainText, QString& strRetJson);
	void OnClickPerMessage(MessageInfo messageinfo, BuddyInfo buddyInfo);
	void OnClickGroupMessage(MessageInfo messageinfo, GroupInfo groupInfo);
public:
	enum enMsgJsonType
	{
		MsgJsonText = 0,//消息普通文本显示
		MsgJsonAt,//@成员，带颜色
	};
public:
	explicit MessageListStore(QObject *parent = nullptr);
	static MessageListStore* instance();

	void init();

	void initHistory();//从数据库中读取并初始化数据,然后更新到界面显示
	QString msgJsonToDesc(QString strJson);
	void clickIndex(int idx);
	void clickItemByUserId(QString strUserId);
	void rightClickItemByUserId(QString strUserId);
	void doUpDownKeyClick(bool isUp);
	void insertPerToPerMessage(MessageInfo messageinfo, BuddyInfo buddyInfo, bool bChangeNum);
	void insertPerToGroupMessage(MessageInfo messageinfo, GroupInfo groupInfo, bool bChangeNum);
	void closeAllChat();
	void closeChat(QString strUserId);
	void dealPerMessageType(MessageInfo msgTmp, BuddyInfo buddyInfo);
	void dealGroupMessageType(MessageInfo msgTmp, GroupInfo groupInfo);
	void updateMessage(bool isGroup, QVariant var);
	void insertSelfMessage(bool isGroup, QVariant var, QString msg, bool bNeedOpen, QMap<QString, QVariant> params);
	void setDraft(QString strUserId, QString strMsg);

	void cancelMessageTop(QString strUserId);
	void setMessageTop(QString strUserId);

	void setMessagePrompt(QString strUserId);
	void cancelMessagePrompt(QString strUserId);
	void dissolveGroup(QString strUserId);
	void quitGroup(QString strUserId);
public:
	//提供外部直接调用的函数
	MessageListInfo getCurrentItemInfo();
	bool isExistUserId(QString strUserId);
signals:

	public slots :
};

#endif // MESSAGELISTSTORE_H