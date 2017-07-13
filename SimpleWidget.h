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
	QPainter	painter;
	QColor	color;
	void paintEvent(QPaintEvent *event);
	uint	id;

protected slots:
	void delWidget();
	void colorChanged(QColor);

signals:
	void deleteWidget(uint);

public:
	SimpleWidget(QColor, QWidget *parent = Q_NULLPTR);
	~SimpleWidget();

	void setID(uint);
};