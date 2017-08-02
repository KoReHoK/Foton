#pragma once

#include "Tab1.h"
#include "Tab2.h"
#include "Tab3.h"

class FotonMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	FotonMainWindow(QWidget *parent = Q_NULLPTR);
	~FotonMainWindow();

private:
	Tab1 *tab1;
	Tab2 *tab2;
	Tab3 *tab3;

	QTabWidget	*centralWidget;
	QStatusBar  *statusBar;
	QToolBar	*toolBar;
	QSettings	*settings;

private:
	void setupCentralWidget();
	void setupStatusBar();
	void setupToolBar();

	void saveSettings();
	void loadSettings();
};
