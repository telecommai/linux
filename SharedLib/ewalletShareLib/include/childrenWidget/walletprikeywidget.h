#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QClipboard>

namespace Ui { class WalletPriKeyWidget; };

class WalletPriKeyWidget : public QWidget
{
	Q_OBJECT

public:
	WalletPriKeyWidget(QWidget *parent = Q_NULLPTR);
	~WalletPriKeyWidget();


	void setPriKey(QString);

	private slots:
	void slotCopy();

private:
	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动

private:
	Ui::WalletPriKeyWidget *ui;

	QPoint mouse;
};
