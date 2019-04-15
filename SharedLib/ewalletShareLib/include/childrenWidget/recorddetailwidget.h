#pragma once

#include <QWidget>
#include <QEvent>
#include "opcommon.h"

namespace Ui { class RecordDetailWidget; };

class RecordDetailWidget : public QWidget
{
	Q_OBJECT

public:
	RecordDetailWidget(QWidget *parent = Q_NULLPTR);
	~RecordDetailWidget();

	void setRecord(RecordInfo);

private:
	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动

private:
	Ui::RecordDetailWidget *ui;

	QPoint mouse;
};
