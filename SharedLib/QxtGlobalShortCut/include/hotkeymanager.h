#ifndef HOTKEYMANAGER_H
#define HOTKEYMANAGER_H

#include <QObject>
class QxtGlobalShortcut;
class HotKeyManager : public QObject
{
	Q_OBJECT

public:
	HotKeyManager(QObject *parent = NULL);
	~HotKeyManager();
	//热键相关 获取和设置热键
	bool InitScreenShot();
	bool InitQuickOpen();
	void setScreenShot(QString strValue);
	void setQuickOpen(QString strValue);
	void setSendMeg(int bValue);
	void setCheckKey(int bValue);
	QString getScreenShot();
	QString getQuickOpen();
	int getSendMeg();
	int getCheckKey();
	//用户文件 更改路径
	QString getUserPath();
	void setUserPath(QString strParh);
	void ChangeNewPath();						//兼容旧版本 将exe目录下的文件拷贝到user/document
	bool copyUserDir(QString oldPath, QString newPath, bool bCover);	//更换路径
	bool DelDir(QString strPath);
	QString getUserFileSize(QString strId);					//获取用户文件大小
	void DelUserFile(QString strId);							//主动清除用户文件
	void DelTempUserFile();						//程序结束时清除剪贴板和截屏
	double getDirSize(QString strPath);
signals:
	void sigGlobalScreenShot();
	void sigQuickOpen();
private:
	QxtGlobalShortcut* m_shortcutPic;
	QxtGlobalShortcut* m_shortcutOpen;
	QString m_strScreenShot;	//截屏快捷键
	QString m_strQuickOpen;		//打开隐藏主窗口
	int m_iSend;				//发消息快捷键
	int m_iCheckKey;
	QString m_strUserPath;		//用户文件路径
	
};

#endif // HOTKEYMANAGER_H
