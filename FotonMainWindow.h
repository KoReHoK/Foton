#pragma once

#include "FotonMainWindowUi.h"

class FotonMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	FotonMainWindow(QWidget *parent = Q_NULLPTR);
	~FotonMainWindow();

private:
	Ui::FotonMainWindowClass ui;
};
