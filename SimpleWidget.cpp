#include "stdafx.h"
#include "SimpleWidget.h"

SimpleWidget::SimpleWidget(QColor col, QWidget * parent) : color(col)
{
	QLabel *defName = new QLabel("Название дефекта", this);
	defName->setGeometry(50, 10, 100, 30);
	QPushButton	*delDef = new QPushButton("Удалить", this);
	delDef->setGeometry(220, 10, 50, 30);

	connect(delDef, &QPushButton::clicked, this, &SimpleWidget::delWidget);
}

void SimpleWidget::paintEvent(QPaintEvent * event) {
	Q_UNUSED(event);
	QPainter painter;
	painter.begin(this);
	painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
	painter.setBrush(QBrush(color, Qt::SolidPattern));
	painter.drawRect(10, 10, 30, 30);
	painter.end();
}

void SimpleWidget::colorChanged(const QColor &col){
	color = col;
	repaint();
}

void SimpleWidget::delWidget() {
	emit deleteWidget(id);
	delete this;
}

void SimpleWidget::setID(uint _id)
{
	id = _id;
}