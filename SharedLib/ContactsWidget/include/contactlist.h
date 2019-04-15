#ifndef CONTACTSLIST_H
#define CONTACTSLIST_H

#include <QListWidget>
#include <QListWidgetItem>
#include <QScrollBar>
#include <QKeyEvent>
#include <QMenu>
#include <QDebug>
#include <qquickwidget.h>
#include "imbuddy.h"
#include "imtranstype.h"
#include "cfrientitembuddy.h"
#include "stdafx.h"
#include "messagebox.h"

#include "ContactListModel.h"
#include "ImgProvider.h"


#define HEAD "head"
#define ITEM "item"
#define NOTE "note"

class ContactList : public QQuickWidget
{
	Q_OBJECT

public:
	ContactListModel* m_pCntlistModel;
	ContactList(QWidget *parent = NULL);
	~ContactList();

	void doUpDownKeyClick(bool isUp);

	//好友信息添加到MODEL列表
	void OnInsertContactsInfo(BuddyInfo buddyInfo);
	//更新信息
	void OnUpdateBuddyInfo(BuddyInfo buddyInfo);
	//更新头像
	void UpdateBuddyImage(QString userID, QString imgPath);
	//删除好友
	void deleteFriend(QString userID);
	//判断头像是否可用
	bool IsValidImage(QString imgPath);

	int getCurrentIndex();
	void setCurrentIndex(int index);
	void showEvent(QShowEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void setUpdateIndexFlag(bool bVal);


	Q_INVOKABLE void doClickItem(QString userId);
	Q_INVOKABLE void doDoubleClickItem(QString userId);
	Q_INVOKABLE void doRightClickItem(QString userId);
protected:
	void keyPressEvent(QKeyEvent * event);
private:
	bool OnJudgeIsListTitle(QString strTitle);
	void OnInsertContactsofIndex(BuddyInfo info, int nIndex, int nHeight = 62);
	void changeStyle(QString styleName);

	QTimer *m_menuTimer;
	bool setCurrIndexFlag;
	bool updateIndexFlag;
	int currIndex;

private slots:
	void slotUpdateBuddyInfo(BuddyInfo buddyInfo);
	void slotDeleteBuddy();
	void slotCheckHttp(bool bSuccess, QString strValue);
	void slotConChangeFoucs();
	void slotDoDeleteBuddy();
	void slotNewFriendItemClicked();
signals:
	void sigPerChat(int type, QVariant strBuddyID);
	void sigProfile(QString strBuddyID);
	void sigChangeFoucs();
	void sigDefaultSelectedId(QString userId);
	void sigCanclePerProfileWid();
};

#endif // CONTACTSLIST_H
