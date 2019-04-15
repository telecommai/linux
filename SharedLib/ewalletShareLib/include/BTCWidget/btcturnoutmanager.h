#pragma once

#include <QObject>
//#ifdef Q_OS_WIN
//#include "qcefview.h"
//#else
#include <QWebEngineView>
#include <QWebChannel>
#include "webobjectsharelib.h"
//#endif
#include "opdatamanager.h"
#include "messagebox.h"
#include "stdafx.h"
#include "oprequestsharelib.h"

class BTCTurnOutManager : public QObject
{
	Q_OBJECT

public:
	BTCTurnOutManager(QObject *parent = NULL);
	~BTCTurnOutManager();

	void setPriKey(QString strKey);
	void turnOut(QString fromAddress, QString toAddress, QString value);

	

	private slots:
	void slotBtcUtxo(QString);
	void slotTransactionData(QString);
	void slotTransResult(bool);

private:
//#ifdef Q_OS_WIN
//    QCefView *cefView;
//#else
    QWebEngineView *cefView;
    QWebChannel *m_pWebChannel;
    WebObjectShareLib *m_pWebObject;
//#endif

	QString strKey;

	QString fromAddress;
	QString toAddress;
	QString value;
};
