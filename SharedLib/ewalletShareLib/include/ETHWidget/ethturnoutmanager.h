﻿#pragma once

#include <QObject>
//#ifdef Q_OS_WIN
//#include "qcefview.h"
//#else
#include <QWebEngineView>
#include <QWebChannel>
#include "webobjectsharelib.h"
//#endif
#include "opdatamanager.h"
#include "oprequestsharelib.h"
#include "messagebox.h"

class ETHTurnOutManager : public QObject
{
	Q_OBJECT

public:
	ETHTurnOutManager(QObject *parent = NULL);
	~ETHTurnOutManager();

	void setPrivateKey(QString);

public slots:
	void slotTurnOut(QString userID, QString otherID, QString fromAddress, QString toAddress, QString miner, QString value,bool bIsWindow);

private slots:
	void slotGetNonce(QString);

	void slotGetTransactionData(QString);

	void slotTransfer(bool, QVariant);

	void slotWebEngineFinish(bool bResult);
signals:
	void sigFinished();
	void sigTransferMsg(QString, QString, QString);

private:
//#ifdef Q_OS_WIN
//    QCefView *cefView;
//#else
    QWebEngineView *cefView;
    QWebChannel *m_pWebChannel;
    WebObjectShareLib *m_pWebObject;
//#endif

	QString userID;
	QString otherID;
	QString fromAddress;
	QString toAddress;
	QString miner;
	QString value;
	bool bIsWindow;
	QString priKey;
};
