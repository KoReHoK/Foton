#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FotonMainWindow.h"

class FotonMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	FotonMainWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::FotonMainWindowClass ui;
};
