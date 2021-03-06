﻿#ifndef VLCWIDGET_H
#define VLCWIDGET_H

#ifdef Q_OS_WIN
#include <Windows.h>
#endif
#include <QWidget>
#include <qtimer.h>
#include <qdesktopwidget.h>
#include <QMouseEvent>
#include <QTime>
#include "videowidget.h"

namespace Ui { class IMVideoPlayer; };

class IMVideoPlayer : public QWidget
{
	Q_OBJECT

public:
	IMVideoPlayer(QWidget *parent = 0);
	~IMVideoPlayer();

	void videoPlay(QString mediaPath);

protected:
	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseDoubleClickEvent(QMouseEvent *event);  //双击
	void mouseMoveEvent(QMouseEvent *event);         //移动

private:
	Ui::IMVideoPlayer *ui;

	QString address;
	QTimer *initTimer;
	QTimer *playTimer;
	QSize originSize;
	bool isPlaying;
	int duration;
	QPoint mouse;

	QPixmap closeImg;
	QPixmap playImg;
	QPixmap pauseImg;

	void setProgress();

signals:
	void sigClose();

public slots:
    void sizeInitSlot();
	void playPauseSlot();
	void stepSliderSlot();
	void setSliderSlot(int);
	void slotSetPositionChanged(qint64);
};

#endif // VLCWIDGET_H
