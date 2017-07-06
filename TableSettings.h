#pragma once
#include <QtWidgets/QTableWidget>

class TableSettings : public QTableWidget
{
	Q_OBJECT

public:
	TableSettings(QWidget *parent = Q_NULLPTR);
	~TableSettings();

};