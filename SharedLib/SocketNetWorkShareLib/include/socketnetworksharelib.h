#ifndef SOCKETNETWORKSHARELIB_H
#define SOCKETNETWORKSHARELIB_H

#include <QObject>
#include <QByteArray>
#include <QtNetwork/QTcpSocket>

/*ͨ�ð�socket*/

class SocketNetWorkShareLib : public QObject
{
	Q_OBJECT
public:
	explicit SocketNetWorkShareLib(QObject *parent = 0);
	~SocketNetWorkShareLib();

	//************************************
	// Method:    ConnectServer
	// FullName:  SocketNetWorkShareLib::ConnectServer
	// Access:    public 
	// Returns:   bool
	// Qualifier: ���ӷ�����
	// Parameter: QString strIP
	// Parameter: int nPort
	//************************************
	bool ConnectServer(QString strIP, int nPort);

	//************************************
	// Method:    DisConnectSocket
	// FullName:  SocketNetWorkShareLib::DisConnectSocket
	// Access:    public 
	// Returns:   void
	// Qualifier: �Ͽ�socket����
	//************************************
	void DisConnectSocket();    

	//************************************
	// Method:    SendMessage
	// FullName:  JFSocketManager::SendMessage
	// Access:    public 
	// Returns:   void
	// Qualifier: ������Ϣ
	// Parameter: QByteArray byteArray
	//************************************
	void SendMsg(QByteArray byteArray);  

private slots:
	//************************************
	// Method:    ReceiveServerData
	// FullName:  JFSocketManager::ReceiveServerData
	// Access:    public 
	// Returns:   void
	// Qualifier: ������ܵ�����
	//************************************
	void slotReceiveServerData();

	//************************************
	// Method:    slotSocketErro
	// FullName:  SocketNetWorkShareLib::slotSocketErro
	// Access:    private 
	// Returns:   void
	// Qualifier: socket����
	// Parameter: QAbstractSocket::SocketError
	//************************************
	void slotSocketErro(QAbstractSocket::SocketError);

signals:
	//************************************
	// Method:    sigSendReadData
	// FullName:  SocketNetWorkShareLib::sigSendReadData
	// Access:    private 
	// Returns:   void
	// Qualifier: ���ͷ���������������
	// Parameter: QByteArray
	//************************************
	void sigSendReadData(QByteArray);

	//************************************
	// Method:    sigDisConnectServer
	// FullName:  SocketNetWorkShareLib::sigDisConnectServer
	// Access:    private 
	// Returns:   void
	// Qualifier: ��������Ͽ�����
	//************************************
	void sigDisConnectServer();
private:
	QTcpSocket *mSocketClient;
};

#endif // SOCKETNETWORKSHARELIB_H
