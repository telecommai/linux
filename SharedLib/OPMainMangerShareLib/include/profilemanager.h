#ifndef PROFILEMANAGER_H
#define PROFILEMANAGER_H

#include <QObject>
#include <QMap>
#include <QVariant>
#include "imbuddy.h"
#include "opcommon.h"
class perProfileWidget;
class GroupProfileWidget;
class profilemanager : public QObject
{
	Q_OBJECT

public:
	static profilemanager* getInstance();
private:
	profilemanager(QObject *parent);
	profilemanager(const profilemanager&);
	profilemanager& operator=(const profilemanager&);
	~profilemanager();
	static profilemanager* instance;
private slots:
	//新建个人资料
	void slotCreatePerFile(QString);
	void slotCreatePerFileByInfo(BuddyInfo);
	//新建群组资料
	void slotCreateGrpFile(QString);
	void slotCreateGrpFileByInfo(GroupInfo);
	//关闭个人窗口
	void slotClosePerFile();
	//关闭群组窗口
	void slotCloseGrpFile();
	//网路获取
	void slotShareBuddyHeader(bool success);
	void slotShareBuddyInfoResult(bool success, QString result);
	void slotShareGroupHeader(bool success);
	void slotShareGroupInfoResult(bool success, QString result);
	void slotAddressInfo(AddressInfo);
signals:
	void sigCreatePerFile(QString);
	void sigCreateGrpFile(QString);
	void sigCreatePerFileByInfo(BuddyInfo);
	void sigCreateGrpFileByInfo(GroupInfo);
	void sigShareID(int, QString);
	void sigOpenPic(QString, QList<QString>*, QWidget*);
	void sigOpenChat(int, QVariant);
// signals:
// 	void sigShareID(int,QString);
private:
	QMap<QString,perProfileWidget*> mapPerFile;
	QMap<QString,GroupProfileWidget*> mapGrpFile;
};
#endif // PROFILEMANAGER_H