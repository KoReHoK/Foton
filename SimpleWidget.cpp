#include "SimpleWidget.h"

SimpleWidget::SimpleWidget(QWidget * parent)
{
	repaint();
	defName = new QLabel("Название дефекта", this);
	defName->setGeometry(50, 10, 100, 30);
	delDef = new QPushButton("Удалить", this);
	delDef->setGeometry(160, 10, 50, 30);

	QObject::connect(delDef, SIGNAL(clicked()), this, SLOT(delWidget()));
}

SimpleWidget::~SimpleWidget()
{
}

void SimpleWidget::paintEvent(QPaintEvent * event)
{
	Q_UNUSED(event);
	QPainter painter(this);
	painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));
	painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
	painter.drawRect(10, 10, 30, 30);
}

void SimpleWidget::delWidget()
{
	delete this;
}