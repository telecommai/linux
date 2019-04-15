#ifndef ZOOMIMG_H
#define ZOOMIMG_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>

namespace Ui { class ZoomImg; };

class ZoomImg : public QWidget
{
	Q_OBJECT

public:
	ZoomImg(QWidget *parent = 0);
	~ZoomImg();
	void OpenImg(QString filePath);
	void OpenImg(QPixmap image);
	QString decodeURI(QString str);
protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
private:
	Ui::ZoomImg *ui;
	//QImage *image;
	//QGraphicsView *graphicsView;
	QLabel* label;
	QPushButton *myButton;
	/*实现无边框可拖拽*/
	bool        mMoveing;
	QPoint      mMovePosition;
};

#endif // ZOOMIMG_H
