#include "stdafx.h"
#include "CameraSettings.h"

CameraSettings::CameraSettings(QString *key, QWidget *parent)
	: QWidget(parent)
{
	formLayout = new QGridLayout(this);
	formLayout->setVerticalSpacing(2);
	formLayout->setMargin(10);

	gBox = new QGroupBox("Поля зрения");
	gBoxLayout = new QGridLayout(gBox);
	settings = new QSettings("config.ini", QSettings::Format::IniFormat, this);
	keySettings = key;
}

CameraSettings::~CameraSettings()
{
	saveSettings();
}


void CameraSettings::addSettings(QString str)
{
	settingsSpace::simpleSettings tmp;
	tmp.nameSettings = new QLabel(str);
	//tmp.nameSettings->setWordWrap(true);
	tmp.sliderSettings = new QSlider(Qt::Orientation::Horizontal);
	tmp.quntitySettings = new QLabel("0");
	ssettings.push_back(tmp);
	formLayout->addWidget(tmp.nameSettings, ssettings.size(), 0, Qt::AlignTop);
	formLayout->addWidget(tmp.sliderSettings, ssettings.size(), 1, Qt::AlignTop);
	formLayout->addWidget(tmp.quntitySettings, ssettings.size(), 2, Qt::AlignTop);

	connect(tmp.sliderSettings, SIGNAL(valueChanged(int)), tmp.quntitySettings, SLOT(setNum(int)));
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
		formLayout->addWidget(gBox, ssettings.size() + 1, 0, 1, 2, Qt::AlignLeft);
		formLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Expanding), ssettings.size() + fSettings.size() + 1, 0);
	}
}

void CameraSettings::saveSettings()
{
	settings->beginWriteArray(*keySettings, ssettings.size());
	for (int i = 0; i < ssettings.size(); ++i) {
		settings->setArrayIndex(i);
		settings->setValue("slider", ssettings[i].sliderSettings->value());
	}
	settings->endArray();
}

void CameraSettings::loadSettings()
{
	settings->beginReadArray(*keySettings);
	for (int i = 0; i < ssettings.size(); ++i) {
		settings->setArrayIndex(i);
		ssettings[i].sliderSettings->setValue(settings->value("slider", 0).toInt());
	}
	settings->endArray();
}
