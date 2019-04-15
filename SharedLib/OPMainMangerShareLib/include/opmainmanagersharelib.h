#ifndef OPMAINMANAGERSHARELIB_H
#define OPMAINMANAGERSHARELIB_H

#include <QObject>
#include "immainwidget.h"
#include "contactsdatamanager.h"
#include "chatdatamanager.h"
#include "common.h"
#include "define.h"
#include "userprofiledatamanager.h"
#include "ewalletmanager.h"
#include "creategroupwidget.h"
#include "imaddperson.h"
#include "alphabeticalsortsharedlib.h"
#include "settings/settingswidget.h"
#include "profilemanager.h"
#include "childrenWidget/recorddetailperwidget.h"
class QxtGlobalShortcut;
class OPMainManagerShareLib : public QObject
{
	Q_OBJECT
public:
	OPMainManagerShareLib(QObject *parent);
	~OPMainManagerShareLib();

	//************************************
	// Method:    startMainWidget
	// FullName:  IMainObjectManager::startMainWidget
	// Access:    public 
	// Returns:   void
	// Qualifier:
	//************************************
	void startMainWidget(UserInfo userInfo);

	//************************************
	// Method:    RevServerMessage
	// FullName:  IMainObjectManager::RevServerMessage
	// Access:    public 
	// Returns:   void
	// Qualifier: 接收到服务器消息
	// Parameter: MessageInfo msgInfo
	//************************************
	void RevServerMessage(MessageInfo msgInfo);

	//以下是电子钱包界面调用的方法。
	void setWalletInfo(WalletInfo);

	void RevInputting(MessageInfo);

private:
	bool InitScreenShot();
	bool InitQuickOpen();
#ifndef Q_OS_WIN

    QString GetNoticeMsgType(MessageInfo);
#ifdef Q_OS_MAC
    //个人消息通知
    void MessageNoticePer(MessageInfo,BuddyInfo);
    //部落消息通知
    void MessageNoticeGroup(MessageInfo,GroupInfo);
    #endif
#endif

	public slots:
	//************************************
	// Method:    slotBuddysManager
	// FullName:  IMainObjectManager::slotBuddysManager
	// Access:    private 
	// Returns:   void
	// Qualifier:
	// Parameter: int type
	// Parameter: QVariant data
	//************************************
	void slotBuddysManager(int type, QVariant data);

	//************************************
	// Method:    slotGroupsManager
	// FullName:  IMainObjectManager::slotGroupsManager
	// Access:    private 
	// Returns:   void
	// Qualifier:
	// Parameter: int type
	// Parameter: QVariant data
	//************************************
	void slotGroupsManager(int type, QVariant data);

	//************************************
	// Method:    slotUpdateUserHeaderImg
	// FullName:  IMainObjectManager::slotUpdateUserHeaderImg
	// Access:    private 
	// Returns:   void
	// Qualifier: 更新用户头像
	// Parameter: int nUserID
	// Parameter: QPixmap pix
	//************************************
	void slotUpdateUserHeaderImg(int nUserID, QPixmap pix);

	//************************************
	// Method:    slotUpdateBuddyHeaderImg
	// FullName:  IMainObjectManager::slotUpdateBuddyHeaderImg
	// Access:    private 
	// Returns:   void
	// Qualifier: 更新好友头像
	// Parameter: int nUserID
	// Parameter: QPixmap pix
	//************************************
	//void slotUpdateBuddyHeaderImg(int nUserID, QString imgPath);
	void slotUpdateBuddyHeaderImgPath(int nUserID, QString path);

	void slotUpdateBuddyHeaderImg(int nUserID, QString imgPath);

	void slotUpdateGroupHeaderImg(int nUserID, QString imgPath);

	//************************************
	// Method:    slotUpdateGroupHeaderImg
	// FullName:  IMainObjectManager::slotUpdateGroupHeaderImg
	// Access:    private 
	// Returns:   void
	// Qualifier: 更新部落头像
	// Parameter: int nUserID
	// Parameter: QPixmap pix
	//************************************
	//void slotUpdateGroupHeaderImg(int nUserID, QPixmap pix);

	//************************************
	// Method:    slotOpenChat
	// FullName:  IMainObjectManager::slotOpenChat
	// Access:    private 
	// Returns:   void
	// Qualifier:
	// Parameter: QString userID
	//************************************
	void slotOpenChat(int type, QVariant userID);

	//************************************
	// Method:    slotUpdateInfo
	// FullName:  IMainObjectManager::slotUpdateInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 更新好友、部落信息
	// Parameter: int type
	// Parameter: QVariant var
	//************************************
	void slotUpdateInfo(int type, QVariant var);

	//************************************
	// Method:    slotUserQuitGroup
	// FullName:  IMainObjectManager::slotUserQuitGroup
	// Access:    public 
	// Returns:   void
	// Qualifier: 用户退出部落
	// Parameter: QString
	// Parameter: QString
	//************************************
	void slotUserQuitGroup(QString groupID, QString buddyID);

	//************************************
	// Method:    slotAddFriendSuccess
	// FullName:  IMainObjectManager::slotAddFriendSuccess
	// Access:    public 
	// Returns:   void
	// Qualifier: 添加好友成功
	//************************************
	void slotAddFriendSuccess(BuddyInfo buddyInfo); 

	//************************************
	// Method:    slotApplyFriend
	// FullName:  IMainObjectManager::slotApplyFriend
	// Access:    public 
	// Returns:   void
	// Qualifier: 添加好友成功
	//************************************
	void slotApplyFriend(int i, MessageInfo * = NULL);


	//************************************
	// Method:    slotAddSuccessGroup
	// FullName:  IMainObjectManager::slotAddSuccessGroup
	// Access:    public 
	// Returns:   void
	// Qualifier: 加入部落成功
	// Parameter: GroupInfo
	//************************************
	void slotAddSuccessGroup(GroupInfo);

	//************************************
	// Method:    slotAddSuccessGroupUserInfo
	// FullName:  IMainObjectManager::slotAddSuccessGroupUserInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 部落添加成员成功
	// Parameter: QString
	// Parameter: BuddyInfo
	//************************************
	void slotAddSuccessGroupUserInfo(QString, BuddyInfo);

	//************************************
	// Method:    slotInitMainWidget
	// FullName:  IMainObjectManager::slotInitMainWidget
	// Access:    public 
	// Returns:   void
	// Qualifier: 初始化主窗口
	// Parameter: UserInfo userInfo
	//************************************
	void slotInitMainWidget(UserInfo userInfo);

	void slotWidgetMinSize();

	void slotShowNormalWindow();

	void slotSettings();//设置按钮响应
	void slotSettingsClose();//设置界面关闭时

	void slotClearPath();
	void slotChangePath(QString);

	void slotShowDeviceWidget();
	void slotShowChatWidget();

	void slotUpdateSelfMessage(bool, QVariant, QString, bool, QMap<QString, QVariant>);
	//改变语言
	void slotLanguage(QString);
	void slotRestart();
public slots:
#ifndef Q_OS_WIN
    void slotSendScreenShotPic();
    #ifdef Q_OS_MAC
    void slotNotifyReplied(QString userID, QString reply);
    #endif
#endif

private slots:
	void slotAddCreateGroup();
	void slotAddChatGroup(QString buddyID);
	void slotOpenCreateGroup(QString groupID);
	void slotCloseCreateGroup();
	void slotAddPerson();
	void slotCloseAddPerson();
	void slotDormancyState(bool bState);//设置休眠状态,如果休眠，不重连。如果唤醒，重新开始重连
	void slotDeleteGroup(QString);   //删除部落
	void slotGroupNoSpeak(int, int);  //部落禁言
	void slotDeleteBuddy(int type, QVariant userID);

	void slotMakeGroupHeader(QString);

	void slotAddStranger(MessageInfo);

	void slotStrangerResult(bool, QString);
	void slotDownloadStrangerHeader(bool);

	void slotRequestGroupResult(bool, QString);
	void slotDownloadGroupHeader(bool);

	void slotTransferRecord(RecordInfo);
	void slotScreenCut(QString strValue);
	void slotSetQuickOpen(QString strValue);
	void slotSendMsg(int iValue);
	void slotCheckKey(int);

	void slotRefreshDeviceState();

	void setScreenShot(QString strValue);
	void setQuickOpen(QString strValue);

	void slotUpdateHtmlBuddyHeaderImagePath(int buddyId, QString path);
signals:
	void sigUpdateMessageState(MessageInfo, int);
	void sigSetMainWidgetStatusLabel(QString);
	void sigExit();
	void sigRevOtherDeviceMsg(MessageInfo);
    void sigClickedDock();
    void sigGlobalMouseMouse();
	void sigCancel();
	void sigCancelandDelete(QString);
	void sigGlobalScreenShot();
	void sigQuickOpen();
	void sigUpdateSelfMessage(bool, QVariant, QString, bool, QMap<QString, QVariant>);
	void sigCheckUpdate();
	void sigNetWarning(bool);
private:
	IMMainWidget *mainWidget;
	UserProfileDataManager *userProfileManager;
	ContactsDataManager *contactsManager;
	ChatDataManager *chatManager;
	EWalletManager *walletManager;
	profilemanager *m_pProFileManager;
	CreateGroupWidget *createGroupWidget;
	IMAddPerson *addPersonWidget;

	SettingsWidget * m_pSettingsWidget;
	bool m_bSShootFaild;
	bool m_bQOpenFaild;

	QxtGlobalShortcut* m_shortcutPic;
	QxtGlobalShortcut* m_shortcutOpen;
};

#endif // OPMAINMANAGERSHARELIB_H
