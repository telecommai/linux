#ifndef QWEBENGINEPAGEDELEGATE_H
#define QWEBENGINEPAGEDELEGATE_H

#include <QWebEnginePage>

class QWebEnginePageDelegate
{

private:
	QWebEnginePage* m_page;
	QString m_chatId;

public:
    QWebEnginePageDelegate(QWebEnginePage* page,const QString& chatId);
	~QWebEnginePageDelegate();


	void setBackgroundColor(const QColor &color);

	//void load(const QUrl &url);//禁用该函数

	void setWebChannel(QWebChannel *channel);

	void runJavaScript(const QString &scriptSource);

};

#endif // QWEBENGINEPAGEDELEGATE_H