#ifndef QGENERALWIDGET_H
#define QGENERALWIDGET_H

#include <QWidget>
namespace Ui {class QGeneralWidget;};

class QGeneralWidget : public QWidget
{
	Q_OBJECT

public:
	QGeneralWidget(QWidget *parent = 0);
	~QGeneralWidget();
	void setClearText(QString strValue);//设置清空聊天记录按钮上的文本
	void setUserPath(QString strValue);//设置清空聊天记录按钮上的文本
	void setLanguage(QString strValue);//设置语言
	//void setStyle();//设置样式
private slots:
	void SLO_openFile();//打开当前文件夹
	void SLO_changePath();//选择新文件夹
	void SLO_clear();//清空浏览记录
	void slotLanguage(int);//选择语言
	void slotSendLang();
	void slotCancelLang();
	void slotChangePath();
	void slotRevert();
signals:
	void sigChangePath(QString);
	void sigClearPath();
	void sigLanguage(QString);
private:
	Ui::QGeneralWidget *ui;
	QString m_strPath;

	QString currentLanguage;
};

#endif // QGENERALWIDGET_H
