#ifndef GETDEVICEINFO_H
#define GETDEVICEINFO_H

#include <QObject>

class GetDeviceInfo : public QObject
{
	Q_OBJECT

public:
	GetDeviceInfo(QObject *parent = 0);
	~GetDeviceInfo();

	QString GetDeviceType();          //获取设备类型

	QString GetDeviceVersion();       //获取设备版本

	QString GetDeviceManufacturer();   //获取设备厂商

	QString GetDeviceModel();          //获取设备型号

	QString GetAppVersion();            //获取应用版本号

	QString GetDeviceID();             //获取设备ID

	QString GetDeviceClass();         //获取设备分类

	QString GetCurrentMacAddress();  //获取mac地址

private:
	
};

#endif // GETDEVICEINFO_H
