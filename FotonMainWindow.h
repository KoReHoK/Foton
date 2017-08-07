#pragma once

#include "Tab1.h"
#include "Tab2.h"
#include "Tab3.h"
#include "NewAnalysDialog.h"

class FotonMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit FotonMainWindow(QWidget *parent = Q_NULLPTR);
	~FotonMainWindow();

private:
	Tab1 *tab1;
	Tab2 *tab2;
	Tab3 *tab3;

	QTabWidget	*centralWidget;
	QStatusBar  *statusBar;
	QToolBar	*toolBar;
	QSettings	*settings;
	NewAnalysDialog *analysDialog;
	QVector<QToolButton*> myToolBar;

private:
	void setupCentralWidget();
	void setupStatusBar();
	void setupToolBar();

	void saveSettings();
	void loadSettings();

public:
	bool eventFilter(QObject *watched, QEvent *event) override;
};
