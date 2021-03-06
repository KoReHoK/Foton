#pragma once

#include <vector>

namespace settingsSpace {

	struct simpleSettings
	{
		QLabel	*nameSettings;
		QSlider *sliderSettings;
		QLabel *quntitySettings;
	};

	struct fieldSettings
	{
		QLabel	*label;
		QLineEdit	*edit;
	};
}


class CameraSettings : public QWidget
{
	Q_OBJECT

protected:
	std::vector<settingsSpace::simpleSettings> ssettings;
	std::vector<settingsSpace::fieldSettings> fSettings;
	QGroupBox	*gBox;
	QGridLayout *formLayout;
	QGridLayout	*gBoxLayout;
	QSettings	*settings;
	QString		*keySettings;

public:
	explicit CameraSettings(QString *key, QWidget *parent = Q_NULLPTR);
	~CameraSettings();
	void addSettings(QString);
	void addFieldSettings(QString);
	void saveSettings();
	void loadSettings();
};