#pragma once

class GroupSizeOfCrystal : public QGroupBox
{
	Q_OBJECT

protected:
	QLabel *lWidthCryst;
	QLabel *lHeightCryst;
	QLabel *lWidthLine;
	QLabel *lHeightLine;
	QLineEdit *editWidthCryst;
	QLineEdit *editHeightCryst;
	QLineEdit *editWidthLine;
	QLineEdit *editHeightLine;
	QPushButton *pushMe;
	QGridLayout *gLayout;

public:
	explicit GroupSizeOfCrystal(QWidget *parent = Q_NULLPTR);
	~GroupSizeOfCrystal();
};