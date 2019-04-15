#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QMouseEvent>
#include <QPainter>
#include <qmath.h>

namespace Ui { class InputBox; };

class InputBox : public QWidget
{
	Q_OBJECT

public:
	InputBox(QWidget *parent = Q_NULLPTR);
	~InputBox();

	//isNumber标识是否是数字，输入模式主要用于区分是否是密码
	static void tip(QWidget *parent, QString content, bool isNumber = false, QLineEdit::EchoMode mode = QLineEdit::Normal);

	//isNumber标识是否是数字，输入模式主要用于区分是否是密码
	void init(QString content, bool isNumber = false, QLineEdit::EchoMode mode = QLineEdit::Normal);

	QVariant getData(){ return data; };
	void setData(QVariant map) { this->data = map; };

	void setLineText(QString strValue, QString strBack = "");

	void setEmpty(bool bVal);

	void setEditFoucs();

signals:
	void sigClose();
	void sigEnter(QString);

	private slots:
	void slotEnter();
	void slotClose();

private:
	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动

	void paintEvent(QPaintEvent * event);

private:
	Ui::InputBox *ui;

	QPoint mouse;

	QVariant data;

	bool m_bEmpty;
};
