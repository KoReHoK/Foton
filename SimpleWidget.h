#pragma once

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
	explicit SimpleWidget(QColor, QWidget *parent = Q_NULLPTR);
	~SimpleWidget();

	void setID(uint);
};