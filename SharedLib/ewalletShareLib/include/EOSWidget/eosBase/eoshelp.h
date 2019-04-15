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

	// Qualifier:EOS 创建钱包，返回创建成功的json
	QString EosCreateWallet();

	// Qualifier:EOS 根据私钥获取公钥
	QString EosGetPublicKey(QString priKey);

	// Qualifier:EOS 根据公钥获取私钥
	QString EosSignTransation(QString address, QString priKey, QString strDataParame,QByteArray InfoData, int blockNum, int blockPrefix);

	// Qualifier:签名
	void signTransaction(SignedTransaction &txn, const std::vector<std::string> &pubKeys, const TypeChainId &cid);
private:
	
};

#endif // EOSHELP_H
