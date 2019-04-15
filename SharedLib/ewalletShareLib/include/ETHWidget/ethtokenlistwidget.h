#pragma once

#include <QWidget>
#include <QDir>
#include <QMouseEvent>
#include <QListWidgetItem>
#include "opcommon.h"
#include "httpnetworksharelib.h"
#include "ewalletItem/ewalletitemchecked.h"
namespace Ui { class ETHTokenListWidget; };

class ETHTokenListWidget : public QWidget
{
	Q_OBJECT

public:
	ETHTokenListWidget(QWidget *parent = Q_NULLPTR);
	~ETHTokenListWidget();

public slots:
	void slotSetToken(QList<TokenInfo> tokenList);

private slots:
    void slotInsertTokenItem();
	void slotDownloadTokenIcon(bool success);
	void slotClickToken(QListWidgetItem *);
	//void 

signals:
	void sigSelectToken(QString name, QString address, QString tokenID);

private:
	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动

private:
	Ui::ETHTokenListWidget *ui;

	QList<TokenInfo> tokens;

	QPoint mouse;
};
