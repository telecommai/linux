#ifndef QSHORTCUTWIDGET_H
#define QSHORTCUTWIDGET_H

#include <QWidget>
namespace Ui {class QShortCutWidget;};

class QShortCutWidget : public QWidget
{
	Q_OBJECT

public:
	QShortCutWidget(QWidget *parent = 0);
	~QShortCutWidget();
	void setSendMsg(int iValue);
	void setScreenCut(QString strValue);
	void setQuickOpen(QString strValue);
	void setCheckKey(int bValue);
private slots:
	void SLO_getShortCut();//创建用户定义截图快捷键窗口
	void SLO_getShortCutKey(QString);//得到用户自定义截图快捷键
	void SLO_getOpen();//创建用户定义打开星际通讯快捷键窗口
	void SLO_getOpenKey(QString);//得到用户自定义打开星际通讯快捷键
	void SLO_setToDefault();//恢复默认设置
	void SLO_onStateChanged(int);//复选框事件
	void SLO_onIndexChanged(int);//下拉框事件
	void keyPressEvent(QKeyEvent *e);
	void keyReleaseEvent(QKeyEvent *e);
	void saveKey();
signals:
	void SIG_val(int val);//用于初始化用户自定义窗口
	void sigScreenCut(QString);
	void sigQuickOpen(QString);
	void sigSendMsg(int);
	void sigCheckKey(int);
protected:
	bool eventFilter(QObject *obj, QEvent *e);
private:
	Ui::QShortCutWidget *ui;
	QString m_strScreenCut;
	QString m_strQuickOpen;
	int m_iSendMsg;
	bool m_bCheckKey;
	int iBtnFlag;
	bool m_bpressOrRelease;
};

#endif // QSHORTCUTWIDGET_H
