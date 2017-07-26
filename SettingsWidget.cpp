#include "stdafx.h"
#include "SettingsWidget.h"

SettingsWidget::SettingsWidget(QWidget *parent)
	: QWidget(parent)
{
	groupSizeOfPlate = new GroupSizeOfPlate();
	groupSizeOfCrystal = new GroupSizeOfCrystal();
	offsetGroupBox = new OffsetGroup();
	vLayout = new QVBoxLayout(this);
	vLayout->addWidget(groupSizeOfPlate);
	vLayout->addWidget(groupSizeOfCrystal);
	vLayout->addWidget(offsetGroupBox);
	vLayout->addStretch();
}

SettingsWidget::~SettingsWidget()
{
}