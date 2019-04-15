#include "eosbytewriter.h"
#include "../ec/typechainid.h"

#include <QVariant>
#include <QDateTime>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonDocument>
#include <sstream>

#include "typepermissionlevel.h"

EOSByteWriter::EOSByteWriter()
{
}

EOSByteWriter::EOSByteWriter(int capacity)
{
    buf.reserve(capacity);
}

EOSByteWriter::EOSByteWriter(const std::vector<unsigned char>& buf)
{
    this->buf.reserve(buf.capacity());
}

EOSByteWriter::~EOSByteWriter()
{
}

void EOSByteWriter::put(unsigned char b)
{
    buf.push_back(b);
}

void EOSByteWriter::putShortLE(short value)
{
    buf.push_back((unsigned char)(0xFF & (value)));
    buf.push_back((unsigned char)(0xFF & (value >> 8)));

}

void EOSByteWriter::putIntLE(int value)
{
    buf.push_back((unsigned char)(0xFF & (value)));
    buf.push_back((unsigned char)(0xFF & (value >> 8)));
    buf.push_back((unsigned char)(0xFF & (value >> 16)));
    buf.push_back((unsigned char)(0xFF & (value >> 24)));
}

void EOSByteWriter::putLongLE(LONG value)
{
    buf.push_back((unsigned char)(0xFF & (value)));
    buf.push_back((unsigned char)(0xFF & (value >> 8)));
    buf.push_back((unsigned char)(0xFF & (value >> 16)));
    buf.push_back((unsigned char)(0xFF & (value >> 24)));
    buf.push_back((unsigned char)(0xFF & (value >> 32)));
    buf.push_back((unsigned char)(0xFF & (value >> 40)));
    buf.push_back((unsigned char)(0xFF & (value >> 48)));
    buf.push_back((unsigned char)(0xFF & (value >> 56)));
}

void EOSByteWriter::putBytes(const unsigned char *value, int len)
{
   const unsigned char *p = value;
    int size = len;
    while(size) {
        buf.push_back(*p);
        p++;
        size--;
    }
}

void EOSByteWriter::putBytes(const unsigned char *value, int offset, int len)
{
    const unsigned char *p = value + offset;
    int size = len;
    while(size) {
        buf.push_back(*p);
        p++;
        size--;
    }
}

std::vector<unsigned char> EOSByteWriter::toBytes()
{
    return buf;
}

int EOSByteWriter::length()
{
    return buf.size();
}

void EOSByteWriter::putString(const std::string& str)
{
    if (str.empty()) {
        putVariableUInt(0);
        return;
    }

    putVariableUInt(str.length());
    putBytes((const unsigned char*)str.c_str(), str.size());
}

void EOSByteWriter::putVariableUInt(LONG val)
{
    do
    {
        unsigned char b = (unsigned char) ((val) & 0x7f);
        val >>= 7;
        b |= (((val > 0) ? 1 : 0) << 7);
        put(b);
    } while(val);
}
