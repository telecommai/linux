﻿#ifndef NOTICEWIDGET_H
#define NOTICEWIDGET_H
#include <QWidget>
#include <QMap>
namespace Ui { class NoticeWidget; };
class QLineEdit;
class NoticeWidget : public QWidget
{
	Q_OBJECT

public:
	NoticeWidget(QString strUserId,QWidget *parent = Q_NULLPTR);
	~NoticeWidget();
    void setLinuxCenter();
	public slots:
	void show();

private:
	bool eventFilter(QObject *obj, QEvent *event);

	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动
private slots:
	void slotSend();
signals:
	void sigSendNotice(QMap<QString, QString>);
private:
	Ui::NoticeWidget *ui;
	QLineEdit* m_pNameLabel;
	QPoint mouse;
	QString m_strPath;
};
#endif
