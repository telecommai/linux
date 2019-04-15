#ifndef ABOUTWIDGET_H
#define ABOUTWIDGET_H

#include <QWidget>
#include <qpainter.h>
#include <qevent.h>
#include <qmath.h>

namespace Ui {
	class AboutWidget;
}

class AboutWidget : public QWidget
{
	Q_OBJECT

public:
	AboutWidget(QWidget *parent = 0);
	~AboutWidget();

	void setName(QString);
	void setNumber(QString);

protected:
	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动
	void paintEvent(QPaintEvent * event);
private:
	Ui::AboutWidget *ui;
	QPoint mouse;
};

#endif // ABOUTWIDGET_H
