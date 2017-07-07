#pragma once
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QComboBox>
#include <QPainter>

class SimpleWidget : public QWidget
{
	Q_OBJECT

protected:
	QLabel *defName;
	QPushButton	*delDef;
	QComboBox	*comboColor;
	QPainter	painter;
	uint id;
	Qt::GlobalColor	color;
	void paintEvent(QPaintEvent *event);

protected slots:
	void delWidget();
	void colorChanged(int);

signals:
	void deleteWidget(uint);

public:
	SimpleWidget(QWidget *parent = Q_NULLPTR);
	~SimpleWidget();
	
	void setID(uint);
};