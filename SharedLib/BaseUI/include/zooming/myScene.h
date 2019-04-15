#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
//#include <QPixmap>
//#include <QPainter>
#include <QRectF>
#include <QMouseEvent>
#include <QPointF>
#include <QDragEnterEvent>
#include <QGraphicsSceneWheelEvent>


class myScene : public QGraphicsScene
{
public:
// 	PixItem(QPixmap *pixmap);   //构造函数初始化了变量pix
// 	QRectF boundingRect() const;    //实现自己的boundingRect 图元边界方法，完成以图元坐标系为基础增加两个像素点的冗余的工作
// 	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //重画图形函数
 	void wheelEvent(QGraphicsSceneWheelEvent *event);
// 	void setZoomState(const int &zoomState);

	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void SpWhellEvent(int iScale, int iX,int iY);

// 	int getScaleValue() const;
// 	void setScaleValue(const int &);
// 
// 	QPixmap	GetPix(){ return pix; }

private:
// 	qreal m_scaleValue;   //缩放值
// 
// 	QPixmap pix;    //作为图元显示的图片
// 	int m_zoomState;
// 
 	bool m_isMove;
	QPointF m_startPos;
};

#endif // PIXITEM_H
