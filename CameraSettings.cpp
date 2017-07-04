#include "CameraSettings.h"

CameraSettings::CameraSettings(QWidget *parent)
	: QWidget(parent)
{
	formLayout = new QGridLayout(this);
	formLayout->setVerticalSpacing(2);
	formLayout->setMargin(10);
}

CameraSettings::~CameraSettings()
{
}


void CameraSettings::addSetings(QString str)
{
	simpleSettings tmp;
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