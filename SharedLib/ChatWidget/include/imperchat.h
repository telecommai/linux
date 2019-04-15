#ifndef IMPERCHAT_H
#define IMPERCHAT_H

#include <QWidget>
#include <QFile>
#include <QKeyEvent>
#include <QDir>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QDesktopServices>
#include <QMainWindow>
#include <QDrag>
#include <QTextEdit>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QList>
#include <QJsonDocument>
#include <qclipboard.h>
#include <QTextBlock>
#ifdef Q_OS_WIN
#include <tchar.h>
#endif
#include <QDesktopWidget>
#include <QProcess>
#include <QJsonDocument>
#include <QJsonObject>
#include "httpnetworksharelib.h"
#include "imvideoplayer.h"

#include "qlabelheader.h"
#include "inputbox.h"
#include "imusermessage.h"
#include "common.h"
#include "opcommon.h"
#include "stdafx.h"
#include "define.h"
#include "opdatebasesharelib.h"
#include "childWidget/filetypeex.h"
#include "childWidget/expresswidget.h"
#include "childWidget/groupuserprofilewidget.h"
#include "amrDec/amrdec.h"
#include "cfrientstylewidget.h"
//#include "zoomimg.h"
#include "secretWidget/enterpasswordwidget.h"
#include "zooming/picwidget.h"
#include "redPacketWidget/openPack.h"
#include "redPacketWidget/RedPackDetail.h"
#include "redPacketWidget/giveredpackwidget.h"
#include "questionbox.h"
#include "perprofilewidget.h"
#include "groupprofilewidget.h"

//#ifdef Q_OS_WIN
//#else
#include <QWebChannel>
#include <webobjectsharelib.h>
#include <QWebEnginePage>

//#endif


namespace Ui { class IMPerChat; };

class IMPerChat : public QWidget
{
	Q_OBJECT

public:
	IMPerChat(QString buddyID, QWidget *parent = 0);
	~IMPerChat();

	WId winId() const;


	//************************************
	// Method:    OnCloseExpress
	// FullName:  IMPerChat::OnCloseExpress
	// Access:    protected 
	// Returns:   void
	// Qualifier: 关闭表情
	//************************************
	void OnCloseExpress();

	//************************************
	// Method:    OnSetNikeName
	// FullName:  IMPerChat::OnSetNikeName
	// Access:    public 
	// Returns:   void
	// Qualifier: 设置昵称
	// Parameter: QString
	// Parameter: QString
	//************************************
	void OnSetNikeName(QString strText, QString strBuddyID);

	//************************************
	// Method:    OnSetAutoGraph
	// FullName:  IMPerChat::OnSetAutoGraph
	// Access:    public 
	// Returns:   void
	// Qualifier: 设置签名
	// Parameter: QString
	//************************************
	void OnSetAutoGraph(QString strText);

	//************************************
	// Method:    OnClearMessageInfo
	// FullName:  IMPerChat::OnClearMessageInfo
	// Access:    protected 
	// Returns:   void
	// Qualifier: 清空webview内容
	//************************************
	void OnClearMessageInfo();

	void onInsertTimeLine(qlonglong time_t);

	void OnSendTransmitMessage(MessageInfo msg);
	void OnShareID(int type, QString contactID);

	//************************************
	// Method:    OnInertSendMessageTextInfo
	// FullName:  IMPerChat::OnInertSendMessageTextInfo
	// Access:    protected 
	// Returns:   void
	// Qualifier: 发送消息 展示
	// Parameter: QString strMsg
	// Parameter: QString strHeadImage
	//************************************
	void OnInertSendMessageTextInfo(QString strMsg, QString strHeadImage, MessageInfo msgInfo);

	//************************************
	// Method:    OnInsertRecMessageTextInfo
	// FullName:  IMPerChat::OnInsertRecMessageTextInfo
	// Access:    protected 
	// Returns:   void
	// Qualifier: 接收消息展示
	// Parameter: QString strMsg
	// Parameter: QString strHeadImage
	//************************************
	void OnInsertRecMessageTextInfo(QString strMsg, QString strHeadImage, QString msgID, int score,QString strBuddyId);
	void OnInsertRecMessagePictureInfo(QString strIsUserDefine, QString strUserDefinePicPath, QString strPicPath, QString strHeadImage, QString strMsgID, int score, QString strBuddyId);

	void OnInsertRecVideoInfo(QString strIsLoading, QString strVideoPicPath, QString strVideoPath, QString strHeadImage, QString strMsgID, int score, QString strBuddyId);

	void UpdateMessageStateInfo(QByteArray msgID, int nState, int score);

	// wxd add code - start
	void OnSetChatHeaderImage(QString strHeaderImg);  // 设置聊天窗口的头像
	void HideChatHeaderImage();    // 隐藏聊天窗口的头像
	// wxd add code - end
	void OnRecvFileMessage(MessageInfo messageInfo, QString strHeadImage, QString fileLocalPath);
	void OnRecvImgMessage(MessageInfo messageInfo, QString strHeadImage);
	//added by fanwenxing
	void OnRecvAudioMessage(MessageInfo messageInfo, QString strHeadImage);
	void OnRecVdoMessage(MessageInfo messageInfo, QString strHeadImage);
	//added by wangqingjie
	void OnRecvTaskMessage(MessageInfo messageInfo, QString strHeadImage);  //接收任务消息

	void OnRecvFormMessage(MessageInfo messageInfo, QString strHeaderPath); // 接收到表单消息

	void onRecvTransferMessage(MessageInfo msgInfo, QString headerImage);
	void OnRecvNoticeMessage(MessageInfo msgInfo, QString headerImage);
	void onRecvShareUrlMessage(MessageInfo msgInfo, QString headerImage);
	void onRecvLocationMessage(MessageInfo msgInfo, QString headerImage);
	void onRecvSecretLetter(MessageInfo msgInfo, QString headerImage);
	void onRecvSecretImage(MessageInfo msgInfo, QString headerImage);
	void onRecvSecretFile(MessageInfo msgInfo, QString headerImage);

	void OnRecvGWMessage(MessageInfo messageInfo, QString strHeadImage);
	void OnRecvNotifyMessage(MessageInfo messageInfo);
	void OnRecvCommonMessage(MessageInfo messageInfo, QString strHeadImage);
	void onRecvRedBagMessage(MessageInfo messageInfo, QString strHeadImage);
	//added by wangqingjie
	void SendDragFile(QString);

//	void OnSendScreenShotPic(QString strShotFileName);  //发送截图

	void SendPicture(QString fileName);

	void SendVideo(MessageInfo msg);

    void InsertTextEditPic(QString strPath);


	void ShowByChatId(bool isNew);

	void StartInputting();
	
	QString GetDraft();

	QString GetFileMd5(QString fileNamePath);
	const QString GetSmallImg(QString strPath);

	bool IsDownloading();

public slots:
    void InitMessageInfo(QString strEndRowId = "");//获取的消息的rowid将小于strEndRowId
    void slotOpenDocument(QString msgID);
	void slotOpenFile(QString msgID);
	void slotGetFile(QString msgID);
	void slotCoverFile();
	void slotRequestHttpFileResult(bool);
	bool slotSaveFile(QString msgID);
	void slotZoomImg(QString strFilePath);
	void slotCancleLoadorDownLoad(QString);
	void slotSendFileByID(QString);
	void slotUpPicReplyFinished(bool result, QByteArray strResult);
	void slotVideoPlay(QString mediaPath);
	void slotOpenLink(QString link);
	void slotOpenPerLog();
	void slotOpenSecret(QString);
	void slotSendScreenShotPic();
    void slotScreenCanclePixMap();
    void slotWebEngineFinish(bool bResult);
	void slotPicClose();
	//文本框右键菜单
	void slotCopy();
	void slotCut();
	void slotPaste();
	void slotDel();

	void slotChangePic(int iType);
	void slotClickedNotice();//发通告
	void slotSendNotice(QMap<QString,QString>);
	void slotUpNoticePicReplyFinished(bool, QByteArray);
	//能量交换
	void slotClickedTransfer();
	void slotClickedETH();
	void slotClickedBTC();
	void slotClickedEOS();
	void slotWalletMenu();
	void slotCloseWalletMenu();
	void slotCloseWalletLeave();
	void slotClickUserHeader(QString msgID);
	void slotWebViewRenderProcessTerminated(QWebEnginePage::RenderProcessTerminationStatus terminationStatus, int exitCode);
	//正在输入
	void slotEndInputting();
	void slotInputTimeOut();
	//notice
	void slotUpdateNotice(bool);
protected:
	//************************************
	// Method:    RegisterHandle
	// FullName:  IMPerChat::RegisterHandle
	// Access:    protected 
	// Returns:   void
	// Qualifier: 注册事件
	//************************************
	void RegisterHandle();

	void showEvent(QShowEvent *event);

	bool eventFilter(QObject *obj, QEvent *e);

	virtual void mousePressEvent(QMouseEvent *event);
	void ExpressHide(QRect, QPoint);

	void OnDealRecvImgMessage(MessageInfo messageInfo, QString strHeadImage);
	
	void dragEnterEvent(QDragEnterEvent *event);
	void dropEvent(QDropEvent *event);

	void hideEvent(QHideEvent *event);
	//bool nativeEvent(const QByteArray &eventType, void *message, long *result);
private: 
	bool IsValidImage(QString imgPath);
	QString convertHeaderToHtmlSrc(QString);
	QString formatSendMessageFromImgPathToImgDescription(const QString& strSendMessage);	// 将 用户发送的信息字符串中的 头像的路径替换为[xx]形式
	//QString formatMessageFromImgDescriptionToImgPath(const QString& strMessage);

	QString recognizeUrl(const QString& strMessage);
	QString formatMessageFromImgDescriptionWithHtmlEncode(const QString& strMessage);
	// 将 包含[xx]表情形式的信息字符串 转换为 表情的路径形式的字符串
	void SendTextMessage(QString strText, QString strHtmlText);

	QString decodeURI(QString str);

	void sendTransmitFile(MessageInfo msg);

	int CalWavLength(QString strPath);

	void ResizeNameLabel(QString);
	//替换原有的changeli等 用于更新file消息的状态
	void ChangeFileState(QString strMsgId, int iState);

private slots:
	//************************************
	// Method:    doExpressNormalImagePath
	// FullName:  IMPerChat::doExpressNormalImagePath
	// Access:    private 
	// Returns:   void
	// Qualifier: 选择表情 返回图片路径
	// Parameter: QString strImgPath
	//************************************
	void doExpressNormalImagePath(QString strImgPath);

	//************************************
	// Method:    doClickedSetFont
	// FullName:  IMPerChat::doClickedSetFont
	// Access:    private 
	// Returns:   void
	// Qualifier: 选择字体
	//************************************
	void doClickedSetFont();   
	//************************************
	// Method:    doSelectExpress
	// FullName:  IMPerChat::doSelectExpress
	// Access:    private 
	// Returns:   void
	// Qualifier: 选择表情
	//************************************
	void doSelectExpress();    
	//************************************
	// Method:    doSendMessage
	// FullName:  IMPerChat::doSendMessage
	// Access:    private 
	// Returns:   void
	// Qualifier: 发送消息
	//************************************
	void doSendMessage();        
	//************************************
	// Method:    doClickedShake
	// FullName:  IMPerChat::doClickedShake
	// Access:    private 
	// Returns:   void
	// Qualifier: 点击发送窗口抖动
	//************************************
	void doClickedShake();     
	//************************************
	// Method:    doClickedVoiceChat
	// FullName:  IMPerChat::doClickedVoiceChat
	// Access:    private 
	// Returns:   void
	// Qualifier: 点击发送红包
	//************************************
	void doClickedRedPacket(); 
	//************************************
	// Method:    doClickedPicture
	// FullName:  IMPerChat::doClickedPicture
	// Access:    private 
	// Returns:   void
	// Qualifier: 点击发送图片
	//************************************
	void doClickedPicture();    
	//************************************
	// Method:    doClickedCutPicture
	// FullName:  IMPerChat::doClickedCutPicture
	// Access:    private 
	// Returns:   void
	// Qualifier: 点击截图
	//************************************
	void doClickedCutPicture(); 

	//点击了发起部落按钮.
	void slotClickedAddGroup();

	void slotUpFileReplyFinished(bool, QByteArray);
	void doUpLoadFileProgress(qint64, qint64);
	void slotDownLoadFileProgress(qint64,qint64);

	//added by fanwenxing
	void slotCefDrags(QStringList);
	void slotPerFile();

	void slotClickedSendLetter();
	void slotSecretLetter(QString password, QString text, QString letter);
	void slotClickedSecretImage();
	void slotSecretImage(QString letter);
	void slotClickedSecretFile();
	void slotSecretFile(QString letter);

	void slotMsgID(QString msgID);

	void slotGivePacket(QString data);

	//void slotShareBuddyInfoResult(bool, QString);
	//void slotShareBuddyHeader(bool);
// 	void slotShareGroupInfoResult(bool, QString);
// 	void slotShareGroupHeader(bool);
	void slotOpenPacket(QString msgID);
	void slotGetPacketResult(QString);
	void slotPacketStatus(bool);

	void slotCloseGroupWidget();
	void slotCloseVideoWidget();
	void slotClosePacketWidget();
	void slotCloseDetailWidget();
	void slotCloseEnterWidget();
	void slotCloseGivePackWidget();

	void slotPopUpMenu(bool isShowCopy, bool isShowTransmit, QString msgId);
	void slotWebViewClear();
	void slotWebViewCopy();
	void slotFileViewCopy();

	void slotWebViewTransmit();
	//重发 重新加载
	void slotReSend();
	void slotReLoad();

	void slotLoadMore();
	//用户正在输入
	void slotUserInputting();
#ifdef Q_OS_WIN
	void slotParseScreenCutMessage(QString strMsg);
#endif
	void slotUpdateHtmlBuddyHeaderImagePath(int buddyId, QString path);
	void slotUpdateHtmlBuddyNickName(int buddyId, QString path,int iGroupId);
	void slotDownFailed();
signals:
	//************************************
	// Method:    SendHideWidget
	// FullName:  IMPerChat::SendHideWidget
	// Access:    private 
	// Returns:   void
	// Qualifier: 发送隐藏窗口信号
	//************************************
	void sigHideWidget();

	//************************************
	// Method:    SendWidgetMinSize
	// FullName:  IMPerChat::SendWidgetMinSize
	// Access:    private 
	// Returns:   void
	// Qualifier: 发送窗口最小化
	//************************************
	void sigWidgetMinSize();

	// wxd add code - start
	void sigBtnCloseWClicked();      // 发送左边的按钮点击事件
	// wxd add coed - end
	void sigCancle(QString);

	void sigKeyUpDown(QKeyEvent *);
	void sigUpdateSelfMessage(bool, QVariant, QString,bool, QMap<QString, QVariant>);

	void sigAddChatGroup(QString);

	void sigOpenChatWindows(QString strToUserID);
	void sigShowNormalWindow();           //窗口还原
	void sigOpenPerLog(QString);
	
	void sigSecretPassword(QString);

	void sigTransferRecord(RecordInfo);

	void sigTransmit(QString);

	void sigTransferWindow(QString,QString);
	void sigETHWindow(QString, QString);
	void sigBTCWindow(QString, QString);
	void sigEOSWindow(QString, QString);

	void sigOpenPic(QString, QList<QString>*, QWidget *);
	void sigHostingCharge(int, QString, QString, QString);
	void sigUserInputting(int);

private:
	Ui::IMPerChat *ui;
	ExpressWidget *mExpressWidget; //表情窗口
	QRect rectExpressWidget;          //表情窗口的位置

	QLabelHeader*    mChatHeaderImage;   // 聊天窗口的头像，单聊天时显示  wxd add 
	bool	   mbExpress_widget_is_showing;   // 表情窗口的状态  是否正在显示

	QString m_foremostRowId;//最前面的消息的rowid，获取更多消息时用
	bool m_isShowingMore;//当前是否是处在正在加载更多消息处理中

	//added by wangqingjie
	QString mMsgID;
	QString mUpFileName;

	//added by fanwenxing
	bool initFinished;
	bool copying;
	QLabel *sendTip;

	QList<MessageInfo> waitMessages;

	EnterPasswordWidget *enterWidget;
	GroupProfileWidget *groupWidget;
	PicWidget* m_pPicWidget;
	OpenPacketWidget *openPacketWidget;
	RedPackDetail *detailWidget;
	GiveRedPackWidget *giveWidget;

	IMVideoPlayer *videoWidget;

	//文本框菜单
	QMenu * m_Menu;
	QAction *ActPaste;
	QAction *ActDel;
	QAction *ActCopy;
	QAction *ActCut;
	//文本框菜单
	QMenu * m_WalletMenu;
	QAction *ActPower;
	QAction *ActETH;
	QAction *ActBTC;
	QAction *ActEOS;
	bool m_bWalletBtn;
	bool m_bWalletMenu;
	QTimer * m_TimerBtn;
	QTimer * m_TimerLeave;
	QTimer * m_TimerInputting;
	QTimer * m_TimerUserInputting;
	QString m_strNickName;
	bool m_bTimeOut;
	QList<QString> m_listPic;
	QList<QString>::iterator m_PicIter;
//#ifdef Q_OS_WIN
//
//#else
    QWebChannel *m_pWebChannel;
    WebObjectShareLib *m_pWebObject;
//#endif
	int m_iHttp;
};

#endif // IMPERCHAT_H
