#ifndef QGROUPQR_H
#define QGROUPQR_H

#include <QWidget>
#include <QPushButton>
#include "qlabelheader.h"
#include "shadow.h"
namespace Ui {class QGroupQR;};

class QGroupQR : public QWidget
{
	Q_OBJECT

public:
	QGroupQR(QWidget *parent = 0);
	~QGroupQR();

	void changeEvent(QEvent * event);
	void moveEvent(QMoveEvent *event);
	void resizeEvent(QResizeEvent* event);

	void OpenImg(QPixmap img);
	void OnSetPicPath(QPixmap pix, int nType = 0);
	void SetNickName(QString strValue);
	void SetIDLabel(QString strValue);
    void setLinuxCenter();
	void setNoteText(QString);
protected:
	virtual void mousePressEvent(QMouseEvent *event);
	virtual void mouseMoveEvent(QMouseEvent *event);
	virtual void mouseReleaseEvent(QMouseEvent *event);
public slots:
	void show();
private:
	Ui::QGroupQR *ui;
// 	QLabelHeader * m_pHeader;
// 	QLabel * m_pGroupName;
// 	QLabel * m_QRLabel;
// 	QLabel * m_pNote;
	//关闭拖拽相关
	QPushButton *myButton;
	Shadow *shadow;
	bool        mMoveing;
	QPoint      mMovePosition;
};

#endif // QGROUPQR_H
