#ifndef QWEBENGINEVIEWMANAGER_H
#define QWEBENGINEVIEWMANAGER_H

#include <QWebEngineView>
#include <QWebChannel>
#include <webobjectsharelib.h>


#define MAX_ALLOWED_QTWEBENGINEPROCESS_NUM 1  //最大允许的QtWebEngineProcess.exe数量

class QWebEngineViewDelegate;

class QWebEngineViewManager : QObject
{
	Q_OBJECT
public:
	struct settingsStu
	{
		bool isSetWebChannel;
		bool isSetBackgroundColor;
		bool isLoadChatManager;//是否加载过ChatManager.html？
		bool isLoadChatManagerFinished;//是否加载ChatManager.html完成了
		QMap<QString, bool> isChatIFrameLoadFinished;

		QWebChannel * bindWebChannel;
		WebObjectShareLib * bindChatManagerObject;

		settingsStu()
		{
			isSetWebChannel = isSetBackgroundColor = isLoadChatManager = isLoadChatManagerFinished = false;

			bindWebChannel = NULL;
			bindChatManagerObject = NULL;
		}

		~settingsStu()
		{
			bindChatManagerObject->deleteLater();
			bindWebChannel->deleteLater();

			bindWebChannel = NULL;
			bindChatManagerObject = NULL;
		}
	};

	QMap<QWebEnginePage*, settingsStu> m_settingFlagsMap;//QWebEnginePage是否已经设置过
private:
	//默认构造和拷贝构造都需要是private
	QWebEngineViewManager();
	QWebEngineViewManager(const QWebEngineViewManager& other);

	struct webEngineStu
	{
		QWebEngineView* engine;
		QSet<QString> chatIds;
	};

	QVector<webEngineStu> m_engineStuVec;

	QWebEngineView* generateWebEngineView();

    void removeWebEngineView(int i);
public:
	~QWebEngineViewManager();

	static QWebEngineViewManager* instance();

	QWebEngineView* addChatWindow(const QString& chatId);
	void removeChatWindow(const QString& chatId);

private slots:
	void slotWebViewRenderProcessTerminated(QWebEnginePage::RenderProcessTerminationStatus terminationStatus, int exitCode);

signals:
	void renderProcessTerminated(QWebEnginePage::RenderProcessTerminationStatus terminationStatus, int exitCode);

};

#endif // QWEBENGINEVIEWMANAGER_H
