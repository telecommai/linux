#ifndef PicWidget_H
#define PicWidget_H

#include <QWidget>
#include <QGraphicsView>    //视图类
#include <QGraphicsScene>   //场景类
#include <QGraphicsItem>    //图元类
#include <QLabel>
#include <QPushButton>
#include <QTimer>

#include "pixitem.h"
#include "myScene.h"
#include "myView.h"
#include "shadow.h"
#include <math.h>

namespace Ui {
	class PicWidget;
}

class PicWidget : public QWidget
{
	Q_OBJECT

public:
	explicit PicWidget(QWidget *parent = 0);
	~PicWidget();
#ifdef Q_OS_WIN
	void paintEvent(QPaintEvent * event);
#endif
	void setPath(QString strPath, QWidget * pParentWidget, int iType = 0);
	void resetPath(QString strPath);
	void setNoteTip(int iType);

    private slots:
	void onIn();            //放大图片

	void onOut();          //缩小图片

// 	void on_pbt_reset_clicked();                //重置图片
// 
// 	void on_pbt_changeImage_clicked();          //更换图片
// 
// 	void on_pbt_setZoomInState_clicked();
// 
// 	void on_pbt_setZoomOutState_clicked();

	void onSave();

	void onRotation();

	void onCopy();

	void mousePressEvent(QMouseEvent *event);        //单击
	void mouseReleaseEvent(QMouseEvent *event);      //释放
	void mouseMoveEvent(QMouseEvent *event);         //移动
	void keyPressEvent(QKeyEvent *event);
	void maxOrRstrWindow();
	void paintgif();
	QString decodeURI(QString str);
	void slotHideLabel();
private slots:
void slotShowBtn(int iType);
void slotLeft();
void slotRight();

protected:
	void closeEvent(QCloseEvent * event);
	void resizeEvent(QResizeEvent * event);
signals:
	void sigPicClose();
	void sigChangePic(int);

private:
	Ui::PicWidget *ui;
	Shadow *shadow;
	PixItem *pixItem;       //自定义的图元类
	QLabel *pLabel;
	QMovie *pMovie;
	myView *m_graphicsView;
	myScene *m_graphicsScene;  //场景
	QString m_strName;
	QString m_strPath;
	QPoint mouse;
	//QTimer* pTimer;
	bool bIsGif;
	double m_dWidth;
	double m_dHeight;
	QMenu * m_Menu;
	QAction *ActR;
	QAction *ActOut;
	QAction *ActIn;
	QAction *ActCopy;
	QAction *ActDown;
	//上一张下一张
	QPushButton * m_pLeftBtn;
	QPushButton * m_pRightBtn;
	QLabel * m_pTipLabel;
	int iShowBtn;//是否显示图片

};

#endif // PicWidget_H
