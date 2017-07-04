#pragma once

#include "Tab1Ui.h"

class Tab1 : public QWidget
{
	Q_OBJECT

public:
	Tab1(QWidget *parent = Q_NULLPTR);
	~Tab1();

private:
	Ui::Tab1 ui;
	
};
