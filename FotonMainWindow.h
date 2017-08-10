#pragma once
#include "CentralWidget.h"
#include "ToolBar.h"

class FotonMainWindow : public QMainWindow
{
public:
	explicit FotonMainWindow(QWidget *parent = Q_NULLPTR);
	~FotonMainWindow();

private:
	CentralWidget	*mainWidget;
	QStatusBar  *statusBar;
	ToolBar	*toolBar;

	QSettings	*settings;

private:
	void setupCentralWidget();
	void setupStatusBar();
	void setupToolBar();

	void saveSettings();
	void loadSettings();
};
