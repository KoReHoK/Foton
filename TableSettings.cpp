#include "stdafx.h"
#include "TableSettings.h"

TableSettings::TableSettings(QWidget *parent)
	: QTableWidget(parent)
{
	setRowCount(12);
	setColumnCount(2);
	QTableWidgetItem *firstColumnHeader = new QTableWidgetItem("Кнопка");
	QTableWidgetItem *secondColumnHeader = new QTableWidgetItem("Функция");
	setHorizontalHeaderItem(0, firstColumnHeader);
	setHorizontalHeaderItem(1, secondColumnHeader);
	setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
	setColumnWidth(0, 138);
	setColumnWidth(1, 138);
}

TableSettings::~TableSettings()
{
}