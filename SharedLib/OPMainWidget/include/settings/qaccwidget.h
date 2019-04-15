#ifndef QACCWIDGET_H
#define QACCWIDGET_H
#include<qlabel.h>
#include <QWidget>
#include"qlabelheader.h"
namespace Ui {class QAccWidget;};

class QAccWidget : public QWidget
{
	Q_OBJECT

public:
	QAccWidget(QWidget *parent = 0);
	~QAccWidget();
	void setAvatar(QString);//设置头像
	void setNickname(QString);//设置昵称
	void setId(QString);//设置id
	//void setBtnStyle();//设置按钮样式

signals:
	void sigquitLogin();

private:
	Ui::QAccWidget *ui;
};

#endif // QACCWIDGET_H
