#include "CameraGroup.h"



CameraGroup::CameraGroup()
{
	horizLayout = new QHBoxLayout(this);
	lightLabel = new QLabel();
	lightLabel->setText("Освещение");
	lightSlider = new QSlider(Qt::Orientation::Horizontal);
	horizLayout->addWidget(lightLabel);
	horizLayout->addWidget(lightSlider);
	this->setFixedSize(380, 50);
}


CameraGroup::~CameraGroup()
{
}
