#pragma once
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QGridLayout>
#include <QtWidgets\QLabel>

class GroupButtons : public QGroupBox
{
public:
	GroupButtons();
	~GroupButtons();

private:
	QPushButton *lazyMode;
	QPushButton *normMode;
	QPushButton *fastMode;
	QPushButton *jerkMode;
	QPushButton *zoneMode;

	QLabel *lazyModeLabel;
	QLabel *normModeLabel;
	QLabel *fastModeLabel;
	QLabel *jerkModeLabel;
	QLabel *zoneModeLabel;

	QGridLayout *gridLayout;
};

