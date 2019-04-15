#pragma once

#include <QWidget>
#include <QMouseEvent>

namespace Ui { class ChangeNumWidget; };

class ChangeNumWidget : public QWidget
{
	Q_OBJECT

public:
	ChangeNumWidget(QWidget *parent = Q_NULLPTR);
	~ChangeNumWidget();

signals:
	void sigChangeNum(QString);

private slots:
	void slotSetChangeNum();

private:
	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动

private:
	Ui::ChangeNumWidget *ui;

	QPoint mouse;
};
