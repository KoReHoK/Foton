#pragma once

#include "Tab2Ui.h"

class Tab2 : public QWidget
{
	Q_OBJECT

public:
	Tab2(QWidget *parent = Q_NULLPTR);
	~Tab2();

private:
	Ui::Tab2 ui;

};