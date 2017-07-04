#include "GroupSizeOfPlate.h"

GroupSizeOfPlate::GroupSizeOfPlate(QWidget *parent)
	: QGroupBox(parent)
{
	this->setTitle("Размер пластины");

	//TODO: Подумать, где лучше хранить QRadioButtons
	size50 = new QRadioButton("50");
	size75 = new QRadioButton("75");
	size100 = new QRadioButton("100");
	size125 = new QRadioButton("125");
	size150 = new QRadioButton("150");
	size200 = new QRadioButton("200");

	gLayout = new QGridLayout(this);
	gLayout->addWidget(size50, 0, 0);
	gLayout->addWidget(size75, 0, 1);
	gLayout->addWidget(size100, 0, 2);
	gLayout->addWidget(size125, 1, 0);
	gLayout->addWidget(size150, 1, 1);
	gLayout->addWidget(size200, 1, 2);
}

GroupSizeOfPlate::~GroupSizeOfPlate()
{
}