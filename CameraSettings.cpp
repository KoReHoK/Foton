#include "CameraSettings.h"

CameraSettings::CameraSettings(QWidget *parent)
	: QWidget(parent)
{
	formLayout = new QGridLayout(this);
	formLayout->setVerticalSpacing(2);
	formLayout->setMargin(10);

	gBox = new QGroupBox("Поля зрения");
	gBoxLayout = new QGridLayout(gBox);
}

CameraSettings::~CameraSettings()
{
}


void CameraSettings::addSettings(QString str)
{
	settingsSpace::simpleSettings tmp;
	tmp.nameSettings = new QLabel(str);
	//tmp.nameSettings->setWordWrap(true);
	tmp.sliderSettings = new QSlider(Qt::Orientation::Horizontal);
	tmp.quntitySettings = new QLabel("0");
	settings.push_back(tmp);
	formLayout->addWidget(tmp.nameSettings, settings.size(), 0, Qt::AlignTop);
	formLayout->addWidget(tmp.sliderSettings, settings.size(), 1, Qt::AlignTop);
	formLayout->addWidget(tmp.quntitySettings, settings.size(), 2, Qt::AlignTop);

	QObject::connect(tmp.sliderSettings, SIGNAL(valueChanged(int)), tmp.quntitySettings, SLOT(setNum(int)));
}

void CameraSettings::addFieldSettings(QString str)
{
	settingsSpace::fieldSettings tmp;
	tmp.label = new QLabel(str);
	tmp.edit = new QLineEdit();
	fSettings.push_back(tmp);

	gBoxLayout->addWidget(tmp.label, fSettings.size(), 0);
	gBoxLayout->addWidget(tmp.edit, fSettings.size(), 1);

	if (fSettings.size() == 3)
	{
		formLayout->addWidget(gBox, settings.size() + 1, 0, 1, 2, Qt::AlignLeft);
		formLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding), settings.size() + fSettings.size() + 1, 0);
	}
}
