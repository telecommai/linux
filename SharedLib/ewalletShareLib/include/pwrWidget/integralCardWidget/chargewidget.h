#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QDoubleValidator>
#include <QStyledItemDelegate>
namespace Ui { class ChargeWidget; };

class ChargeWidget : public QWidget
{
	Q_OBJECT

public:
	ChargeWidget(QWidget *parent = Q_NULLPTR);
	~ChargeWidget();

private:
	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动

private:
	Ui::ChargeWidget *ui;

	QPoint mouse;
};
