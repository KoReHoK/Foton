#include "CircumWidget.h"

CircumWidget::CircumWidget(QWidget *parent)
	: QGroupBox(parent)
{
	this->setTitle("Обход");
	this->setFixedSize(400, 150);

	checkSaveBox = new QCheckBox();
	saveLabel = new QLabel("Сохранять относительное положение на кристалле");
	saveLabel->setSizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
	groupButton = new GroupButtons();
	gridLayout = new QGridLayout(this);
	gridLayout->addWidget(checkSaveBox, 0, 0);
	gridLayout->addWidget(saveLabel, 0, 1);
	gridLayout->addWidget(groupButton, 1, 0, 1, 2);
}