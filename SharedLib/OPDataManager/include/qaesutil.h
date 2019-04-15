#ifndef QAESUTIL_H
#define QAESUTIL_H

#include <QObject>
#include <QtWidgets/QApplication>
#include <iostream>
#include <botan/botan.h>
#include <botan/pbkdf.h>
#include <string>  
using namespace std;
using namespace Botan;

#pragma comment(lib,"botan")

class QAesUtil : public QObject
{
	Q_OBJECT

public:
	QAesUtil(QObject *parent = 0);
	~QAesUtil();


	// Qualifier: AES加密数据 返回加密后base64
	QByteArray EncryptionData(QByteArray strData, QString passWord, bool base64 = true);

	// Qualifier: AES解密数据 传入base64 返回字符串
	QByteArray DecryptData(QByteArray strData, QString passWord, bool base64 = true);

private:
	// Qualifier: AES加密解密
	QByteArray cryptoAES256(QByteArray input, SymmetricKey passphrase, Cipher_Dir opt);

	// Qualifier: 对key进行加密
	OctetString AESKeyForPassword(QString passWord);
};

#endif // QAESUTIL_H
