#pragma once
#include <QtWidgets/QWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QLayout>

class TableSettings : public QWidget
{
	Q_OBJECT

protected:
	QTableWidget *table;
	QVBoxLayout	 *vLayout;

public:
	TableSettings(QWidget *parent = Q_NULLPTR);
	~TableSettings();

};