#ifndef GROUPCHATWIDGET_H
#define GROUPCHATWIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>

#include <QDebug>
#include <QScrollBar>
#include <QMovie>
#include <qmenu.h>
#include <qclipboard.h>
#include <qmimedata.h>
#include <QTextBlock>
#include "messagebox.h"
#include "inputbox.h"
#ifdef Q_OS_WIN
#include <tchar.h>
#endif
#include <QJsonDocument>
#include <QFileDialog>
#include "childWidget/filetypeex.h"
#include <QDesktopServices>
#include <QProcess>
//#include "zoomimg.h"
#include "zooming/picwidget.h"
#include "questionbox.h"
#include "imvideoplayer.h"

#include "imusermessage.h"
#include "stdafx.h"
#include "define.h"
#include "opdatebasesharelib.h"
#include "imdownloadheaderimg.h"
#include "imrequestbuddyinfo.h"
#include "childWidget/expresswidget.h"
#include "childWidget/groupsearchwidget.h"
#include "childWidget/groupuserprofilewidget.h"
#include "childWidget/groupaddbuddywidget.h"
#include "amrDec/amrdec.h"
#include "thread/threadloadgroupuserlist.h"
#include "perprofilewidget.h"
#include "groupprofilewidget.h"
#include "SearchWidget/atwidget.h"
#include "redPacketWidget/openPack.h"
#include "redPacketWidget/RedPackDetail.h"
#include "redPacketWidget/GroupPackWidget.h"
//#ifdef Q_OS_WIN
//
//#else
#include <QWebChannel>
#include <webobjectsharelib.h>
#include <QWebEnginePage>
//#endif

namespace Ui { class GroupChatWidget; };

class GroupChatWidget : public QWidget
{
	Q_OBJECT

public:
	GroupChatWidget(const QString& groupId,QWidget *parent = 0);
	~GroupChatWidget();

	WId winId() const;

	bool IsValidImage(QString imgPath);

	void OnCloseExpress();
	void ExpressHide(QRect rect, QPoint pos);
	void OnInsertGroupUserList(QString strGroupID);
	void OnInsertGroupUser(QString manaID, BuddyInfo info);

	void onInsertTimeLine(qlonglong time_t);
	void OnSendTransmitMessage(MessageInfo msg);
	void OnShareID(int type, QString contactID);
	void OnRevMessage(MessageInfo messageInfo);
	void OnUpdateGroupBuddyHeaderImg(QString strBuddyID, QString strPath);
	void UpdateMessageStateInfo(QByteArray msgID, int nState, int integral);
	void OnInertSendMessageTextInfo(QString strMsg, QString strHeadImage, MessageInfo msgInfo);

	void OnRecvGroupFile(MessageInfo, QString);
	void OnRecvAudioMessage(MessageInfo msgInfo, QString nickName, QString headerImage);
	void onRecvLocationMessage(MessageInfo msgInfo,QString nickName, QString headerImage);
	void OnRecvNoticeMessage(MessageInfo msgInfo, QString nickName, QString headerImage);
	void onRecvShareUrlMessage(MessageInfo msgInfo, QString nickName, QString headerImage);
	void OnRecvNotifyMessage(MessageInfo msgInfo);
	void OnRecvCommonMessage(MessageInfo messageInfo, QString nickName, QString strHeadImage);
	void onRecvRedBagMessage(MessageInfo messageInfo, QString nickName, QString strHeadImage);
	//added by wangqingjie
	void OnInsertRecvFileMessage(MessageInfo msgInfo, QString strNickName);
	void InsertSendFileMessage(MessageInfo msgInfo);//

	void OnSendScreenShotPic(QString strShotFileName);
	//added by fanwenxing
	void scrollBottom();
	void userQuitGroup(QString userID);
	void setNoSpeak(int noSpeak);

    void InsertTextEditPic(QString strPath);

	void ShowByChatId(bool isNew);

	QString GetDraft();

	bool IsDownloading();

protected:
	void resizeEvent(QResizeEvent * event);
	//bool nativeEvent(const QByteArray &eventType, void *message, long *result);
private:
	void RegisterHandle();
	bool eventFilter(QObject *obj, QEvent *e);//事件过滤器
	void showEvent(QShowEvent *event);

	void mousePressEvent(QMouseEvent *event);
	void OnInsertGroupUserItem(QString strUserID, QString strPicPath, QString strNickName, int mana, bool bHasNote,int nHeight=30);

	void OnInsertRecMessageTextInfo(QString strMsg, QString strHeadImage, QString strMsgId, int score, QString strBuddyId);
	QString GetBuddyHeaderImage(QString strGroupID, QString strBuddyID);
	void OnClearMessageInfo();

	// wxd add code - start
	void OnInsertRecvMessageTextInfo(QString strMsg, QString strHeadImage, QString strNickName,QString strMsgId, int score, QString strBuddyId);//changed by wqj 
	void OnInsertRecvPictureInfo(QString strIsUserDefine, QString strUserDefinePicPath, QString strPicPath, QString strHeadImage, QString strNickName, QString strMsgId, int score, QString strBuddyId);//插入图片单独用的函数

	void updateGroupMemberCount(int member_count);      // 更新部落成员数量(部落成员列表上面的Label)
	QString formatSendMessageFromImgPathToImgDescription(const QString& strSendMessage);   // 将包含表情的 <img src='xxx'/> 形式的字符串转化为 表情的描述字 [xx]  eg: [微笑]
	//QString formatMessageFromImgDescriptionToImgPath(const QString& strMessage);

	QString recognizeUrl(const QString& strMessage);
	QString formatMessageFromImgDescriptionWithHtmlEncode(const QString& strMessage);
	// wxd add code - end
	//added by fanwenxing
	void OnInsertRecVideoInfo(QString strIsLoading, QString strVideoPicPath, QString strVideoPath, QString strHeadImage, QString strNickName, QString strMsgId, int score, QString strBuddyId);

	void SendPicture(QString fileName);

	void SendTextMessage(QString strText, QString strHtmlText);
	QString decodeURI(QString str);

	QString convertHeaderToHtmlSrc(QString headerImage);

	void sendTransmitFile(MessageInfo msg);
	void SendVideo(MessageInfo msg);


	int CalWavLength(QString strPath);

	QString GetFileMd5(QString fileNamePath);
	const QString GetSmallImg(QString strPath);

	void ChangeFileState(QString strMsgId, int iState);
private slots:
    void InitMessageInfo(QString strEndRowId = "");

	void slotClickedClose();
	void slotClickedCutPic();
	void slotClickedExpress();
	void slotClickedFont();
	void slotClickedPicture();
	void slotClickedSend();
	void slotClickedShake();

	void slotClickedRedPacket();
	void slotGivePacket(QString data);

	void slotClickedSpeak();
	void slotClickAdd();

	void slotExpressNormalImagePath(QString strPath);
	void slotClickedDoubleItem(QListWidgetItem *item);
	void slotGetItemInfo(bool, QString);

	void slotOnBtnCloseWClicked(); 
	void slotGroupFile();
	void doUpLoadFileProgress(qint64 sendnum, qint64 total);
	void slotDownLoadFileProgress(qint64, qint64);

	void slotUpPicReplyFinished(bool result, QByteArray strResult);

	void slotStartGroupUserThread();    //加载groupuser到线程的方法。
	void slotGroupUserInfoLoad(int); //部落成员滚动条到底时，线程执行加载方法。
	void slotThreadLoadGroupUserInfo(BuddyInfo buddyInfo);   //通过线程加载部落成员。
	void slotReLoadGroupUserList();

	void slotUpdateGroupBuddyImage(int, QPixmap);
	void slotUpdateGroupBuddyImagePath(int userID, QString imagePath);

	void slotCefDrags(QStringList list);

	void slotParseGroupBuddyInfo(QString, QList<BuddyInfo>);

	void slotChangePic(int iType);

	void slotClickedNotice();//发通告
	void slotSendNotice(QMap<QString, QString>);
	void slotUpNoticePicReplyFinished(bool, QByteArray);

	void slotTipMessage(int, QString, QString);
	void slotReSend();
	void slotReLoad();
	void slotWebViewRenderProcessTerminated(QWebEnginePage::RenderProcessTerminationStatus terminationStatus, int exitCode);
	void slotUpdateNotice(bool);
	void slotDownFailed();
public slots:
	void slotUpFileReplyFinished(bool, QByteArray);
	void slotGetFile(QString msgID);
	void slotCoverFile();
	bool slotSaveFile(QString msgID);
	void slotRequestHttpFileResult(bool result);
	void slotOpenDocument(QString msgID);
	void slotOpenGroupFile(QString msgID);
	void slotZoomImg(QString strFileName);
	void slotVideoPlay(QString mediaPath);
	void slotCancleLoadorDownLoad(QString msgId);
	void slotSendFile(QString strFileName);
	void slotSendFileByID(QString msgID);
	void slotOpenLink(QString link);
	void slotSendScreenShotPic();
    void slotScreenCanclePixMap();
    void slotWebEngineFinish(bool bResult);
	void slotPicClose();
#ifdef Q_OS_WIN
	void slotParseScreenCutMessage(QString strMsg);
#endif

	void slotUpdateHtmlBuddyHeaderImagePath(int buddyId, QString path);
	void slotUpdateHtmlBuddyNickName(int buddyId, QString nickName,int iGrp);

signals:
	void sigClose();

	void sigUpdateSelfImage(int, QPixmap);

	//void sigShowPerChat(QString strUserID);
	// wxd add code - start
	void sigBtnCloseWClicked();
	// wxd add code - end
	void sigMakeGroupHeader(QString groupID);
	void sigUpdateSelfMessage(bool, QVariant, QString,bool, QMap<QString, QVariant>);
	void sigKeyUpDown(QKeyEvent *);

	void sigGroupBuddyPerChat(QString strUserID);
	//added by wangqingjie for cancle
	void sigCancle(QString);

	void sigShowWindowMinsize();           //窗口最小化
	void sigShowNormalWindow();           //窗口还原

	void sigOpenMessageLog();    //打开消息记录的信号

	void sigTransmit(QString);

	void sigOpenPic(QString, QList<QString>*, QWidget *);
	void sigHostingCharge(int, QString, QString, QString);

private slots:
	void slotContextMenuRequested(const QPoint &pos);
	void slotSetManager();
	void slotCancelManager();
	void slotRemoveBuddy();
	void slotAddFriend();
	void slotHttpAddPersonResultInfo(bool bResult, QString strResult);

	void slotShowOrHideSearch(bool);
	void slotOpenSearchUser(QString);

	void slotFinished();
	void slotCefInited();

	void slotTest(bool, QString);
	void slotOpenNote();
	void slotSetNote(QString);

	void slotMsgID(QString msgID);

	void slotOpenPacket(QString msgID);
	void slotGetPacketResult(QString);
	void slotPacketStatus(bool);

	void slotShareBuddyInfoResult(bool, QString);
	void slotShareBuddyHeader(bool);
	void slotShareGroupInfoResult(bool, QString);
	void slotShareGroupHeader(bool);

	void slotShowProfile();
	void slotClickUserHeader(QString msgID);

	void slotCloseVideoWidget();
	void slotClosePacketWidget();
	void slotCloseDetailWidget();
	void slotCloseGivePackWidget();

	void slotAtGroupUser(QString path);
	void slotSendAtMessage(QString content, QString message);

	void slotChangeText();

	void slotOpenGroupUserChat(int type, QVariant buddyID);

	void slotPopUpMenu(bool isShowCopy, bool isShowTransmit, QString msgId);
	
	//文本框右键菜单
	void slotCopy();
	void slotCut();
	void slotPaste();
	void slotDel();

	void slotWebViewClear();
	void slotWebViewCopy();
	void slotFileViewCopy();
	void slotWebViewTransmit();

	void slotGroupListContextMenuRequested(int);
	void slotItemDoubleClicked(int);

	void slotLoadMore();
private:
	Ui::GroupChatWidget *ui;
	ExpressWidget *mExpressWidget; //表情窗口
	QRect rectExpressWidget;          //表情窗口的位置
	QString mCurrentID; 

	QMovie *movie;   //刷新按钮的gif。
	
	//int mGroupMemberCount;     // 部落成员计数 wxd add
	bool mbExpress_widget_is_showing;    // 表情窗口状态   是否正在显示

	ThreadLoadGroupUserList *thread;

	QString m_foremostRowId;//最前面的消息的rowid，获取更多消息时用
	bool m_isShowingMore;//当前是否是处在正在加载更多消息处理中

	//added by fanwenxing
	bool copying;
	GroupSearchWidget *searchWidget;
	QLabel *sendTip;
	QLabel *noSpeakTip;

	bool cefInited;          //cef初始化标志
	//bool listLoadFinished;   //部落成员列表初始化标志
	bool initFinisthed;      //以上两个初始化完毕

	int atPosition;


	bool m_bHasStartGroupUserThread;
	bool m_bNeedManulInit;
	bool m_bReloadGroupUserList;

	QList<MessageInfo> waitMessages;

	PicWidget* m_pPicWidget;
	GroupProfileWidget *groupWidget;
	IMVideoPlayer *videoWidget;
	OpenPacketWidget *openPacketWidget;
	GroupPackWidget *groupPackWidget;
	RedPackDetail *detailWidget;
	AtWidget *atWidget;

	//文本框菜单
	QMenu * m_Menu;
	QAction *ActPaste;
	QAction *ActDel;
	QAction *ActCopy;
	QAction *ActCut;
	QList<QString> m_listPic;
	QList<QString>::iterator m_PicIter;
//#ifdef Q_OS_WIN
//
//#else
    QWebChannel *m_pWebChannel;
    WebObjectShareLib *m_pWebObject;
//#endif

	QTimer *m_menuTimer;
	
	int m_iHttp;
};

#endif // GROUPCHATWIDGET_H
