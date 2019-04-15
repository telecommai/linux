#ifndef RECORDDETAILPERWIDGET_H
#define RECORDDETAILPERWIDGET_H
#include <QWidget>
#include "opcommon.h"

namespace Ui { class RecordDetailPerWidget; };

class RecordDetailPerWidget : public QWidget
{
	Q_OBJECT

public:
	RecordDetailPerWidget(QWidget *parent = Q_NULLPTR);
	~RecordDetailPerWidget();

	void setRecord(RecordInfo);

private:
	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动
private:
	Ui::RecordDetailPerWidget *ui;

	QPoint mouse;
};
#endif//RECORDDETAILPERWIDGET_H