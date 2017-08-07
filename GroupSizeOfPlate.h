#pragma once

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
	explicit GroupSizeOfPlate(QWidget *parent = Q_NULLPTR);
	~GroupSizeOfPlate();
};