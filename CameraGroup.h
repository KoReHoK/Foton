#pragma once
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QLayout>

class CameraGroup : public QGroupBox
{
public:
	CameraGroup();
	~CameraGroup();

private:
	QHBoxLayout *horizLayout;
	QLabel *lightLabel;
	QSlider *lightSlider;
};

