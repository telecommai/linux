#ifndef EOSHELP_H
#define EOSHELP_H

#include <QObject>
#include "chain/signedtransaction.h"
#include "chain/packedtransaction.h"
#include "chain/chainmanager.h"

class EOSHelp : public QObject
{
	Q_OBJECT

public:
	EOSHelp(QObject *parent =0);
	~EOSHelp();

	// Qualifier:EOS ����Ǯ�������ش����ɹ���json
	QString EosCreateWallet();

	// Qualifier:EOS ����˽Կ��ȡ��Կ
	QString EosGetPublicKey(QString priKey);

	// Qualifier:EOS ���ݹ�Կ��ȡ˽Կ
	QString EosSignTransation(QString address, QString priKey, QString strDataParame,QByteArray InfoData, int blockNum, int blockPrefix);

	// Qualifier:ǩ��
	void signTransaction(SignedTransaction &txn, const std::vector<std::string> &pubKeys, const TypeChainId &cid);
private:
	
};

#endif // EOSHELP_H
