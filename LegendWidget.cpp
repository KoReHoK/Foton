#include "LegendWidget.h"

LegendWidget::LegendWidget(QWidget *parent)
	: QWidget(parent)
{
	pushMe = new QPushButton("Добавить дефект");
	QObject::connect(pushMe, SIGNAL(clicked()), this, SLOT(createButtons()));
	vLayout = new QVBoxLayout(this);
	vLayout->addWidget(pushMe);
}

LegendWidget::~LegendWidget()
{
}

void LegendWidget::createButtons()
{
	QLabel *tmp = new QLabel("example");
	defVector.push_back(tmp);
	vLayout->addWidget(tmp);
	tmp->setVisible(true);
}