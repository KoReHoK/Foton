#include "stdafx.h"
#include "Redaktor.h"
#include "CentralWidget.h"

Redaktor::Redaktor(QWidget * parent)
	: QTableWidget(parent)
{
	QVector<QString> headers{
		"Код", "Описание", "Цвет", "Клавиатура", "Джойстик",
		"Обход", "Кнопка", "Автофото", "Удалить"
	};
	
	setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
	setColumnCount(headers.count());
	setRowCount(1);
	//insertRow(1);

	QVector<QString>::iterator i = headers.begin();
	for (int count = 0; i != headers.end(); ++i) {
		QTableWidgetItem *columnHeader = new QTableWidgetItem(*i);
		setHorizontalHeaderItem(count, columnHeader);
		count++;
	}

	for (int i = 0; i <= rowCount(); i++)
		for (int j = 5; j <= columnCount(); j++) {
			QWidget *pCheckBoxWholeWidget = new QWidget();
			QHBoxLayout *pLayoutWidget = new QHBoxLayout(pCheckBoxWholeWidget);
			pLayoutWidget->setMargin(0);
			pLayoutWidget->setSpacing(0);
			QCheckBox *pCheckBox = new QCheckBox();
			pLayoutWidget->addWidget(pCheckBox, 0, Qt::AlignCenter);

			setCellWidget(i, j, pCheckBoxWholeWidget);
		}

	connect(this, &QTableWidget::cellDoubleClicked, this, &Redaktor::showColorDialog);
}

void Redaktor::showColorDialog(int row, int column)
{
	if (column == 2) {
		QColorDialog cDialog(this);
		// TODO: Возможно происходит утечка памяти
		QTableWidgetItem *tmp = new QTableWidgetItem();
		if (cDialog.exec() == QDialog::Accepted) {
			tmp->setBackgroundColor(cDialog.currentColor());
			setItem(row, column, tmp);
		}
	}
}

void Redaktor::addDef(QString desc, int code, bool good, bool butt, bool foto) {
	defekt tmp;
	tmp.deskription = desc;
	tmp.code = code;
	tmp.good = good;
	tmp.button = butt;
	tmp.autoFoto = foto;

	def.push_back(tmp);
	insertRow(def.size());
}