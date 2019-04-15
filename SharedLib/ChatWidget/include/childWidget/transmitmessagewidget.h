#pragma once

#include <QWidget>
#include <QEvent>
#include <QMoveEvent>
#include <QListWidgetItem>
#include "shadow.h"
#include "stdafx.h"
#include "imtranstype.h"
#include "messagebox.h"
#include "pinyin.h"
#include "cfrientstylewidget.h"
namespace Ui { class TransmitMessageWidget; };

class TransmitMessageWidget : public QWidget
{
	Q_OBJECT

public:
	TransmitMessageWidget(QWidget *parent = Q_NULLPTR);
	~TransmitMessageWidget();

	void init();

	void setData(QVariant var) { this->data = var;  }
    QVariant getData() { return this->data; }

#ifdef Q_OS_LINUX
    void setLinuxCenter();
#endif

public slots:
	void show();

protected:
	void changeEvent(QEvent * event);
	void moveEvent(QMoveEvent *event);
	void resizeEvent(QResizeEvent* event);
	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动

	bool eventFilter(QObject *obj, QEvent *e);//事件过滤器

private slots:
    void slotSwitchBuddyTab();
	void slotSwitchGroupTab();

	void slotClickSearchItem(QListWidgetItem *);
	void slotClickMessageItem(QListWidgetItem *);
	void slotClickBuddyItem(QListWidgetItem *);
	void slotClickGroupItem(QListWidgetItem *);

	void slotDBClickSearchItem(QListWidgetItem *);
	void slotDBClickMessageItem(QListWidgetItem *);
	void slotDBClickBuddyItem(QListWidgetItem *);
	void slotDBClickGroupItem(QListWidgetItem *);

	void slotEditSearchLine(QString);
	

	void slotEnter();

signals:
	void sigTransmitContact(int type, QString contactID);

private:
	void doListCancelSelected(QListWidget *);
	void onInsertSearchResult(QList<BuddyInfo>, QList<GroupInfo>);
	


private:
	Ui::TransmitMessageWidget *ui;

	Shadow *shadow;
	QPoint mouse;

	QVariant data;

	int type;
	QString contactID;
};
