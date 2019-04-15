#pragma once

#include <QMenu>
#include <QListWidget>
#include <QListWidgetItem>
#include <QScrollBar>
#include <QKeyEvent>
#include <QDebug>
#include "cfrientitemgroup.h"
#include "cfrientitembuddy.h"
#include "imbuddy.h"
#include "imtranstype.h"
#include "pinyin.h"

namespace Ui { class SearchList; };

class SearchList : public QListWidget
{
	Q_OBJECT

public:
	SearchList(QWidget *parent = Q_NULLPTR);
	~SearchList();

	void onInsertContacts(QList<BuddyInfo>, QList<GroupInfo>, QList<BuddyInfo> GroupbuddyList);
	void onChangeItem(QKeyEvent *);

protected:
	void keyPressEvent(QKeyEvent * event);
	void enterEvent(QEvent * event);
	void leaveEvent(QEvent * event);

	private slots:
	//************************************
	// Method:    doDoubleClickedItem
	// FullName:  GroupListWidget::doDoubleClickedItem
	// Access:    private 
	// Returns:   void
	// Qualifier: 双击点击列表
	// Parameter: QListWidgetItem * item
	//************************************
	void slotDoubleClickedItem(QListWidgetItem *item);
signals:

	void sigOpenChat(int type, QVariant strID);

private:
	Ui::SearchList *ui;
};
