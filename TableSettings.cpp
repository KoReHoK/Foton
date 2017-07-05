#include "TableSettings.h"

TableSettings::TableSettings(QWidget *parent)
	: QWidget(parent)
{
	table = new QTableWidget(12, 2);
	QTableWidgetItem *firstColumnHeader = new QTableWidgetItem("Кнопка");
	QTableWidgetItem *secondColumnHeader = new QTableWidgetItem("Функция");
	table->setHorizontalHeaderItem(0, firstColumnHeader);
	table->setHorizontalHeaderItem(1, secondColumnHeader);
	table->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
	table->setColumnWidth(0, 125);
	table->setColumnWidth(1, 126);

	vLayout = new QVBoxLayout(this);
	vLayout->addWidget(table);
}

TableSettings::~TableSettings()
{
}