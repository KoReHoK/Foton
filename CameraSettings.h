#pragma once
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QGridLayout>
#include <vector>

struct simpleSettings
{
	QLabel	*nameSettings;
	QSlider *sliderSettings;
	QLabel *quntitySettings;
};

class CameraSettings : public QWidget
{
	Q_OBJECT

protected:
	std::vector<simpleSettings> settings;
	QGridLayout *formLayout;

public:
	CameraSettings(QWidget *parent = Q_NULLPTR);
	~CameraSettings();
	void addSetings(QString);

};