﻿#ifndef IMDATAMANAGERSHARELIB_H
#define IMDATAMANAGERSHARELIB_H

/*数据暂存类*/
#include "common.h"
#include <QWidget>

class IMDataManagerShareLib
{
public:
	IMDataManagerShareLib();
	~IMDataManagerShareLib();

	//************************************
	// Method:    setAppConfigInfo
	// FullName:  IMDataManagerShareLib::setAppConfigInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 设置App 配置文件信息
	// Parameter: AppConfig conf
	//************************************
	void setAppConfigInfo(AppConfig conf) { mAppConf = conf; }

	//************************************
	// Method:    getAppConfigInfo
	// FullName:  IMDataManagerShareLib::getAppConfigInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 获取App配置文件信息
	//************************************
	AppConfig getAppConfigInfo() { return mAppConf; }

	//************************************
	// Method:    setUserInfo
	// FullName:  IMDataManagerShareLib::setUserInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 设置当前用户
	// Parameter: UserInfo userInfo
	//************************************
	void setUserInfo(UserInfo userInfo);

	//************************************
	// Method:    updateUserInfo
	// FullName:  IMDataManagerShareLib::updateUserInfo
	// Access:    public 
	// Returns:   void
	// Qualifier: 更新用户信息
	//************************************
	void updateUserInfo(UserInfo userInfo);

	//************************************
	// Method:    getUserInfo
	// FullName:  IMDataManagerShareLib::getUserInfo
	// Access:    public 
	// Returns:   UserInfo
	// Qualifier: 获取用户信息
	//************************************
	UserInfo getUserInfo() { return mUserInfo; }

    //void setCurrentChatWidget(WId id);

#ifdef Q_OS_WIN
    void setCurrentChatWidget(WId id);
	HWND getCurrentChatWidget();
    WId currentChatWidget;
#endif

	void setMainWidget(QWidget *widget) { this->mainWidget = widget; }
	QWidget *getMainWidget() { return this->mainWidget; }

private:
	AppConfig mAppConf;
	UserInfo mUserInfo;

	QWidget *mainWidget;
};

#endif // IMDATAMANAGERSHARELIB_H
