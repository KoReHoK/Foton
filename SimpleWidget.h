#pragma once
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QPainter>

class SimpleWidget : public QWidget
{
	Q_OBJECT

protected:
	QLabel *defName;
	QPushButton	*delDef;
	void paintEvent(QPaintEvent *event);

protected slots:
	void delWidget();

public:
	SimpleWidget(QWidget *parent = Q_NULLPTR);
	~SimpleWidget();
};