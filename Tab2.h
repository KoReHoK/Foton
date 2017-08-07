#pragma once

#include "SettingsWidget.h"
#include "LegendWidget.h"
#include "navigationbar.h"

class Tab2 : public QWidget
{
	Q_OBJECT

public:
	explicit Tab2(QWidget *parent = Q_NULLPTR);

protected:
	SettingsWidget *settings;
	LegendWidget	*legend;
	QWidget			*widget;
	QHBoxLayout		*hLayout;
	QToolBox		*toolBox;
	NavigationBar	*navBar;

public slots:
	void dialog(QString*);
};