#pragma once

#include <QWidget>
namespace Ui { class PackUnitWidget; };

class PackUnitWidget : public QWidget
{
	Q_OBJECT

public:
	PackUnitWidget(QWidget *parent = Q_NULLPTR);
	~PackUnitWidget();

	void setInfo(QString picPath, QString unit, QString useable,QString frozen);//图片路径，单位，可用资产，冻结资产

	QString m_unit;//单位
private:
	Ui::PackUnitWidget *ui;
};
