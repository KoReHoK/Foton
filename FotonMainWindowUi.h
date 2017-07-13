#pragma once

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QSettings>

#include "Tab1.h"
#include "Tab2.h"
#include "Tab3.h"

QT_BEGIN_NAMESPACE

class FotonMainWindowClassUi
{
protected:
	Tab1 *tab1;
	Tab2 *tab2;
	Tab3 *tab3;

	QTabWidget	*centralWidget;
	QStatusBar *statusBar;
	QSettings	*settings;

	void setupCentralWidget(QMainWindow *FotonMainWindowClass);

public:

	void setupUi(QMainWindow *FotonMainWindowClass);
	void saveSettings(QMainWindow *FotonMainWindowClass);
	void loadSettings(QMainWindow *FotonMainWindowClass);
};

namespace Ui {
	class FotonMainWindowClass : public FotonMainWindowClassUi {};
} // namespace Ui

QT_END_NAMESPACE