#include "TableSettings.h"

TableSettings::TableSettings(QWidget *parent)
	: QTableWidget(parent)
{
	this->setRowCount(12);
	this->setColumnCount(2);
	QTableWidgetItem *firstColumnHeader = new QTableWidgetItem("Кнопка");
	QTableWidgetItem *secondColumnHeader = new QTableWidgetItem("Функция");
	this->setHorizontalHeaderItem(0, firstColumnHeader);
	this->setHorizontalHeaderItem(1, secondColumnHeader);
	this->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
	this->setColumnWidth(0, 138);
	this->setColumnWidth(1, 138);
}

TableSettings::~TableSettings()
{
}