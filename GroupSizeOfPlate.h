#pragma once

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QRadioButton>

class GroupSizeOfPlate : public QGroupBox
{
	Q_OBJECT

protected:
	QRadioButton *size50;
	QRadioButton *size75;
	QRadioButton *size100;
	QRadioButton *size125;
	QRadioButton *size150;
	QRadioButton *size200;
	QGridLayout *gLayout;

public:
	GroupSizeOfPlate(QWidget *parent = Q_NULLPTR);
	~GroupSizeOfPlate();
};