#include "eoshelp.h"
#include <QJsonParseError>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <memory>
#include <QDebug>
#include "eos/ec/eos_key_encode.h"
#include "eos/chain/chainmanager.h"

EOSHelp::EOSHelp(QObject *parent)
	: QObject(parent)
{

}

EOSHelp::~EOSHelp()
{

}

QString EOSHelp::EosCreateWallet()
{
	QString ownPriKey;
	QString activePriKey;
	QString ownPubKey;
	QString activePubKey;
	for (int i = 0; i < 2; ++i) 
	{
		eos_key key;
		auto pub = QString::fromStdString(key.get_wif_private_key());
		if (i == 0) {
			ownPriKey = pub;
		}
		else {
			activePriKey = pub;
		}
	}

	ownPubKey = EosGetPublicKey(ownPriKey);
	activePubKey = EosGetPublicKey(activePriKey);

	QJsonObject json;
	json.insert("ownPriKey", ownPriKey);
	json.insert("activePriKey", activePriKey);
	json.insert("ownPubKey", ownPubKey);
	json.insert("activePubKey", activePubKey);
	QString strJSON = QString(QJsonDocument(json).toJson());
	return strJSON;
}

QString EOSHelp::EosGetPublicKey(QString priKey)
{
	if (!priKey.isEmpty())
	{
		eos_key key;
		std::string pubKey = key.get_eos_public_key_by_wif(priKey.toStdString());
		QString str = QString::fromStdString(pubKey);
		return str;
	}
	return "";
}

// Qualifier:EOS 根据公钥获取私钥
QString EOSHelp::EosSignTransation(QString priKey, QString strDataParame, QByteArray InfoData, int blockNum, int blockPrefix)
{
	if (!priKey.isEmpty())
	{

		SignedTransaction signedTxn = ChainManager::createTransaction("eosio.token", "transfer", strDataParame.toStdString(), ChainManager::getActivePermission("eosiotest3"), InfoData);

		auto infoObj = QJsonDocument::fromJson(InfoData).object();
		auto infoObj2 = infoObj.value("data").toObject();
		if (infoObj.isEmpty()) {
			return "";
		}

		std::vector<std::string> keys;
		keys.push_back(priKey.toStdString());

		signTransaction(signedTxn, keys, TypeChainId::fromHex(infoObj2.value("chain_id").toString().toStdString()));
		return PackedTransaction(signedTxn, "none", infoObj2.value("head_block_time").toString(), blockNum, blockPrefix).getJson();
	}
	return "";
}

void EOSHelp::signTransaction(SignedTransaction &txn, const std::vector<std::string> &pubKeys, const TypeChainId &cid)
{
	if (pubKeys.empty()) {
		return;
	}

	for (const auto& k : pubKeys) 
	{
			auto priKey = eos_key::get_private_key_by_wif(k);
			txn.sign(priKey, cid);
	}
}