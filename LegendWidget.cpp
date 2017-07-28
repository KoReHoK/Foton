#include "stdafx.h"
#include "LegendWidget.h"

LegendWidget::LegendWidget(QWidget *parent)
	: QWidget(parent) 
{
	pushMe = new QPushButton("Добавить дефект", this);
	pushMe->setGeometry(10, 10, 280, 30);
	connect(pushMe, &QPushButton::clicked, this, &LegendWidget::createDefekt);
}

LegendWidget::~LegendWidget()
{
}

void LegendWidget::createDefekt() {
	QColorDialog *cDialog = new QColorDialog();
	cDialog->show();
	SimpleWidget *sWidget = new SimpleWidget(cDialog->currentColor());
	defVector.push_back(sWidget);
	resizeEvent();

	connect(sWidget, &SimpleWidget::deleteWidget, this, &LegendWidget::resizeVector);
	//TODO: изменить на безопасный формат connect
	connect(cDialog, SIGNAL(currentColorChanged(QColor)), sWidget, SLOT(colorChanged(QColor)));
}

void LegendWidget::resizeEvent() {
	for (size_t i = 0; i < defVector.size(); i++) {
		defVector[i]->setParent(this);
		defVector[i]->setGeometry(10, 50*(i+1), 280, 100);
		defVector[i]->setVisible(true);
		defVector[i]->setID(i);
	}
}

void LegendWidget::resizeVector(uint _id) {
	defVector.erase(defVector.begin() + _id);
	resizeEvent();
}