#include "stdafx.h"
#include "FotonMainWindow.h"

FotonMainWindow::FotonMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.loadSettings(this);
}

FotonMainWindow::~FotonMainWindow()
{
	ui.saveSettings(this);
}
