#pragma once

#include <QWidget>
#include <QMouseEvent>
#include "eosBase/eoshelp.h"
#include "messagebox.h"
namespace Ui { class EOSRecoveryWidget; };

class EOSRecoveryWidget : public QWidget
{
	Q_OBJECT

public:
	EOSRecoveryWidget(QWidget *parent = Q_NULLPTR);
	~EOSRecoveryWidget();

private:
	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动

	private slots:
	void slotEnter();

signals:
	void sigEosPubKey(QString ownerPubKey, QString ownerPriKey,
		QString activePubKey, QString activePriKey);

private:
	Ui::EOSRecoveryWidget *ui;

	QPoint mouse;
};
