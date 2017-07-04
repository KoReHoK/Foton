#pragma once

#include <QtWidgets/QMainWindow>
#include "FotonMainWindowUi.h"

class FotonMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	FotonMainWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::FotonMainWindowClass ui;
};
