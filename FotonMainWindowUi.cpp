#include "FotonMainWindowUi.h"

void FotonMainWindowClassUi::setupCentralWidget(QMainWindow *FotonMainWindowClass)
{
	centralWidget = new QTabWidget(FotonMainWindowClass);
	centralWidget->setObjectName(QStringLiteral("centralWidget"));
	FotonMainWindowClass->setCentralWidget(centralWidget);

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
	FotonMainWindowClass->resize(600, 400);

	setupCentralWidget(FotonMainWindowClass);
	statusBar = new QStatusBar(FotonMainWindowClass);
	statusBar->setObjectName(QStringLiteral("statusBar"));
	FotonMainWindowClass->setStatusBar(statusBar);

	QMetaObject::connectSlotsByName(FotonMainWindowClass);
}