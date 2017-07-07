#include "LegendWidget.h"

LegendWidget::LegendWidget(QWidget *parent)
	: QWidget(parent) 
{
	pushMe = new QPushButton("Добавить дефект", this);
	pushMe->setGeometry(10, 10, 280, 30);
	QObject::connect(pushMe, SIGNAL(clicked()), this, SLOT(createDefekt()));
}

LegendWidget::~LegendWidget()
{
}

void LegendWidget::createDefekt() {
	SimpleWidget *sWidget = new SimpleWidget();
	defVector.push_back(sWidget);
	resizeEvent();

	QObject::connect(sWidget, SIGNAL(deleteWidget(uint)), this, SLOT(resizeVector(uint)));
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