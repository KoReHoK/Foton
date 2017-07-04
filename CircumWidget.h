#pragma once
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include "GroupButtons.h"

class CircumWidget : public QGroupBox
{
	Q_OBJECT

public:
	CircumWidget(QWidget *parent = Q_NULLPTR);

private:
	QGridLayout *gridLayout;
	QCheckBox *checkSaveBox;
	QLabel *saveLabel;
	GroupButtons *groupButton;
};
