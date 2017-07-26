#include "stdafx.h"
#include "OffsetGroup.h"

OffsetGroup::OffsetGroup(QWidget *parent)
	: QGroupBox(parent)
{
	this->setTitle("Смещение");

	//TODO: Подумать, как хранить эти элементы
	xLabel = new QLabel("X:");
	xLineEdit = new QLineEdit();
	xSlider = new QSlider(Qt::Orientation::Horizontal);
	percentLabelX = new QLabel("%");
	yLabel = new QLabel("Y:");
	yLineEdit = new QLineEdit();
	ySlider = new QSlider(Qt::Orientation::Horizontal);
	percentLabelY = new QLabel("%");

	gLayout = new QGridLayout(this);
	gLayout->addWidget(xLabel, 0, 0);
	gLayout->addWidget(xLineEdit, 0, 1);
	gLayout->addWidget(xSlider, 0, 2);
	gLayout->addWidget(percentLabelX, 0, 3);
	gLayout->addWidget(yLabel, 1, 0);
	gLayout->addWidget(yLineEdit, 1, 1);
	gLayout->addWidget(ySlider, 1, 2);
	gLayout->addWidget(percentLabelY, 1, 3);
}

OffsetGroup::~OffsetGroup()
{
}