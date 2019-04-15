#pragma once

#include <QWidget>
#include <QMouseEvent>
#include "messagebox.h"
#include <QMenu>
namespace Ui {
	class RecoveryWidget;
}

class RecoveryWidget : public QWidget
{
	Q_OBJECT

public:
	RecoveryWidget(QWidget *parent = Q_NULLPTR);
	~RecoveryWidget();

	void setBTCMode();

	private slots:
	void slotSwitchStackedWidget();
	void slotClickedBtn();
#ifdef Q_OS_LINUX
    void setLinuxCenter();
#endif
protected:
	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动
	bool eventFilter(QObject *obj, QEvent *e);

private slots:
	void slotPaste();

signals:
	void sigClose();
	void sigRecoveryWord(QString);
	void sigPrivateKey(QString);

private:
	Ui::RecoveryWidget *ui;
	QMenu* m_Menu;
	QAction* m_ActPaste;


	QPoint mouse;
};
