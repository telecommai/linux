#ifndef USERPROFILEWIDGET_H
#define USERPROFILEWIDGET_H

#include <QWidget>
#include <QFile>
#include <qbitmap.h>
#include <QPushButton>
#include <QPainter>
#include <qmath.h>
#include <QMouseEvent>
#include "common.h"

namespace Ui {
	class UserProfileWidget;
}

class UserProfileWidget : public QWidget
{
	Q_OBJECT

public:
	UserProfileWidget(QWidget *parent = 0);
	~UserProfileWidget();

	//************************************
	// Method:    setUserInfo
	// FullName:  UserProfileWidget::setUserInfo
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: UserInfo
	//************************************
	void setUserInfo(UserInfo);

	//************************************
	// Method:    setHeaderImage
	// FullName:  UserProfileWidget::setHeaderImage
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: QPixmap
	//************************************
	void setHeaderImage(QPixmap);

protected:
	bool eventFilter(QObject *obj, QEvent *e);

signals:
	void sigOpenAvatarWidget();
	void sigOpenUserInfoWidget();

	void sigDisableStrangers(bool);

	private slots:
	void slotClickStrangersBtn();
	void slotClickQRcodeBtn();
	
private:
	Ui::UserProfileWidget *ui;

	QPoint mouse;  //用于窗口移动的暂存变量

	UserInfo userInfo;

	QPushButton *closeBtn;
	QPushButton *headerBtn;
	QPushButton *editBtn;
};

#endif // USERPROFILEWIDGET_H
