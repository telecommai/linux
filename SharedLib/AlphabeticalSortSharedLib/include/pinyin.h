#ifndef PINYIN_H
#define PINYIN_H

#include <stdio.h>
#include <string.h>
#include <QTextCodec>

struct PinYin
{
	QString fullPinYin;
	QString easyPinYin;
};

//////////////////////////////////////////////////////////////////////////
/// 汉字转拼音函数 使用gb2312编码
//////////////////////////////////////////////////////////////////////////
#define HZ2PY_OUTPUT_BUF_ARRAY_SIZE 5120	//一个字段的拼音最长长度
#define HZ2PY_MAX_PINYIN_SIZE 30			//一个字的拼音最长长度

bool safeAddToOutbuf(char* outbuf, int &iOutbuf, char* pinyinValue, int iPinyinValue);
//////////////////////////////////////////////////////////////////////////
//判断一个字符串是否为utf8编码
//////////////////////////////////////////////////////////////////////////
int findLetter(int nCode, char* strValue);

void pinyin_gb2312(char * inbuf, char * outbuf, bool m_blnSimaple = false, bool polyphone_support = false, bool m_blnFirstBig = false, bool m_blnAllBiG = false, bool m_LetterEnd = false, bool m_unknowSkip = true, bool m_filterPunc = true);
///////////////////////////////////////////拼音结束/////////////////////////////////////////

PinYin getPinYin(QString name);

#endif // PINYIN_H
