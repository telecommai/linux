#ifndef INLINE_MAC_H
#define INLINE_MAC_H

#include "QtCore/QString"
#include <QObject>
#include <QStandardPaths>

inline QString getResourcePath()
{
    QString strLocationName = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    strLocationName = strLocationName.section("/", -1, -1);
    #ifdef Q_OS_MAC
    QString strPath = "/Users/" + strLocationName +"/Library/Application\ Support/OpenPlanet/";
    #else
    QString strPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/OpenPlanet";
    #endif
    return strPath;
}

#endif // INLINE_MAC_H
