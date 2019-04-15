#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
#include <QRectF>
#include <QMouseEvent>
#include <QPointF>
#include <QDragEnterEvent>
#include <QGraphicsSceneWheelEvent>


class myView : public QGraphicsView
{
	Q_OBJECT
public:
	void wheelEvent(QWheelEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void setGif(bool bValue);
	void translate(QPointF delta);  // 平移

	explicit myView(QWidget *parent = 0);
signals:
	void sigShowBtn(int);
private:
	bool bIsGif;
 	bool m_bMouseTranslate;  // 平移标识
 	QPoint m_lastMousePos;  // 鼠标最后按下的位置
};

#endif // PIXITEM_H
