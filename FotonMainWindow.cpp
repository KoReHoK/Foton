#include "stdafx.h"
#include "FotonMainWindow.h"

FotonMainWindow::FotonMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setupCentralWidget();
	setupStatusBar();
	setupToolBar();

	loadSettings();
}

FotonMainWindow::~FotonMainWindow()
{
	saveSettings();
}

void FotonMainWindow::setupCentralWidget()
{
	centralWidget = new QTabWidget(this);
	setCentralWidget(centralWidget);

	settings = new QSettings("config.ini", QSettings::Format::IniFormat, this);

	tab1 = new Tab1(centralWidget);
	tab2 = new Tab2(centralWidget);
	tab3 = new Tab3(centralWidget);

	centralWidget->addTab(tab1, "Осмотр");
	centralWidget->addTab(tab2, "Карта");
	centralWidget->addTab(tab3, "Настройки");
}

void FotonMainWindow::setupStatusBar()
{
	statusBar = new QStatusBar(this);
	statusBar->addWidget(new QLabel("StatusBar"));
	setStatusBar(statusBar);
}

void FotonMainWindow::setupToolBar()
{
	toolBar = new QToolBar(this);
	toolBar->setMovable(false);

	QVector<QIcon*> icons;
	icons.push_back(new QIcon(":/icons/Resources/icons/toFirst.png"));
	icons.push_back(new QIcon(":/icons/Resources/icons/next.png"));
	icons.push_back(new QIcon(":/icons/Resources/icons/prev.png"));
	icons.push_back(new QIcon(":/icons/Resources/icons/liftUp.png"));
	icons.push_back(new QIcon(":/icons/Resources/icons/liftDown.png"));

	QVector<QIcon*>::const_iterator i;
	for (i = icons.begin(); i != icons.end(); ++i) {
		QToolButton *tmp;
		tmp = new QToolButton();
		tmp->setIcon(**i);
		toolBar->addWidget(tmp);
	}

	addToolBar(toolBar);
}

void FotonMainWindow::saveSettings()
{
	settings->setValue("geometry", geometry());
}

void FotonMainWindow::loadSettings()
{
	setGeometry(settings->value("geometry", QRect(200, 200, 600, 600)).toRect());
}