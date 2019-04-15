#ifndef QSETKEYWIDGET_H
#define QSETKEYWIDGET_H


#include <QWidget>
#include <QKeyEvent>
#include <QCloseEvent>
namespace Ui {class QSetKeyWidget;};
class Shadow;
class QSetKeyWidget : public QWidget
{
	Q_OBJECT
public:
	QSetKeyWidget(QWidget *parent = 0);
	~QSetKeyWidget();
	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动
	void setDistinct(int iValue);
	void setShortCut(QString strValue);
	void changeEvent(QEvent * event);
	void moveEvent(QMoveEvent *event);
	void resizeEvent(QResizeEvent* event);
private:
	Ui::QSetKeyWidget *ui;
	void keyPressEvent(QKeyEvent  *event);
	void keyReleaseEvent(QKeyEvent  *event);
	QPoint mouse;
	int distinct;//区分用户进入哪个自定义快捷键窗口
	Shadow *shadow;
	bool pressOrRelease;
signals:
	void SIG_sendKey_1(QString);//用户自定义截图快捷键信号
	void SIG_sendKey_2(QString);//用户自定义打开星际通讯快捷键信号
public slots:
	void show();
private slots:
	void SLO_confirm();
	void SLO_cancel();
};

#endif // QSETKEYWIDGET_H
