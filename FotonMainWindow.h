#pragma once
#include "CentralWidget.h"
#include "ToolBar.h"

class FotonMainWindow : public QMainWindow
{
public:
	explicit FotonMainWindow(QWidget *parent = Q_NULLPTR);
	~FotonMainWindow();

private:
	QSettings	*settings;
	CentralWidget *mainWidget;

private:
	void setupCentralWidget();
	void setupStatusBar();
	void setupToolBar();

	void saveSettings();
	void loadSettings();
};
