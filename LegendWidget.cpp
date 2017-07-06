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

void LegendWidget::createDefekt()
{
	SimpleWidget *sWidget = new SimpleWidget();
	sWidget->setParent(this);
	defVector.push_back(sWidget);
	sWidget->setGeometry(10, 50 * defVector.size(), 280, 100);
	sWidget->setVisible(true);
	//resizeEvent();
}

void LegendWidget::resizeEvent()
{

	for (size_t i = 0; i < defVector.size(); i++)
	{
		defVector[i]->setParent(this);
		defVector[i]->setGeometry(10, 50*(i+1), 280, 100);
		defVector[i]->setVisible(true);
	}
}