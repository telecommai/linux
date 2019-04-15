#ifndef IMMAINWIDGET_H
#define IMMAINWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QMenu>
//#include <QSystemTrayIcon>
#include <QTimer>
#include <QDesktopWidget>
#include <QButtonGroup>
#include <qrect.h>

#include "FunctionWidget.h"
#include "imusermessage.h"
#include "netwarningwidget.h"

#ifdef Q_OS_WIN
#include <windows.h>
#else
#include <qsystemtrayicon.h>
#endif

#ifndef Q_OS_WIN
#ifdef Q_OS_MACOS
#include <IOKit/pwr_mgt/IOPMLib.h>
#include <IOKit/IOMessage.h>
#endif
#include "xsystraymeauaction.h"
#include <QWidgetAction>

enum CursorPos{ Default, Right, Left, Bottom, Top, TopRight, TopLeft, BottomRight, BottomLeft };
struct pressWindowsState
{
    bool    MousePressed;
    bool   IsPressBorder;
    QPoint  MousePos;
    QPoint  WindowPos;
    QSize PressedSize;
};
#endif

#ifdef Q_OS_WIN
#include "CSysTrayIcon.h"
#endif

namespace Ui {
    class IMMainWidget;
}

#ifndef GET_X_LPARAM
#define GET_X_LPARAM(lp)                        ((int)(short)LOWORD(lp))
#endif  // GET_X_LPARAM
#ifndef GET_Y_LPARAM
#define GET_Y_LPARAM(lp)                        ((int)(short)HIWORD(lp))
#endif  // GET_Y_LPARAM

class Shadow;
class AboutWidget;
class MenuWidget;

class IMMainWidget : public QWidget
{
    Q_OBJECT

public:
    IMMainWidget(QWidget *parent = 0);
    ~IMMainWidget();

    static IMMainWidget* self();

    //************************************
    // Method:    setNikeName
    // FullName:  IMMainWidget::setNikeName
    // Access:    public
    // Returns:   void
    // Qualifier: 设置用户名
    // Parameter: QString nickName
    //************************************
    void setNikeName(QString nickName);

    //************************************
    // Method:    setNikeName
    // FullName:  IMMainWidget::setNikeName
    // Access:    public
    // Returns:   void
    // Qualifier: 设置用户头像
    // Parameter: QString nickName
    //************************************
    void setHeaderImage(QPixmap headerImage);

    //************************************
    // Method:    addWidget
    // FullName:  IMMainWidget::addWidget
    // Access:    public
    // Returns:   void
    // Qualifier:
    // Parameter: QWidget *
    //************************************
    void addWidget(QWidget *);

    //************************************
    // Method:    setCurrentWidget
    // FullName:  IMMainWidget::setCurrentWidget
    // Access:    public
    // Returns:   void
    // Qualifier:
    // Parameter: int
    //************************************
    void setCurrentWidget(int);

    //************************************
    // Method:    setAppVersion
    // FullName:  IMMainWidget::setAppVersion
    // Access:    public
    // Returns:   void
    // Qualifier: 设置应用版本号
    // Parameter: QString version
    //************************************
    void setAppVersion(QString version);

    //************************************
    // Method:    setAppName
    // FullName:  IMMainWidget::setAppName
    // Access:    public
    // Returns:   void
    // Qualifier: 设置应用中文程序名
    // Parameter: QString name
    //************************************
    void setAppName(QString name);

    void StartMessageFlash(int type, QString imagePath, MessageInfo *messageInfo);  //开始闪动
    void StopMessageFlash();   //停止闪动

#ifdef Q_OS_MACOS
    int registerForSystemSleep();
    void deregisterForSystemSleep();
    static void handleSleepCallBack( void * refCon, io_service_t service,natural_t messageType, void * messageArgument);
    void DealMacSystemSleep();
    void DealMacSystemPowerOn();

    void onNotifyClicked(const QString& userID);
    void onNotifyReplied(const QString& userID, const QString &reply);

    void NotifyNotice(QString title,QString userID,QString strMsg);
#endif
protected:

    void paintEvent(QPaintEvent * event);
    void moveEvent(QMoveEvent *event);
    void resizeEvent(QResizeEvent* event);
    void changeEvent(QEvent * event);
	void showEvent(QShowEvent * event);
    void closeEvent(QCloseEvent * event);
    bool eventFilter(QObject *obj, QEvent *e);
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);

#ifndef Q_OS_WIN
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveRect(const QPoint &p);
    void enterEvent(QEvent *event);
    pressWindowsState m_state;
    int m_border;
    CursorPos m_curPos;
#endif
public slots:
    //************************************
    // Method:    show
    // FullName:  IMMainWidget::show
    // Access:    public
    // Returns:   void
    // Qualifier:
    //************************************
    void show();
    //************************************
    // Method:    slotExit
    // FullName:  IMMainWidget::slotExit
    // Access:    private
    // Returns:   void
    // Qualifier:
    //************************************
    void slotExit();
    //************************************
    // Method:    slotFullScreen
    // FullName:  IMMainWidget::slotFullScreen
    // Access:    private
    // Returns:   void
    // Qualifier:
    //************************************
    void slotFullScreen();
    //************************************
    // Method:    slotCheckWidget
    // FullName:  IMMainWidget::slotCheckWidget
    // Access:    private
    // Returns:   void
    // Qualifier:
    // Parameter: int
    // Parameter: bool
    //************************************
    void slotCheckWidget(int, bool);

    //************************************
    // Method:    slotSysTrayIconClicked
    // FullName:  IMMainWidget::slotSysTrayIconClicked
    // Access:    private
    // Returns:   void
    // Qualifier: 托盘图标响应
    // Parameter: QSystemTrayIcon::ActivationReason reason
    //************************************
    void slotSysTrayIconClicked();

	void slotNetWarning(bool);


#ifdef  Q_OS_WIN
	//忽略消息
	void slotIgnoreBtnClicked();
	//消息盒子响应
	void slotItemOfMsgBoxClicked(QString id, int funcType);
#endif

#ifndef Q_OS_WIN
    void slotSysTrayIconClickedMac(QSystemTrayIcon::ActivationReason reason);
#endif

    //************************************
    // Method:    setMainWidgetStatusLabel
    // FullName:  IMMainWidget::setMainWidgetStatusLabel
    // Access:    private
    // Returns:   void
    // Qualifier: 设置与服务器连接状态
    // Parameter: QString msg
    //************************************
    void slotSetMainWidgetStatusLabel(QString msg);

    void slotDealTrayIconFlash(QString buddyID);  //根据消息状态处理闪动
    void slotMessageRevFlashTime();  //执行闪动操作
    void slotShowAllClicked();     //点击闪动的托盘图标时，显示所有的消息窗。

    //计数的槽。
    void slotCountMessage(int num);

    void slotContactsMessageNum(int num);

    void slotClickedDock();  //mac下点击dock

    void slotGlobalMouseMouse();

    void slotQuickOpen();

    void slotTriggered();
private:
    //************************************
    // Method:    registerHandle
    // FullName:  IMMainWidget::registerHandle
    // Access:    private
    // Returns:   void
    // Qualifier:
    //************************************
    void registerHandle();

    void CreateTrayMenu();
	
	//加载消息通知窗口(消息盒子)
#ifdef Q_OS_WIN
	void loadMsgNotifyBox();
#endif

signals:
    void sigExit();        //退出的信号。
    void sigUserProfile();  //显示个人信息页面的信号

    void sigMenuItem(QString);

    void sigDormancyState(bool);   //是否休眠信号

    void sigTrayOpenChat(int type, QVariant buddyID);

    void sigNewApply();

    void sigOpenChat(int ,QVariant);

    void sigNotifyReplied(QString userID,QString reply);

    void sigSettings();

    void sigParseScreenCutMessage(QString strMsg);//截图信号发送

    void sigUpdateBuddyHeaderImagePath(int nIMUserID, QString headerPath);//广播头像更改

	void sigUpdateBuddyNickName(int nIMUserID, QString nickName,int nGroupID);//广播昵称更改

	void sigCheckUpdate();//检查更新

	void sigTipMessage(int, QString, QString);//加入自由群组

	void sigAskExit();//询问chatdatamanager是否可以退出
	void sigAnswerExit();
	void sigDestroyIcon();
	void sigSendFlashStatus(bool);
private:
    Ui::IMMainWidget *ui;
    Shadow *shadow;  //窗口阴影。
    QPoint mouse;  //用于窗口移动的暂存变量
    /*QAction *ActionCheckUpdate; //检查更新
    QAction *ActionExit;        //退出
    QMenu *mTrayMenu;        //系统托盘菜单
    QSystemTrayIcon *mSysTrayIcon;*/
    QButtonGroup *buttonGroup;  //单选按钮组。
    //AboutWidget *aboutWidget;  //关于窗口.
	FunctionWidget *functionWidget;//关于窗口
    MenuWidget *menuWidget;

    QString mAppVersion;

    QString mMessageRevHeaderImg;
    int mMessageRevType;
    QTimer *mMessageRevFlashTime;  //来消息闪动
    int mMessageRevFlashNum;
    bool mFlashingFlag;
	NetWarningWidget * m_pNetWarning;
	bool bNetWarn;

    static IMMainWidget* pThis;


#ifdef Q_OS_WIN
    CSysTrayIcon mSysTrayIcon;
#else
    QSystemTrayIcon mSysTrayIcon;
    xSysTrayMeauAction *mAction;
    QWidgetAction *mWidgetAction;
    QMenu *mTrayIconMenu;
    static IMMainWidget* main_window_;
#ifdef Q_OS_MACOS
    bool is_registered_;
    IONotificationPortRef  notify_port_ref_;
    io_object_t            notifier_object_;
#endif
#endif
};

#endif // IMMAINWIDGET_H
