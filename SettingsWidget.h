#pragma once
#include "GroupSizeOfPlate.h"
#include "GroupSizeOfCrystal.h"
#include "OffsetGroup.h"

class SettingsWidget : public QWidget
{
	Q_OBJECT

protected:
	QVBoxLayout *vLayout;
	GroupSizeOfPlate *groupSizeOfPlate;
	GroupSizeOfCrystal *groupSizeOfCrystal;
	OffsetGroup *offsetGroupBox;

public:
	SettingsWidget(QWidget *parent = Q_NULLPTR);
	~SettingsWidget();

};