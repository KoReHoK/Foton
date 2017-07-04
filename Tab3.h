#pragma once

#include "Tab3Ui.h"

class Tab3 : public QWidget
{
	Q_OBJECT

public:
	Tab3(QWidget *parent = Q_NULLPTR);
	~Tab3();

private:
	Ui::Tab3 ui;

};