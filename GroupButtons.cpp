#include "GroupButtons.h"



GroupButtons::GroupButtons()
{
	this->setTitle("Режимы джойстика");

	lazyMode = new QPushButton(QIcon(":/icons/Resources/icons/slouly.png"), "");
	normMode = new QPushButton(QIcon(":/icons/Resources/icons/norm.png"), "");
	fastMode = new QPushButton(QIcon(":/icons/Resources/icons/fast.png"), "");
	jerkMode = new QPushButton(QIcon(":/icons/Resources/icons/jerk.png"), "");
	zoneMode = new QPushButton(QIcon(":/icons/Resources/icons/zone.png"), "");

	lazyMode->setFixedWidth(70);
	normMode->setFixedWidth(70);
	fastMode->setFixedWidth(70);
	jerkMode->setFixedWidth(70);
	zoneMode->setFixedWidth(70);

	lazyModeLabel = new QLabel("Медленно");
	normModeLabel = new QLabel("Нормально");
	fastModeLabel = new QLabel("Быстро");
	jerkModeLabel = new QLabel("Рывки");
	zoneModeLabel = new QLabel("В зоне");

	gridLayout = new QGridLayout(this);

	gridLayout->addWidget(lazyMode, 0, 0, Qt::AlignCenter);
	gridLayout->addWidget(normMode, 0, 1, Qt::AlignCenter);
	gridLayout->addWidget(fastMode, 0, 2, Qt::AlignCenter);
	gridLayout->addWidget(jerkMode, 0, 3, Qt::AlignCenter);
	gridLayout->addWidget(zoneMode, 0, 4, Qt::AlignCenter);

	gridLayout->addWidget(lazyModeLabel, 1, 0, Qt::AlignHCenter);
	gridLayout->addWidget(normModeLabel, 1, 1, Qt::AlignHCenter);
	gridLayout->addWidget(fastModeLabel, 1, 2, Qt::AlignHCenter);
	gridLayout->addWidget(jerkModeLabel, 1, 3, Qt::AlignHCenter);
	gridLayout->addWidget(zoneModeLabel, 1, 4, Qt::AlignHCenter);
}


GroupButtons::~GroupButtons()
{
}
