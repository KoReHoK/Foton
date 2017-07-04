#include "LensesGroup.h"



LensesGroup::LensesGroup()
{
	buttonX5 = new QRadioButton();
	buttonX5->setText("X5");
	buttonX5->setChecked(true);
	buttonX10 = new QRadioButton();
	buttonX10->setText("X10");
	buttonX20 = new QRadioButton();
	buttonX20->setText("X20");
	buttonIX5 = new QRadioButton();
	buttonIX5->setText("IX5");
	buttonIX10 = new QRadioButton();
	buttonIX10->setText("IX10");
	buttonIX20 = new QRadioButton();
	buttonIX20->setText("IX20");

	gridLayout = new QGridLayout(this);
	gridLayout->addWidget(buttonX5, 0, 0);
	gridLayout->addWidget(buttonX10, 0, 1);
	gridLayout->addWidget(buttonX20, 0, 2);
	gridLayout->addWidget(buttonIX5, 1, 0);
	gridLayout->addWidget(buttonIX10, 1, 1);
	gridLayout->addWidget(buttonIX20, 1, 2);
}


LensesGroup::~LensesGroup()
{
}
