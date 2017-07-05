#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets\QLabel>
#include <QtWidgets/QLayout>



class LegendWidget : public QWidget
{
	Q_OBJECT

protected:
	QVBoxLayout *vLayout;
	QPushButton	*pushMe;
	std::vector<QLabel*> defVector;

public:
	LegendWidget(QWidget *parent = Q_NULLPTR);
	~LegendWidget();

public slots:
	void createButtons();
};