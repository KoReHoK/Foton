#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include "SimpleWidget.h"


class LegendWidget : public QWidget
{
	Q_OBJECT

protected:
	QPushButton	*pushMe;
	std::vector<SimpleWidget*> defVector;

	void resizeEvent();

public:
	LegendWidget(QWidget *parent = Q_NULLPTR);
	~LegendWidget();

public slots:
	void createDefekt();
};