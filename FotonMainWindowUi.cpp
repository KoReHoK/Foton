#include "stdafx.h"
#include "FotonMainWindowUi.h"

void FotonMainWindowClassUi::setupCentralWidget(QMainWindow *FotonMainWindowClass)
{
	centralWidget = new QTabWidget(FotonMainWindowClass);
	centralWidget->setObjectName(QStringLiteral("centralWidget"));
	FotonMainWindowClass->setCentralWidget(centralWidget);

	settings = new QSettings("config.ini", QSettings::Format::IniFormat, FotonMainWindowClass);

	tab1 = new Tab1();
	tab2 = new Tab2();
	tab3 = new Tab3();

	centralWidget->addTab(tab1, "Осмотр");
	centralWidget->addTab(tab2, "Карта");
	centralWidget->addTab(tab3, "Настройки");
}

void FotonMainWindowClassUi::setupUi(QMainWindow *FotonMainWindowClass)
{
	if (FotonMainWindowClass->objectName().isEmpty())
		FotonMainWindowClass->setObjectName(QStringLiteral("FotonMainWindowClass"));

	setupCentralWidget(FotonMainWindowClass);
	statusBar = new QStatusBar(FotonMainWindowClass);
	statusBar->setObjectName(QStringLiteral("statusBar"));
	FotonMainWindowClass->setStatusBar(statusBar);

	//QMetaObject::connectSlotsByName(FotonMainWindowClass);
}

void FotonMainWindowClassUi::saveSettings(QMainWindow *FotonMainWindowClass)
{
	settings->setValue("geometry", FotonMainWindowClass->geometry());
}

void FotonMainWindowClassUi::loadSettings(QMainWindow *FotonMainWindowClass)
{
	FotonMainWindowClass->setGeometry(settings->value("geometry", QRect(200, 200, 600, 600)).toRect());
}
