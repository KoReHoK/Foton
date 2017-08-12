#include "stdafx.h"
#include "FotonMainWindow.h"

FotonMainWindow::FotonMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	setupCentralWidget();
	setupStatusBar();
	setupToolBar();

	settings = new QSettings("config.ini", QSettings::Format::IniFormat, this);
	loadSettings();
	_CrtSetDbgFlag(0);
}

FotonMainWindow::~FotonMainWindow()
{
	saveSettings();
}

void FotonMainWindow::setupCentralWidget()
{
	mainWidget = new CentralWidget(this);
	setCentralWidget(mainWidget);
}

void FotonMainWindow::setupStatusBar()
{
	statusBar = new QStatusBar(this);
	statusBar->addWidget(new QLabel("StatusBar"));
	setStatusBar(statusBar);
}

void FotonMainWindow::setupToolBar()
{
	toolBar = new ToolBar(this);
	addToolBar(toolBar);

	connect(toolBar, &ToolBar::showPanorama, mainWidget, &CentralWidget::showPanorama);
	connect(toolBar, &ToolBar::showCamera, mainWidget, &CentralWidget::showCamera);
	connect(toolBar, &ToolBar::showWizard, mainWidget, &CentralWidget::showWizard);
	connect(toolBar, &ToolBar::setCrystMode, mainWidget, &CentralWidget::setCrystMode);
}

void FotonMainWindow::saveSettings()
{
	settings->setValue("geometry", geometry());
}

void FotonMainWindow::loadSettings()
{
	setGeometry(settings->value("geometry", QRect(200, 200, 600, 600)).toRect());
}