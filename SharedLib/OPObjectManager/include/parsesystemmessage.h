#ifndef PARSESYSTEMMESSAGE_H
#define PARSESYSTEMMESSAGE_H

#include <QObject>
#include "stdafx.h"
#include "alphabeticalsortsharedlib.h"
#include "imdownloadheaderimg.h"
#include "opcommon.h"
/*解析系统消息*/

class ParseSystemMessage : public QObject
{
	Q_OBJECT

public:
	ParseSystemMessage(QObject *parent = 0);
	~ParseSystemMessage();

	//************************************
	// Method:    ParseSystemMessage
	// FullName:  ParseSystemMessage::ParseSystemMessage
	// Access:    public 
	// Returns:   void
	// Qualifier: 解析系统消息
	// Parameter: MessageInfo messageInfo
	//************************************
	void ParseSysMessage(MessageInfo messageInfo);

private:
	//************************************
	// Method:    GetExeDir
	// FullName:  ParseSystemMessage::GetExeDir
	// Access:    private 
	// Returns:   QT_NAMESPACE::QString
	// Qualifier: 获取程序运行路径
	//************************************
	QString GetExeDir();

	//************************************
	// Method:    OnDealUpUser
	// FullName:  ParseSystemMessage::OnDealUpUser
	// Access:    private 
	// Returns:   void
	// Qualifier: 处理更新好友信息
	// Parameter: QVariantMap mapResult
	//************************************
	void OnDealUpDateUser(MessageInfo msgInfo, QVariantMap mapResult);

	//************************************
	// Method:    OnDealupdateFriend
	// FullName:  ParseSystemMessage::OnDealUpUser
	// Access:    private 
	// Returns:   void
	// Qualifier: 处理更新好友信息
	// Parameter: QVariantMap mapResult
	//************************************
	void OnDealUpDateFriend(MessageInfo msgInfo, QString userID);

	//************************************
	// Method:    onDealUpdateOwnerNoteInGroup
	// FullName:  ParseSystemMessage::onDealUpdateOwnerNoteInGroup
	// Access:    private 
	// Returns:   void
	// Qualifier: 处理更新好友信息
	// Parameter: QVariantMap mapResult
	//************************************
	void onDealUpdateOwnerNoteInGroup(QVariantMap mapResult);

	//************************************
	// Method:    OnDealUpdateGroupInfo
	// FullName:  ParseSystemMessage::OnDealUpdateGroupInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 更新部落信息
	// Parameter: GroupInfo groupInfo
	//************************************
	void OnDealUpdateGroupInfo(QVariantMap mapResult);

	//************************************
	// Method:    OnDealUserQuitGroup
	// FullName:  ParseSystemMessage::OnDealUserQuitGroup
	// Access:    private 
	// Returns:   void
	// Qualifier: 处理用户退出部落
	// Parameter: QVariantMap mapResult
	//************************************
	void OnDealUserQuitGroup(QVariantMap mapResult);

	//************************************
	// Method:    OnDealAddFriend
	// FullName:  ParseSystemMessage::OnDealAddFriend
	// Access:    private 
	// Returns:   void 
	// Qualifier: 添加好友
	// Parameter: QVariantMap result
	//************************************
	void OnDealAddFriend(QVariantMap result);

	//************************************
	// Method:    OnDealAddUserToGroup
	// FullName:  ParseSystemMessage::OnDealAddUserToGroup
	// Access:    private 
	// Returns:   void
	// Qualifier: 申请加入部落成功
	// Parameter: QVariantMap result
	//************************************
	void OnDealAddUserToGroup(QVariantMap result);

	//解散部落
	void OnDealDisSolveGroup(QVariantMap result);

	void OnDealGroupNoSpeak(QVariantMap result);
	void OnDealUpdateGroupType(QVariantMap result);
	void OnDealUpdateGroupDesc(QVariantMap result);
	void OnDealUpdateGroupKey(QVariantMap result);
	void OnDealApplyFriend(QVariantMap result,QString strMegId);//处理好友申请
	void OnDealApplyGroup(QVariantMap result, QString strMegId);//处理加群申请
	void OnDealRejectFriend(QVariantMap result, QString strMegId);
	void OnDealRejectGroup(QVariantMap result, QString strMegId);
	private slots:
	void slotRequestPersonInfoFinished(bool bResult, QString result);
	void slotRequestGroupInfoFinished(bool bResult, QString result);
	void slotRecvAddGroupUser(bool success, QString data);
	void slotUpdateBuddyHeaderImage(int buddyID, QPixmap pix);
	void slotUpdateGroupHeaderImage(int buddyID, QPixmap pix);
	void slotTempFriend(bool bSuc, QString strValue);
	void slotInsertAddressInfo(AddressInfo);
signals:
	//************************************
	// Method:    sigDeviceLogout
	// FullName:  ParseSystemMessage::sigDeviceLogout
	// Access:    private 
	// Returns:   void
	// Qualifier: 下线操作
	//************************************
	void sigDeviceLogout();
	//************************************
	// Method:    sigRefreshDeviceState
	// FullName:  ParseSystemMessage::sigRefreshDeviceState
	// Access:    private 
	// Returns:   void
	// Qualifier: 刷新设备状态
	//************************************
	void sigRefreshDeviceState();
	//************************************
	// Method:    sigUpdateUserInfo
	// FullName:  ParseSystemMessage::sigUpdateUserInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 更新用户信息
	// Parameter: UserInfo userInfo
	//************************************
	void sigUpdateUserInfo(UserInfo userInfo);

	//************************************
	// Method:    sigUpdateBuddyInfo
	// FullName:  ParseSystemMessage::sigUpdateBuddyInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: 更新好友信息
	// Parameter: BuddyInfo
	//************************************
	void sigUpdateInfo(int,QVariant);

	//************************************
	// Method:    sigAddFriendSuccess
	// FullName:  ParseSystemMessage::sigAddFriendSuccess
	// Access:    private 
	// Returns:   void
	// Qualifier: 添加好友成功
	//************************************
	void sigAddFriendSuccess(BuddyInfo);

	//************************************
	// Method:    sigApplyFriend
	// FullName:  ParseSystemMessage::sigApplyFriend
	// Access:    private 
	// Returns:   void
	// Qualifier: 收到好友申请
	//************************************
	void sigApplyFriend(int, MessageInfo *messageInfo = NULL);

	//************************************
	// Method:    sigAddSuccessGroup
	// FullName:  ParseSystemMessage::sigAddSuccessGroup
	// Access:    private 
	// Returns:   void
	// Qualifier: 添加部落成功
	// Parameter: GroupInfo
	//************************************
	void sigAddSuccessGroup(GroupInfo);

	//************************************
	// Method:    sigAddSuccessGroupUserInfo
	// FullName:  ParseSystemMessage::sigAddSuccessGroupUserInfo
	// Access:    private 
	// Returns:   void
	// Qualifier: /*部落添加成员成功*/
	// Parameter: QString strMap 包含groupID和manaID
	// Parameter: BuddyInfo buddy
	//************************************
	void sigAddSuccessGroupUserInfo(QString strMsg, BuddyInfo buddy);

	//************************************
	// Method:    sigUserQuitGroup
	// FullName:  ParseSystemMessage::sigUserQuitGroup
	// Access:    private 
	// Returns:   void
	// Qualifier: 用户退出部落消息
	// Parameter: QString groupID
	// Parameter: QString userID
	//************************************
	void sigUserQuitGroup(QString groupID, QString userID);

	void sigDeleteFriend(int type, QVariant userID);

	// Qualifier: 删除部落
	void sigDeleteGroup(QString groupID);

	void sigGroupNoSpeak(int groupID, int noSpeak);

private:
	AlphabeticalSortSharedLib mAlphabeticalSort;   //根据汉字返回首字母拼音
};

#endif // PARSESYSTEMMESSAGE_H
