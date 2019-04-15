#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <qmath.h>

namespace Ui { class IMessageBox; };

class IMessageBox : public QWidget
{
	Q_OBJECT

public:
	IMessageBox(QWidget *parent = Q_NULLPTR);
	~IMessageBox();

	static void tip(QWidget *parent, QString title, QString text);
	static void askTip(QWidget *parent, QString title, QString text);
	void init(QString title, QString text);
	void initAsk(QString title, QString text);
signals:
	void sigClose();
	void sigOK();
private slots:
	void slotClose();
	void slotOK();

private:
	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动

	void paintEvent(QPaintEvent * event);

private:
	Ui::IMessageBox *ui;

	QPoint mouse;
};
