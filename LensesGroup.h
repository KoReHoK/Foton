#pragma once
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QLayout>

class LensesGroup : public QGroupBox
{
public:
	LensesGroup();
	~LensesGroup();

private:
	QGridLayout *gridLayout;
	QRadioButton *buttonX5;
	QRadioButton *buttonX10;
	QRadioButton *buttonX20;
	QRadioButton *buttonIX5;
	QRadioButton *buttonIX10;
	QRadioButton *buttonIX20;
};

