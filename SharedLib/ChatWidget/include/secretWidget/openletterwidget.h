#pragma once

#include <QWidget>
#include <QJsonDocument>
#include "messagebox.h"
#include "opdatamanager.h"

namespace Ui {
	class OpenLetterWidget;
}

class OpenLetterWidget : public QWidget
{
	Q_OBJECT

public:
	OpenLetterWidget(QString data, QWidget *parent = Q_NULLPTR);
	~OpenLetterWidget();

	void directOpen(QString);

public slots:
	void show();

private slots:
    void slotClickedEnterBtn();

private:
	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动

signals:
	void sigClose();

private:
	Ui::OpenLetterWidget *ui;

	QPoint mouse;

	QString letter;
};
