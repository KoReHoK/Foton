#include "ViewWidget.h"

ViewWidget::ViewWidget(QWidget *parent)
	: QGroupBox(parent)
{
	this->setTitle("Вид");
	this->setFixedSize(400, 200);

	lensGroup = new LensesGroup();
	lensGroup->setTitle("Объективы");
	camGroup = new CameraGroup();
	camGroup->setTitle("Камера");
	vertLayout = new QVBoxLayout(this);
	vertLayout->addWidget(lensGroup);
	vertLayout->addWidget(camGroup);
}
