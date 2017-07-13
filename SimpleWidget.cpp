#include "SimpleWidget.h"

SimpleWidget::SimpleWidget(QColor col, QWidget * parent) : color(col)
{
	defName = new QLabel("Название дефекта", this);
	defName->setGeometry(50, 10, 100, 30);
	delDef = new QPushButton("Удалить", this);
	delDef->setGeometry(220, 10, 50, 30);
	repaint();

	QObject::connect(delDef, SIGNAL(clicked()), this, SLOT(delWidget()));
}

SimpleWidget::~SimpleWidget()
{
}

void SimpleWidget::paintEvent(QPaintEvent * event) {
	Q_UNUSED(event);
	painter.begin(this);
	painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
	painter.setBrush(QBrush(color, Qt::SolidPattern));
	painter.drawRect(10, 10, 30, 30);
	painter.end();
}

void SimpleWidget::colorChanged(QColor col){
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