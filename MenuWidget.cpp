#include "stdafx.h"
#include "MenuWidget.h"
#include <iterator>

MenuWidget::MenuWidget(QList<QPushButton*> *list, QWidget *parent) : QWidget(parent)
{
	state = false;
	vLayout = new QVBoxLayout(this);

	QList<QPushButton*>::const_iterator i;
	int height = 0;
	for (i = list->begin(); i != list->end(); ++i) {
		vLayout->addWidget(*i);
		height += 32;	// высота одной менюшки
	}
		

	setFixedSize(100, height);
	hide();

	setStyleSheet("background: rgb(200,200,200)");
}